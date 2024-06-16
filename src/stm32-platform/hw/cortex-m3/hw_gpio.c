#include "common.h"
#include "hw_gpio.h"

struct GPIO_TypeDef
{
    __IO uint32_t CRL;
    __IO uint32_t CRH;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t BRR;
    __IO uint32_t LCKR;
};

#define GPIOA               ((struct GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((struct GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((struct GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((struct GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((struct GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((struct GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((struct GPIO_TypeDef *) GPIOG_BASE)

#define __GET_GPIO_CRL__(GPIOx)         (GPIOx->CRL)
#define __GET_GPIO_CRH__(GPIOx)         (GPIOx->CRH)
#define __GET_GPIO_IDR__(GPIOx)         (GPIOx->IDR)
#define __GET_GPIO_ODR__(GPIOx)         (GPIOx->ODR)
#define __GET_GPIO_BSRR__(GPIOx)        (GPIOx->BSRR)
#define __GET_GPIO_BRR__(GPIOx)         (GPIOx->BRR)
#define __GET_GPIO_LCKR__(GPIOx)        (GPIOx->LCKR)

static struct GPIO_TypeDef* hw_gpio_group[] = {
        GPIOA,
        GPIOB,
        GPIOC,
        GPIOD,
        GPIOE,
        GPIOF,
        GPIOG,
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

#define HW_GPIO_MODE_INPUT     (0x00)
#define HW_GPIO_MODE_OUTPUT    (0x01)
#define HW_GPIO_MODE_ALTERNATE (0x02)
#define HW_GPIO_MODE_ANALOG    (0x03)
#define HW_GPIO_MODE_MASK      (0x03)

#define HW_GPIO_PUPD_NOPULL    (0x00)
#define HW_GPIO_PUPD_UP        (0x04)
#define HW_GPIO_PUPD_DOWN      (0x08)
#define HW_GPIO_PUPD_RESERVED  (0x0C)
#define HW_GPIO_PUPD_MASK      (0x0C)

#define HW_GPIO_OTYPE_PP       (0x00)
#define HW_GPIO_OTYPE_OD       (0x10)
#define HW_GPIO_OTYPE_MASK     (0x10)

enum hw_gpio_prop_e
{
    hw_gpio_prop_analog                     = (HW_GPIO_MODE_ANALOG | HW_GPIO_PUPD_NOPULL),

    hw_gpio_prop_input_floating             = (HW_GPIO_MODE_INPUT | HW_GPIO_PUPD_NOPULL),
    hw_gpio_prop_input_pull_up              = (HW_GPIO_MODE_INPUT | HW_GPIO_PUPD_UP),
    hw_gpio_prop_input_pull_down            = (HW_GPIO_MODE_INPUT | HW_GPIO_PUPD_DOWN),

    hw_gpio_prop_output_push_pull           = (HW_GPIO_MODE_OUTPUT | HW_GPIO_OTYPE_PP | HW_GPIO_PUPD_NOPULL),
    hw_gpio_prop_output_push_pull_up        = (HW_GPIO_MODE_OUTPUT | HW_GPIO_OTYPE_PP | HW_GPIO_PUPD_UP),
    hw_gpio_prop_output_push_pull_down      = (HW_GPIO_MODE_OUTPUT | HW_GPIO_OTYPE_PP | HW_GPIO_PUPD_DOWN),

    hw_gpio_prop_output_open_drain          = (HW_GPIO_MODE_OUTPUT | HW_GPIO_OTYPE_OD | HW_GPIO_PUPD_NOPULL),
    hw_gpio_prop_output_open_drain_up       = (HW_GPIO_MODE_OUTPUT | HW_GPIO_OTYPE_OD | HW_GPIO_PUPD_UP),
    hw_gpio_prop_output_open_drain_down     = (HW_GPIO_MODE_OUTPUT | HW_GPIO_OTYPE_OD | HW_GPIO_PUPD_DOWN),

    hw_gpio_prop_alternate_push_pull        = (HW_GPIO_MODE_ALTERNATE | HW_GPIO_OTYPE_PP | HW_GPIO_PUPD_NOPULL),
    hw_gpio_prop_alternate_push_pull_up     = (HW_GPIO_MODE_ALTERNATE | HW_GPIO_OTYPE_PP | HW_GPIO_PUPD_UP),
    hw_gpio_prop_alternate_push_pull_down   = (HW_GPIO_MODE_ALTERNATE | HW_GPIO_OTYPE_PP | HW_GPIO_PUPD_DOWN),

    hw_gpio_prop_alternate_open_drain       = (HW_GPIO_MODE_ALTERNATE | HW_GPIO_OTYPE_OD | HW_GPIO_PUPD_NOPULL),
    hw_gpio_prop_alternate_open_drain_up    = (HW_GPIO_MODE_ALTERNATE | HW_GPIO_OTYPE_OD | HW_GPIO_PUPD_UP),
    hw_gpio_prop_alternate_open_drain_down  = (HW_GPIO_MODE_ALTERNATE | HW_GPIO_OTYPE_OD | HW_GPIO_PUPD_DOWN),
};

static uint32_t hw_gpio_set_mode(uint32_t gpio, uint32_t mode)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);

    uint32_t CR = 0;
    uint32_t ODR = __GET_GPIO_ODR__(GPIOx);
    uint32_t MODE = 0x00000000;

    switch(mode) {
        case hw_gpio_prop_input_pull_up:
            ODR = ODR |  (0x00000001 << port);
            break;
        case hw_gpio_prop_input_pull_down:
            ODR = ODR & ~(0x00000001 << port);
            break;
        default:
            break;
    }

    switch(port){
        case 0 ... 7:
            CR = __GET_GPIO_CRL__(GPIOx);
            break;
        case 8 ... 15:
            CR = __GET_GPIO_CRH__(GPIOx);
            port -= 8;
            break;
        default:
            break;
    }
    if(CR != 0) {
        MODE = CR;
        MODE = MODE & ~(0x0F << (port << 2));

        switch(mode) {
            case hw_gpio_prop_analog:
                break;
            case hw_gpio_prop_input_floating:
                MODE  =  MODE | (0x04 << (port << 2));
                break;
            case hw_gpio_prop_input_pull_up:
            case hw_gpio_prop_input_pull_down:
                MODE  =  MODE | (0x08 << (port << 2));
                break;

            case hw_gpio_prop_output_push_pull_up:
            case hw_gpio_prop_output_push_pull_down:
            case hw_gpio_prop_output_open_drain_up:
            case hw_gpio_prop_output_open_drain_down:
            case hw_gpio_prop_alternate_push_pull_up:
            case hw_gpio_prop_alternate_push_pull_down:
            case hw_gpio_prop_alternate_open_drain_up:
            case hw_gpio_prop_alternate_open_drain_down:
                break;

            case hw_gpio_prop_output_push_pull:
                MODE = MODE |  (0x03 << (port << 2));
                break;

            case hw_gpio_prop_output_open_drain:
                MODE = MODE |  (0x07 << (port << 2));
                break;
            case hw_gpio_prop_alternate_push_pull:
                MODE = MODE |  (0x0B << (port << 2));
                break;
            case hw_gpio_prop_alternate_open_drain:
                MODE = MODE |  (0x0F << (port << 2));
                break;
            default:
                break;
        }
        CR = MODE;
        switch(port) {
            case 0 ... 7:
                __GET_GPIO_CRL__(GPIOx) = CR;
                break;
            case 8 ... 15:
                __GET_GPIO_CRH__(GPIOx) = CR;
                break;
            default:
                break;
        }
        __GET_GPIO_ODR__(GPIOx) = ODR;
    }
    return 0;
}

static void hw_gpio_set_status(uint32_t gpio, enum hw_gpio_status_e status)
{
    struct GPIO_TypeDef* GPIOx = __GET_GPIO_REGISTER__(gpio);
    uint32_t port = __GET_GPIO_PORT__(gpio);
    if(status == hw_gpio_status_high) {
        __BIT_OR__(__GET_GPIO_BSRR__(GPIOx), __BIT__(port));
    } else {
        __BIT_OR__(__GET_GPIO_BRR__(GPIOx), __BIT__(port));
    }
}
static enum hw_gpio_status_e hw_gpio_get_status(uint32_t gpio)
{
    return hw_gpio_status_null;
}

enum hw_platform_errcode_e hw_platform_gpio_cmd(uint8_t type, WPARAM wParam, LPARAM lParam)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(type) {
        case HW_GPIO_CMD_SET_PROP:
            hw_gpio_set_mode(wParam, lParam);
            break;
        case HW_GPIO_CMD_GET_PROP:
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

