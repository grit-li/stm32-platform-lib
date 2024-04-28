#ifndef __SETM32_PLATFORM_HAL_RCC_H__
#define __SETM32_PLATFORM_HAL_RCC_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum hal_rcc_clock_enable_e
{
    hal_rcc_clock_usart1,
    hal_rcc_clock_gpioa,
    hal_rcc_clock_gpiob,
    hal_rcc_clock_gpioc,
    hal_rcc_clock_gpiod,
    hal_rcc_clock_gpioe,
    hal_rcc_clock_gpiof,
    hal_rcc_clock_gpiog,
    hal_rcc_clock_gpioh,
    hal_rcc_clock_afio,
    hal_rcc_clock_can1,
};

enum hal_rcc_clock_source_e
{
    hal_rcc_clock_source_lse,
    hal_rcc_clock_source_lsi,
    hal_rcc_clock_source_msi,
    hal_rcc_clock_source_hsi,
    hal_rcc_clock_source_hse,
};

enum hal_rcc_pll_clock_source_e
{
    hal_rcc_pll_clock_source_msi,
    hal_rcc_pll_clock_source_hsi,
    hal_rcc_pll_clock_source_hse,
};

enum hal_rcc_system_clock_source_e
{
    hal_rcc_system_clock_source_msi,
    hal_rcc_system_clock_source_hsi,
    hal_rcc_system_clock_source_hse,
    hal_rcc_system_clock_source_pllclk,
};

enum hal_rcc_usart_clock_source_e
{
    hal_rcc_usart_clock_source_pclk2,
    hal_rcc_usart_clock_source_sysclk,
    hal_rcc_usart_clock_source_hsi,
    hal_rcc_usart_clock_source_lse,
};

enum hal_rcc_usart_type_e
{
    hal_rcc_usart_type_1,
    hal_rcc_usart_type_2,
    hal_rcc_usart_type_3,
};

struct hal_rcc_pll_clock_configure_t
{
    enum hal_rcc_pll_clock_source_e source;
    uint32_t pll_mul;
    uint32_t pll_prescaler;
    uint32_t pllr_prescaler;
    uint32_t pllq_prescaler;
    uint32_t pllp_prescaler;
    uint32_t flash_wait_time;    
};

struct hal_rcc_system_clock_configure_t
{
    enum hal_rcc_system_clock_source_e source;
    uint32_t ahb_prescaler;
    uint32_t apb1_prescaler;
    uint32_t apb2_prescaler;
    uint32_t cortex_system_prescaler;
    uint32_t apb1_timer_mul;
    uint32_t apb2_timer_mul;
};

struct hal_rcc_usart_clock_configure_t
{
    enum hal_rcc_usart_type_e usart;
    enum hal_rcc_usart_clock_source_e source;
};

int32_t hal_rcc_clock_init(enum hal_rcc_clock_source_e, uint32_t);
int32_t hal_rcc_pll_clock_init(const struct hal_rcc_pll_clock_configure_t *);
int32_t hal_rcc_system_clock_init(const struct hal_rcc_system_clock_configure_t *);
int32_t hal_rcc_usart_clock_init(const struct hal_rcc_usart_clock_configure_t *);
int32_t hal_rcc_clock_enable(    enum hal_rcc_clock_enable_e);
int32_t hal_rcc_clock_disable(enum hal_rcc_clock_enable_e);

#ifdef __cplusplus
}
#endif

#endif
