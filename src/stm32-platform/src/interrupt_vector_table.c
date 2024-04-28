#include <stdio.h>
#include "hal/hal_interrupt_vector_table.h"
#include "stm32/interrupt_vector_table.h"

static irq_vector_handler irq_vector_table[irq_vector_type_max] = {0};

static inline void exec_irq_handler(enum irq_vector_type_e irq)
{
    if(irq_vector_table[irq]) {
        irq_vector_table[irq]();
    }
}

int32_t irq_register_handler(enum irq_vector_type_e irq, irq_vector_handler handler)
{
    if(irq_vector_table[irq] != NULL || handler == NULL || irq >= irq_vector_type_max) {
        return stm32_errcode_param_invaild;
    }
    irq_vector_table[irq] = handler;
    return stm32_errcode_success;
}

int32_t irq_unregister_handler(enum irq_vector_type_e irq)
{
    if(irq < irq_vector_type_max) {
        return stm32_errcode_param_invaild;
    }
    irq_vector_table[irq] = NULL;
    return stm32_errcode_success;
}

int32_t irq_set_priority_group(enum irq_priority_group_e group)
{
    int32_t bRet = stm32_errcode_success;
    switch(group) {
        case irq_priority_group_0: bRet = hal_irq_set_priority_group(hal_irqn_priority_group_0); break;
        case irq_priority_group_1: bRet = hal_irq_set_priority_group(hal_irqn_priority_group_1); break;
        case irq_priority_group_2: bRet = hal_irq_set_priority_group(hal_irqn_priority_group_2); break;
        case irq_priority_group_3: bRet = hal_irq_set_priority_group(hal_irqn_priority_group_3); break;
        case irq_priority_group_4: bRet = hal_irq_set_priority_group(hal_irqn_priority_group_4); break;
        default: break;
    }
    return bRet;
}

enum irq_priority_group_e irq_get_priority_group(void)
{
    enum hal_irqn_priority_group_e group = hal_irq_get_priority_group();
    enum irq_priority_group_e bRet = irq_priority_group_null;
    switch(group) {
        case hal_irqn_priority_group_0: bRet = hal_irqn_priority_group_0; break;
        case hal_irqn_priority_group_1: bRet = hal_irqn_priority_group_1; break;
        case hal_irqn_priority_group_2: bRet = hal_irqn_priority_group_2; break;
        case hal_irqn_priority_group_3: bRet = hal_irqn_priority_group_3; break;
        case hal_irqn_priority_group_4: bRet = hal_irqn_priority_group_4; break;
        default: break;
    }
    return bRet;
}

int32_t irq_set_priority(enum irq_vector_type_e irq, enum irq_preempt_priority_e preempt_priority, enum irq_sub_priority_e sub_priority)
{
    int32_t bRet = stm32_errcode_success;
    switch(irq) {
        case irq_vector_type_systick: bRet = hal_irq_set_priority(hal_irqn_type_systick, preempt_priority, sub_priority); break;
        case irq_vector_type_can1_rx0: bRet = hal_irq_set_priority(hal_irqn_type_can1_rx0, preempt_priority, sub_priority); break;
        default: bRet = stm32_errcode_fail; break;
    }
    return bRet;
}

int32_t irq_get_priority(enum irq_vector_type_e irq, enum irq_preempt_priority_e *const preempt_priority, enum irq_sub_priority_e *const sub_priority)
{
    int32_t bRet = stm32_errcode_success;
    switch(irq) {
        case irq_vector_type_systick: bRet = hal_irq_get_priority(hal_irqn_type_systick, preempt_priority, sub_priority); break;
        case irq_vector_type_can1_rx0: bRet = hal_irq_get_priority(hal_irqn_type_can1_rx0, preempt_priority, sub_priority); break;
        default: bRet = stm32_errcode_fail; break;
    }
    return bRet;
}

int32_t irq_enable(enum irq_vector_type_e irq)
{
    int32_t bRet = stm32_errcode_success;
    switch(irq) {
        case irq_vector_type_systick: bRet = hal_irq_enable(hal_irqn_type_systick); break;
        case irq_vector_type_can1_rx0: bRet = hal_irq_enable(hal_irqn_type_can1_rx0); break;
        default: bRet = stm32_errcode_fail; break;
    }
    return bRet;
}

int32_t irq_get_enable(enum irq_vector_type_e irq)
{
    int32_t bRet = stm32_false;
    switch(irq) {
        case irq_vector_type_systick: bRet = hal_irq_get_enable(hal_irqn_type_systick); break;
        case irq_vector_type_can1_rx0: bRet = hal_irq_get_enable(hal_irqn_type_can1_rx0); break;
        default: break;
    }
    return bRet;
}

int32_t irq_disable(enum irq_vector_type_e irq)
{
    int32_t bRet = stm32_errcode_success;
    switch(irq) {
        case irq_vector_type_systick: bRet = hal_irq_disable(hal_irqn_type_systick); break;
        case irq_vector_type_can1_rx0: bRet = hal_irq_disable(hal_irqn_type_can1_rx0); break;
        default: bRet = stm32_errcode_fail; break;
    }
    return bRet;
}

int32_t irq_get_disable(enum irq_vector_type_e irq)
{
    int32_t bRet = stm32_false;
    switch(irq) {
        case irq_vector_type_systick: bRet = hal_irq_get_disable(hal_irqn_type_systick); break;
        case irq_vector_type_can1_rx0: bRet = hal_irq_get_disable(hal_irqn_type_can1_rx0); break;
        default: break;
    }
    return bRet;
}

void nmi_handler(void)
{

}
// void hard_fault_handler(void)
// {
//     while(1) {

//     }
// }
void mem_manage_handler(void)
{
    while(1) {
    
    }
}
void bus_fault_handler(void)
{
    while(1) {
        
    }    
}
void usage_fault_handler(void)
{
    while(1) {
        
    }    
}
void svcall_handler(void)
{
    
}
void debug_monitor_handler(void)
{
    
}
void systick_handler(void)
{
    exec_irq_handler(irq_vector_type_systick);
}

void can1_rx0_handler(void)
{
    exec_irq_handler(irq_vector_type_can1_rx0);
}