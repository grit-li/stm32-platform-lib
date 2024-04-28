#ifndef __SETM32_PLATFORM_CAN_H__
#define __SETM32_PLATFORM_CAN_H__

#include <stdint.h>
#include <stm32_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t HCAN;
#define HCAN_NULL ((HCAN)0xffffffff)

struct can_init_t
{
    uint8_t mode;
};

struct can_frame_t
{
    uint32_t id;
    uint8_t IDE;
    uint8_t DLC;
    uint8_t DATA[8];
};
HCAN can_init(const struct can_init_t *);
uint32_t can_send_data(HCAN, const struct can_frame_t *);
uint32_t can_recv_data(HCAN, struct can_frame_t *, uint32_t);

#ifdef __cplusplus
}
#endif

#endif