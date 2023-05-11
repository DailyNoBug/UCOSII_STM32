#include "clock_config.h"
#include "gpio.h"
#include "uart.h"
#include "mpu6050.h"
#include "iic.h"
#include "pwm.h"
#include "rev.h"
#include "ucos_ii.h"
#include "task.h"
#include "stm32f401ret6.h"
#include <stdio.h>

extern float Ax,Ay,Az;
extern float Gx,Gy,Gz;
extern float temp;
extern uint16_t data[9];
#define TASK_STACK_SIZE 1024
OS_STK Task_1Stack[TASK_STACK_SIZE];
#define TASKF_PRIO 3

OS_STK Task0Stack[TASK_STACK_SIZE];
#define TASK0_PRIO 4

OS_STK Task1Stack[TASK_STACK_SIZE];
#define TASK1_PRIO 5

OS_STK Task2Stack[TASK_STACK_SIZE];
#define TASK2_PRIO 6

#if 1

#pragma import(__use_no_semihosting)

/* 定义 _sys_exit() 以避免使用半主机模式 */
struct __FILE
{
    int handle;
};

FILE __stdout;
void _sys_exit(int x)
{
    x = x;
}
//重定义fputc函数
int fputc(int ch, FILE *f)
{
    while((USART6->SR & 0X40)==0);
    USART6->DR = (uint8_t) ch;
    return ch;
}
#endif

void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
    if ((int32_t)IRQn < 0) {
        SCB->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] =
                (uint8_t)((priority << (8 - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
    } else {
        NVIC->IP[((uint32_t)(int32_t)IRQn)] =
                (uint8_t)((priority << (8 - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
    }
}
void delay_init(void)
{
    SysTick->CTRL &= ~SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->LOAD = 84000000/OS_TICKS_PER_SEC -1; // 设置重装载值为最大值
    SysTick->VAL = 0; // 清除当前计数值
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                     SysTick_CTRL_TICKINT_Msk   |
                     SysTick_CTRL_ENABLE_Msk;
    NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);

//    u32 reload;
//    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
//    fac_us = SYSCLK/8;						//不论是否使用OS,fac_us都需要使用
//    reload = SYSCLK/8;						//每秒钟的计数次数 单位为M
//    reload *= 1000000 / delay_ostickspersec;	//根据delay_ostickspersec设定溢出时间
//    //reload为24位寄存器,最大值:16777216,在168M下,约合0.7989s左右
//    fac_ms=1000 / delay_ostickspersec;		//代表OS可以延时的最少单位
//    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;   	//开启SYSTICK中断
//    SysTick->LOAD = reload; 					//每1/delay_ostickspersec秒中断一次
//    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; 	//开启SYSTICK
    //fac_ms=(u16)fac_us*1000;				//非OS下,代表每个ms需要的systick时钟数
}
void First_Task() {
    USART_SendStr(USART1,"[SWITCH] First Task\n");
    delay_init();  //初始化延时函数
}
/*
 * init PA5
 */
void debug_init(){
    GPIO_InitTypeDef InitStruct;
    InitStruct.GPIO_Pin     = GPIO_Pin_5;
    InitStruct.GPIO_Mode    = GPIO_Mode_Out;
    InitStruct.GPIO_OType   = GPIO_OType_PP;
    InitStruct.GPIO_Speed   = GPIO_Speed_2MHz;
    InitStruct.GPIO_Pupd    = GPIO_Pupd_NOPULL;
    GPIO_Init(GPIOA,&InitStruct);
}

int main(){
    pll_clock_config();
    USART_Init(USART6,9600,42);
    USART_Init(USART1,9600,42);
    USART_SendStr(USART1,"-----------------------------------------------------------------------------------\n");
    USART_SendStr(USART1,"|STM32F401RET6 UCOS II DESIGNED BY LSC WITH GROUP ONE|\n");
    USART_SendStr(USART1,"-----------------------------------------------------------------------------------\n");
    I2C_Init(I2C2);
    USART_SendStr(USART1,"[INFO] I2C init\n");
    TIM_Init(19999,41);
    USART_SendStr(USART1,"[INFO] TIM init\n");
    TIM_UnLock();
    USART_SendStr(USART1,"[INFO] MENTOR unlock\n");
    REV_TIM_Init();
    USART_SendStr(USART1,"[INFO] Reciver TIM init\n");
    MPU6050_Init();
    USART_SendStr(USART1,"[INFO] IMU init\n");
//    USART_SendChar(USART1,'c');
    OSInit();
    delay_init();
    USART_SendStr(USART1,"OS init\n");
    OSTaskCreate(First_Task, (void *)0, &Task_1Stack[TASK_STACK_SIZE - 1], TASKF_PRIO);
    USART_SendStr(USART1,"First_Task Created\n");
    OSTaskCreate(MPU6050Task,(void *)0,&Task0Stack[TASK_STACK_SIZE-1],TASK0_PRIO);
    USART_SendStr(USART1,"IMU Task Created\n");
    OSTaskCreate(SerialTask,(void *)0,&Task1Stack[TASK_STACK_SIZE-1],TASK1_PRIO);
    USART_SendStr(USART1,"SerialTask Created\n");
    OSTaskCreate(PWMTask,(void *)0,&Task2Stack[TASK_STACK_SIZE-1],TASK2_PRIO);
    USART_SendStr(USART1,"PWM Task Created\n");
    OSStart();
//    while(1){
//
//        for(int i=1;i<=8;i++)
//        {
//            printf("%d        %d\n",i,data[i]);
//        }
//        if(data[7]>1200&&data[7]){
//            //遥控器未开启
//            PWM_All(1000);
//        }
//        else if(data[2]==0||3000-data[2]>2000){
//            PWM_All(1000);
//        }
//        else{
//            PWM_All(3000-data[2]);
//        }
//        for(int i=1;i<=10000000;i++);
//        GPIO_ReSetBits(GPIOA,GPIO_Pin_5);
//    }
}