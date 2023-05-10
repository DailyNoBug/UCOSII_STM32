#include "clock_config.h"
#include "gpio.h"
#include "uart.h"
#include "mpu6050.h"
#include "iic.h"
#include "pwm.h"
#include "rev.h"
#include "ucos_ii.h"
#include "task.h"
#include <stdio.h>

extern float Ax,Ay,Az;
extern float Gx,Gy,Gz;
extern float temp;
extern uint16_t data[9];
#define TASK_STACK_SIZE 512
OS_STK Task0Stack[TASK_STACK_SIZE];
#define TASK0_PRIO 3

OS_STK Task1Stack[TASK_STACK_SIZE];
#define TASK1_PRIO 4

OS_STK Task2Stack[TASK_STACK_SIZE];
#define TASK2_PRIO 5

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
    I2C_Init(I2C2);
    TIM_Init(19999,41);
    TIM_UnLock();
    REV_TIM_Init();
    MPU6050_Init();
//    USART_SendChar(USART6,'c');
    USART_SendStr(USART1,"test1\n");
    printf("%s\n","OSIniting");
    OSInit();
    OSTaskCreate((void *)MPU6050Task,(void *)0,&Task0Stack[TASK_STACK_SIZE-1],TASK0_PRIO);
    OSTaskCreate((void *)SerialTask,(void *)0,&Task1Stack[TASK_STACK_SIZE-1],TASK1_PRIO);
    OSTaskCreate((void *)PWMTask,(void *)0,&Task2Stack[TASK_STACK_SIZE-1],TASK2_PRIO);
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