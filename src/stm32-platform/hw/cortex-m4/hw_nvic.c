#include "common.h"
#include "hw_nvic.h"

enum hw_nvic_irqn_type_e
{
    CORTEX_IRQ_NON_MASKABLE         = -14,    /*!< 2 Cortex-M4 Non Maskable Interrupt                                */
    CORTEX_IRQ_HARD_FAULT           = -13,    /*!< 3 Cortex-M4 Hard Fault Interrupt                                  */
    CORTEX_IRQ_MEMORY_MANAGEMENT    = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
    CORTEX_IRQ_BUS_FAULT            = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
    CORTEX_IRQ_USAGE_FAULT          = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
    CORTEX_IRQ_SVCALL               = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
    CORTEX_IRQ_DEBUG_MONITOR        = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
    CORTEX_IRQ_PENDSV               = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
    CORTEX_IRQ_SYSTICK              = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
    /******  STM32 specific Interrupt Numbers **********************************************************************/
    WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
    PVD_PVM_IRQn                = 1,      /*!< PVD/PVM1/PVM2/PVM3/PVM4 through EXTI Line detection Interrupts    */
    TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
    RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
    FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
    RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
    EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
    EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
    EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                              */
    EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
    EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
    DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                                   */
    DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                                   */
    DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                                   */
    DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                                   */
    DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                                   */
    DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                                   */
    DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                                   */
    ADC1_2_IRQn                 = 18,     /*!< ADC1, ADC2 SAR global Interrupts                                  */
    CAN1_TX_IRQn                = 19,     /*!< CAN1 TX Interrupt                                                 */
    CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0 Interrupt                                                */
    CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                                */
    CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                                */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
    TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 Break interrupt and TIM15 global interrupt                   */
    TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM16 global interrupt                  */
    TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM17 global interrupt */
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
    USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                                           */
    EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
    RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
    DFSDM1_FLT3_IRQn            = 42,     /*!< DFSDM1 Filter 3 global Interrupt                                  */
    TIM8_BRK_IRQn               = 43,     /*!< TIM8 Break Interrupt                                              */
    TIM8_UP_IRQn                = 44,     /*!< TIM8 Update Interrupt                                             */
    TIM8_TRG_COM_IRQn           = 45,     /*!< TIM8 Trigger and Commutation Interrupt                            */
    TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                                    */
    ADC3_IRQn                   = 47,     /*!< ADC3 global  Interrupt                                            */
    FMC_IRQn                    = 48,     /*!< FMC global Interrupt                                              */
    SDMMC1_IRQn                 = 49,     /*!< SDMMC1 global Interrupt                                           */
    TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                             */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
    UART4_IRQn                  = 52,     /*!< UART4 global Interrupt                                            */
    UART5_IRQn                  = 53,     /*!< UART5 global Interrupt                                            */
    TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
    TIM7_IRQn                   = 55,     /*!< TIM7 global interrupt                                             */
    DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                                   */
    DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                                   */
    DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                                   */
    DMA2_Channel4_IRQn          = 59,     /*!< DMA2 Channel 4 global Interrupt                                   */
    DMA2_Channel5_IRQn          = 60,     /*!< DMA2 Channel 5 global Interrupt                                   */
    DFSDM1_FLT0_IRQn            = 61,     /*!< DFSDM1 Filter 0 global Interrupt                                  */
    DFSDM1_FLT1_IRQn            = 62,     /*!< DFSDM1 Filter 1 global Interrupt                                  */
    DFSDM1_FLT2_IRQn            = 63,     /*!< DFSDM1 Filter 2 global Interrupt                                  */
    COMP_IRQn                   = 64,     /*!< COMP1 and COMP2 Interrupts                                        */
    LPTIM1_IRQn                 = 65,     /*!< LP TIM1 interrupt                                                 */
    LPTIM2_IRQn                 = 66,     /*!< LP TIM2 interrupt                                                 */
    OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                       */
    DMA2_Channel6_IRQn          = 68,     /*!< DMA2 Channel 6 global interrupt                                   */
    DMA2_Channel7_IRQn          = 69,     /*!< DMA2 Channel 7 global interrupt                                   */
    LPUART1_IRQn                = 70,     /*!< LP UART1 interrupt                                                */
    QUADSPI_IRQn                = 71,     /*!< Quad SPI global interrupt                                         */
    I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                              */
    I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                              */
    SAI1_IRQn                   = 74,     /*!< Serial Audio Interface 1 global interrupt                         */
    SAI2_IRQn                   = 75,     /*!< Serial Audio Interface 2 global interrupt                         */
    SWPMI1_IRQn                 = 76,     /*!< Serial Wire Interface 1 global interrupt                          */
    TSC_IRQn                    = 77,     /*!< Touch Sense Controller global interrupt                           */
    RNG_IRQn                    = 80,     /*!< RNG global interrupt                                              */
    FPU_IRQn                    = 81      /*!< FPU global interrupt                                              */
};

struct NVIC_Type
{
  __IOM uint32_t ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[24U];
  __IOM uint32_t ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RESERVED1[24U];
  __IOM uint32_t ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[24U];
  __IOM uint32_t ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[24U];
  __IOM uint32_t IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[56U];
  __IOM uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32_t RESERVED5[644U];
  __OM  uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
};

#define NVIC                 ((struct NVIC_Type *) NVIC_BASE)
static inline struct NVIC_Type* __GET_NVIC_REGISTER__(void)
{
    return NVIC;
}

#define __GET_NVIC_ISER__(n)        (__GET_NVIC_REGISTER__()->ISER[n])
#define __GET_NVIC_ICER__(n)        (__GET_NVIC_REGISTER__()->ICER[n])
#define __GET_NVIC_ISPR__(n)        (__GET_NVIC_REGISTER__()->ISPR[n])
#define __GET_NVIC_ICPR__(n)        (__GET_NVIC_REGISTER__()->ICPR[n])
#define __GET_NVIC_IABR__(n)        (__GET_NVIC_REGISTER__()->IABR[n])
#define __GET_NVIC_IP__(n)          (__GET_NVIC_REGISTER__()->IP[n])
#define __GET_NVIC_STIR__           (__GET_NVIC_REGISTER__()->STIR)

struct SCB_Type
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
};

#define SCB                 ((struct SCB_Type *) SCB_BASE)
static inline struct SCB_Type* __GET_SCB_REGISTER__(void)
{
    return SCB;
}

#define __GET_SCB_CPUID__           (__GET_SCB_REGISTER__()->CPUID)
#define __GET_SCB_ICSR__            (__GET_SCB_REGISTER__()->ICSR)
#define __GET_SCB_VTOR__            (__GET_SCB_REGISTER__()->VTOR)
#define __GET_SCB_AIRCR__           (__GET_SCB_REGISTER__()->AIRCR)
#define __GET_SCB_SCR__             (__GET_SCB_REGISTER__()->SCR)
#define __GET_SCB_CCR__             (__GET_SCB_REGISTER__()->CCR)
#define __GET_SCB_SHP__(n)          (__GET_SCB_REGISTER__()->SHP[n])
#define __GET_SCB_SHCSR__           (__GET_SCB_REGISTER__()->SHCSR)
#define __GET_SCB_CFSR__            (__GET_SCB_REGISTER__()->CFSR)
#define __GET_SCB_HFSR__            (__GET_SCB_REGISTER__()->HFSR)
#define __GET_SCB_DFSR__            (__GET_SCB_REGISTER__()->DFSR)
#define __GET_SCB_MMFAR__           (__GET_SCB_REGISTER__()->MMFAR)
#define __GET_SCB_BFAR__            (__GET_SCB_REGISTER__()->BFAR)
#define __GET_SCB_AFSR__            (__GET_SCB_REGISTER__()->AFSR)
#define __GET_SCB_PFR__(n)          (__GET_SCB_REGISTER__()->PFR[n])
#define __GET_SCB_DFR__             (__GET_SCB_REGISTER__()->DFR)
#define __GET_SCB_ADR__             (__GET_SCB_REGISTER__()->ADR)
#define __GET_SCB_MMFR__(n)         (__GET_SCB_REGISTER__()->MMFR[n])
#define __GET_SCB_ISAR__(n)         (__GET_SCB_REGISTER__()->ISAR[n])
#define __GET_SCB_CPACR__           (__GET_SCB_REGISTER__()->CPACR)

#define AIRCR_VECTKEY_MASK           ((uint32_t)0x05FA0000)

#define SCB_AIRCR_PRIGROUP_Pos                      (8U)
#define SCB_AIRCR_PRIGROUP_Msk                      (0x7UL << SCB_AIRCR_PRIGROUP_Pos)   /*!< 0x00000700 */
#define SCB_AIRCR_PRIGROUP                          SCB_AIRCR_PRIGROUP_Msk

#define __NVIC_PRIO_BITS 3
static uint32_t hw_irq_encode_priority(uint32_t group, uint8_t preempt_priority, uint8_t sub_priority)
{
    uint32_t PriorityGroupTmp = (group & (uint32_t)0x07UL);
    uint32_t PreemptPriorityBits;
    uint32_t SubPriorityBits;

    PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(__NVIC_PRIO_BITS)) ? (uint32_t)(__NVIC_PRIO_BITS) : (uint32_t)(7UL - PriorityGroupTmp);
    SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(__NVIC_PRIO_BITS));

    return (
            ((preempt_priority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
            ((sub_priority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
            );
}

static void hw_irq_decode_priority(uint32_t priority, uint32_t group, uint8_t *const preempt_priority, uint8_t *const sub_priority)
{
    uint32_t PriorityGroupTmp = (group & (uint32_t)0x07UL);
    uint32_t PreemptPriorityBits;
    uint32_t SubPriorityBits;

    PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(__NVIC_PRIO_BITS)) ? (uint32_t)(__NVIC_PRIO_BITS) : (uint32_t)(7UL - PriorityGroupTmp);
    SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(__NVIC_PRIO_BITS));

    *preempt_priority = (priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
    *sub_priority     = (priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}

void hw_nvic_enable_irq(int32_t irq)
{
    __BIT_SET__(__GET_NVIC_ISER__(irq >> 5UL), (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL)));
}

void hw_nvic_disable_irq(int32_t irq)
{
    __BIT_SET__(__GET_NVIC_ICER__(irq >> 5UL), (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL)));
}

uint32_t hw_nvic_get_enable_irq(int32_t irq)
{
    return (__GET_NVIC_ISER__(irq >> 5UL) & (1UL << (irq) & 0x1FUL)) != 0UL ? 1UL : 0UL;
}

uint32_t hw_nvic_get_pending_irq(int32_t irq)
{
    return (__GET_NVIC_ISPR__(irq >> 5UL) & (1UL << (irq & 0x1FUL))) != 0UL ? 1UL : 0UL;
}

void hw_nvic_enable_pending_irq(int32_t irq)
{
    __BIT_SET__(__GET_NVIC_ISPR__(irq >> 5UL), 1UL << (irq & 0x1FUL));
}

void hw_nvic_disable_pending_irq(int32_t irq)
{
    __BIT_SET__(__GET_NVIC_ICPR__(irq >> 5UL), 1UL << (irq & 0x1FUL));
}

uint32_t hw_nvic_get_active(int32_t irq)
{
    return (__GET_NVIC_IABR__(irq >> 5UL) & (1UL << (irq & 0x1FUL))) != 0UL ? 1UL : 0UL;
}

void hw_nvic_set_priority(int32_t irq, uint32_t group, uint8_t preempt_priority, uint8_t sub_priority)
{
    uint32_t priority = hw_irq_encode_priority(group, preempt_priority, sub_priority);
    __BIT_SET__(__GET_NVIC_IP__(irq), (priority << (8UL - __NVIC_PRIO_BITS)) & 0xFFUL);
}

uint32_t hw_nvic_get_priority(int32_t irq, uint32_t group, uint8_t *const preempt_priority, uint8_t *const sub_priority)
{
    uint32_t priority = (__GET_NVIC_IP__(irq) >> (8UL - __NVIC_PRIO_BITS));
    hw_irq_decode_priority(priority, group, preempt_priority, sub_priority);
    return 0;
}

void hw_scb_set_priority(int32_t irq, uint32_t group, uint8_t preempt_priority, uint8_t sub_priority)
{
    uint32_t priority = hw_irq_encode_priority(group, preempt_priority, sub_priority);
    __BIT_SET__(__GET_SCB_SHP__((irq & 0xFUL) - 4UL), (priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
}
uint32_t hw_scb_get_priority(int32_t irq, uint32_t group, uint8_t *const preempt_priority, uint8_t *const sub_priority)
{
    uint32_t priority = __GET_SCB_SHP__((irq & 0xFUL) - 4UL) >> (8U - __NVIC_PRIO_BITS);
    hw_irq_decode_priority(priority, group, preempt_priority, sub_priority);
    return 0;
}

void hw_scb_set_priority_group(uint32_t prioritygroup)
{
    __BIT_SET__(__GET_SCB_AIRCR__, (AIRCR_VECTKEY_MASK | (prioritygroup << SCB_AIRCR_PRIGROUP_Pos)));
}

uint32_t hw_scb_get_priority_group(void)
{
    return (__GET_SCB_AIRCR__ & SCB_AIRCR_PRIGROUP) >> SCB_AIRCR_PRIGROUP_Pos;
}

static void hw_irq_set_priority(enum hw_nvic_irq_type_e irq, struct hw_nvic_priority_t* priority)
{
    switch(irq) {
        case hw_nvic_irq_type_systick:
            hw_scb_get_priority(CORTEX_IRQ_SYSTICK, hw_scb_get_priority_group(), &priority->preempt_priority, &priority->sub_priority);
            break;
        default:
            break;
    }
}
enum hw_platform_errcode_e hw_platform_nvic_cmd(uint8_t type, WPARAM wParam, LPARAM lParam)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(type) {
        case HW_NVIC_CMD_SET_ENABLE:
            break;
        case HW_NVIC_CMD_GET_ENABLE:
            break;
        case HW_NVIC_CMD_SET_GROUP:
            hw_scb_set_priority_group(wParam);
            break;
        case HW_NVIC_CMD_GET_GROUP:
            *(enum hw_nvic_priority_group_e *)wParam = hw_scb_get_priority_group();
            break;
        case HW_NVIC_CMD_SET_PRIORITY:
            hw_irq_set_priority(wParam, (struct hw_nvic_priority_t *)lParam);
            break;
        default:
            bRet = hw_platform_errcode_not_support;
            break;
    }
    return bRet;
}

