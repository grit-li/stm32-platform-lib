#include "hal/hal_gpio.h"
#include "stm32/gpio.h"

uint32_t gpio_init(HGPIO hgpio)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_param_error;
    }
    enum gpio_group_e  group  = HGPIO_GET_GROUP(hgpio);
    enum gpio_port_e   port   = HGPIO_GET_PORT(hgpio);
    enum gpio_mode_e   mode   = HGPIO_GET_MODE(hgpio);
    enum gpio_status_e status = HGPIO_GET_STATUS(hgpio);
    enum gpio_alternate_e alternate = HGPIO_GET_ALTERNATE(hgpio);

    hal_gpio_set_mode(group, port, mode, alternate);
    hal_gpio_set_speed(group, port);
    hal_gpio_set_status(group, port, status);
    return stm32_errcode_success;
}

uint32_t gpio_set_mode(HGPIO hgpio, enum gpio_mode_e mode)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_param_error;
    }
    enum gpio_group_e  group  = HGPIO_GET_GROUP(hgpio);
    enum gpio_port_e   port   = HGPIO_GET_PORT(hgpio);

    hal_gpio_set_mode(group, port, mode, gpio_alternate_invalid);
    return stm32_errcode_success;
}

uint32_t gpio_set_status(HGPIO hgpio, enum gpio_status_e status)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_param_error;
    }
    enum gpio_group_e  group  = HGPIO_GET_GROUP(hgpio);
    enum gpio_port_e   port   = HGPIO_GET_PORT(hgpio);

    hal_gpio_set_status(group, port, status);
    return stm32_errcode_success;
}

uint32_t gpio_toggle_status(HGPIO hgpio)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_param_error;
    }
    return stm32_errcode_success;
}

