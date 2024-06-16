#include "hw_common.h"
#include "hw_can.h"
#include "hal_can.h"

uint32_t hal_can_init(void)
{
    hw_platform_send_cmd(hw_platform_can, HW_CAN_CMD_INIT, 0, 0);
    return 0;
}
uint32_t hal_can_send_data(const struct hal_can_frame_t* data)
{
    struct hw_can_frame_t frame;
    frame.ID = data->ID;
    frame.IDE = data->IDE;
    frame.RTR = data->RTR;
    frame.DLC = data->DLC;
    for (int i = 0; i < data->DLC; i++) {
        frame.DATA[i] = data->DATA[i];
    }
    hw_platform_send_cmd(hw_platform_can, HW_CAN_CMD_SEND_CMD, (WPARAM)&frame, 0);
    return 0;
}

uint32_t hal_can_recv_data(struct hal_can_frame_t* data)
{
    struct hw_can_frame_t frame;
    hw_platform_send_cmd(hw_platform_can, HW_CAN_CMD_RECV_CMD, (WPARAM)&frame, 0);

    data->ID = frame.ID;
    data->IDE = frame.IDE;
    data->RTR = frame.RTR;
    data->DLC = frame.DLC;
    for (int i = 0; i < 8; i++) {
        data->DATA[i] = frame.DATA[i];
    }
    return 0;
}
