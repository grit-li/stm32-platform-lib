#include <stdio.h>
#include "hw/hw_usart.h"
#include "hal_usart.h"


#define USART_BRR_MIN    0x10U        /* USART BRR minimum authorized value */
#define USART_BRR_MAX    0xFFFFU      /* USART BRR maximum authorized value */
#define USART_DIV_SAMPLING16(__PCLK__, __BAUD__) (((__PCLK__) + ((__BAUD__)/2U)) / (__BAUD__))

static struct USART_TypeDef* hal_usart_get_register(enum usart_type_e type)
{
    struct USART_TypeDef* bRet = NULL;
    switch(type) {
        case usart_type_1: bRet = __GET_USART_REGISTER__(USART1); break;
        case usart_type_2: bRet = __GET_USART_REGISTER__(USART2); break;
        case usart_type_3: bRet = __GET_USART_REGISTER__(USART3); break;
        default: break;
    }
    return bRet;
}

uint32_t hal_usart_set_baud_rate(enum usart_type_e type, enum usart_baud_e baud_rate)
{
    struct USART_TypeDef* USARTx = hal_usart_get_register(type);
    uint32_t usartdiv = 0x00000000;
    uint16_t brrtemp;

    if(!USARTx) {
        return stm32_errcode_param_error;
    }
    hw_usart_set_disable(USARTx);
    usartdiv = USART_DIV_SAMPLING16(80 * 1000 * 1000, baud_rate);
    if((usartdiv >= USART_BRR_MIN) && (usartdiv <= USART_BRR_MAX)) {
        brrtemp = (uint16_t)(usartdiv & 0xFFF0U);
        brrtemp |= (uint16_t)((usartdiv & (uint16_t)0x000FU) >> 1U);
        hw_usart_set_baud_rate(USARTx, brrtemp);
    }
    hw_usart_set_enable(USARTx);
    return stm32_errcode_success;
}

uint32_t hal_usart_set_word_length(enum usart_type_e type, enum usart_word_length_e word_length)
{
    struct USART_TypeDef* USARTx = hal_usart_get_register(type);

    if(!USARTx) {
        return stm32_errcode_param_error;
    }
    hw_usart_set_disable(USARTx);
    switch(word_length) {
        case usart_word_length_7bit:
            hw_usart_set_m0(USARTx, 0);
            hw_usart_set_m1(USARTx, USART_CR1_M1);
            break;
        case usart_word_length_8bit:
            hw_usart_set_m0(USARTx, 0);
            hw_usart_set_m1(USARTx, 0);
            break;
        case usart_word_length_9bit:
            hw_usart_set_m0(USARTx, USART_CR1_M0);
            hw_usart_set_m1(USARTx, 0);
            break;
        default:
            break;
    }
    hw_usart_set_enable(USARTx);
    return stm32_errcode_success;  
}

uint32_t hal_usart_set_parity(enum usart_type_e type)
{
    struct USART_TypeDef* USARTx = hal_usart_get_register(type);

    if(!USARTx) {
        return stm32_errcode_param_error;
    }
    hw_usart_set_disable(USARTx);
    // Parity None
    hw_usart_set_parity_control_disable(USARTx);
    hw_usart_set_enable(USARTx);
    return stm32_errcode_success;  
}

uint32_t hal_usart_set_mode(enum usart_type_e type)
{
    struct USART_TypeDef* USARTx = hal_usart_get_register(type);

    if(!USARTx) {
        return stm32_errcode_param_error;
    }
    hw_usart_set_disable(USARTx);
    hw_usart_set_receiver_enable(USARTx);
    hw_usart_set_transmitter_enable(USARTx);
    hw_usart_set_enable(USARTx);
    return stm32_errcode_success;  
}

uint32_t hal_usart_set_stop_bit(enum usart_type_e type, enum usart_stop_bits_e stop_bits)
{
    struct USART_TypeDef* USARTx = hal_usart_get_register(type);

    if(!USARTx) {
        return stm32_errcode_param_error;
    }
    hw_usart_set_disable(USARTx);
    switch(stop_bits) {
        case usart_stop_bits_0_5:
            hw_usart_set_stop_bit(USARTx, USART_CR2_STOP_0_5);
            break;
        case usart_stop_bits_1:
            hw_usart_set_stop_bit(USARTx, USART_CR2_STOP_1);
            break;
        case usart_stop_bits_1_5:
            hw_usart_set_stop_bit(USARTx, USART_CR2_STOP_1_5);
            break;
        case usart_stop_bits_2:
            hw_usart_set_stop_bit(USARTx, USART_CR2_STOP_2);
            break;
        default:
            break;
    }
    hw_usart_set_enable(USARTx);
    return stm32_errcode_success;  
}

uint32_t hal_usart_set_flow_control(enum usart_type_e type, enum usart_flow_control_e control)
{
    struct USART_TypeDef* USARTx = hal_usart_get_register(type);

    if(!USARTx) {
        return stm32_errcode_param_error;
    }
    hw_usart_set_disable(USARTx);
    switch(control) {
        case usart_flow_control_none:
            hw_usart_set_cts_disable(USARTx);
            hw_usart_set_rts_disable(USARTx);
            break;
        case usart_flow_control_rts:
            hw_usart_set_cts_disable(USARTx);
            hw_usart_set_rts_enable(USARTx);
            break;
        case usart_flow_control_cts:
            hw_usart_set_cts_enable(USARTx);
            hw_usart_set_rts_disable(USARTx);
            break;
        case usart_flow_control_rts_cts:
            hw_usart_set_cts_enable(USARTx);
            hw_usart_set_rts_enable(USARTx);
            break;
        default:
            break;
    }
    hw_usart_set_enable(USARTx);
    return stm32_errcode_success;  
}

uint32_t hal_usart_send_data(enum usart_type_e type, const uint8_t* data, uint32_t length)
{
    struct USART_TypeDef* USARTx = hal_usart_get_register(type);

    if(!USARTx) {
        return stm32_errcode_param_error;
    }
    for(uint32_t i = 0; i < length; i++) {
        while(hw_usart_transmit_data_register_empty_flag(USARTx) != USART_ISR_TXE);
        hw_usart_transmit_data(USARTx, data[i]);
    }
    return stm32_errcode_success;  
}

uint32_t hal_usart_set_enable(enum usart_type_e type)
{
    struct USART_TypeDef* USARTx = hal_usart_get_register(type);

    if(!USARTx) {
        return stm32_errcode_param_error;
    }
    hw_usart_set_enable(USARTx);
    return stm32_errcode_success;  
}