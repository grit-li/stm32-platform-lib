#include <stdint.h>
#include <stdio.h>
#include <rtthread.h>
#include <syslog.h>

#include "led.h"
#include "can.h"
#include "stm32/rcc.h"

static struct can_device_msg_t can_send_msg =
{
    .id = 0x01,
    .ide = 0,
    .rtr = 0,
    .data = {
        0xAB,
        0xCD,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
    },
    .size = 2,
};

static struct can_device_msg_t can_recv_msg;

int main(void)
{
    led_init();
    can_device_init();
    rcc_print_clock_tree();
    while(1)
    {
        led_toggle();
        can_send_msg.ide = 0;
        can_send_msg.rtr = 0;
        can_device_send(&can_send_msg);
        rt_thread_mdelay(500);
        can_send_msg.ide = 1;
        can_send_msg.rtr = 0;
        can_device_send(&can_send_msg);
        rt_thread_mdelay(500);
        can_send_msg.ide = 0;
        can_send_msg.rtr = 1;
        can_device_send(&can_send_msg);
        rt_thread_mdelay(500);
        can_send_msg.ide = 1;
        can_send_msg.rtr = 1;
        can_device_send(&can_send_msg);
        rt_thread_mdelay(500);
    }
    
    return 0;
}
