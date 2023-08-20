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

uint32_t irq_register_handler(enum irq_vector_type_e irq, irq_vector_handler handler)
{
    if(irq_vector_table[irq] != NULL || handler == NULL || irq >= irq_vector_type_max) {
        return stm32_errcode_param_error;
    }
    irq_vector_table[irq] = handler;
    return stm32_errcode_success;
}

uint32_t irq_unregister_handler(enum irq_vector_type_e irq)
{
    if(irq < irq_vector_type_max) {
        return stm32_errcode_param_error;
    }
    irq_vector_table[irq] = NULL;
    return stm32_errcode_success;
}

uint32_t irq_set_priority_group(enum irq_priority_group_e group)
{
    return hal_irq_set_priority_group(group + 3);
}

enum irq_priority_group_e irq_get_priority_group(void)
{
    return hal_irq_get_priority_group() - 3;
}

uint32_t irq_set_priority(enum irq_vector_type_e irq, enum irq_preempt_priority_e preempt_priority, enum irq_sub_priority_e sub_priority)
{
    uint32_t priority = hal_irq_encode_priority(hal_irq_get_priority_group(), preempt_priority, sub_priority);
    return hal_irq_set_priority(irq, priority);
}

uint32_t irq_get_priority(enum irq_vector_type_e irq, enum irq_preempt_priority_e *const preempt_priority, enum irq_sub_priority_e *const sub_priority)
{
    uint32_t priority = 0x00000000;
    hal_irq_get_priority(irq, &priority);
    hal_irq_decode_priority(priority, hal_irq_get_priority_group(), preempt_priority, sub_priority);
    return stm32_errcode_success;
}

uint32_t irq_enable(enum irq_vector_type_e irq)
{
    return hal_irq_enable(irq);
}

uint32_t irq_get_enable(enum irq_vector_type_e irq)
{
    return irq_get_enable(irq);
}

uint32_t irq_disable(enum irq_vector_type_e irq)
{
    return irq_disable(irq);
}

uint32_t irq_get_disable(enum irq_vector_type_e irq)
{
    return irq_get_disable(irq);
}

void nmi_handler(void)
{

}
void hard_fault_handler(void)
{
    while(1) {

    }
}
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
void pendsv_handler(void)
{
    
}
void systick_handler(void)
{
    exec_irq_handler(irq_vector_type_systick);
}
