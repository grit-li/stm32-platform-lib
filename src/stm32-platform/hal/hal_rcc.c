#include "hw_common.h"
#include "hw_rcc.h"
#include "hal_rcc.h"

static int32_t clock_init(enum hal_rcc_clock_source_e source, uint32_t speed)
{
    switch(source) {
        case hal_rcc_clock_source_lse:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_FREQ, hw_rcc_clock_source_lse, speed);
            break;
        case hal_rcc_clock_source_lsi:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_FREQ, hw_rcc_clock_source_lsi, speed);
            break;
        case hal_rcc_clock_source_msi:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_FREQ, hw_rcc_clock_source_msi, speed);
            break;
        case hal_rcc_clock_source_hsi:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_FREQ, hw_rcc_clock_source_hsi, speed);
            break;
        case hal_rcc_clock_source_hse:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_FREQ, hw_rcc_clock_source_hse, speed);
            break;
        default:
            break;
    }
    return hw_platform_errcode_success;
}

static int32_t clock_deinit(enum hal_rcc_clock_source_e clock)
{
    switch(clock) {
        case hal_rcc_clock_source_lse:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_ENABLE, hw_rcc_clock_source_lse, hw_rcc_clock_disable);
            break;
        case hal_rcc_clock_source_lsi:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_ENABLE, hw_rcc_clock_source_lsi, hw_rcc_clock_disable);
            break;
        case hal_rcc_clock_source_msi:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_ENABLE, hw_rcc_clock_source_msi, hw_rcc_clock_disable);
            break;
        case hal_rcc_clock_source_hsi:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_ENABLE, hw_rcc_clock_source_hsi, hw_rcc_clock_disable);
            break;
        case hal_rcc_clock_source_hse:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_ENABLE, hw_rcc_clock_source_hse, hw_rcc_clock_disable);
            break;
        default:
            break;
    }
    return hw_platform_errcode_success;
}

int32_t hal_rcc_clock_init(enum hal_rcc_clock_source_e source, uint32_t speed)
{
    return (speed != 0) ? clock_init(source, speed) : clock_deinit(source);
}
int32_t hal_rcc_pll_clock_init(const struct hal_rcc_pll_clock_configure_t* config)
{
    switch(config->source) {
        case hal_rcc_pll_clock_source_msi: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PLL_CLOCK_SOURCE, hw_rcc_pll_clock_source_msi, 0); break;
        case hal_rcc_pll_clock_source_hsi: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PLL_CLOCK_SOURCE, hw_rcc_pll_clock_source_hsi, 0); break;
        case hal_rcc_pll_clock_source_hse: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PLL_CLOCK_SOURCE, hw_rcc_pll_clock_source_hse, 0); break;
        default: break;
    }
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_ENABLE, hw_rcc_clock_source_pll, hw_rcc_clock_disable);
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PRESCALER, hw_rcc_prescaler_clock_pll, config->pll_prescaler);
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_FREQ_MULTIPLIER, hw_rcc_clock_source_pll, config->pll_mul);
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PRESCALER, hw_rcc_prescaler_clock_pllr, config->pllr_prescaler);
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_MASTER_CLOCK_ENABLE, hw_rcc_clock_enable, 0);
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_CLOCK_FREQ, hw_rcc_clock_source_pll, 0);
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_FLASH_WAIT_TIME, config->flash_wait_time, 0);
    return hw_platform_errcode_success;
}
int32_t hal_rcc_system_clock_init(const struct hal_rcc_system_clock_configure_t* config)
{
    switch(config->source) {
        case hal_rcc_system_clock_source_msi: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_SYSTEM_CLOCK_SOURCE, hw_rcc_system_clock_source_msi, 0); break;
        case hal_rcc_system_clock_source_hsi: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_SYSTEM_CLOCK_SOURCE, hw_rcc_system_clock_source_hsi, 0); break;
        case hal_rcc_system_clock_source_hse: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_SYSTEM_CLOCK_SOURCE, hw_rcc_system_clock_source_hse, 0); break;
        case hal_rcc_system_clock_source_pllclk: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_SYSTEM_CLOCK_SOURCE, hw_rcc_system_clock_source_pllclk, 0); break;
        default:
            break;
    }

    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PRESCALER, hw_rcc_prescaler_clock_ahb, config->ahb_prescaler);
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PRESCALER, hw_rcc_prescaler_clock_apb1, config->apb1_prescaler);
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PRESCALER, hw_rcc_prescaler_clock_apb2, config->apb2_prescaler);
    hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PRESCALER, hw_rcc_prescaler_clock_cortex, config->cortex_system_prescaler);
    return hw_platform_errcode_success;

}
int32_t hal_rcc_usart_clock_init(const struct hal_rcc_usart_clock_configure_t* config)
{
    switch(config->usart) {
        case hal_rcc_usart_type_1:
            hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_USART_CLOCK_SOURCE, config->source, 0);
            break;
        default:
            break;
    }
    return hw_platform_errcode_success;
}
int32_t hal_rcc_clock_enable(enum hal_rcc_clock_enable_e clock)
{
    switch(clock) {
        case hal_rcc_clock_usart1: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_usart1, hw_rcc_clock_enable); break;
        case hal_rcc_clock_gpioa: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpioa, hw_rcc_clock_enable); break;
        case hal_rcc_clock_gpiob: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpiob, hw_rcc_clock_enable); break;
        case hal_rcc_clock_gpioc: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpioc, hw_rcc_clock_enable); break;
        case hal_rcc_clock_gpiod: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpiod, hw_rcc_clock_enable); break;
        case hal_rcc_clock_gpioe: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpioe, hw_rcc_clock_enable); break;
        case hal_rcc_clock_gpiof: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpiof, hw_rcc_clock_enable); break;
        case hal_rcc_clock_gpiog: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpiog, hw_rcc_clock_enable); break;
        case hal_rcc_clock_gpioh: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpioh, hw_rcc_clock_enable); break;
        case hal_rcc_clock_afio:  hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_afio, hw_rcc_clock_enable); break;
        case hal_rcc_clock_can1:  hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_can1, hw_rcc_clock_enable); break;
   }
    return hw_platform_errcode_success;
}
int32_t hal_rcc_clock_disable(enum hal_rcc_clock_enable_e clock)
{
     switch(clock) {
         case hal_rcc_clock_usart1: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_usart1, hw_rcc_clock_disable); break;
         case hal_rcc_clock_gpioa: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpioa, hw_rcc_clock_disable); break;
         case hal_rcc_clock_gpiob: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpiob, hw_rcc_clock_disable); break;
         case hal_rcc_clock_gpioc: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpioc, hw_rcc_clock_disable); break;
         case hal_rcc_clock_gpiod: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpiod, hw_rcc_clock_disable); break;
         case hal_rcc_clock_gpioe: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpioe, hw_rcc_clock_disable); break;
         case hal_rcc_clock_gpiof: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpiof, hw_rcc_clock_disable); break;
         case hal_rcc_clock_gpiog: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpiog, hw_rcc_clock_disable); break;
         case hal_rcc_clock_gpioh: hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_gpioh, hw_rcc_clock_disable); break;
         case hal_rcc_clock_afio:  hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_afio, hw_rcc_clock_disable); break;
         case hal_rcc_clock_can1:  hw_platform_send_cmd(hw_platform_rcc, HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, hw_rcc_peripheral_clock_can1, hw_rcc_clock_disable); break;
    }
    return hw_platform_errcode_success;
}
