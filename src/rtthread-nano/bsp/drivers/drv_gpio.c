/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2017-11-20     DQL               the first version
 * 2018-08-16     Tanek             add IO function description
 * 2019-06-28     SummerGift        update to the latest version
 */

#include <rtdevice.h>
#include "drv_gpio.h"

static void stm32_pin_write(rt_device_t dev, rt_base_t pin, rt_base_t value)
{
}

static int stm32_pin_read(rt_device_t dev, rt_base_t pin)
{
    return 0;
}

static void stm32_pin_mode(rt_device_t dev, rt_base_t pin, rt_base_t mode)
{
}

static rt_err_t stm32_pin_attach_irq(struct rt_device *device, rt_int32_t pin,
                                     rt_uint32_t mode, void (*hdr)(void *args), void *args)
{
    return RT_EOK;
}

static rt_err_t stm32_pin_dettach_irq(struct rt_device *device, rt_int32_t pin)
{
    return RT_EOK;
}

static rt_err_t stm32_pin_irq_enable(struct rt_device *device, rt_base_t pin,
                                     rt_uint32_t enabled)
{

    return RT_EOK;
}
const static struct rt_pin_ops _stm32_pin_ops =
{
    stm32_pin_mode,
    stm32_pin_write,
    stm32_pin_read,
    stm32_pin_attach_irq,
    stm32_pin_dettach_irq,
    stm32_pin_irq_enable,
};

int rt_hw_pin_init(void)
{
    return rt_device_pin_register("pin", &_stm32_pin_ops, RT_NULL);
}

