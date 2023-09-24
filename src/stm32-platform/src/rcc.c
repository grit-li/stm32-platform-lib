#include "hal/hal_rcc.h"
#include "stm32/rcc.h"
#include <stdio.h>
#include <string.h>

#define RCC_CLOCK_TREE(clock) (rcc_clock_tree[clock])

static uint32_t rcc_clock_tree[rcc_clock_tree_max] = {0};

static void rcc_print_clock_freq(enum rcc_clock_tree_e clock, const char* name)
{
    printf("[RCC][%2d][%25s] %8ldHz\n", clock, name, rcc_get_clock_freq(clock));
}

static inline void rcc_update_usart_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_usart_clock_source_e source, enum rcc_clock_tree_e clock)
{
    if(en) {
        switch(source) {
            case rcc_usart_clock_source_pclk2:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_apb2clk);
                break;
            case rcc_usart_clock_source_sysclk:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_sysclk);
                break;
            case rcc_usart_clock_source_hsi:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_hsi);
                break;
            case rcc_usart_clock_source_lse:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_lse);
                break;
            default:
                break;
        }
    }
}

static inline void rcc_update_lptim_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_lptim_clock_source_e source, enum rcc_clock_tree_e clock)
{
    if(en) {
        switch(source) {
            case rcc_lptim_clock_source_pclk1:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_apb1clk);
                break;
            case rcc_lptim_clock_source_lsi:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_lsi);
                break;
            case rcc_usart_clock_source_hsi:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_hsi);
                break;
            case rcc_usart_clock_source_lse:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_lse);
                break;
            default:
                break;
        }
    }
}

void rcc_clock_setup_init(const struct rcc_clock_scale_t* clock)
{
    hal_rcc_clock_init(hal_rcc_clock_source_lse, clock->lse);
    hal_rcc_clock_init(hal_rcc_clock_source_lsi, clock->lsi);
    hal_rcc_clock_init(hal_rcc_clock_source_msi, clock->msi);
    hal_rcc_clock_init(hal_rcc_clock_source_hsi, clock->hsi);
    hal_rcc_clock_init(hal_rcc_clock_source_hse, clock->hse);

    hal_rcc_pll_clock_select(clock->pll_source);
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
    memset(rcc_clock_tree, 0, rcc_clock_tree_max * sizeof(uint32_t));
    RCC_CLOCK_TREE(rcc_clock_lse) = clock->lse;
    RCC_CLOCK_TREE(rcc_clock_lsi) = clock->lsi;
    RCC_CLOCK_TREE(rcc_clock_msi) = clock->msi;
    RCC_CLOCK_TREE(rcc_clock_hsi) = clock->hsi;
    RCC_CLOCK_TREE(rcc_clock_hse) = clock->hse;

    switch(clock->pll_source)
    {
        case rcc_pll_clock_source_msi:
            RCC_CLOCK_TREE(rcc_clock_pllclk) = RCC_CLOCK_TREE(rcc_clock_msi);
            break;
        case rcc_pll_clock_source_hsi:
            RCC_CLOCK_TREE(rcc_clock_pllclk) = RCC_CLOCK_TREE(rcc_clock_hsi);
            break;
        case rcc_pll_clock_source_hse:
            RCC_CLOCK_TREE(rcc_clock_pllclk) = RCC_CLOCK_TREE(rcc_clock_hse);
            break;
    }
    RCC_CLOCK_TREE(rcc_clock_pllclk) = RCC_CLOCK_TREE(rcc_clock_pllclk) / clock->pllm_prescaler;

    RCC_CLOCK_TREE(rcc_clock_pllq) = RCC_CLOCK_TREE(rcc_clock_pllclk) * clock->pll_mul / clock->pllq_prescaler;
    RCC_CLOCK_TREE(rcc_clock_pllp) = RCC_CLOCK_TREE(rcc_clock_pllclk) * clock->pll_mul / clock->pllp_prescaler;

    RCC_CLOCK_TREE(rcc_clock_pllsai1r) = RCC_CLOCK_TREE(rcc_clock_pllclk) * clock->pllsai1_mul / clock->pllsai1r_prescaler;
    RCC_CLOCK_TREE(rcc_clock_pllsai1q) = RCC_CLOCK_TREE(rcc_clock_pllclk) * clock->pllsai1_mul / clock->pllsai1q_prescaler;
    RCC_CLOCK_TREE(rcc_clock_pllsai1p) = RCC_CLOCK_TREE(rcc_clock_pllclk) * clock->pllsai1_mul / clock->pllsai1p_prescaler;

    RCC_CLOCK_TREE(rcc_clock_pllsai2r) = RCC_CLOCK_TREE(rcc_clock_pllclk) * clock->pllsai2_mul / clock->pllsai2r_prescaler;
    RCC_CLOCK_TREE(rcc_clock_pllsai2p) = RCC_CLOCK_TREE(rcc_clock_pllclk) * clock->pllsai2_mul / clock->pllsai2p_prescaler;

    RCC_CLOCK_TREE(rcc_clock_pllclk) = RCC_CLOCK_TREE(rcc_clock_pllclk) * clock->pll_mul / clock->pllr_prescaler;

    switch(clock->system_clock_source)
    {
        case rcc_system_clock_source_msi:
            RCC_CLOCK_TREE(rcc_clock_sysclk) = RCC_CLOCK_TREE(rcc_clock_msi);
            break;
        case rcc_system_clock_source_hsi:
            RCC_CLOCK_TREE(rcc_clock_sysclk) = RCC_CLOCK_TREE(rcc_clock_hsi);
            break;
        case rcc_system_clock_source_hse:
            RCC_CLOCK_TREE(rcc_clock_sysclk) = RCC_CLOCK_TREE(rcc_clock_hse);
            break;
        case rcc_system_clock_source_pllclk:
            RCC_CLOCK_TREE(rcc_clock_sysclk) = RCC_CLOCK_TREE(rcc_clock_pllclk);
            break;
    }

    RCC_CLOCK_TREE(rcc_clock_hclk) = RCC_CLOCK_TREE(rcc_clock_sysclk) / clock->ahb_prescaler;

    RCC_CLOCK_TREE(rcc_clock_powerclk) = RCC_CLOCK_TREE(rcc_clock_hclk);
    RCC_CLOCK_TREE(rcc_clock_ahbclk) = RCC_CLOCK_TREE(rcc_clock_hclk);
    RCC_CLOCK_TREE(rcc_clock_coreclk) = RCC_CLOCK_TREE(rcc_clock_hclk);
    RCC_CLOCK_TREE(rcc_clock_memoryclk) = RCC_CLOCK_TREE(rcc_clock_hclk);
    RCC_CLOCK_TREE(rcc_clock_dmaclk) = RCC_CLOCK_TREE(rcc_clock_hclk);
    RCC_CLOCK_TREE(rcc_clock_systickclk) = RCC_CLOCK_TREE(rcc_clock_hclk) / clock->cortex_system_prescaler;
    RCC_CLOCK_TREE(rcc_clock_fclk) = RCC_CLOCK_TREE(rcc_clock_hclk);

    RCC_CLOCK_TREE(rcc_clock_apb1clk) = RCC_CLOCK_TREE(rcc_clock_hclk) / clock->apb1_prescaler;
    RCC_CLOCK_TREE(rcc_clock_apb2clk) = RCC_CLOCK_TREE(rcc_clock_hclk) / clock->apb2_prescaler;
    RCC_CLOCK_TREE(rcc_clock_apb1timerclk) = clock->apb1_prescaler == rcc_clock_prescaler_1 ? RCC_CLOCK_TREE(rcc_clock_apb1clk) : RCC_CLOCK_TREE(rcc_clock_apb1clk) << 1;
    RCC_CLOCK_TREE(rcc_clock_apb2timerclk) = clock->apb2_prescaler == rcc_clock_prescaler_1 ? RCC_CLOCK_TREE(rcc_clock_apb2clk) : RCC_CLOCK_TREE(rcc_clock_apb2clk) << 1;

    if(clock->clock_enable.RTCEN) {
        switch(clock->rtc_source) {
            case rcc_rtc_clock_source_hse_rtc:
                RCC_CLOCK_TREE(rcc_clock_rtcclk) = RCC_CLOCK_TREE(rcc_clock_hse) / 32;
                break;
            case rcc_rtc_clock_source_lse:
                RCC_CLOCK_TREE(rcc_clock_rtcclk) = RCC_CLOCK_TREE(rcc_clock_lse);
                break;
            case rcc_rtc_clock_source_lsi:
                RCC_CLOCK_TREE(rcc_clock_rtcclk) = RCC_CLOCK_TREE(rcc_clock_lsi);
                break;
            default:
                break;
        }
    }

    rcc_update_usart_clock(clock->clock_enable.USART1EN, clock->usart1_source, rcc_clock_usart1clk);
    rcc_update_usart_clock(clock->clock_enable.USART2EN, clock->usart2_source, rcc_clock_usart2clk);
    rcc_update_usart_clock(clock->clock_enable.USART3EN, clock->usart3_source, rcc_clock_usart3clk);
    rcc_update_usart_clock(clock->clock_enable.USART4EN, clock->usart4_source, rcc_clock_usart4clk);
    rcc_update_usart_clock(clock->clock_enable.USART5EN, clock->usart5_source, rcc_clock_usart5clk);
    rcc_update_usart_clock(clock->clock_enable.LPUSART1EN, clock->lpusart1_source, rcc_clock_lpusart1clk);
    rcc_update_lptim_clock(clock->clock_enable.LPTIM1EN, clock->lptime1_source, rcc_clock_lptim1clk);
    rcc_update_lptim_clock(clock->clock_enable.LPTIM2EN, clock->lptime2_source, rcc_clock_lptim2clk);

        // .SWPMI1EN = rcc_peripheral_clock_enable,
        // .MCOEN = rcc_peripheral_clock_enable,
        // .LSCOEN = rcc_peripheral_clock_enable,
        // .CLK48EN = rcc_peripheral_clock_enable,
        // .I2C1EN = rcc_peripheral_clock_enable,
        // .I2C2EN = rcc_peripheral_clock_enable,
        // .I2C3EN = rcc_peripheral_clock_enable,
        // .ADCEN = rcc_peripheral_clock_enable,
        // .SAI1EN = rcc_peripheral_clock_enable,
        // .SAI2EN = rcc_peripheral_clock_enable,
        // .DFSDM1EN = rcc_peripheral_clock_enable,

}

uint32_t rcc_get_clock_freq(enum rcc_clock_tree_e clock)
{
    if(clock >= rcc_clock_tree_max) return HZ(0);
    return RCC_CLOCK_TREE(clock);
}

void rcc_print_clock_tree(void)
{
    #define rcc_print_clock_freq_func(clk) rcc_print_clock_freq(clk, #clk)

    rcc_print_clock_freq_func(rcc_clock_lse);
    rcc_print_clock_freq_func(rcc_clock_lsi);
    rcc_print_clock_freq_func(rcc_clock_msi);
    rcc_print_clock_freq_func(rcc_clock_hsi);
    rcc_print_clock_freq_func(rcc_clock_hse);
    rcc_print_clock_freq_func(rcc_clock_pllclk);
    rcc_print_clock_freq_func(rcc_clock_pllq);
    rcc_print_clock_freq_func(rcc_clock_pllp);
    rcc_print_clock_freq_func(rcc_clock_pllsai1r);
    rcc_print_clock_freq_func(rcc_clock_pllsai1q);
    rcc_print_clock_freq_func(rcc_clock_pllsai1p);
    rcc_print_clock_freq_func(rcc_clock_pllsai2r);
    rcc_print_clock_freq_func(rcc_clock_pllsai2p);
    rcc_print_clock_freq_func(rcc_clock_sysclk);
    rcc_print_clock_freq_func(rcc_clock_hclk);
    rcc_print_clock_freq_func(rcc_clock_powerclk);
    rcc_print_clock_freq_func(rcc_clock_ahbclk);
    rcc_print_clock_freq_func(rcc_clock_coreclk);
    rcc_print_clock_freq_func(rcc_clock_memoryclk);
    rcc_print_clock_freq_func(rcc_clock_dmaclk);
    rcc_print_clock_freq_func(rcc_clock_systickclk);
    rcc_print_clock_freq_func(rcc_clock_fclk);
    rcc_print_clock_freq_func(rcc_clock_apb1clk);
    rcc_print_clock_freq_func(rcc_clock_apb2clk);
    rcc_print_clock_freq_func(rcc_clock_apb1timerclk);
    rcc_print_clock_freq_func(rcc_clock_apb2timerclk);
    rcc_print_clock_freq_func(rcc_clock_rtcclk);
    rcc_print_clock_freq_func(rcc_clock_usart1clk);
    rcc_print_clock_freq_func(rcc_clock_usart2clk);
    rcc_print_clock_freq_func(rcc_clock_usart3clk);
    rcc_print_clock_freq_func(rcc_clock_usart4clk);
    rcc_print_clock_freq_func(rcc_clock_usart5clk);
    rcc_print_clock_freq_func(rcc_clock_lpusart1clk);
    rcc_print_clock_freq_func(rcc_clock_lptim1clk);
    rcc_print_clock_freq_func(rcc_clock_lptim2clk);
}
