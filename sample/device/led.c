#include "Config.h"
#include "led.h"
#include "stm32/gpio.h"

static const struct gpio_init_t led_config = {
    .group = LED_GPIO_GROUP,
    .port = LED_GPIO_PORT,
    .mode = gpio_mode_output_push_pull,
    .alternate = gpio_alternate_invalid,
    .speed = gpio_speed_very_high,
    .status = gpio_status_high,
};

static HGPIO hled = HGPIO_NULL;

static inline void LED(HGPIO h, int n)
{
	n ? gpio_set_status(h, gpio_status_low) : gpio_set_status(h, gpio_status_high);
}

void led_init(void)
{
    hled = gpio_init(&led_config);
}

void led_toggle(void)
{
    static unsigned char color = 0;
    if(color++ % 2 == 0) {
        LED(hled, 0);
    } else {
        LED(hled, 1);
    }
}
