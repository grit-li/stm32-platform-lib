#ifndef __SETM32_PLATFORM_GPIO_H__
#define __SETM32_PLATFORM_GPIO_H__

#include <stdint.h>
#include <stm32_types.h>
#include <stm32_bitops.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t HGPIO;
#define HGPIO_NULL ((HGPIO)0xffffffff)

#define MAKE_HGPIO(group, port, mode, alternate, status) (HGPIO)(((status & 0x000000FF) << 24) | ((mode & 0x000000FF) << 16) | ((port & 0x0000000F) << 12) | ((port & 0x0000000F) << 8) | ((group & 0x000000FF) << 0))

#define HGPIO_GET_GROUP(hgpio)      (uint8_t)((hgpio >>  0) & 0x000000FF)
#define HGPIO_GET_PORT(hgpio)       (uint8_t)((hgpio >>  8) & 0x0000000F)
#define HGPIO_GET_ALTERNATE(hgpio)  (uint8_t)((hgpio >> 12) & 0x0000000F)
#define HGPIO_GET_MODE(hgpio)       (uint8_t)((hgpio >> 16) & 0x000000FF)
#define HGPIO_GET_STATUS(hgpio)     (uint8_t)((hgpio >> 24) & 0x000000FF)

#define HGPIO_SET_GROUP(hgpio, group)               __BIT_COVER_SET__(hgpio, 0x000000FF, (group     & 0x000000FF) <<  0)
#define HGPIO_SET_PORT(hgpio, port)                 __BIT_COVER_SET__(hgpio, 0x00000F00, (port      & 0x0000000F) <<  8)
#define HGPIO_SET_ALTERNATE(hgpio, alternate)       __BIT_COVER_SET__(hgpio, 0x0000F000, (alternate & 0x0000000F) << 12)
#define HGPIO_SET_MODE(hgpio, mode)                 __BIT_COVER_SET__(hgpio, 0x00FF0000, (mode      & 0x000000FF) << 16)
#define HGPIO_SET_STATUS(hgpio, status)             __BIT_COVER_SET__(hgpio, 0xFF000000, (status    & 0x000000FF) << 24)

#define GPIO_MODE_INPUT     (0x00)
#define GPIO_MODE_OUTPUT    (0x01)
#define GPIO_MODE_ALTERNATE (0x02)
#define GPIO_MODE_ANALOG    (0x03)
#define GPIO_MODE_MASK      (0x03)

#define GPIO_PUPD_NOPULL    (0x00)
#define GPIO_PUPD_UP        (0x04)
#define GPIO_PUPD_DOWN      (0x08)
#define GPIO_PUPD_RESERVED  (0x0C)
#define GPIO_PUPD_MASK      (0x0C)

#define GPIO_OTYPE_PP       (0x00)
#define GPIO_OTYPE_OD       (0x10)
#define GPIO_OTYPE_MASK     (0x10)

enum gpio_group_e
{
    gpio_group_a,
    gpio_group_b,
    gpio_group_c,
    gpio_group_d,
    gpio_group_e,
    gpio_group_f,
    gpio_group_g,
    gpio_group_h,
};

enum gpio_port_e
{
    gpio_port_0,
    gpio_port_1,
    gpio_port_2,
    gpio_port_3,
    gpio_port_4,
    gpio_port_5,
    gpio_port_6,
    gpio_port_7,
    gpio_port_8,
    gpio_port_9,
    gpio_port_10,
    gpio_port_11,
    gpio_port_12,
    gpio_port_13,
    gpio_port_14,
    gpio_port_15,
    gpio_port_invalid = 0xF,
};

enum gpio_alternate_e
{
    gpio_alternate_0,
    gpio_alternate_1,
    gpio_alternate_2,
    gpio_alternate_3,
    gpio_alternate_4,
    gpio_alternate_5,
    gpio_alternate_6,
    gpio_alternate_7,
    gpio_alternate_8,
    gpio_alternate_9,
    gpio_alternate_10,
    gpio_alternate_11,
    gpio_alternate_12,
    gpio_alternate_13,
    gpio_alternate_14,
    gpio_alternate_15,
    gpio_alternate_invalid = 0xF,
};

enum gpio_mode_e
{
    gpio_mode_analog                            = (GPIO_MODE_ANALOG | GPIO_PUPD_NOPULL),

    gpio_mode_input_floating                    = (GPIO_MODE_INPUT | GPIO_PUPD_NOPULL),
    gpio_mode_input_pull_up                     = (GPIO_MODE_INPUT | GPIO_PUPD_UP),
    gpio_mode_input_pull_down                   = (GPIO_MODE_INPUT | GPIO_PUPD_DOWN),

    gpio_mode_output_push_pull                  = (GPIO_MODE_OUTPUT | GPIO_OTYPE_PP | GPIO_PUPD_NOPULL),
    gpio_mode_output_push_pull_up               = (GPIO_MODE_OUTPUT | GPIO_OTYPE_PP | GPIO_PUPD_UP),
    gpio_mode_output_push_pull_down             = (GPIO_MODE_OUTPUT | GPIO_OTYPE_PP | GPIO_PUPD_DOWN),

    gpio_mode_output_open_drain                 = (GPIO_MODE_OUTPUT | GPIO_OTYPE_OD | GPIO_PUPD_NOPULL),
    gpio_mode_output_open_drain_up              = (GPIO_MODE_OUTPUT | GPIO_OTYPE_OD | GPIO_PUPD_UP),
    gpio_mode_output_open_drain_down            = (GPIO_MODE_OUTPUT | GPIO_OTYPE_OD | GPIO_PUPD_DOWN),

    gpio_mode_output_alternate_push_pull        = (GPIO_MODE_ALTERNATE | GPIO_OTYPE_PP | GPIO_PUPD_NOPULL),
    gpio_mode_output_alternate_push_pull_up     = (GPIO_MODE_ALTERNATE | GPIO_OTYPE_PP | GPIO_PUPD_UP),
    gpio_mode_output_alternate_push_pull_down   = (GPIO_MODE_ALTERNATE | GPIO_OTYPE_PP | GPIO_PUPD_DOWN),

    gpio_mode_output_alternate_open_drain       = (GPIO_MODE_ALTERNATE | GPIO_OTYPE_OD | GPIO_PUPD_NOPULL),
    gpio_mode_output_alternate_open_drain_up    = (GPIO_MODE_ALTERNATE | GPIO_OTYPE_OD | GPIO_PUPD_UP),
    gpio_mode_output_alternate_open_drain_down  = (GPIO_MODE_ALTERNATE | GPIO_OTYPE_OD | GPIO_PUPD_DOWN),
};

enum gpio_status_e
{
    gpio_status_low,
    gpio_status_hight,
};

uint32_t gpio_init(HGPIO);
uint32_t gpio_set_mode(HGPIO, enum gpio_mode_e);
uint32_t gpio_set_status(HGPIO, enum gpio_status_e);
uint32_t gpio_toggle_status(HGPIO);

#ifdef __cplusplus
}
#endif

#endif