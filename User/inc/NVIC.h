//
// Created by lsc on 23-5-11.
//

#ifndef UCOS_STM32_NVIC_H
#define UCOS_STM32_NVIC_H
#include "stm32f401ret6.h"
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);
void NVIC_EnableIRQ(IRQn_Type IRQn);
#endif //UCOS_STM32_NVIC_H
