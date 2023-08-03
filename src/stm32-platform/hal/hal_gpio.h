#ifndef __SETM32_PLATFORM_HAL_GPIO_H__
#define __SETM32_PLATFORM_HAL_GPIO_H__

#include <stdint.h>
#include "stm32/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

enum hal_gpio_mode_e
{
    hal_gpio_mode_input,
    hal_gpio_mode_output,
    hal_gpio_mode_alternate,
    hal_gpio_mode_analog,
};

uint32_t hal_gpio_set_mode(enum gpio_group_e group, enum gpio_port_e port, enum gpio_mode_e mode, enum gpio_alternate_e);
uint32_t hal_gpio_set_status(enum gpio_group_e group, enum gpio_port_e port, enum gpio_status_e status);
uint32_t hal_gpio_set_speed(enum gpio_group_e group, enum gpio_port_e port);

#ifdef __cplusplus
}
#endif

#endif