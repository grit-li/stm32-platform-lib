#ifndef __SETM32_PLATFORM_HAL_USART_H__
#define __SETM32_PLATFORM_HAL_USART_H__

#include <stdint.h>
#include "stm32/usart.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t hal_usart_set_baud_rate(enum usart_type_e type, enum usart_baud_e baud_rate);
uint32_t hal_usart_set_word_length(enum usart_type_e type, enum usart_word_length_e word_length);
uint32_t hal_usart_set_parity(enum usart_type_e type);
uint32_t hal_usart_set_mode(enum usart_type_e type);
uint32_t hal_usart_set_stop_bit(enum usart_type_e type, enum usart_stop_bits_e stop_bits);
uint32_t hal_usart_set_flow_control(enum usart_type_e type, enum usart_flow_control_e control);
uint32_t hal_usart_transport_data(enum usart_type_e type, const uint8_t* data, uint32_t length);
uint32_t hal_usart_receive_data(enum usart_type_e type, uint8_t* data, uint32_t length);
uint8_t hal_usart_receive_buffer(enum usart_type_e type);

uint32_t hal_usart_set_enable(enum usart_type_e type);

#ifdef __cplusplus
}
#endif

#endif