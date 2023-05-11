//
//  Created by LSC on 2023/1/20.
//  code with utf-8
//  寄存器定义文件
#ifndef STM32_REGISTER_STM32F401RET6_H
#define STM32_REGISTER_STM32F401RET6_H

#define __IO volatile
#ifndef uint32_t
#include "stdint.h"
//typedef unsigned int    uint32_t;
//typedef unsigned short  uint16_t;
//typedef unsigned char   uint8_t;
#endif
#define MaxRound 1000
#define PLL_M 8
#define PLL_N 84
#define PLL_P 2
/*
 * 基地址定义部分
 */
#define RCC_BASE    0x40023800
#define GPIOA_BASE  0x40020000
#define GPIOB_BASE  0x40020400
#define GPIOC_BASE  0x40020800
#define GPIOD_BASE  0x40020C00
#define GPIOE_BASE  0x40021000

#define USART1_BASE 0x40011000
#define USART2_BASE 0x40004400
#define USART6_BASE 0x40011400

#define I2C1_BASE   0x40005400
#define I2C2_BASE   0x40005800
#define I2C3_BASE   0x40005C00

#define TIM1_BASE   0x40010000
#define TIM2_BASE   0x40000000
#define TIM3_BASE   0x40000400
#define TIM4_BASE   0x40000800
#define TIM5_BASE   0x40000C00

#define EXTI_BASE   0x40013C00
#define NVIC_BASE   0xe000e000
#define NVIC_ISER1  *(uint32_t *)(NVIC_BASE+0x100)
/*
 * RCC时钟部分寄存器定义
 */
typedef struct {
    __IO uint32_t CR;
    __IO uint32_t PLLCFGR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t AHB1RSTR;
    __IO uint32_t AHB2RSTR;
    __IO uint32_t RES1;
    __IO uint32_t RES2;
    __IO uint32_t APB1RSTR;
    __IO uint32_t APB2RSTR;
    __IO uint32_t RES3;
    __IO uint32_t RES4;
    __IO uint32_t AHB1ENR;
    __IO uint32_t AHB2ENR;
    __IO uint32_t RES5;
    __IO uint32_t RES6;
    __IO uint32_t APB1ENR;
    __IO uint32_t APB2ENR;
    __IO uint32_t RES7;
    __IO uint32_t RES8;
    __IO uint32_t AHB1LPENR;
    __IO uint32_t AHB2LPENR;
    __IO uint32_t RES9;
    __IO uint32_t RES10;
    __IO uint32_t APB1LPENR;
    __IO uint32_t APB2LPENR;
    __IO uint32_t RES11;
    __IO uint32_t RES12;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
    __IO uint32_t RES13;
    __IO uint32_t RES14;
    __IO uint32_t SSCGR;
    __IO uint32_t PLLI2SCFGR;
    __IO uint32_t RES15;
    __IO uint32_t DCKCFGR;
} RCC_TypeDef;
/*
 * GPIO部分的寄存器定义
 */
typedef struct {
    __IO uint32_t MODER;
    __IO uint32_t OTYPER;
    __IO uint32_t OSPEEDR;
    __IO uint32_t PUPDR;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint16_t BSRRL;
    __IO uint16_t BSRRH;
    __IO uint32_t LCKR;
    __IO uint32_t AFRL;
    __IO uint32_t AFRH;
}GPIO_TypeDef;
/*
 * 定义引脚模式的枚举定义
 */
typedef enum {
    GPIO_Mode_In    = 0x00,
    GPIO_Mode_Out   = 0x01,
    GPIO_Mode_AF    = 0x02,
    GPIO_Mode_AN    = 0x03
}GPIOMode_TypeDef;              //枚举引脚模式
typedef enum {
    GPIO_OType_PP   = 0x00,
    GPIO_OType_OD   = 0x01
}GPIOOType_TypeDef;             //枚举输出模式
typedef enum {
    GPIO_Speed_2MHz = 0x00,
    GPIO_Speed_25MHz= 0x01,
    GPIO_Speed_50MHz= 0x02,
    GPIO_Speed_100MHz=0x03
}GPIOSpeed_TypeDef;             //枚举GPIO速率
typedef enum {
    GPIO_Pupd_NOPULL    = 0x00,
    GPIO_Pupd_UP        = 0x01,
    GPIO_Pupd_DOWN      = 0x02
}GPIOPupd_TypeDef;              //枚举GPIO上拉下拉
/*
 * 初始化GPIO所需要的信息
 */
typedef struct {
    uint32_t            GPIO_Pin;       //需要配置的GPIO引脚
    GPIOMode_TypeDef    GPIO_Mode;      //GPIO引脚的工作模式
    GPIOSpeed_TypeDef   GPIO_Speed;     //GPIO引脚的工作速率
    GPIOOType_TypeDef   GPIO_OType;     //GPIO引脚的输出类型
    GPIOPupd_TypeDef    GPIO_Pupd;      //选择GPIO引脚的上拉/下拉模式
}GPIO_InitTypeDef;
/*
 * 初始化iic所需要的寄存器
 */
typedef struct {
    __IO uint32_t CR1;
    __IO uint32_t CR2;
    __IO uint32_t OAR1;
    __IO uint32_t OAR2;
    __IO uint32_t DR;
    __IO uint32_t SR1;
    __IO uint32_t SR2;
    __IO uint32_t CCR;
    __IO uint32_t TRISE;
    __IO uint32_t FLTR;
}I2C_TypeDef;

typedef struct {
    __IO uint32_t    SR;
    __IO uint32_t    DR;
    __IO uint32_t    BRR;
    __IO uint32_t    CR1;
    __IO uint32_t    CR2;
    __IO uint32_t    CR3;
    __IO uint32_t    GTPR;
}USART_TypeDef;
/**
 * TIM2 - TIM5 寄存器定义
 */
typedef struct {
    __IO uint32_t CR1;
    __IO uint32_t CR2;
    __IO uint32_t SMCR;
    __IO uint32_t DIER;
    __IO uint32_t SR;
    __IO uint32_t EGR;
    __IO uint32_t CCMR1;
    __IO uint32_t CCMR2;
    __IO uint32_t CCER;
    __IO uint32_t CNT;
    __IO uint32_t PSC;
    __IO uint32_t ARR;
    __IO uint32_t RES1;
    __IO uint32_t CCR1;
    __IO uint32_t CCR2;
    __IO uint32_t CCR3;
    __IO uint32_t CCR4;
    __IO uint32_t RES2;
    __IO uint32_t DCR;
    __IO uint32_t DMAR;
    __IO uint32_t TIM2_OR;
    __IO uint32_t TIM5_OR;
}TIM_TypeDef;
/**
 * EXIT 寄存器定义
 */
 typedef struct {
     __IO uint32_t IMR;
     __IO uint32_t EMR;
     __IO uint32_t RTSR;
     __IO uint32_t FTSR;
     __IO uint32_t SWIER;
     __IO uint32_t PR;
 }EXTI_TypeDef;

#define GPIO_Pin_0  ((uint16_t) 0x0001)
#define GPIO_Pin_1  ((uint16_t) 0x0002)
#define GPIO_Pin_2  ((uint16_t) 0x0004)
#define GPIO_Pin_3  ((uint16_t) 0x0008)
#define GPIO_Pin_4  ((uint16_t) 0x0010)
#define GPIO_Pin_5  ((uint16_t) 0x0020)
#define GPIO_Pin_6  ((uint16_t) 0x0040)
#define GPIO_Pin_7  ((uint16_t) 0x0080)
#define GPIO_Pin_8  ((uint16_t) 0x0100)
#define GPIO_Pin_9 ((uint16_t) 0x0200)
#define GPIO_Pin_10 ((uint16_t) 0x0400)
#define GPIO_Pin_11 ((uint16_t) 0x0800)
#define GPIO_Pin_12 ((uint16_t) 0x1000)
#define GPIO_Pin_13 ((uint16_t) 0x2000)
#define GPIO_Pin_14 ((uint16_t) 0x4000)
#define GPIO_Pin_15 ((uint16_t) 0x8000)
#define GPIO_Pin_all ((uint16_t)    0xFFFF)
//base point part
#define RCC     ((RCC_TypeDef *)    RCC_BASE)
#define GPIOA   ((GPIO_TypeDef *)   GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *)   GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *)   GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef *)   GPIOD_BASE)
#define GPIOE   ((GPIO_TypeDef *)   GPIOE_BASE)
#define USART1  ((USART_TypeDef *)  USART1_BASE)
#define USART6  ((USART_TypeDef *)  USART6_BASE)

#define I2C1    ((I2C_TypeDef *)    I2C1_BASE)
#define I2C2    ((I2C_TypeDef *)    I2C2_BASE)
#define I2C3    ((I2C_TypeDef *)    I2C3_BASE)

#define TIM1    ((TIM_TypeDef *)    TIM1_BASE)
#define TIM2    ((TIM_TypeDef *)    TIM2_BASE)
#define TIM3    ((TIM_TypeDef *)    TIM3_BASE)
#define TIM4    ((TIM_TypeDef *)    TIM4_BASE)
#define TIM5    ((TIM_TypeDef *)    TIM5_BASE)
#define EXTI    ((EXTI_TypeDef*)    EXTI_BASE)

#define __IOM volatile       /*!< Defines 'read / write' permissions */
#define __IM  volatile const /*!< Defines 'read-only' permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */

typedef struct
{
    __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
    __IOM uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
    __IOM uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
    __IM  uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;

/* SysTick Control / Status Register Definitions */
#define SysTick_CTRL_COUNTFLAG_Pos         16U                                            /*!< SysTick CTRL: COUNTFLAG Position */
#define SysTick_CTRL_COUNTFLAG_Msk         (1UL << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG Mask */

#define SysTick_CTRL_CLKSOURCE_Pos          2U                                            /*!< SysTick CTRL: CLKSOURCE Position */
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE Mask */

#define SysTick_CTRL_TICKINT_Pos            1U                                            /*!< SysTick CTRL: TICKINT Position */
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */

#define SysTick_CTRL_ENABLE_Pos             0U                                            /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL /*<< SysTick_CTRL_ENABLE_Pos*/)           /*!< SysTick CTRL: ENABLE Mask */

/* SysTick Reload Register Definitions */
#define SysTick_LOAD_RELOAD_Pos             0U                                            /*!< SysTick LOAD: RELOAD Position */
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFUL /*<< SysTick_LOAD_RELOAD_Pos*/)    /*!< SysTick LOAD: RELOAD Mask */

/* SysTick Current Register Definitions */
#define SysTick_VAL_CURRENT_Pos             0U                                            /*!< SysTick VAL: CURRENT Position */
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFUL /*<< SysTick_VAL_CURRENT_Pos*/)    /*!< SysTick VAL: CURRENT Mask */

/* SysTick Calibration Register Definitions */
#define SysTick_CALIB_NOREF_Pos            31U                                            /*!< SysTick CALIB: NOREF Position */
#define SysTick_CALIB_NOREF_Msk            (1UL << SysTick_CALIB_NOREF_Pos)               /*!< SysTick CALIB: NOREF Mask */

#define SysTick_CALIB_SKEW_Pos             30U                                            /*!< SysTick CALIB: SKEW Position */
#define SysTick_CALIB_SKEW_Msk             (1UL << SysTick_CALIB_SKEW_Pos)                /*!< SysTick CALIB: SKEW Mask */

#define SysTick_CALIB_TENMS_Pos             0U                                            /*!< SysTick CALIB: TENMS Position */
#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFUL /*<< SysTick_CALIB_TENMS_Pos*/)    /*!< SysTick CALIB: TENMS Mask */

/*@} end of group CMSIS_SysTick */

#define SCS_BASE            (0xE000E000UL)
#define SysTick_BASE        (SCS_BASE +  0x0010UL)
#define SCB_BASE            (SCS_BASE +  0x0D00UL)
#define SysTick             ((SysTick_Type   *)     SysTick_BASE  )

typedef struct
{
    __IOM uint32_t ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
    uint32_t RESERVED0[24U];
    __IOM uint32_t ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
    uint32_t RSERVED1[24U];
    __IOM uint32_t ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
    uint32_t RESERVED2[24U];
    __IOM uint32_t ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
    uint32_t RESERVED3[24U];
    __IOM uint32_t IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
    uint32_t RESERVED4[56U];
    __IOM uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
    uint32_t RESERVED5[644U];
    __OM  uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;

/* Software Triggered Interrupt Register Definitions */
#define NVIC_STIR_INTID_Pos                 0U                                         /*!< STIR: INTLINESNUM Position */
#define NVIC_STIR_INTID_Msk                (0x1FFUL /*<< NVIC_STIR_INTID_Pos*/)        /*!< STIR: INTLINESNUM Mask */

#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   /*!< NVIC configuration struct */

typedef struct
{
    uint32_t RESERVED0[1U];
    __IM  uint32_t ICTR;                   /*!< Offset: 0x004 (R/ )  Interrupt Controller Type Register */
    __IOM uint32_t ACTLR;                  /*!< Offset: 0x008 (R/W)  Auxiliary Control Register */
} SCnSCB_Type;

typedef struct
{
    __IM  uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
    __IOM uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
    __IOM uint32_t VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
    __IOM uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
    __IOM uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
    __IOM uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
    __IOM uint8_t  SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
    __IOM uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
    __IOM uint32_t CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
    __IOM uint32_t HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
    __IOM uint32_t DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
    __IOM uint32_t MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
    __IOM uint32_t BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
    __IOM uint32_t AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
    __IM  uint32_t PFR[2U];                /*!< Offset: 0x040 (R/ )  Processor Feature Register */
    __IM  uint32_t DFR;                    /*!< Offset: 0x048 (R/ )  Debug Feature Register */
    __IM  uint32_t ADR;                    /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
    __IM  uint32_t MMFR[4U];               /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
    __IM  uint32_t ISAR[5U];               /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
    uint32_t RESERVED0[5U];
    __IOM uint32_t CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
} SCB_Type;

/* Interrupt Controller Type Register Definitions */
#define SCnSCB_ICTR_INTLINESNUM_Pos         0U                                         /*!< ICTR: INTLINESNUM Position */
#define SCnSCB_ICTR_INTLINESNUM_Msk        (0xFUL /*<< SCnSCB_ICTR_INTLINESNUM_Pos*/)  /*!< ICTR: INTLINESNUM Mask */

/* Auxiliary Control Register Definitions */
#define SCnSCB_ACTLR_DISOOFP_Pos            9U                                         /*!< ACTLR: DISOOFP Position */
#define SCnSCB_ACTLR_DISOOFP_Msk           (1UL << SCnSCB_ACTLR_DISOOFP_Pos)           /*!< ACTLR: DISOOFP Mask */

#define SCnSCB_ACTLR_DISFPCA_Pos            8U                                         /*!< ACTLR: DISFPCA Position */
#define SCnSCB_ACTLR_DISFPCA_Msk           (1UL << SCnSCB_ACTLR_DISFPCA_Pos)           /*!< ACTLR: DISFPCA Mask */

#define SCnSCB_ACTLR_DISFOLD_Pos            2U                                         /*!< ACTLR: DISFOLD Position */
#define SCnSCB_ACTLR_DISFOLD_Msk           (1UL << SCnSCB_ACTLR_DISFOLD_Pos)           /*!< ACTLR: DISFOLD Mask */

#define SCnSCB_ACTLR_DISDEFWBUF_Pos         1U                                         /*!< ACTLR: DISDEFWBUF Position */
#define SCnSCB_ACTLR_DISDEFWBUF_Msk        (1UL << SCnSCB_ACTLR_DISDEFWBUF_Pos)        /*!< ACTLR: DISDEFWBUF Mask */

#define SCnSCB_ACTLR_DISMCYCINT_Pos         0U                                         /*!< ACTLR: DISMCYCINT Position */
#define SCnSCB_ACTLR_DISMCYCINT_Msk        (1UL /*<< SCnSCB_ACTLR_DISMCYCINT_Pos*/)    /*!< ACTLR: DISMCYCINT Mask */
#define SCB  ((SCB_Type *) SCB_BASE)
#define __NVIC_PRIO_BITS          3U
typedef enum
{
/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
    NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
    MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
    BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
    UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
    SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
    DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
    PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
    SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
    WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
    PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
    TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
    RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
    FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
    RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
    EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
    EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
    EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
    EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
    EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
    DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
    DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
    DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
    DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
    DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
    DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
    DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
    ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
    TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
    TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
    TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
    TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
    TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
    TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
    TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
    I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                              */
    I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
    I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                              */
    I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
    SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
    SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
    USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                           */
    USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                           */
    EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
    RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
    DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                            */
    SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                             */
    TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
    DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
    DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
    DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
    DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
    DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
    OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
    DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
    DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
    DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
    USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                           */
    I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
    I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
    FPU_IRQn                    = 81,     /*!< FPU global interrupt                                              */
    SPI4_IRQn                   = 84      /*!< SPI4 global Interrupt                                              */
} IRQn_Type;

#endif //STM32_REGISTER_STM32F401RET6_H