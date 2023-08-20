#ifndef __SETM32_PLATFORM_HAL_IVT_H__
#define __SETM32_PLATFORM_HAL_IVT_H__

#include <stdint.h>
#include "stm32/interrupt_vector_table.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t hal_irq_set_priority_group(enum irq_priority_group_e group);
enum irq_priority_group_e hal_irq_get_priority_group(void);
uint32_t hal_irq_enable(enum irq_vector_type_e irq);
uint32_t hal_irq_get_enable(enum irq_vector_type_e irq);
uint32_t hal_irq_disable(enum irq_vector_type_e irq);
uint32_t hal_irq_get_disable(enum irq_vector_type_e irq);

uint32_t hal_irq_set_priority(enum irq_vector_type_e irq, uint32_t priority);
uint32_t hal_irq_get_priority(enum irq_vector_type_e irq, uint32_t *const priority);

uint32_t hal_irq_encode_priority(enum irq_priority_group_e group, enum irq_preempt_priority_e preempt_priority, enum irq_sub_priority_e sub_priority);
void hal_irq_decode_priority(uint32_t priority, enum irq_priority_group_e group, enum irq_preempt_priority_e *const preempt_priority, enum irq_sub_priority_e *const sub_priority);

#ifdef __cplusplus
}
#endif

#endif