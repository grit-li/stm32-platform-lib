#ifndef __SETM32_PLATFORM_HAL_CAN_H__
#define __SETM32_PLATFORM_HAL_CAN_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct hal_can_frame_t
{
    uint32_t ID;
    uint8_t IDE;
    uint8_t RTR;
    uint8_t DLC;
    uint8_t DATA[8];
};

uint32_t hal_can_init(void);
uint32_t hal_can_send_data(const struct hal_can_frame_t *);
uint32_t hal_can_recv_data(struct hal_can_frame_t *);

#ifdef __cplusplus
}
#endif

#endif
