#include "Config.h"
#include "can.h"
#include "stm32/can.h"
#include "stm32/gpio.h"
#include "stm32/interrupt_vector_table.h"

static const struct gpio_init_t can_tx_config = {
    .group = CAN_TX_GPIO_GROUP,
    .port = CAN_TX_GPIO_PORT,
    .mode = gpio_mode_alternate_push_pull,
    .alternate = gpio_alternate_invalid,
    .speed = gpio_speed_very_high,
    .status = gpio_status_low,
};
static const struct gpio_init_t can_rx_config = {
    .group = CAN_RX_GPIO_GROUP,
    .port = CAN_RX_GPIO_PORT,
    .mode = gpio_mode_input_pull_up,
    .alternate = gpio_alternate_invalid,
    .speed = gpio_speed_very_high,
    .status = gpio_status_high,
};

struct can_frame_t mCandata;

static void irq_can0_handler(void)
{
    can_recv_data(&mCandata);
}

void can_device_init(void)
{
    gpio_init(&can_tx_config);
    gpio_init(&can_rx_config);

    irq_set_priority(irq_vector_type_can1_rx0, irq_preempt_priority_0, irq_sub_priority_0);
    irq_register_handler(irq_vector_type_can1_rx0, irq_can0_handler);
    irq_enable(irq_vector_type_can1_rx0);

    can_init();
}

void can_device_send(const struct can_device_msg_t* msg)
{
    struct can_frame_t can_data;
    can_data.ID = msg->id;
    can_data.IDE = msg->ide;
    can_data.RTR = msg->rtr;
    can_data.DLC = msg->size;
    for (int i = 0; i < 8; i++) {
        can_data.DATA[i] = msg->data[i];
    }
    can_send_data(&can_data);
}
void can_device_recv(struct can_device_msg_t* msg, uint32_t size)
{

}