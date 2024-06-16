#include "hal/hal_can.h"
#include "stm32/can.h"

uint32_t can_init(void)
{
    hal_can_init();
    return 0;
}
uint32_t can_send_data(const struct can_frame_t* data)
{
    return hal_can_send_data((const struct hal_can_frame_t *)data);

}
uint32_t can_recv_data(struct can_frame_t* data)
{
    return hal_can_recv_data((struct hal_can_frame_t *)data);
}
