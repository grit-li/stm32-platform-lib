#ifndef __SETM32_PLATFORM_HAL_IVT_H__
#define __SETM32_PLATFORM_HAL_IVT_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum hal_irqn_type_e
{
    hal_irqn_type_systick,
    hal_irqn_type_can1_rx0,
};

enum hal_irqn_priority_group_e
{
    hal_irqn_priority_group_0,
    hal_irqn_priority_group_1,
    hal_irqn_priority_group_2,
    hal_irqn_priority_group_3,
    hal_irqn_priority_group_4,
};
void hal_irq_set_vector_table(uint32_t, uint32_t);
int32_t hal_irq_set_priority_group(enum hal_irqn_priority_group_e);
enum hal_irqn_priority_group_e hal_irq_get_priority_group(void);
int32_t hal_irq_enable(enum hal_irqn_type_e);
int32_t hal_irq_get_enable(enum hal_irqn_type_e);
int32_t hal_irq_disable(enum hal_irqn_type_e);
int32_t hal_irq_get_disable(enum hal_irqn_type_e);
int32_t hal_irq_set_priority(enum hal_irqn_type_e, uint8_t preempt_priority, uint8_t sub_priority);
int32_t hal_irq_get_priority(enum hal_irqn_type_e, uint8_t *const preempt_priority, uint8_t *const sub_priority);

#ifdef __cplusplus
}
#endif

#endif
