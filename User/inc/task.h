//
// Created by lsc on 23-5-9.
//

#ifndef UCOS_STM32_TASK_H
#define UCOS_STM32_TASK_H
#include "mpu6050.h"
#include "uart.h"
#include "stdio.h"
#include "pwm.h"
void MPU6050Task(void);
void SerialTask(void);
void PWMTask(void);
#endif //UCOS_STM32_TASK_H
