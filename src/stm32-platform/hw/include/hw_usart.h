#ifndef __SETM32_PLATFORM_HW_USART_H__
#define __SETM32_PLATFORM_HW_USART_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum hw_usart_enable_e
{
    hw_usart_enable,
    hw_usart_disable,
};

enum hw_usart_word_length_e
{
    hw_usart_word_length_7bit,
    hw_usart_word_length_8bit,
    hw_usart_word_length_9bit,
};

enum hw_usart_stop_bits_e
{
    hw_usart_stop_bits_0_5,
    hw_usart_stop_bits_1,
    hw_usart_stop_bits_1_5,
    hw_usart_stop_bits_2,
};

enum hw_usart_flow_control_e
{
    hw_usart_flow_control_none,
    hw_usart_flow_control_rts,
    hw_usart_flow_control_cts,
    hw_usart_flow_control_rts_cts,
};


enum hw_usart_parity_control_e
{
    hw_usart_parity_control_none,
};

enum hw_usart_transport_mode_e
{
    hw_usart_transport_mode_rx_tx,
};
struct hw_usart_baud_rate_t
{
    uint32_t clk;
    uint32_t baud;
};
struct hw_usart_send_data_t
{
    uint8_t* data;
    uint32_t size;
};

struct hw_usart_recv_data_t
{
    uint8_t* data;
    uint32_t size;
};

enum hw_usart_cmd_e
{
    HW_USART_CMD_SET_ENABLE, /*< WPARAM: uint32_t, LPARAM: enum hw_usart_enable_e >*/
    HW_USART_CMD_GET_ENABLE, /*< WPARAM: uint32_t, LPARAM: enum hw_usart_enable_e * >*/

    HW_USART_CMD_SET_BAUD_RATE, /*< WPARAM: uint32_t, LPARAM: const struct hw_usart_baud_rate_t * >*/

    HW_USART_CMD_SET_WORD_LENGTH, /*< WPARAM: uint32_t, LPARAM: hw_usart_word_length_e >*/

    HW_USART_CMD_SET_PARITY_CONTROL, /*< WPARAM: uint32_t, LPARAM: enum hw_usart_parity_control_e >*/

    HW_USART_CMD_SET_TRANSPORT_MODE, /*< WPARAM: uint32_t, LPARAM: enum hw_usart_transport_mode_e >*/

    HW_USART_CMD_SET_STOP_BITS, /*< WPARAM: uint32_t, LPARAM: enum hw_usart_stop_bits_e >*/

    HW_USART_CMD_SET_FLOW_CONTROL, /*< WPARAM: uint32_t, LPARAM: enum hw_usart_flow_control_e >*/

    HW_USART_CMD_SEND_DATA, /*< WPARAM: uint32_t, LPARAM: const struct hw_usart_send_data_t * >*/

    HW_USART_CMD_RECV_DATA, /*< WPARAM: uint32_t, LPARAM: const struct hw_usart_recv_data_t * >*/

    HW_USART_CMD_FETCH_DATA, /*< WPARAM: uint32_t, LPARAM: int32_t * >*/

};

#ifdef __cplusplus
}
#endif

#endif
