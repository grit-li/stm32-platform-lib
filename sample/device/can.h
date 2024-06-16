#ifndef __SETM32_DEVICE_CAN_H__
#define __SETM32_DEVICE_CAN_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct can_device_msg_t
{
    uint32_t id;
    uint8_t ide;
    uint8_t rtr;
    uint8_t size;
    uint8_t data[8];
};

void can_device_init(void);
void can_device_send(const struct can_device_msg_t *);
void can_device_recv(struct can_device_msg_t *, uint32_t);

#ifdef __cplusplus
}
#endif

#endif