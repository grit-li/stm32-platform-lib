#include "hw_common.h"
#include "hw_can.h"
#include "hal_can.h"

uint32_t hal_can_init(uint32_t mode)
{
    hw_platform_send_cmd(hw_platform_can, HW_CAN_CMD_SET_PROP, 0, 0);
    return 0;
}
uint32_t hal_can_send_data(uint32_t id, uint8_t IDE, uint8_t DLC, const uint8_t* DATA)
{
    struct hw_can_frame_t frame;
    frame.id = id;
    frame.IDE = IDE;
    frame.DLC = DLC;
    for (int i = 0; i < 8; i++) {
        frame.DATA[i] = DATA[i];
    }
    hw_platform_send_cmd(hw_platform_can, HW_CAN_CMD_SEND_CMD, (WPARAM)&frame, 0);
    return 0;
}

uint32_t hal_can_recv_data(uint32_t* id, uint8_t* IDE, uint8_t* DLC, uint8_t* DATA)
{
    struct hw_can_frame_t frame;
    hw_platform_send_cmd(hw_platform_can, HW_CAN_CMD_RECV_CMD, (WPARAM)&frame, 0);

    *id = frame.id;
    *IDE = frame.IDE;
    *DLC = frame.DLC;
    for (int i = 0; i < 8; i++) {
        DATA[i] = frame.DATA[i];
    }
    return 0;
}
