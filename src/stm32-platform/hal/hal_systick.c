#include "hw_common.h"
#include "hw_systick.h"
#include "hal_systick.h"

void hal_systick_select_clock_source(void)
{
    hw_platform_send_cmd(hw_platform_systick, HW_SYSTICK_CMD_SET_CLOCK_SOURCE, hw_systick_clock_source_fclock, 0);
}

void hal_systick_exception_enable(void)
{
    hw_platform_send_cmd(hw_platform_systick, HW_SYSTICK_CMD_SET_EXCEPTION_REQUEST, hw_systick_exception_request_enable, 0);
}

void hal_systick_exception_disable(void)
{
    hw_platform_send_cmd(hw_platform_systick, HW_SYSTICK_CMD_SET_EXCEPTION_REQUEST, hw_systick_exception_request_disable, 0);
}

void hal_systick_set_reload(uint32_t value)
{
    hw_platform_send_cmd(hw_platform_systick, HW_SYSTICK_CMD_SET_RELOAD_VALUE, value, 0);
}

void hal_systick_set_value(uint32_t value)
{
    hw_platform_send_cmd(hw_platform_systick, HW_SYSTICK_CMD_SET_COUNTER_VALUE, value, 0);
}

void hal_systick_set_count_enable(void)
{
    hw_platform_send_cmd(hw_platform_systick, HW_SYSTICK_CMD_SET_ENABLE, hw_systick_enable, 0);
}

void hal_systick_set_count_disable(void)
{
    hw_platform_send_cmd(hw_platform_systick, HW_SYSTICK_CMD_SET_ENABLE, hw_systick_disable, 0);
}

