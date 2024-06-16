#include "hal/hal_systick.h"
#include "stm32/systick.h"

void systick_init(enum systick_time_e time)
{
    hal_systick_select_clock_source();
    hal_systick_exception_enable();
    hal_systick_set_reload(80000);
    hal_systick_set_count_enable();
    hal_systick_set_value(0x00);
}
void systick_deinit(void)
{
    hal_systick_exception_disable();
    hal_systick_set_count_disable();
}
