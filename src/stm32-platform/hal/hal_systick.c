#include <stdio.h>
#include "hw/hw_systick.h"
#include "hal_systick.h"

void hal_systick_select_clock_source(void)
{
    hw_systick_select_clock_source(SysTick_CTRL_CLKSOURCE);
}

void hal_systick_exception_enable(void)
{
    hw_systick_exception_request_enable();
}

void hal_systick_exception_disable(void)
{
    hw_systick_exception_request_disable();
}

void hal_systick_set_reload(uint32_t value)
{
    hw_systick_set_reload_value(value);
}

void hal_systick_set_value(uint32_t value)
{
    hw_systick_set_current_value(value);
}

void hal_systick_set_count_enable(void)
{
    hw_systick_counter_enable();
}

void hal_systick_set_count_disable(void)
{
    hw_systick_counter_enable();
}

uint32_t hal_systick_counted(void)
{
    return hw_systick_get_count_flag();
}