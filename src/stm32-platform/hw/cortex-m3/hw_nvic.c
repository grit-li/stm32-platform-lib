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
    USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */

};

struct NVIC_Type
{
     __IO uint32_t ISER[8];                      /*!< Interrupt Set Enable Register            */
          uint32_t RESERVED0[24];
     __IO uint32_t ICER[8];                      /*!< Interrupt Clear Enable Register          */
          uint32_t RSERVED1[24];
     __IO uint32_t ISPR[8];                      /*!< Interrupt Set Pending Register           */
          uint32_t RESERVED2[24];
     __IO uint32_t ICPR[8];                      /*!< Interrupt Clear Pending Register         */
          uint32_t RESERVED3[24];
     __IO uint32_t IABR[8];                      /*!< Interrupt Active bit Register            */
          uint32_t RESERVED4[56];
     __IO uint8_t  IP[240];                      /*!< Interrupt Priority Register, 8Bit wide   */
          uint32_t RESERVED5[644];
     __O  uint32_t STIR;                         /*!< Software Trigger Interrupt Register      */
};

#define NVIC                ((struct NVIC_Type *)          NVIC_BASE)        /*!< NVIC configuration struct            */

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
    __I  uint32_t CPUID;                        /*!< CPU ID Base Register                                     */
    __IO uint32_t ICSR;                         /*!< Interrupt Control State Register                         */
    __IO uint32_t VTOR;                         /*!< Vector Table Offset Register                             */
    __IO uint32_t AIRCR;                        /*!< Application Interrupt / Reset Control Register           */
    __IO uint32_t SCR;                          /*!< System Control Register                                  */
    __IO uint32_t CCR;                          /*!< Configuration Control Register                           */
    __IO uint8_t  SHP[12];                      /*!< System Handlers Priority Registers (4-7, 8-11, 12-15)    */
    __IO uint32_t SHCSR;                        /*!< System Handler Control and State Register                */
    __IO uint32_t CFSR;                         /*!< Configurable Fault Status Register                       */
    __IO uint32_t HFSR;                         /*!< Hard Fault Status Register                               */
    __IO uint32_t DFSR;                         /*!< Debug Fault Status Register                              */
    __IO uint32_t MMFAR;                        /*!< Mem Manage Address Register                              */
    __IO uint32_t BFAR;                         /*!< Bus Fault Address Register                               */
    __IO uint32_t AFSR;                         /*!< Auxiliary Fault Status Register                          */
    __I  uint32_t PFR[2];                       /*!< Processor Feature Register                               */
    __I  uint32_t DFR;                          /*!< Debug Feature Register                                   */
    __I  uint32_t ADR;                          /*!< Auxiliary Feature Register                               */
    __I  uint32_t MMFR[4];                      /*!< Memory Model Feature Register                            */
    __I  uint32_t ISAR[5];                      /*!< ISA Feature Register                                     */
};

#define SCB                 ((struct SCB_Type *)           SCB_BASE)         /*!< SCB configuration struct             */

static inline struct SCB_Type* __GET_SCB_REGISTER__(void)
{
    return SCB;
}

#define __GET_SCB_CPUID__           (__GET_SCB_REGISTER__()->CPUID  )
#define __GET_SCB_ICSR__            (__GET_SCB_REGISTER__()->ICSR   )
#define __GET_SCB_VTOR__            (__GET_SCB_REGISTER__()->VTOR   )
#define __GET_SCB_AIRCR__           (__GET_SCB_REGISTER__()->AIRCR  )
#define __GET_SCB_SCR__             (__GET_SCB_REGISTER__()->SCR    )
#define __GET_SCB_CCR__             (__GET_SCB_REGISTER__()->CCR    )
#define __GET_SCB_SHP__(n)          (__GET_SCB_REGISTER__()->SHP[n] )
#define __GET_SCB_SHCSR__           (__GET_SCB_REGISTER__()->SHCSR  )
#define __GET_SCB_CFSR__            (__GET_SCB_REGISTER__()->CFSR   )
#define __GET_SCB_HFSR__            (__GET_SCB_REGISTER__()->HFSR   )
#define __GET_SCB_DFSR__            (__GET_SCB_REGISTER__()->DFSR   )
#define __GET_SCB_MMFAR__           (__GET_SCB_REGISTER__()->MMFAR  )
#define __GET_SCB_BFAR__            (__GET_SCB_REGISTER__()->BFAR   )
#define __GET_SCB_AFSR__            (__GET_SCB_REGISTER__()->AFSR   )
#define __GET_SCB_PFR__(n)          (__GET_SCB_REGISTER__()->PFR[n] )
#define __GET_SCB_DFR__             (__GET_SCB_REGISTER__()->DFR    )
#define __GET_SCB_ADR__             (__GET_SCB_REGISTER__()->ADR    )
#define __GET_SCB_MMFR__(n)         (__GET_SCB_REGISTER__()->MMFR[n])
#define __GET_SCB_ISAR__(n)         (__GET_SCB_REGISTER__()->ISAR[n])

#define AIRCR_VECTKEY_MASK           ((uint32_t)0x05FA0000)

#define SCB_AIRCR_PRIGROUP_Pos                      (8U)
#define SCB_AIRCR_PRIGROUP_Msk                      (0x7UL << SCB_AIRCR_PRIGROUP_Pos)   /*!< 0x00000700 */
#define SCB_AIRCR_PRIGROUP                          SCB_AIRCR_PRIGROUP_Msk
#define SCB_VTOR_TBLOFF                             ((uint32_t)0x1FFFFF80)

#define __NVIC_PRIO_BITS 4
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

void hw_scb_set_vector_table(uint32_t vectTab, uint32_t offset)
{
    __BIT_SET__(__GET_SCB_VTOR__, vectTab | (offset  & SCB_VTOR_TBLOFF));
}

static void hw_irq_set_priority(enum hw_nvic_irq_type_e irq, struct hw_nvic_priority_t* priority)
{
    switch(irq) {
        case hw_nvic_irq_type_systick:
            hw_scb_set_priority(CORTEX_IRQ_SYSTICK, hw_scb_get_priority_group(), priority->preempt_priority, priority->sub_priority);
            break;
        case hw_nvic_irq_type_can1_rx0:
            hw_nvic_set_priority(USB_LP_CAN1_RX0_IRQn, hw_scb_get_priority_group(), priority->preempt_priority, priority->sub_priority);
            break;
        default:
            break;
    }
}

static void hw_nvic_set_irq_enable(uint32_t irq)
{
    __BIT_SET__(__GET_NVIC_ISER__(irq >> 5), (1 << (irq & 0x1F)));
}
static void hw_irq_set_enable(enum hw_nvic_irq_type_e irq)
{
    switch(irq) {
        case hw_nvic_irq_type_can1_rx0:
            hw_nvic_set_irq_enable(USB_LP_CAN1_RX0_IRQn);
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
            hw_irq_set_enable(wParam);
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
        case HW_NVIC_CMD_SET_VECTOR_TABLE:
            hw_scb_set_vector_table(wParam, lParam);
            break;
        default:
            bRet = hw_platform_errcode_not_support;
            break;
    }
    return bRet;
}

