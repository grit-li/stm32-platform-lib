#include "hal/hal_systick.h"
#include "stm32/systick.h"
static uint32_t fac_us = 0;
static uint32_t fac_ms = 0;

void systick_init(void)
{
    hal_systick_select_clock_source();
    hal_systick_exception_disable();

    fac_us = 80000000 / 1000000;
    fac_ms = 80000000 / 1000;

    hal_systick_set_count_disable();
    hal_systick_set_value(0x00);
}

void systick_delay_us(uint32_t us)
{
    hal_systick_set_reload(us * fac_us);
    hal_systick_set_value(0x00);
    hal_systick_set_count_enable();
    while(!hal_systick_counted());
    hal_systick_set_count_disable();
    hal_systick_set_value(0x00);
}

void systick_delay_ms(uint32_t ms)
{
    hal_systick_set_reload(ms * fac_ms);
    hal_systick_set_value(0x00);
    hal_systick_set_count_enable();
    while(!hal_systick_counted());
    hal_systick_set_count_disable();
    hal_systick_set_value(0x00);
}
