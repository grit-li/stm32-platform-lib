#include "hw_systick.h"
#include "stm32_assert.h"

uint32_t hw_systick_get_count_flag(void)
{
    return (__GET_SYSTICK_CTRL__ & SysTick_CTRL_COUNTFLAG);
}

void hw_systick_select_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_SYSTICK_CTRL__, SysTick_CTRL_CLKSOURCE, source);
}

void hw_systick_exception_request_enable(void)
{
    __BIT_OR__(__GET_SYSTICK_CTRL__, SysTick_CTRL_TICKINT);
}

void hw_systick_exception_request_disable(void)
{
    __BIT_RESET__(__GET_SYSTICK_CTRL__, SysTick_CTRL_TICKINT);
}

uint32_t hw_systick_get_exception_request_enable(void)
{
    return (__GET_SYSTICK_CTRL__ & SysTick_CTRL_TICKINT);
}

void hw_systick_counter_enable(void)
{
    __BIT_OR__(__GET_SYSTICK_CTRL__, SysTick_CTRL_ENABLE);
}

void hw_systick_counter_disable(void)
{
    __BIT_RESET__(__GET_SYSTICK_CTRL__, SysTick_CTRL_ENABLE);
}

uint32_t hw_systick_get_counter_enable(void)
{
    return (__GET_SYSTICK_CTRL__ & SysTick_CTRL_ENABLE);
}

void hw_systick_set_reload_value(uint32_t value)
{
    __BIT_COVER_SET__(__GET_SYSTICK_LOAD__, SysTick_LOAD_RELOAD, value);
}

uint32_t hw_systick_get_reload_value(void)
{
    return (__GET_SYSTICK_LOAD__ & SysTick_LOAD_RELOAD);
}

void hw_systick_set_current_value(uint32_t value)
{
    __BIT_COVER_SET__(__GET_SYSTICK_VAL__, SysTick_VAL_CURRENT, value);
}

uint32_t hw_systick_get_current_value(void)
{
    return (__GET_SYSTICK_VAL__ & SysTick_VAL_CURRENT);
}

uint32_t hw_systick_get_noref_flag(void)
{
    return (__GET_SYSTICK_CALIB__ & SysTick_CALIB_NOREF);
}

uint32_t hw_systick_get_skew_flag(void)
{
    return (__GET_SYSTICK_CALIB__ & SysTick_CALIB_SKEW);
}

uint32_t hw_systick_get_calibration_value(void)
{
    return (__GET_SYSTICK_CALIB__ & SysTick_CALIB_TENMS);
}