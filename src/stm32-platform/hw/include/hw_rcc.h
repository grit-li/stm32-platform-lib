#ifndef __SETM32_PLATFORM_HW_RCC_H__
#define __SETM32_PLATFORM_HW_RCC_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum hw_rcc_clock_enable_e
{
    hw_rcc_clock_enable,
    hw_rcc_clock_disable,
};

enum hw_rcc_clock_source_e
{
    hw_rcc_clock_source_lse,
    hw_rcc_clock_source_lsi,
    hw_rcc_clock_source_msi,
    hw_rcc_clock_source_hsi,
    hw_rcc_clock_source_hse,
    hw_rcc_clock_source_pll,
};

enum hw_rcc_pll_clock_source_e
{
    hw_rcc_pll_clock_source_msi,
    hw_rcc_pll_clock_source_hsi,
    hw_rcc_pll_clock_source_hse,
};

enum hw_rcc_system_clock_source_e
{
    hw_rcc_system_clock_source_msi,
    hw_rcc_system_clock_source_hsi,
    hw_rcc_system_clock_source_hse,
    hw_rcc_system_clock_source_pllclk,
};

enum hw_rcc_usart_clock_source_e
{
    hw_rcc_usart_clock_source_pclk2,
    hw_rcc_usart_clock_source_sysclk,
    hw_rcc_usart_clock_source_hsi,
    hw_rcc_usart_clock_source_lse,
};

enum hw_rcc_peripheral_clock_enable_e
{   
    hw_rcc_peripheral_clock_usart1,
    hw_rcc_peripheral_clock_gpioa,
    hw_rcc_peripheral_clock_gpiob,
    hw_rcc_peripheral_clock_gpioc,
    hw_rcc_peripheral_clock_gpiod,
    hw_rcc_peripheral_clock_gpioe,
    hw_rcc_peripheral_clock_gpiof,
    hw_rcc_peripheral_clock_gpiog,
    hw_rcc_peripheral_clock_gpioh,
    hw_rcc_peripheral_clock_afio,
    hw_rcc_peripheral_clock_can1,
};

enum hw_rcc_prescaler_clock_e
{   
    hw_rcc_prescaler_clock_pll,
    hw_rcc_prescaler_clock_pllr,

    hw_rcc_prescaler_clock_ahb,
    hw_rcc_prescaler_clock_apb1,
    hw_rcc_prescaler_clock_apb2,
    hw_rcc_prescaler_clock_cortex,
};

enum hw_rcc_cmd_e
{
    HW_RCC_CMD_SET_CLOCK_FREQ, /*< WPARAM: enum hw_rcc_clock_source_e, LPARAM: uint32_t >*/

    HW_RCC_CMD_SET_CLOCK_ENABLE, /*< WPARAM: enum hw_rcc_clock_source_e, LPARAM: enum hw_rcc_clock_enable_e >*/
    HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE, /*< WPARAM: enum hw_rcc_peripheral_clock_enable_e, LPARAM: enum hw_rcc_clock_enable_e >*/

    HW_RCC_CMD_SET_PLL_CLOCK_SOURCE, /*< WPARAM: enum hw_rcc_pll_clock_source_e >*/
    HW_RCC_CMD_GET_PLL_CLOCK_SOURCE, /*< WPARAM: enum hw_rcc_pll_clock_source_e * >*/

    HW_RCC_CMD_SET_SYSTEM_CLOCK_SOURCE, /*< WPARAM: enum hw_rcc_system_clock_source_e >*/
    HW_RCC_CMD_GET_SYSTEM_CLOCK_SOURCE, /*< WPARAM: enum hw_rcc_system_clock_source_e * >*/

    HW_RCC_CMD_SET_USART_CLOCK_SOURCE, /*< WPARAM: enum hw_rcc_usart_clock_source_e >*/
    HW_RCC_CMD_GET_USART_CLOCK_SOURCE, /*< WPARAM: enum hw_rcc_usart_clock_source_e * >*/

    HW_RCC_CMD_SET_MASTER_CLOCK_ENABLE, /*< WPARAM: enum hw_rcc_clock_enable_e >*/

    HW_RCC_CMD_SET_FREQ_MULTIPLIER, /*< WPARAM: enum hw_rcc_clock_source_e, LPARAM: uint32_t >*/
    HW_RCC_CMD_SET_PRESCALER, /*< WPARAM: hw_rcc_prescaler_clock_e, LPARAM: uint32_t >*/

    HW_RCC_CMD_SET_FLASH_WAIT_TIME, /*< WPARAM: uint32_t >*/

};

#ifdef __cplusplus
}
#endif

#endif
