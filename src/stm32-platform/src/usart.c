#include "hal/hal_usart.h"
#include "stm32/usart.h"

uint32_t usart_init(const struct usart_init_t* init)
{
    if(!init) {
        return stm32_errcode_param_error;
    }

    hal_usart_set_baud_rate(init->type, init->baud);
    hal_usart_set_word_length(init->type, init->word_length);
    hal_usart_set_parity(init->type);
    hal_usart_set_mode(init->type);
    hal_usart_set_stop_bit(init->type, init->stop_bits);
    hal_usart_set_flow_control(init->type, init->flow_control);
    hal_usart_set_enable(init->type);
    return stm32_errcode_success;
}

uint32_t usart_deinit(enum usart_type_e type)
{
    return stm32_errcode_success;
}

uint32_t usart_transport_data(enum usart_type_e type, const uint8_t* data, uint32_t length)
{
    return hal_usart_transport_data(type, data, length);
}

uint32_t usart_receive_data(enum usart_type_e type, uint8_t* data, uint32_t length)
{
    return hal_usart_receive_data(type, data, length);
}

int32_t usart_receive_buffer(enum usart_type_e type)
{
    return hal_usart_receive_buffer(type);
}