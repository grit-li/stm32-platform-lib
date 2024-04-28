#ifndef __SETM32_PLATFORM_HW_SYSTICK_H__
#define __SETM32_PLATFORM_HW_SYSTICK_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum hw_systick_clock_source_e
{
    hw_systick_clock_source_fclock,
    hw_systick_clock_source_stclock,
};
enum hw_systick_exception_request_e
{
    hw_systick_exception_request_enable,
    hw_systick_exception_request_disable,
};
enum hw_systick_enable_e
{
    hw_systick_enable,
    hw_systick_disable,
};
enum hw_systick_cmd_e
{
    HW_SYSTICK_CMD_SET_CLOCK_SOURCE, /*< WPARAM: enum hw_systick_clock_source_e >*/
    HW_SYSTICK_CMD_GET_CLOCK_SOURCE, /*< WPARAM: enum hw_systick_clock_source_e * >*/

    HW_SYSTICK_CMD_SET_EXCEPTION_REQUEST, /*< WPARAM: enum hw_systick_exception_request_e >*/
    HW_SYSTICK_CMD_GET_EXCEPTION_REQUEST, /*< WPARAM: enum hw_systick_exception_request_e * >*/

    HW_SYSTICK_CMD_SET_ENABLE, /*< WPARAM: enum hw_systick_enable_e >*/
    HW_SYSTICK_CMD_GET_ENABLE, /*< WPARAM: enum hw_systick_enable_e * >*/

    HW_SYSTICK_CMD_SET_RELOAD_VALUE, /*< WPARAM: uint32_t >*/
    HW_SYSTICK_CMD_GET_RELOAD_VALUE, /*< WPARAM: uint32_t * >*/

    HW_SYSTICK_CMD_SET_COUNTER_VALUE, /*< WPARAM: uint32_t >*/
    HW_SYSTICK_CMD_GET_COUNTER_VALUE, /*< WPARAM: uint32_t * >*/
};

#ifdef __cplusplus
}
#endif

#endif
