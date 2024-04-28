#ifndef __SETM32_PLATFORM_HAL_USART_H__
#define __SETM32_PLATFORM_HAL_USART_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum hal_usart_stop_bits_e
{
    hal_usart_stop_bits_0_5,
    hal_usart_stop_bits_1,
    hal_usart_stop_bits_1_5,
    hal_usart_stop_bits_2,
};

enum hal_usart_word_length_e
{
    hal_usart_word_length_7bit,
    hal_usart_word_length_8bit,
    hal_usart_word_length_9bit,
};

enum hal_usart_flow_control_e
{
    hal_usart_flow_control_none,
    hal_usart_flow_control_rts,
    hal_usart_flow_control_cts,
    hal_usart_flow_control_rts_cts,
};

uint32_t hal_usart_set_baud_rate(uint32_t usart, uint32_t pclk, uint32_t baud_rate);
uint32_t hal_usart_set_word_length(uint32_t usart, enum hal_usart_word_length_e word_length);
uint32_t hal_usart_set_parity(uint32_t usart);
uint32_t hal_usart_set_mode(uint32_t usart);
uint32_t hal_usart_set_stop_bit(uint32_t usart, enum hal_usart_stop_bits_e stop_bits);
uint32_t hal_usart_set_flow_control(uint32_t usart, enum hal_usart_flow_control_e control);
uint32_t hal_usart_transport_data(uint32_t usart, const uint8_t* data, uint32_t length);
uint32_t hal_usart_receive_data(uint32_t usart, uint8_t* data, uint32_t length);
int32_t hal_usart_receive_buffer(uint32_t usart);

uint32_t hal_usart_set_enable(uint32_t usart);

#ifdef __cplusplus
}
#endif

#endif
