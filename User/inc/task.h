//
// Created by lsc on 23-5-9.
//

#ifndef UCOS_STM32_TASK_H
#define UCOS_STM32_TASK_H
#include "mpu6050.h"
#include "uart.h"
#include "stdio.h"
#include "pwm.h"
extern float Ax,Ay,Az,Gx,Gy,Gz,temp;
extern uint16_t data[9];
void delay_init(void);
void TIME_INIT(void);
void IMU_TASK(void);
void ULOG_TASK(void);
void MOTOR_TASK(void);
#endif //UCOS_STM32_TASK_H
