#include <stdio.h>
#include "hw/hw_scb.h"
#include "hw/hw_nvic.h"
#include "hal_interrupt_vector_table.h"

#define __NVIC_PRIO_BITS 3
#define IVT_INVALID_IRQ     (-127)

static int8_t ivt_map[irq_vector_type_max] = {
    [irq_vector_type_systick] = cortex_irq_systick,
};

static int8_t hal_ivt_map(enum irq_vector_type_e irq)
{
    int8_t bRet = IVT_INVALID_IRQ;
    if(irq < irq_vector_type_max) {
        bRet = ivt_map[irq];
    }
    return bRet;
}
uint32_t hal_irq_set_priority_group(enum irq_priority_group_e group)
{
    hw_scb_set_priority_group(group << SCB_AIRCR_PRIGROUP_Pos);
    return stm32_errcode_success;
}

enum irq_priority_group_e hal_irq_get_priority_group(void)
{
    return (hw_scb_get_priority_group() >> SCB_AIRCR_PRIGROUP_Pos);
}

uint32_t hal_irq_enable(enum irq_vector_type_e irq)
{
    int8_t irq_map = hal_ivt_map(irq);
    if(irq == IVT_INVALID_IRQ) {
        return stm32_errcode_param_error;
    }
    if(irq >= 0) {
        hw_nvic_enable_irq(irq_map);
    }
    return stm32_errcode_success;
}

uint32_t hal_irq_get_enable(enum irq_vector_type_e irq)
{
    return stm32_enable;
}

uint32_t hal_irq_disable(enum irq_vector_type_e irq)
{
    return stm32_errcode_success;
}

uint32_t hal_irq_get_disable(enum irq_vector_type_e irq)
{
    return stm32_enable;
}

uint32_t hal_irq_set_priority(enum irq_vector_type_e irq, uint32_t priority)
{
    int8_t irq_map = hal_ivt_map(irq);
    if(irq == IVT_INVALID_IRQ) {
        return stm32_errcode_param_error;
    }
    if(irq >= 0) {
        hw_nvic_set_priority(irq_map, priority);
    } else {
        hw_scb_set_priority(irq_map, priority);
    }
    return stm32_errcode_success;
}

uint32_t hal_irq_get_priority(enum irq_vector_type_e irq, uint32_t *const priority)
{
    int8_t irq_map = hal_ivt_map(irq);
    if(irq == IVT_INVALID_IRQ) {
        return stm32_errcode_param_error;
    }
    if(irq >= 0) {
        *priority = hw_nvic_get_priority(irq_map);
    } else {
        *priority = hw_scb_get_priority(irq_map);
    }
    return stm32_errcode_success;
}

uint32_t hal_irq_encode_priority(enum irq_priority_group_e group, enum irq_preempt_priority_e preempt_priority, enum irq_sub_priority_e sub_priority)
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

void hal_irq_decode_priority(uint32_t priority, enum irq_priority_group_e group, enum irq_preempt_priority_e *const preempt_priority, enum irq_sub_priority_e *const sub_priority)
{
    uint32_t PriorityGroupTmp = (group & (uint32_t)0x07UL);
    uint32_t PreemptPriorityBits;
    uint32_t SubPriorityBits;

    PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(__NVIC_PRIO_BITS)) ? (uint32_t)(__NVIC_PRIO_BITS) : (uint32_t)(7UL - PriorityGroupTmp);
    SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(__NVIC_PRIO_BITS));

    *preempt_priority = (priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
    *sub_priority     = (priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}