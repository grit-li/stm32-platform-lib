#include "common.h"
#include "hw_gpio.h"

#define hw_gpio_mode_mask 0x03
#define hw_gpio_output_mode_mask 0x01
#define hw_gpio_output_speed_mask 0x03
#define hw_gpio_pupd_pull_mask 0x02
#define hw_gpio_status_mask 0x01

struct GPIO_TypeDef
{
    __IO uint32_t MODER;       /*!< GPIO port mode register,               Address offset: 0x00      */
    __IO uint32_t OTYPER;      /*!< GPIO port output type register,        Address offset: 0x04      */
    __IO uint32_t OSPEEDR;     /*!< GPIO port output speed register,       Address offset: 0x08      */
    __IO uint32_t PUPDR;       /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    __IO uint32_t IDR;         /*!< GPIO port input data register,         Address offset: 0x10      */
    __IO uint32_t ODR;         /*!< GPIO port output data register,        Address offset: 0x14      */
    __IO uint32_t BSRR;        /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
    __IO uint32_t LCKR;        /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    __IO uint32_t AFR[2];      /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
    __IO uint32_t BRR;         /*!< GPIO Bit Reset register,               Address offset: 0x28      */
    __IO uint32_t ASCR;        /*!< GPIO analog switch control register,   Address offset: 0x2C     */
};

#define GPIOA                   ((struct GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                   ((struct GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                   ((struct GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                   ((struct GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE                   ((struct GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF                   ((struct GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG                   ((struct GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH                   ((struct GPIO_TypeDef *) GPIOH_BASE)

#define __GET_GPIO_MODER__(GPIOx)           (GPIOx->MODER)
#define __GET_GPIO_OTYPER__(GPIOx)          (GPIOx->OTYPER)
#define __GET_GPIO_OSPEEDR__(GPIOx)         (GPIOx->OSPEEDR)
#define __GET_GPIO_PUPDR__(GPIOx)           (GPIOx->PUPDR)
#define __GET_GPIO_IDR__(GPIOx)             (GPIOx->IDR)
#define __GET_GPIO_ODR__(GPIOx)             (GPIOx->ODR)
#define __GET_GPIO_BSRR__(GPIOx)            (GPIOx->BSRR)
#define __GET_GPIO_LCKR__(GPIOx)            (GPIOx->LCKR)
#define __GET_GPIO_AFR__(GPIOx, n)          (GPIOx->AFR[n])
#define __GET_GPIO_BRR__(GPIOx)             (GPIOx->BRR)
#define __GET_GPIO_ASCR__(GPIOx)            (GPIOx->ASCR)

static struct GPIO_TypeDef* hw_gpio_group[] = {
        GPIOA,
        GPIOB,
        GPIOC,
        GPIOD,
        GPIOE,
        GPIOF,
        GPIOG,
        GPIOH,
};

static struct GPIO_TypeDef* __GET_GPIO_REGISTER__(uint32_t gpio)
{
    uint32_t group = gpio / 32;
    stm32_assert(group > sizeof(hw_gpio_group)/sizeof(hw_gpio_group[0]), "gpio group overflow!");
    return hw_gpio_group[group];
}

static uint32_t __GET_GPIO_PORT__(uint32_t gpio)
{
    uint32_t port = gpio % 32;
    stm32_assert(port >= 16, "gpio port error!");
    return port;
}

static void hw_gpio_set_mode(uint32_t gpio, enum hw_gpio_mode_e mode)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    __BIT_COVER_SET__(__GET_GPIO_MODER__(GPIOx), hw_gpio_mode_mask << (port << 1), mode << (port << 1));
}

static enum hw_gpio_mode_e hw_gpio_get_mode(uint32_t gpio)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    return __BIT_RIGHT_SHIFT__(__GET_GPIO_MODER__(GPIOx), port << 1) & hw_gpio_mode_mask;
}

static void hw_gpio_set_output_mode(uint32_t gpio, enum hw_gpio_output_mode_e mode)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    __BIT_COVER_SET__(__GET_GPIO_OTYPER__(GPIOx), hw_gpio_output_mode_mask << port, mode << port);
}
static enum hw_gpio_output_mode_e hw_gpio_get_output_mode(uint32_t gpio)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    return __BIT_RIGHT_SHIFT__(__GET_GPIO_OTYPER__(GPIOx), port) & hw_gpio_output_mode_mask;
}

static void hw_gpio_set_output_speed(uint32_t gpio, enum hw_gpio_output_speed_e speed)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    __BIT_COVER_SET__(__GET_GPIO_OSPEEDR__(GPIOx), hw_gpio_output_speed_mask << (port << 1), speed << (port << 1));
}
static enum hw_gpio_output_speed_e hw_gpio_get_output_speed(uint32_t gpio)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    return __BIT_RIGHT_SHIFT__(__GET_GPIO_OSPEEDR__(GPIOx), port << 1) & hw_gpio_output_speed_mask;
}

static void hw_gpio_set_pupd_mode(uint32_t gpio, enum hw_gpio_pupd_e pull)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    __BIT_COVER_SET__(__GET_GPIO_PUPDR__(GPIOx), hw_gpio_pupd_pull_mask << (port << 1), pull << (port << 1));

}
static enum hw_gpio_pupd_e hw_gpio_get_pupd_mode(uint32_t gpio)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    return __BIT_RIGHT_SHIFT__(__GET_GPIO_PUPDR__(GPIOx), port << 1) & hw_gpio_pupd_pull_mask;
}

static void hw_gpio_set_alternate_function(uint32_t gpio, uint8_t af)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    __BIT_COVER_SET__(__GET_GPIO_AFR__(GPIOx, port >> 3), 0xFUL << ((port % 8) << 2), af << ((port % 8) << 2));

}
static uint8_t hw_gpio_get_alternate_function(uint32_t gpio)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    return __BIT_RIGHT_SHIFT__(__GET_GPIO_AFR__(GPIOx, port >> 3), (port % 8) << 2) & 0xFUL;
}

static void hw_gpio_set_status(uint32_t gpio, enum hw_gpio_status_e status)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    __BIT_COVER_SET__(__GET_GPIO_ODR__(GPIOx), hw_gpio_status_mask << port, status << port);
}
static enum hw_gpio_status_e hw_gpio_get_status(uint32_t gpio)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    return __BIT_RIGHT_SHIFT__(__GET_GPIO_ODR__(GPIOx), port) & hw_gpio_status_mask;
}

enum hw_platform_errcode_e hw_platform_gpio_cmd(uint8_t type, WPARAM wParam, LPARAM lParam)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(type) {
        case HW_GPIO_CMD_SET_MODE:
            hw_gpio_set_mode(wParam, lParam);
            break;
        case HW_GPIO_CMD_GET_MODE:
            *(enum hw_gpio_mode_e *)lParam = hw_gpio_get_mode(wParam);
            break;
        case HW_GPIO_CMD_SET_OUTPUT_MODE:
            hw_gpio_set_output_mode(wParam, lParam);
            break;
        case HW_GPIO_CMD_GET_OUTPUT_MODE:
            *(enum hw_gpio_output_mode_e *)lParam = hw_gpio_get_output_mode(wParam);
            break;
        case HW_GPIO_CMD_SET_OUTPUT_SPEED:
            hw_gpio_set_output_speed(wParam, lParam);
            break;
        case HW_GPIO_CMD_GET_OUTPUT_SPEED:
            *(enum hw_gpio_output_speed_e *)lParam = hw_gpio_get_output_speed(wParam);
            break;
        case HW_GPIO_CMD_SET_PUPD_MODE:
            hw_gpio_set_pupd_mode(wParam, lParam);
            break;
        case HW_GPIO_CMD_GET_PUPD_MODE:
            *(enum hw_gpio_pupd_e *)lParam = hw_gpio_get_pupd_mode(wParam);
            break;
        case HW_GPIO_CMD_SET_ALTERNATE:
            hw_gpio_set_alternate_function(wParam, lParam);
            break;
        case HW_GPIO_CMD_GET_ALTERNATE:
            *(uint8_t *) lParam = hw_gpio_get_alternate_function(wParam);
            break;
        case HW_GPIO_CMD_SET_STATUS:
            hw_gpio_set_status(wParam, lParam);
            break;
        case HW_GPIO_CMD_GET_STATUS:
            *(enum hw_gpio_status_e *)lParam = hw_gpio_get_status(wParam);
            break;
        default:
            bRet = hw_platform_errcode_not_support;
            break;
    }
    return bRet;
}

