#ifndef __SETM32_PLATFORM_HAL_RCC_H__
#define __SETM32_PLATFORM_HAL_RCC_H__

#include <stdint.h>
#include "stm32/rcc.h"

#ifdef __cplusplus
extern "C" {
#endif

enum hal_rcc_clock_source_e
{
    hal_rcc_clock_source_lse,
    hal_rcc_clock_source_lsi,
    hal_rcc_clock_source_msi,
    hal_rcc_clock_source_hsi,
    hal_rcc_clock_source_hse,
};

enum hal_usart_type_e
{
    hal_usart_type_1,
    hal_usart_type_2,
    hal_usart_type_3,
};

struct hal_rcc_pll_configure_t
{
    enum rcc_pll_mul_e pll_mul;
    enum rcc_clock_prescaler_e pllm_prescaler;
    enum rcc_clock_prescaler_e pllr_prescaler;
    enum rcc_clock_prescaler_e pllq_prescaler;
    enum rcc_clock_prescaler_e pllp_prescaler;
};

uint32_t hal_rcc_clock_init(enum hal_rcc_clock_source_e clock, uint32_t speed);
uint32_t hal_rcc_pll_clock_select(enum rcc_pll_clock_source_e source);
uint32_t hal_rcc_pll_clock_configure(const struct hal_rcc_pll_configure_t* config);
uint32_t hal_rcc_system_clock_select(enum rcc_system_clock_source_e source);
uint32_t hal_rcc_usart_clock_select(enum hal_usart_type_e usart, enum rcc_usart_clock_source_e source);
uint32_t hal_rcc_gpio_clock_enable(void);
uint32_t hal_rcc_usart_clock_enable(void);

#ifdef __cplusplus
}
#endif

#endif