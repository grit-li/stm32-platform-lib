#ifndef __SETM32_PLATFORM_HAL_GPIO_H__
#define __SETM32_PLATFORM_HAL_GPIO_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum hal_gpio_mode_e
{
    hal_gpio_mode_input,
    hal_gpio_mode_output,
    hal_gpio_mode_alternate,
    hal_gpio_mode_analog,
    hal_gpio_mode_null,
};

enum hal_gpio_output_mode_e
{
    hal_gpio_output_mode_pp,
    hal_gpio_output_mode_od,
    hal_gpio_output_mode_max,
};

enum hal_gpio_status_e
{
    hal_gpio_status_low,
    hal_gpio_status_high,
    hal_gpio_status_null,
};

enum hal_gpio_speed_e
{
    hal_gpio_speed_low,
    hal_gpio_speed_medium,
    hal_gpio_speed_high,
    hal_gpio_speed_very_high,
};

enum hal_gpio_pupd_e
{
    hal_gpio_pupd_nopull,
    hal_gpio_pupd_pull_up,
    hal_gpio_pupd_pull_down,
};

int32_t hal_gpio_set_prop(uint32_t, uint32_t);
int32_t hal_gpio_set_mode(uint32_t, enum hal_gpio_mode_e);
int32_t hal_gpio_set_output_mode(uint32_t, enum hal_gpio_output_mode_e);
int32_t hal_gpio_set_output_speed(uint32_t, enum hal_gpio_speed_e);
int32_t hal_gpio_set_pupd_mode(uint32_t, enum hal_gpio_pupd_e);
int32_t hal_gpio_set_alternate(uint32_t, uint8_t);
int32_t hal_gpio_set_status(uint32_t, enum hal_gpio_status_e);
enum hal_gpio_status_e hal_gpio_get_status(uint32_t);
int32_t hal_gpio_toggle_status(uint32_t);

#ifdef __cplusplus
}
#endif

#endif
