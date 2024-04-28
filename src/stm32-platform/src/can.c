#include "hal/hal_can.h"
#include "stm32/can.h"

HCAN can_init(const struct can_init_t* init)
{
    if(!init) {
        return HCAN_NULL;
    }
    HCAN hcan = 1;
    hal_can_init(0);
    return hcan;
}
uint32_t can_send_data(HCAN hcan, const struct can_frame_t* data)
{
    return hal_can_send_data(data->id, data->IDE, data->DLC, data->DATA);
}
uint32_t can_recv_data(HCAN hcan, struct can_frame_t* data, uint32_t len)
{
    return hal_can_recv_data(&data->id, &data->IDE, &data->DLC, data->DATA);
}

