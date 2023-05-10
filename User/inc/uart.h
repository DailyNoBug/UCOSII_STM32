//
// Created by 27900 on 2023/1/21.
//

#ifndef STM32_REGISTER_UART_H
#define STM32_REGISTER_UART_H
#pragma once
#include "stm32f401ret6.h"
#include "gpio.h"
#include "string.h"
#include "stdio.h"
#include "ucos_ii.h"
/*
 * UART1: PA9 -> TX
 *        PA10-> RX
 */
void USART_Init(USART_TypeDef *UARTx , uint32_t bound,uint32_t pclk);
void USART_SendChar(USART_TypeDef *USARTx,char c);
void USART_SendStr(USART_TypeDef *USARTx,char *s);
void transGY86Data(void);
#endif //STM32_REGISTER_UART_H
