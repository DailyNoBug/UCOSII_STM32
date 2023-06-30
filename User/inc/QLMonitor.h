//
// Created by lsc on 23-6-30.
//

#ifndef UCOS_STM32_QLMONITOR_H
#define UCOS_STM32_QLMONITOR_H
#include "uart.h"
void SetTickNum(int Tick);
int max(int a ,int b);
void StoreSwInfo();
void SendSwInfo();
#endif //UCOS_STM32_QLMONITOR_H
