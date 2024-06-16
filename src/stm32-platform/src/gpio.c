#include "hal/hal_gpio.h"
#include "stm32/gpio.h"

#define MAKE_GPIO(group, port) (HGPIO)(group * 32 + port)
#define STM32_TO_HAL_TYPE(t1, t2, v) t1 ## _to_ ## t2(v)

static inline enum hal_gpio_mode_e gpio_mode_e_to_hal_gpio_mode_e(enum gpio_mode_e mode)
{
    enum hal_gpio_mode_e bRet = hal_gpio_mode_null;

    switch(mode) {
        case gpio_mode_analog:
            bRet = hal_gpio_mode_analog;
            break;
        case gpio_mode_input_floating:
        case gpio_mode_input_pull_up:
        case gpio_mode_input_pull_down:
            bRet = hal_gpio_mode_input;
            break;
        case gpio_mode_output_push_pull:
        case gpio_mode_output_push_pull_up:
        case gpio_mode_output_push_pull_down:
        case gpio_mode_output_open_drain:
        case gpio_mode_output_open_drain_up:
        case gpio_mode_output_open_drain_down:
            bRet = hal_gpio_mode_output;
            break;
        case gpio_mode_alternate_push_pull:
        case gpio_mode_alternate_push_pull_up:
        case gpio_mode_alternate_push_pull_down:
        case gpio_mode_alternate_open_drain:
        case gpio_mode_alternate_open_drain_up:
        case gpio_mode_alternate_open_drain_down:
            bRet = hal_gpio_mode_alternate;
            break;
        default:
            break;
     }
    return bRet;
}

static inline enum hal_gpio_output_mode_e gpio_mode_e_to_hal_gpio_output_mode_e(enum gpio_mode_e mode)
{
    enum hal_gpio_output_mode_e bRet = hal_gpio_output_mode_max;
    switch(mode) {
        case gpio_mode_output_push_pull:
        case gpio_mode_output_push_pull_up:
        case gpio_mode_output_push_pull_down:
        case gpio_mode_alternate_push_pull:
        case gpio_mode_alternate_push_pull_up:
        case gpio_mode_alternate_push_pull_down:
            bRet = hal_gpio_output_mode_pp;
            break;
        case gpio_mode_output_open_drain:
        case gpio_mode_output_open_drain_up:
        case gpio_mode_output_open_drain_down:
        case gpio_mode_alternate_open_drain:
        case gpio_mode_alternate_open_drain_up:
        case gpio_mode_alternate_open_drain_down:
            bRet = hal_gpio_output_mode_od;
            break;
        default:
            break;
     }
    return bRet;
}

static inline enum hal_gpio_pupd_e gpio_mode_e_to_hal_gpio_pupd_e(enum gpio_mode_e mode)
{
    enum hal_gpio_pupd_e bRet = hal_gpio_pupd_nopull;
    switch(mode) {
        case gpio_mode_analog:
        case gpio_mode_input_floating:
        case gpio_mode_output_push_pull:
        case gpio_mode_output_open_drain:
        case gpio_mode_alternate_push_pull: 
        case gpio_mode_alternate_open_drain:
            bRet = hal_gpio_pupd_nopull;
            break;
        case gpio_mode_input_pull_up:
        case gpio_mode_output_push_pull_up:
        case gpio_mode_output_open_drain_up:
        case gpio_mode_alternate_push_pull_up:
        case gpio_mode_alternate_open_drain_up:
            bRet = hal_gpio_pupd_pull_up;
            break;
        case gpio_mode_input_pull_down:
        case gpio_mode_output_push_pull_down:
        case gpio_mode_output_open_drain_down:
        case gpio_mode_alternate_push_pull_down:
        case gpio_mode_alternate_open_drain_down:
            bRet = hal_gpio_pupd_pull_down;
            break;
        default:
            break;
     }
    return bRet;
}


static inline enum hal_gpio_speed_e gpio_speed_e_to_hal_gpio_speed_e(enum gpio_speed_e speed)
{
    enum hal_gpio_speed_e bRet = hal_gpio_speed_low;
    switch(speed) {
        case gpio_speed_low:
            bRet = hal_gpio_speed_low;
            break;
        case gpio_speed_medium:
            bRet = hal_gpio_speed_medium;
            break;
        case gpio_speed_high:
            bRet = hal_gpio_speed_high;
            break;
        case gpio_speed_very_high:
            bRet = hal_gpio_speed_very_high;
            break;
        default:
            break;
     }
    return bRet;
}

static inline enum hal_gpio_status_e gpio_status_e_to_hal_gpio_status_e(enum gpio_status_e speed)
{
    enum hal_gpio_status_e bRet = hal_gpio_status_low;
    switch(speed) {
        case gpio_status_low:
            bRet = hal_gpio_status_low;
            break;
        case gpio_status_high:
            bRet = hal_gpio_status_high;
            break;
        default:
            break;
     }
    return bRet;
}

HGPIO gpio_init(const struct gpio_init_t* init)
{
    if(!init || init->group >= gpio_group_max || init->port >= gpio_port_max) {
        return HGPIO_NULL;
    }
    HGPIO hgpio = MAKE_GPIO(init->group, init->port);
    gpio_set_mode(hgpio, init->mode);
    gpio_set_speed(hgpio, init->speed);
    gpio_set_alternate(hgpio, init->alternate);
    gpio_set_status(hgpio, init->status);
    return hgpio;    
}
uint32_t gpio_set_mode(HGPIO hgpio, enum gpio_mode_e mode)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_fail;
    }
    enum hal_gpio_mode_e gpio_mode = STM32_TO_HAL_TYPE(gpio_mode_e, hal_gpio_mode_e, mode);
    hal_gpio_set_prop(hgpio, mode);
    hal_gpio_set_mode(hgpio, gpio_mode);
    hal_gpio_set_output_mode(hgpio, STM32_TO_HAL_TYPE(gpio_mode_e, hal_gpio_output_mode_e, mode));
    hal_gpio_set_pupd_mode(hgpio, STM32_TO_HAL_TYPE(gpio_mode_e, hal_gpio_pupd_e, mode));
    return stm32_errcode_success;
}
uint32_t gpio_set_speed(HGPIO hgpio, enum gpio_speed_e speed)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_fail;
    }
    enum hal_gpio_speed_e speed_mode = STM32_TO_HAL_TYPE(gpio_speed_e, hal_gpio_speed_e, speed);
    hal_gpio_set_output_speed(hgpio, speed_mode);
    return stm32_errcode_success;
}

uint32_t gpio_set_alternate(HGPIO hgpio, enum gpio_alternate_e af)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_fail;
    }
    hal_gpio_set_alternate(hgpio, af);
    return stm32_errcode_success;
}
uint32_t gpio_set_status(HGPIO hgpio, enum gpio_status_e status)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_fail;
    }
    enum hal_gpio_status_e gpio_status = STM32_TO_HAL_TYPE(gpio_status_e, hal_gpio_status_e, status);
    hal_gpio_set_status(hgpio, gpio_status);
    return stm32_errcode_success;
}
enum gpio_status_e gpio_get_status(HGPIO hgpio)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_fail;
    }
    enum hal_gpio_status_e gpio_status = hal_gpio_get_status(hgpio);
    return (gpio_status == hal_gpio_status_low ? gpio_status_low : gpio_status_high);
}
uint32_t gpio_toggle_status(HGPIO hgpio)
{
    if(hgpio == HGPIO_NULL) {
        return stm32_errcode_fail;
    }
    hal_gpio_toggle_status(hgpio);
    return stm32_errcode_success;
}
