#ifndef __SETM32_PLATFORM_HW_GPIO_H__
#define __SETM32_PLATFORM_HW_GPIO_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum hw_gpio_mode_e
{
    hw_gpio_mode_input      = 0x00,
    hw_gpio_mode_output     = 0x01,
    hw_gpio_mode_alternate  = 0x02,
    hw_gpio_mode_analog     = 0x03,
    hw_gpio_mode_max,
};

enum hw_gpio_output_mode_e
{
    hw_gpio_output_mode_push_pull   = 0x00,
    hw_gpio_output_mode_open_drain  = 0x01,
    hw_gpio_output_mode_max,
};

enum hw_gpio_output_speed_e
{
    hw_gpio_output_speed_low        = 0x00,
    hw_gpio_output_speed_medium     = 0x01,
    hw_gpio_output_speed_high       = 0x02,
    hw_gpio_output_speed_very_high  = 0x03,
    hw_gpio_output_speed_max,
};

enum hw_gpio_pupd_e
{
    hw_gpio_pupd_nopull     = 0x00,
    hw_gpio_pupd_pull_up    = 0x01,
    hw_gpio_pupd_pull_down  = 0x02,
    hw_gpio_pupd_max,
};

enum hw_gpio_status_e
{
    hw_gpio_status_low   = 0x00,
    hw_gpio_status_high  = 0x01,
    hw_gpio_status_null,
};

enum hw_gpio_cmd_e
{
    HW_GPIO_CMD_SET_PROP, /*< WPARAM: gpio, LPARAM: uint32_t >*/
    HW_GPIO_CMD_GET_PROP, /*< WPARAM: gpio, LPARAM: uint32_t * >*/

    HW_GPIO_CMD_SET_MODE, /*< WPARAM: gpio, LPARAM: enum hw_gpio_mode_e >*/
    HW_GPIO_CMD_GET_MODE, /*< WPARAM: gpio, LPARAM: enum hw_gpio_mode_e * >*/

    HW_GPIO_CMD_SET_OUTPUT_MODE, /*< WPARAM: gpio, LPARAM: enum hw_gpio_output_mode_e >*/
    HW_GPIO_CMD_GET_OUTPUT_MODE, /*< WPARAM: gpio, LPARAM: enum hw_gpio_output_mode_e * >*/

    HW_GPIO_CMD_SET_OUTPUT_SPEED, /*< WPARAM: gpio, LPARAM: enum hw_gpio_output_speed_e >*/
    HW_GPIO_CMD_GET_OUTPUT_SPEED, /*< WPARAM: gpio, LPARAM: enum hw_gpio_output_speed_e * >*/

    HW_GPIO_CMD_SET_PUPD_MODE, /*< WPARAM: gpio, LPARAM: enum hw_gpio_pupd_e >*/
    HW_GPIO_CMD_GET_PUPD_MODE, /*< WPARAM: gpio, LPARAM: enum hw_gpio_pupd_e * >*/

    HW_GPIO_CMD_SET_ALTERNATE, /*< WPARAM: gpio, LPARAM: uint8_t >*/
    HW_GPIO_CMD_GET_ALTERNATE, /*< WPARAM: gpio, LPARAM: uint8_t * >*/

    HW_GPIO_CMD_SET_STATUS, /*< WPARAM: gpio, LPARAM: enum hw_gpio_status_e >*/
    HW_GPIO_CMD_GET_STATUS, /*< WPARAM: gpio, LPARAM: enum hw_gpio_status_e * >*/
};

#ifdef __cplusplus
}
#endif

#endif
