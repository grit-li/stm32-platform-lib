#include "hw_common.h"
#include "hw_usart.h"
#include "hal_usart.h"

uint32_t hal_usart_set_baud_rate(uint32_t usart, uint32_t pclk, uint32_t baud_rate)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    struct hw_usart_baud_rate_t baud_config = {
        .clk = pclk,
        .baud = baud_rate,
    };
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_disable);
    bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_BAUD_RATE, usart, (LPARAM)&baud_config);
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_enable);
    return bRet;
}
uint32_t hal_usart_set_word_length(uint32_t usart, enum hal_usart_word_length_e word_length)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_disable);
    switch(word_length) {
        case hal_usart_word_length_7bit:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_WORD_LENGTH, usart, hw_usart_word_length_7bit);
            break;
        case hal_usart_word_length_8bit:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_WORD_LENGTH, usart, hw_usart_word_length_8bit);
            break;
        case hal_usart_word_length_9bit:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_WORD_LENGTH, usart, hw_usart_word_length_9bit);
            break;
        default:
            break;
    }
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_enable);
    return bRet;

}
uint32_t hal_usart_set_parity(uint32_t usart)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_disable);
    // Parity None
    bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_PARITY_CONTROL, usart, hw_usart_parity_control_none);
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_enable);
    return bRet;
}
uint32_t hal_usart_set_mode(uint32_t usart)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_disable);
    bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_TRANSPORT_MODE, usart, hw_usart_transport_mode_rx_tx);
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_enable);
    return bRet;
}
uint32_t hal_usart_set_stop_bit(uint32_t usart, enum hal_usart_stop_bits_e stop_bits)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_disable);
    switch(stop_bits) {
        case hal_usart_stop_bits_0_5:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_STOP_BITS, usart, hw_usart_stop_bits_0_5);
            break;
        case hal_usart_stop_bits_1:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_STOP_BITS, usart, hw_usart_stop_bits_1);
            break;
        case hal_usart_stop_bits_1_5:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_STOP_BITS, usart, hw_usart_stop_bits_1_5);
            break;
        case hal_usart_stop_bits_2:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_STOP_BITS, usart, hw_usart_stop_bits_2);
            break;
        default:
            break;
    }
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_enable);
    return bRet;
}
uint32_t hal_usart_set_flow_control(uint32_t usart, enum hal_usart_flow_control_e control)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_disable);
    switch(control) {
        case hal_usart_flow_control_none:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_FLOW_CONTROL, usart, hw_usart_flow_control_none);
            break;
        case hal_usart_flow_control_rts:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_FLOW_CONTROL, usart, hw_usart_flow_control_rts);
            break;
        case hal_usart_flow_control_cts:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_FLOW_CONTROL, usart, hw_usart_flow_control_cts);
            break;
        case hal_usart_flow_control_rts_cts:
            bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_FLOW_CONTROL, usart, hw_usart_flow_control_rts_cts);
            break;
        default:
            break;
    }
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_enable);
    return bRet;
}
uint32_t hal_usart_transport_data(uint32_t usart, const uint8_t* data, uint32_t length)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    struct hw_usart_send_data_t buff = {
        .data = data,
        .size = length,
    };
    bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SEND_DATA, usart, (LPARAM)&buff);
    return bRet;
}
uint32_t hal_usart_receive_data(uint32_t usart, uint8_t* data, uint32_t length)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    struct hw_usart_recv_data_t buff = {
        .data = data,
        .size = length,
    };
    bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_RECV_DATA, usart, (LPARAM)&buff);
    return bRet;
}
int32_t hal_usart_receive_buffer(uint32_t usart)
{
    int32_t bRet = -1;
    hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_FETCH_DATA, usart, (LPARAM)&bRet);
    return bRet;
}

uint32_t hal_usart_set_enable(uint32_t usart)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    bRet = hw_platform_send_cmd(hw_platform_usart, HW_USART_CMD_SET_ENABLE, usart, hw_usart_enable);
    return bRet;
}
