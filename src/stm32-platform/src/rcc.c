#include "hal/hal_rcc.h"
#include "stm32/rcc.h"

#define RCC_CLOCK_TREE(clock) (rcc_clock_tree[clock])

static uint32_t rcc_clock_tree[rcc_clock_tree_max] = {0};

void rcc_clock_setup_init(const struct rcc_clock_scale_t* clock)
{
    hal_rcc_clock_init(hal_rcc_clock_source_lse, clock->lse);
    hal_rcc_clock_init(hal_rcc_clock_source_lsi, clock->lsi);
    hal_rcc_clock_init(hal_rcc_clock_source_msi, clock->msi);
    hal_rcc_clock_init(hal_rcc_clock_source_hsi, clock->hsi);
    hal_rcc_clock_init(hal_rcc_clock_source_hse, clock->hse);

    hal_rcc_pll_clock_select(rcc_pll_clock_source_hse);
    struct hal_rcc_pll_configure_t config;
    config.pll_mul = clock->pll_mul;
    config.pllm_prescaler = clock->pllm_prescaler;
    config.pllr_prescaler = clock->pllr_prescaler;
    config.pllq_prescaler = clock->pllq_prescaler;
    config.pllp_prescaler = clock->pllp_prescaler;
    hal_rcc_pll_clock_configure(&config);
    hal_rcc_system_clock_select(clock->system_clock_source);
    hal_rcc_usart_clock_select(hal_usart_type_1, clock->usart1_source);
    hal_rcc_gpio_clock_enable();
    hal_rcc_usart_clock_enable();
    rcc_update_clock_tree(clock);
}

void rcc_update_clock_tree(const struct rcc_clock_scale_t* clock)
{
}

uint32_t rcc_get_clock_freq(enum rcc_clock_tree_e clock)
{
    if(clock >= rcc_clock_tree_max) return HZ(0);
    return RCC_CLOCK_TREE(clock);
}
