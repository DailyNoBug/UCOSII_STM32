//
// Created by lsc on 23-5-9.
//
#include "task.h"
void MPU6050Task(void){
    while(1){
        MPU6050_Read();
        OSTimeDlyHMSM(0,0,0,1000);
    }
}
void SerialTask(void){
    while(1){
//        USART_SendChar(USART6,'p');
        printf("%s\n","test");
        OSTimeDlyHMSM(0,0,0,1000);
    }
}
void PWMTask(void){
    while(1){
        PWM_All(1200);
        OSTimeDlyHMSM(0,0,0,1000);
    }
}