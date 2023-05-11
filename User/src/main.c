#include "clock_config.h"
#include "gpio.h"
#include "uart.h"
#include "mpu6050.h"
#include "iic.h"
#include "pwm.h"
#include "rev.h"
#include "ucos_ii.h"
#include "task.h"
#include "NVIC.h"
#include "stm32f401ret6.h"
#include <stdio.h>

extern float Ax,Ay,Az;
extern float Gx,Gy,Gz;
extern float temp;
extern uint16_t data[9];
#define TASK_STACK_SIZE 1024
OS_STK TIME_INIT_STACK[TASK_STACK_SIZE];
#define TIME_INIT_PRIO 3

OS_STK IMU_TASK_STACK[TASK_STACK_SIZE];
#define IMU_TASK_PRIO 4

OS_STK ULOG_TASK_STACK[TASK_STACK_SIZE];
#define ULOG_TASK_PRIO 5

OS_STK MOTOR_TASK_STACK[TASK_STACK_SIZE];
#define MOTOR_TASK_PRIO 6

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
    OSTaskCreate(TIME_INIT, (void *)0, &TIME_INIT_STACK[TASK_STACK_SIZE - 1], TIME_INIT_PRIO);
    USART_SendStr(USART1,"TIME INIT TASK Created\n");
    OSTaskCreate(IMU_TASK,(void *)0,&IMU_TASK_STACK[TASK_STACK_SIZE-1],IMU_TASK_PRIO);
    USART_SendStr(USART1,"IMU Task Created\n");
    OSTaskCreate(ULOG_TASK,(void *)0,&ULOG_TASK_STACK[TASK_STACK_SIZE-1],ULOG_TASK_PRIO);
    USART_SendStr(USART1,"SerialTask Created\n");
    OSTaskCreate(MOTOR_TASK,(void *)0,&MOTOR_TASK_STACK[TASK_STACK_SIZE-1],MOTOR_TASK_PRIO);
    USART_SendStr(USART1,"PWM Task Created\n");
    OSStart();
//    while(1){
//
//        for(int i=1;i<=8;i++)
//        {
//            printf("%d        %d\n",i,data[i]);
//        }

//        for(int i=1;i<=10000000;i++);

//    }
}