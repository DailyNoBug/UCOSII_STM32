//
// Created by lsc on 23-5-11.
//
#include "NVIC.h"
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
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
    if ((int32_t)(IRQn) >= 0)
    {
        NVIC->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    }
}