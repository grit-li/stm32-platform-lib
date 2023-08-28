#include <rtthread.h>
#include "stm32/systick.h"
#include "stm32/interrupt_vector_table.h"

static void irq_systick_handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
}

#if defined(RT_USING_HEAP)
#define RT_HEAP_SIZE 1024 * 4
static uint8_t rt_heap[RT_HEAP_SIZE];  // heap default size: 4K(1024 * 4)
RT_WEAK void *rt_heap_begin_get(void)
{
    return rt_heap;
}

RT_WEAK void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif

void rt_hw_board_init(void)
{
    irq_set_priority_group(irq_priority_group_2);
    irq_set_priority(irq_vector_type_systick, irq_preempt_priority_3, irq_sub_priority_3);
    irq_register_handler(irq_vector_type_systick, irq_systick_handler);
    systick_init();

#if defined(RT_USING_HEAP)
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());
#endif
}
