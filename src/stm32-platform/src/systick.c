#include "hal/hal_systick.h"
#include "stm32/systick.h"

void systick_init(void)
{
    hal_systick_select_clock_source();
    hal_systick_exception_enable();
    hal_systick_set_reload(80000);
    hal_systick_set_count_disable();
    hal_systick_set_value(0x00);
}

