//
// Created by lsc on 23-5-9.
//
#include "task.h"
int lll=1000;
void MPU6050Task(void){
    while(1){
        USART_SendStr(USART1,"[SWITCH] IMU Task\n");
        MPU6050_Read();
//        OSTimeDly(50);
        OSTimeDlyHMSM(0,0,0,50);
    }
}
void SerialTask(void){
    while(1){
        USART_SendStr(USART1,"[SWITCH] SerialTask\n");
//        printf("%s\n","test");
//        OSTimeDly(50);
        OSTimeDlyHMSM(0,0,0,50);
    }
}
void PWMTask(void){
    while(1){
        USART_SendStr(USART1,"[SWITCH] PWM Task\n");
        PWM_All(1200);
//        OSTimeDly(50);
        OSTimeDlyHMSM(0,0,0,50);
    }
}