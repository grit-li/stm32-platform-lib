#include "hw_nvic.h"
#include "stm32_assert.h"

#define __NVIC_PRIO_BITS 3

void hw_nvic_enable_irq(enum nvic_irqn_type_e irq)
{
    __BIT_SET__(__GET_NVIC_ISER__(irq >> 5UL), (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL)));
}

void hw_nvic_disable_irq(enum nvic_irqn_type_e irq)
{
    __BIT_SET__(__GET_NVIC_ICER__(irq >> 5UL), (uint32_t)(1UL << (((uint32_t)irq) & 0x1FUL)));
}

uint32_t hw_nvic_get_enable_irq(enum nvic_irqn_type_e irq)
{
    return (__GET_NVIC_ISER__(irq >> 5UL) & (1UL << (irq) & 0x1FUL)) != 0UL ? 1UL : 0UL;
}

uint32_t hw_nvic_get_pending_irq(enum nvic_irqn_type_e irq)
{
    return (__GET_NVIC_ISPR__(irq >> 5UL) & (1UL << (irq & 0x1FUL))) != 0UL ? 1UL : 0UL;
}

void hw_nvic_enable_pending_irq(enum nvic_irqn_type_e irq)
{
    __BIT_SET__(__GET_NVIC_ISPR__(irq >> 5UL), 1UL << (irq & 0x1FUL));
}

void hw_nvic_disable_pending_irq(enum nvic_irqn_type_e irq)
{
    __BIT_SET__(__GET_NVIC_ICPR__(irq >> 5UL), 1UL << (irq & 0x1FUL));
}

uint32_t hw_nvic_get_active(enum nvic_irqn_type_e irq)
{
    return (__GET_NVIC_IABR__(irq >> 5UL) & (1UL << (irq & 0x1FUL))) != 0UL ? 1UL : 0UL;
}

void hw_nvic_set_priority(enum nvic_irqn_type_e irq, uint32_t priority)
{
    __BIT_SET__(__GET_NVIC_IP__(irq), (priority << (8UL - __NVIC_PRIO_BITS)) & 0xFFUL);
}

uint32_t hw_nvic_get_priority(enum nvic_irqn_type_e irq)
{
    return (__GET_NVIC_IP__(irq) >> (8UL - __NVIC_PRIO_BITS));
}

