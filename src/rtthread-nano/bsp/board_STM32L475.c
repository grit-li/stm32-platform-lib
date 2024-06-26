#include <rtthread.h>
#include "stm32/systick.h"
#include "stm32/interrupt_vector_table.h"
#include "stm32/usart.h"
#include "stm32/gpio.h"

#include "drivers/drv_gpio.h"

static const struct gpio_init_t rx_config = {
    .group = gpio_group_a,
    .port = gpio_port_10,
    .mode = gpio_mode_alternate_push_pull_up,
    .alternate = gpio_alternate_7,
    .speed = gpio_speed_very_high,
    .status = gpio_status_low,
};
static const struct gpio_init_t tx_config = {
    .group = gpio_group_a,
    .port = gpio_port_9,
    .mode = gpio_mode_alternate_push_pull_up,
    .alternate = gpio_alternate_7,
    .speed = gpio_speed_very_high,
    .status = gpio_status_low,
};
static unsigned int g_rt_console_init_flag = 0;

static void irq_systick_handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
}

#if defined(RT_USING_HEAP)
#define RT_HEAP_SIZE 1024 * 10
static uint8_t rt_heap[RT_HEAP_SIZE];
void *rt_heap_begin_get(void)
{
    return rt_heap;
}

void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif

static void rt_hw_console_init(void)
{
    gpio_init(&rx_config);
    gpio_init(&tx_config);
    struct usart_init_t init;
    usart_struct_init(&init, usart_type_1);
    usart_init(&init);
    g_rt_console_init_flag = 1;
}

void rt_hw_console_writedata(const uint8_t* data, uint32_t len)
{
    if(g_rt_console_init_flag) {
        usart_transport_data(usart_type_1, data, len);
    }
}
char rt_hw_console_getchar(void)
{
    if(g_rt_console_init_flag) {
        return usart_receive_buffer(usart_type_1);
    }
    return -1;
}

void rt_hw_board_init(void)
{
    irq_set_priority_group(irq_priority_group_2);
    irq_set_priority(irq_vector_type_systick, irq_preempt_priority_3, irq_sub_priority_3);
    irq_register_handler(irq_vector_type_systick, irq_systick_handler);
    systick_init(systick_time_1ms);

    rt_hw_pin_init();
    
    rt_hw_console_init();

#if defined(RT_USING_HEAP)
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());
#endif
}
