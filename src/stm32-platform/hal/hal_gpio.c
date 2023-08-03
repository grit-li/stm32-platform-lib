#include <stdio.h>
#include "hw/hw_gpio.h"
#include "hal_gpio.h"

static inline uint8_t gpio_is_alternate_function(enum gpio_mode_e mode)
{
    return stm32_errcode_valid;
} 

static struct GPIO_TypeDef* hal_gpio_get_register(enum gpio_group_e group)
{
    struct GPIO_TypeDef* bRet = NULL;
    switch(group) {
        case gpio_group_a: bRet = __GET_GPIO_REGISTER__(GPIOA); break;
        case gpio_group_b: bRet = __GET_GPIO_REGISTER__(GPIOB); break;
        case gpio_group_c: bRet = __GET_GPIO_REGISTER__(GPIOC); break;
        case gpio_group_d: bRet = __GET_GPIO_REGISTER__(GPIOD); break;
        case gpio_group_e: bRet = __GET_GPIO_REGISTER__(GPIOE); break;
        case gpio_group_f: bRet = __GET_GPIO_REGISTER__(GPIOF); break;
        case gpio_group_g: bRet = __GET_GPIO_REGISTER__(GPIOG); break;
        case gpio_group_h: bRet = __GET_GPIO_REGISTER__(GPIOH); break;
        default: break;
    }
    return bRet;
}

uint32_t hal_gpio_set_mode(enum gpio_group_e group, enum gpio_port_e port, enum gpio_mode_e mode, enum gpio_alternate_e alternate)
{
    struct GPIO_TypeDef* GPIOx = hal_gpio_get_register(group);
    if(GPIOx == NULL) {
        return stm32_errcode_param_error;
    }
    if(gpio_is_alternate_function(mode) == stm32_errcode_valid) {
        hw_gpio_set_alternate_function(GPIOx, port >> 3, 0xFUL << ((port % 8) << 2), alternate << ((port % 8) << 2));
    }
    hw_gpio_set_mode(GPIOx, 0x03 << (port << 1), (mode & GPIO_MODE_MASK) << (port << 1));
    if(mode & GPIO_MODE_OUTPUT || mode & GPIO_MODE_ALTERNATE) {
        hw_gpio_set_output_speed(GPIOx,  0x03 << (port << 1),  0x03 << (port << 1));
        hw_gpio_set_output_type(GPIOx, 0x01 << port, (mode & GPIO_OTYPE_MASK) << port);
    }
    if(mode & GPIO_MODE_ANALOG) {
        hw_gpio_switch_analog_port_control(GPIOx, 0x01 << port, 0x01 << port);
    }
    hw_gpio_set_pull_up_pull_down(GPIOx,  0x03 << (port << 1),  (mode & GPIO_PUPD_MASK) << (port << 1));
    return stm32_errcode_success;
}
uint32_t hal_gpio_set_status(enum gpio_group_e group, enum gpio_port_e port, enum gpio_status_e status)
{
    struct GPIO_TypeDef* GPIOx = hal_gpio_get_register(group);
    if(GPIOx == NULL) {
        return stm32_errcode_param_error;
    }
    if(status == gpio_status_hight) {
        hw_gpio_set_port(GPIOx, 0x01 << port, 0x01 << port);
    } else {
        hw_gpio_port_output_reset(GPIOx, 0x01 << port, 0x01 << port);
    }
    return stm32_errcode_success;
}
uint32_t hal_gpio_set_speed(enum gpio_group_e group, enum gpio_port_e port)
{
    struct GPIO_TypeDef* GPIOx = hal_gpio_get_register(group);
    if(GPIOx == NULL) {
        return stm32_errcode_param_error;
    }
    hw_gpio_set_output_speed(GPIOx,  0x03 << (port << 1),  0x03 << (port << 1));
    return stm32_errcode_success;
}