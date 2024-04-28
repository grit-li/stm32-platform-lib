#ifndef __SETM32_PLATFORM_HW_CAN_H__
#define __SETM32_PLATFORM_HW_CAN_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct hw_can_frame_t
{
    uint32_t id;
    uint8_t IDE;
    uint8_t RTR;
    uint8_t FMI;
    uint8_t DLC;
    uint8_t DATA[8];
};

enum hw_can_cmd_e
{
    HW_CAN_CMD_SET_PROP,
    HW_CAN_CMD_GET_PROP,
    HW_CAN_CMD_SEND_CMD, /*< WPARAM: const struct hw_can_frame_t * */
    HW_CAN_CMD_RECV_CMD, /*< WPARAM: const struct hw_can_frame_t * */
};

#ifdef __cplusplus
}
#endif

#endif
