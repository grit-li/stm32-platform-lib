#include "hw_usart.h"
#include "stm32_assert.h"

void hw_usart_set_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_UE);
}

void hw_usart_set_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_UE);
}

uint32_t hw_usart_get_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_UE);
}

void hw_usart_set_stop_mode_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_UESM);
}

void hw_usart_set_stop_mode_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_UESM);
}

uint32_t hw_usart_get_stop_mode_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_UESM);
}

void hw_usart_set_receiver_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_RE);
}

void hw_usart_set_receiver_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_RE);
}

uint32_t hw_usart_get_receiver_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_RE);
}

void hw_usart_set_transmitter_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_TE);
}

void hw_usart_set_transmitter_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_TE);
}

uint32_t hw_usart_get_transmitter_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_TE);
}

void hw_usart_set_idle_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_IDLEIE);
}

void hw_usart_set_idle_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_IDLEIE);
}

uint32_t hw_usart_get_idle_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_IDLEIE);
}

void hw_usart_set_m1(struct USART_TypeDef* USARTx, uint32_t m1)
{
    __BIT_COVER_SET__(__GET_USART_CR1__(USARTx), USART_CR1_M0, m1);
}

uint32_t hw_usart_get_m1(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_M1);
}

void hw_usart_set_end_of_block_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_EOBIE);
}

void hw_usart_set_end_of_block_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_EOBIE);
}

uint32_t hw_usart_get_end_of_block_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_EOBIE);
}

void hw_usart_set_receiver_timeout_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_RTOIE);
}

void hw_usart_set_receiver_timeout_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_RTOIE);
}

uint32_t hw_usart_get_receiver_timeout_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_RTOIE);
}

void hw_usart_set_driver_enable_assertion_time(struct USART_TypeDef* USARTx, uint32_t time)
{
    __BIT_COVER_SET__(__GET_USART_CR1__(USARTx), USART_CR1_DEAT, time);
}

uint32_t hw_usart_get_driver_enable_assertion_time(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_DEAT);
}

void hw_usart_set_driver_enable_de_assertion_time(struct USART_TypeDef* USARTx, uint32_t time)
{
    __BIT_COVER_SET__(__GET_USART_CR1__(USARTx), USART_CR1_DEDT, time);
}

uint32_t hw_usart_get_driver_enable_de_assertion_time(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_DEDT);
}

void hw_usart_set_oversampling_mode(struct USART_TypeDef* USARTx, uint32_t mode)
{
    __BIT_COVER_SET__(__GET_USART_CR1__(USARTx), USART_CR1_OVER8, mode);
}

uint32_t hw_usart_get_oversampling_mode(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_OVER8);
}

void hw_usart_set_character_match_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_CMIE);
}

void hw_usart_set_character_match_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_CMIE);
}

uint32_t hw_usart_get_character_match_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_CMIE);
}

void hw_usart_set_mute_mode_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_MME);
}

void hw_usart_set_mute_mode_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_MME);
}

uint32_t hw_usart_get_mute_mode_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_MME);
}

void hw_usart_set_m0(struct USART_TypeDef* USARTx, uint32_t m0)
{
    __BIT_COVER_SET__(__GET_USART_CR1__(USARTx), USART_CR1_M0, m0);
}

uint32_t hw_usart_get_m0(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_M0);
}

void hw_usart_set_receiver_wakeup_method(struct USART_TypeDef* USARTx, uint32_t method)
{
    __BIT_COVER_SET__(__GET_USART_CR1__(USARTx), USART_CR1_WAKE, method);
}

uint32_t hw_usart_receiver_wakeup_method(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_WAKE);
}

void hw_usart_set_parity_control_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_PCE);
}

void hw_usart_set_parity_control_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_PCE);
}

uint32_t hw_usart_get_parity_control_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_PCE);
}

void hw_usart_parity_selection(struct USART_TypeDef* USARTx, uint32_t parity)
{
    __BIT_COVER_SET__(__GET_USART_CR1__(USARTx), USART_CR1_PS, parity);
}

uint32_t hw_usart_parity(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_PS);
}

void hw_usart_set_pe_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_PEIE);
}

void hw_usart_set_pe_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_PEIE);
}

uint32_t hw_usart_get_pe_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_PEIE);
}

void hw_usart_set_transmission_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_TXEIE);
}

void hw_usart_set_transmission_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_TXEIE);
}

uint32_t hw_usart_get_transmission_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_TXEIE);
}

void hw_usart_set_transmission_complete_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_TCIE);
}

void hw_usart_set_transmission_complete_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_TCIE);
}

uint32_t hw_usart_get_transmission_complete_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_TCIE);
}

void hw_usart_set_rxne_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR1__(USARTx), USART_CR1_RXNEIE);
}

void hw_usart_set_rxne_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR1__(USARTx), USART_CR1_RXNEIE);
}

uint32_t hw_usart_get_rxne_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR1__(USARTx) & USART_CR1_RXNEIE);
}

void hw_usart_set_address_of_node(struct USART_TypeDef* USARTx, uint32_t node)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_ADD, node);
}

uint32_t hw_usart_get_address_of_node(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_ADD);
}

void hw_usart_set_receiver_timeout_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR2__(USARTx), USART_CR2_RTOEN);
}

void hw_usart_set_receiver_timeout_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR2__(USARTx), USART_CR2_RTOEN);
}

uint32_t hw_usart_get_receiver_timeout_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_RTOEN);
}

void hw_usart_set_auto_baud_rate_mode(struct USART_TypeDef* USARTx, uint32_t mode)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_ABRMODE, mode);
}

uint32_t hw_usart_get_auto_baud_rate_mode(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_ABRMODE);
}

void hw_usart_set_auto_baud_rate_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR2__(USARTx), USART_CR2_ABREN);
}

void hw_usart_set_auto_baud_rate_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR2__(USARTx), USART_CR2_ABREN);
}

uint32_t hw_usart_get_auto_baud_rate_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_ABREN);
}

void hw_usart_set_most_significant_bit_first(struct USART_TypeDef* USARTx, uint32_t bit)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_MSBFIRST, bit);
}

uint32_t hw_usart_get_most_significant_bit_first(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_MSBFIRST);
}

void hw_usart_set_binary_data_inversion(struct USART_TypeDef* USARTx, uint32_t inversion)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_DATAINV, inversion);
}

uint32_t hw_usart_get_binary_data_inversion(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_DATAINV);
}

void hw_usart_set_tx_pin_active_level_inversion(struct USART_TypeDef* USARTx, uint32_t inversion)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_TXINV, inversion);
}

uint32_t hw_usart_get_tx_pin_active_level_inversion(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_TXINV);
}

void hw_usart_set_rx_pin_active_level_inversion(struct USART_TypeDef* USARTx, uint32_t inversion)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_RXINV, inversion);
}

uint32_t hw_usart_get_rx_pin_active_level_inversion(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_RXINV);
}

void hw_usart_set_swap_rx_tx(struct USART_TypeDef* USARTx, uint32_t swap)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_SWAP, swap);
}

uint32_t hw_usart_get_swap_rx_tx(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_SWAP);
}

void hw_usart_set_lin_mode_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR2__(USARTx), USART_CR2_LINEN);
}

void hw_usart_set_lin_mode_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR2__(USARTx), USART_CR2_LINEN);
}

uint32_t hw_usart_get_lin_mode_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_LINEN);
}

void hw_usart_set_stop_bit(struct USART_TypeDef* USARTx, uint32_t stop_bit)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_STOP, stop_bit);
}

uint32_t hw_usart_get_stop_bit(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_STOP);
}

void hw_usart_set_clock_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR2__(USARTx), USART_CR2_CLKEN);
}

void hw_usart_set_clock_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR2__(USARTx), USART_CR2_CLKEN);
}

uint32_t hw_usart_get_clock_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_CLKEN);
}

void hw_usart_set_clock_polarity(struct USART_TypeDef* USARTx, uint32_t polarity)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_CPOL, polarity);
}

uint32_t hw_usart_get_clock_polarity(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_CPOL);
}

void hw_usart_set_clock_phase(struct USART_TypeDef* USARTx, uint32_t phase)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_CPHA, phase);
}

uint32_t hw_usart_get_clock_phase(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_CPHA);
}

void hw_usart_set_last_bit_clock_pulse(struct USART_TypeDef* USARTx, uint32_t pulse)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_LBCL, pulse);
}

uint32_t hw_usart_get_last_bit_clock_pulse(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_LBCL);
}

void hw_usart_set_lin_break_detection_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR2__(USARTx), USART_CR2_LBDIE);
}

void hw_usart_set_lin_break_detection_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR2__(USARTx), USART_CR2_LBDIE);
}

uint32_t hw_usart_get_lin_break_detection_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_LBDIE);
}

void hw_usart_set_lin_break_detection_length(struct USART_TypeDef* USARTx, uint32_t length)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_LBDL, length);
}

uint32_t hw_usart_get_lin_break_detection_length(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_LBDL);
}

void hw_usart_set_address_detection_mode(struct USART_TypeDef* USARTx, uint32_t mode)
{
    __BIT_COVER_SET__(__GET_USART_CR2__(USARTx), USART_CR2_ADDM7, mode);
}

uint32_t hw_usart_get_address_detection_mode(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR2__(USARTx) & USART_CR2_ADDM7);
}

void hw_usart_set_clock_enable_in_stop_mode(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_UCESM);
}

void hw_usart_set_clock_disable_in_stop_mode(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_UCESM);
}

uint32_t hw_usart_get_clock_enable_in_stop_mode(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_UCESM);
}

void hw_usart_set_wakeup_from_stop_mode_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_WUFIE);
}

void hw_usart_set_wakeup_from_stop_mode_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_WUFIE);
}

uint32_t hw_usart_get_wakeup_from_stop_mode_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_WUFIE);
}

void hw_usart_set_wakeup_from_stop_mode_interrupt_flag(struct USART_TypeDef* USARTx, uint32_t flag)
{
    __BIT_COVER_SET__(__GET_USART_CR3__(USARTx), USART_CR3_WUS, flag);
}

uint32_t hw_usart_get_wakeup_from_stop_mode_interrupt_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_WUS);
}

void hw_usart_set_smartcard_auto_retry_count(struct USART_TypeDef* USARTx, uint32_t count)
{
    __BIT_COVER_SET__(__GET_USART_CR3__(USARTx), USART_CR3_SCARCNT, count);
}

uint32_t hw_usart_get_smartcard_auto_retry_count(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_SCARCNT);
}

void hw_usart_set_driver_enable_polarity(struct USART_TypeDef* USARTx, uint32_t mode)
{
    __BIT_COVER_SET__(__GET_USART_CR3__(USARTx), USART_CR3_DEP, mode);
}

uint32_t hw_usart_get_driver_enable_polarity(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_DEP);
}

void hw_usart_set_de_mode_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_DEM);
}

void hw_usart_set_de_mode_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_DEM);
}

uint32_t hw_usart_get_de_mode_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_DEM);
}

void hw_usart_set_dma_disable_on_reception_error(struct USART_TypeDef* USARTx, uint32_t mode)
{
    __BIT_COVER_SET__(__GET_USART_CR3__(USARTx), USART_CR3_DDRE, mode);
}

uint32_t hw_usart_get_dma_disable_on_reception_error(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_DDRE);
}

void hw_usart_set_overrun_disable(struct USART_TypeDef* USARTx, uint32_t mode)
{
    __BIT_COVER_SET__(__GET_USART_CR3__(USARTx), USART_CR3_OVRDIS, mode);
}

uint32_t hw_usart_get_overrun_disable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_OVRDIS);
}

void hw_usart_set_sample_bit_method(struct USART_TypeDef* USARTx, uint32_t method)
{
    __BIT_COVER_SET__(__GET_USART_CR3__(USARTx), USART_CR3_ONEBIT, method);
}

uint32_t hw_usart_get_sample_bit_method(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_ONEBIT);
}

void hw_usart_set_cts_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_CTSIE);
}

void hw_usart_set_cts_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_CTSIE);
}

uint32_t hw_usart_get_cts_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_CTSIE);
}

void hw_usart_set_cts_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_CTSE);
}

void hw_usart_set_cts_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_CTSE);
}

uint32_t hw_usart_get_cts_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_CTSE);
}

void hw_usart_set_rts_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_RTSE);
}

void hw_usart_set_rts_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_RTSE);
}

uint32_t hw_usart_get_rts_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_RTSE);
}

void hw_usart_set_dma_transmitter_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_DMAT);
}

void hw_usart_set_dma_transmitter_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_DMAT);
}

uint32_t hw_usart_get_dma_transmitter_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_DMAT);
}

void hw_usart_set_dma_receiver_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_DMAR);
}

void hw_usart_set_dma_receiver_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_DMAR);
}

uint32_t hw_usart_get_dma_receiver_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_DMAR);
}

void hw_usart_set_smartcard_mode_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_SCEN);
}

void hw_usart_set_smartcard_mode_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_SCEN);
}

uint32_t hw_usart_get_smartcard_mode_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_SCEN);
}

void hw_usart_set_smartcard_nack_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_NACK);
}

void hw_usart_set_smartcard_nack_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_NACK);
}

uint32_t hw_usart_get_smartcard_nack_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_NACK);
}

void hw_usart_set_half_duplex_mode(struct USART_TypeDef* USARTx, uint32_t mode)
{
    __BIT_COVER_SET__(__GET_USART_CR3__(USARTx), USART_CR3_HDSEL, mode);
}

uint32_t hw_usart_get_half_duplex_mode(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_HDSEL);
}

void hw_usart_set_irda_mode(struct USART_TypeDef* USARTx, uint32_t mode)
{
    __BIT_COVER_SET__(__GET_USART_CR3__(USARTx), USART_CR3_IRLP, mode);
}

uint32_t hw_usart_get_irda_mode(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_IRLP);
}

void hw_usart_set_irda_mode_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_IREN);
}

void hw_usart_set_irda_mode_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_IREN);
}

uint32_t hw_usart_get_irda_mode_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_IREN);
}

void hw_usart_set_error_interrupt_enable(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_CR3__(USARTx), USART_CR3_EIE);
}

void hw_usart_set_error_interrupt_disable(struct USART_TypeDef* USARTx)
{
    __BIT_RESET__(__GET_USART_CR3__(USARTx), USART_CR3_EIE);
}

uint32_t hw_usart_get_error_interrupt_enable(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_CR3__(USARTx) & USART_CR3_EIE);
}

void hw_usart_set_baud_rate(struct USART_TypeDef* USARTx, uint32_t baud_rate)
{
    __BIT_COVER_SET__(__GET_USART_BRR__(USARTx), USART_BRR_BRR, baud_rate);
}

uint32_t hw_usart_get_baud_rate(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_BRR__(USARTx) & USART_BRR_BRR);
}

void hw_usart_set_guard_time(struct USART_TypeDef* USARTx, uint16_t time)
{
    __BIT_COVER_SET__(__GET_USART_GTPR__(USARTx), USART_GTPR_GT, time);
}

uint32_t hw_usart_get_guard_time(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_GTPR__(USARTx) & USART_GTPR_GT);
}

void hw_usart_set_prescaler_value(struct USART_TypeDef* USARTx, uint16_t prescaler)
{
    __BIT_COVER_SET__(__GET_USART_GTPR__(USARTx), USART_GTPR_PSC, prescaler);
}

uint32_t hw_usart_get_prescaler_value(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_GTPR__(USARTx) & USART_GTPR_PSC);
}

void hw_usart_set_block_length(struct USART_TypeDef* USARTx, uint16_t length)
{
    __BIT_COVER_SET__(__GET_USART_RTOR__(USARTx), USART_RTOR_BLEN, length);
}

uint32_t hw_usart_get_block_length(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_RTOR__(USARTx) & USART_RTOR_BLEN);
}

void hw_usart_set_receiver_timeout_value(struct USART_TypeDef* USARTx, uint16_t timeout)
{
    __BIT_COVER_SET__(__GET_USART_RTOR__(USARTx), USART_RTOR_RTO, timeout);
}

uint32_t hw_usart_get_receiver_timeout_value(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_RTOR__(USARTx) & USART_RTOR_RTO);
}

void hw_usart_set_auto_baud_rate_request(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_RQR__(USARTx), USART_RQR_ABRRQ);
}

void hw_usart_set_send_break_request(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_RQR__(USARTx), USART_RQR_SBKRQ);
}

void hw_usart_set_mute_mode_request(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_RQR__(USARTx), USART_RQR_MMRQ);
}

void hw_usart_set_receive_data_flush_request(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_RQR__(USARTx), USART_RQR_RXFRQ);
}

void hw_usart_set_transmit_data_flush_request(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_RQR__(USARTx), USART_RQR_TXFRQ);
}

uint32_t hw_usart_parity_error_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_PE);
}

uint32_t hw_usart_framing_error_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_FE);
}

uint32_t hw_usart_start_bit_noise_detection_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_NE);
}

uint32_t hw_usart_overrun_error_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_ORE);
}

uint32_t hw_usart_idle_line_detected_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_IDLE);
}

uint32_t hw_usart_read_data_register_not_empty_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_RXNE);
}

uint32_t hw_usart_transmission_complete_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_TC);
}

uint32_t hw_usart_transmit_data_register_empty_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_TXE);
}

uint32_t hw_usart_lin_break_detection_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_LBDF);
}

uint32_t hw_usart_cts_interrupt_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_CTSIF);
}

uint32_t hw_usart_cts_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_CTS);
}

uint32_t hw_usart_receiver_timeout_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_RTOF);
}

uint32_t hw_usart_end_of_block_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_EOBF);
}

uint32_t hw_usart_auto_baud_rate_error_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_ABRE);
}

uint32_t hw_usart_auto_baud_rate_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_ABRF);
}

uint32_t hw_usart_busy_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_BUSY);
}

uint32_t hw_usart_character_match_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_CMF);
}

uint32_t hw_usart_send_break_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_SBKF);
}

uint32_t hw_usart_receiver_wakeup_from_mute_mode_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_RWU);
}

uint32_t hw_usart_wakeup_from_stop_mode_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_WUF);
}

uint32_t hw_usart_transmit_enable_acknowledge_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_TEACK);
}

uint32_t hw_usart_receive_enable_acknowledge_flag(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_ISR__(USARTx) & USART_ISR_REACK);
}

void hw_usart_clear_wakeup_from_stop_mode_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_WUCF);
}

void hw_usart_clear_character_match_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_CMCF);
}

void hw_usart_clear_end_of_block_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_EOBCF);
}

void hw_usart_clear_receiver_timeout_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_RTOCF);
}

void hw_usart_clear_cts_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_CTSCF);
}

void hw_usart_clear_lin_break_detection_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_LBDCF);
}

void hw_usart_clear_transmission_complete_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_TCCF);
}

void hw_usart_clear_idle_line_detected_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_IDLECF);
}

void hw_usart_clear_overrun_error_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_ORECF);
}

void hw_usart_clear_noise_detected_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_NCF);
}

void hw_usart_clear_framing_error_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_FECF);
}

void hw_usart_clear_parity_error_flag(struct USART_TypeDef* USARTx)
{
    __BIT_OR__(__GET_USART_ICR__(USARTx), USART_ICR_PECF);
}

uint8_t hw_usart_receive_data(struct USART_TypeDef* USARTx)
{
    return (__GET_USART_RDR__(USARTx) & USART_RDR_RDR);
}

void hw_usart_transmit_data(struct USART_TypeDef* USARTx, const uint8_t data)
{
    __BIT_SET__(__GET_USART_TDR__(USARTx), data);
}