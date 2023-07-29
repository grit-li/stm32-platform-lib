#include "hw_gpio.h"
#include "stm32_assert.h"

void hw_gpio_set_mode(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t mode)
{
    __BIT_COVER_SET__(__GET_GPIO_MODER__(GPIOx), mask, mode);
}

uint32_t hw_gpio_get_mode(struct GPIO_TypeDef* GPIOx, uint32_t mask)
{
    return (__GET_GPIO_MODER__(GPIOx) & mask);
}

void hw_gpio_set_output_mode(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t type)
{
    __BIT_COVER_SET__(__GET_GPIO_OTYPER__(GPIOx), mask, type);
}

uint32_t hw_gpio_get_output_mode(struct GPIO_TypeDef* GPIOx, uint32_t mask)
{
    return (__GET_GPIO_OTYPER__(GPIOx) & mask);
}

void hw_gpio_set_output_speed(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t speed)
{
    __BIT_COVER_SET__(__GET_GPIO_OSPEEDR__(GPIOx), mask, speed);
}

uint32_t hw_gpio_get_output_speed(struct GPIO_TypeDef* GPIOx, uint32_t mask)
{
    return (__GET_GPIO_OSPEEDR__(GPIOx) & mask);
}

void hw_gpio_set_pull_up_down(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t pull)
{
    __BIT_COVER_SET__(__GET_GPIO_PUPDR__(GPIOx), mask, pull);
}

uint32_t hw_gpio_get_pull_up_down(struct GPIO_TypeDef* GPIOx, uint32_t mask)
{
    return (__GET_GPIO_PUPDR__(GPIOx) & mask);
}

uint32_t hw_gpio_get_input_data(struct GPIO_TypeDef* GPIOx, uint32_t mask)
{
    return (__GET_GPIO_IDR__(GPIOx) & mask);
}

void hw_gpio_set_output_data(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t value)
{
    __BIT_COVER_SET__(__GET_GPIO_ODR__(GPIOx), mask, value);
}

uint32_t hw_gpio_get_output_data(struct GPIO_TypeDef* GPIOx, uint32_t mask)
{
    return (__GET_GPIO_ODR__(GPIOx) & mask);
}

void hw_gpio_reset_port(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t port)
{
    __BIT_COVER_SET__(__GET_GPIO_BSRR__(GPIOx), mask, port);
}

void hw_gpio_set_port(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t port)
{
    __BIT_COVER_SET__(__GET_GPIO_BSRR__(GPIOx), mask, port);
}

void hw_gpio_set_lock(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t port)
{
    __BIT_COVER_SET__(__GET_GPIO_LCKR__(GPIOx), mask, port);
}

void hw_gpio_set_unlock(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t port)
{
    __BIT_COVER_SET__(__GET_GPIO_LCKR__(GPIOx), mask, port);
}

uint32_t hw_gpio_get_lock_status(struct GPIO_TypeDef* GPIOx, uint32_t mask)
{
    return (__GET_GPIO_LCKR__(GPIOx) & mask);
}

void hw_gpio_set_alternate_function(struct GPIO_TypeDef* GPIOx, uint8_t index, uint32_t mask, uint32_t func)
{
    __BIT_COVER_SET__(__GET_GPIO_AFR__(GPIOx, index), mask, func);
}

uint32_t hw_gpio_get_alternate_function(struct GPIO_TypeDef* GPIOx, uint8_t index, uint32_t mask)
{
    return (__GET_GPIO_AFR__(GPIOx, index) & mask);
}

void hw_gpio_port_output_reset(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t port)
{
    __BIT_COVER_SET__(__GET_GPIO_BRR__(GPIOx), mask, port);
}

void hw_gpio_switch_analog_port_control(struct GPIO_TypeDef* GPIOx, uint32_t mask, uint32_t port)
{
    __BIT_COVER_SET__(__GET_GPIO_ASCR__(GPIOx), mask, port);
}

uint32_t hw_gpio_get_analog_port_control(struct GPIO_TypeDef* GPIOx, uint32_t mask)
{
    return (__GET_GPIO_ASCR__(GPIOx) & mask);
}

