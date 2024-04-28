#include <stdio.h>
#include <string.h>
#include "hal/hal_rcc.h"
#include "stm32/rcc.h"

#define RCC_CLOCK_TREE(clock) (rcc_clock_tree[clock])

static uint32_t rcc_clock_tree[rcc_clock_tree_max] = {0};

static void rcc_print_clock_freq(enum rcc_clock_tree_e clock, const char* name)
{
    printf("[RCC][%2d][%25s] %8ldHz\n", clock, name, rcc_get_clock_freq(clock));
}

static inline void rcc_update_pll_clock(const struct rcc_pll_clock_scale_t* clock)
{
    switch(clock->pll_source)
    {
        case rcc_pll_clock_source_msi:
            RCC_CLOCK_TREE(rcc_clock_pll) = RCC_CLOCK_TREE(rcc_clock_msi);
            break;
        case rcc_pll_clock_source_hsi:
            RCC_CLOCK_TREE(rcc_clock_pll) = RCC_CLOCK_TREE(rcc_clock_hsi);
            break;
        case rcc_pll_clock_source_hse:
            RCC_CLOCK_TREE(rcc_clock_pll) = RCC_CLOCK_TREE(rcc_clock_hse);
            break;
    }
    RCC_CLOCK_TREE(rcc_clock_pll) = RCC_CLOCK_TREE(rcc_clock_pll) / clock->pll_prescaler;
    RCC_CLOCK_TREE(rcc_clock_pllq) = RCC_CLOCK_TREE(rcc_clock_pll) * clock->pll_mul / clock->pllq_prescaler;
    RCC_CLOCK_TREE(rcc_clock_pllp) = RCC_CLOCK_TREE(rcc_clock_pll) * clock->pll_mul / clock->pllp_prescaler;

    RCC_CLOCK_TREE(rcc_clock_pllsai1r) = RCC_CLOCK_TREE(rcc_clock_pll) * clock->pllsai1_mul / clock->pllsai1r_prescaler;
    RCC_CLOCK_TREE(rcc_clock_pllsai1q) = RCC_CLOCK_TREE(rcc_clock_pll) * clock->pllsai1_mul / clock->pllsai1q_prescaler;
    RCC_CLOCK_TREE(rcc_clock_pllsai1p) = RCC_CLOCK_TREE(rcc_clock_pll) * clock->pllsai1_mul / clock->pllsai1p_prescaler;

    RCC_CLOCK_TREE(rcc_clock_pllsai2r) = RCC_CLOCK_TREE(rcc_clock_pll) * clock->pllsai2_mul / clock->pllsai2r_prescaler;
    RCC_CLOCK_TREE(rcc_clock_pllsai2p) = RCC_CLOCK_TREE(rcc_clock_pll) * clock->pllsai2_mul / clock->pllsai2p_prescaler;

    RCC_CLOCK_TREE(rcc_clock_pll) = RCC_CLOCK_TREE(rcc_clock_pll) * clock->pll_mul / clock->pllr_prescaler;
}

static inline void rcc_update_rtc_clock(enum rcc_peripheral_clock_enable_e en, const struct rcc_rtc_clock_scale_t* clock)
{
    if(en) {
        switch(clock->rtc_source) {
            case rcc_rtc_clock_source_hse:
                RCC_CLOCK_TREE(rcc_clock_rtcclk) = RCC_CLOCK_TREE(rcc_clock_hse) / clock->hse_prescaler;
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
}
static inline void rcc_update_system_clock(const struct rcc_system_clock_scale_t* clock)
{
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
            RCC_CLOCK_TREE(rcc_clock_sysclk) = RCC_CLOCK_TREE(rcc_clock_pll);
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
    RCC_CLOCK_TREE(rcc_clock_apb1timerclk) = RCC_CLOCK_TREE(rcc_clock_apb1clk) * clock->apb1_timer_mul;
    RCC_CLOCK_TREE(rcc_clock_apb2timerclk) = RCC_CLOCK_TREE(rcc_clock_apb2clk) * clock->apb2_timer_mul;
}

static inline void rcc_update_mco_clock(enum rcc_peripheral_clock_enable_e en, const struct rcc_mco_clock_scale_t* clock)
{
    if(en) {
        switch(clock->mco_source) {
            case rcc_mco_clock_source_lse:
                RCC_CLOCK_TREE(rcc_clock_mco) = RCC_CLOCK_TREE(rcc_clock_lse);
                break;
            case rcc_mco_clock_source_lsi:
                RCC_CLOCK_TREE(rcc_clock_mco) = RCC_CLOCK_TREE(rcc_clock_lsi);
                break;
            case rcc_mco_clock_source_hse:
                RCC_CLOCK_TREE(rcc_clock_mco) = RCC_CLOCK_TREE(rcc_clock_hse);
                break;
            case rcc_mco_clock_source_hsi:
                RCC_CLOCK_TREE(rcc_clock_mco) = RCC_CLOCK_TREE(rcc_clock_hsi);
                break;
            case rcc_mco_clock_source_pllclk:
                RCC_CLOCK_TREE(rcc_clock_mco) = RCC_CLOCK_TREE(rcc_clock_pll);
                break;
            case rcc_mco_clock_source_sysclk:
                RCC_CLOCK_TREE(rcc_clock_mco) = RCC_CLOCK_TREE(rcc_clock_sysclk);
                break;
            case rcc_mco_clock_source_msi:
                RCC_CLOCK_TREE(rcc_clock_mco) = RCC_CLOCK_TREE(rcc_clock_msi);
                break;
            default:
                break;
        }
        RCC_CLOCK_TREE(rcc_clock_mco) = RCC_CLOCK_TREE(rcc_clock_mco) / clock->mco_prescaler;
    }
}

static inline void rcc_update_clk48_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_clk48_source_e source)
{
    if(en) {
        switch(source) {
            case rcc_clk48_source_pllsai1q:
                RCC_CLOCK_TREE(rcc_clock_clk48) = RCC_CLOCK_TREE(rcc_clock_pllsai1q);
                break;
            case rcc_clk48_source_pllq:
                RCC_CLOCK_TREE(rcc_clock_clk48) = RCC_CLOCK_TREE(rcc_clock_pllq);
                break;
            case rcc_clk48_source_msi:
                RCC_CLOCK_TREE(rcc_clock_clk48) = RCC_CLOCK_TREE(rcc_clock_msi);
                break;
            default:
                break;
        }
    }
}

static inline void rcc_update_adc_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_adc_clock_source_e source, enum rcc_clock_tree_e clock)
{
    if(en) {
        switch(source) {
            case rcc_adc_clock_source_pllsai1r:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_pllsai1r);
                break;
            case rcc_adc_clock_source_pllsai2r:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_pllsai2r);
                break;
            case rcc_adc_clock_source_sysclk:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_sysclk);
                break;
            default:
                break;
        }
    }
}

static inline void rcc_update_sai_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_sai_clock_source_e source, enum rcc_clock_tree_e clock)
{
    if(en) {
        switch(source) {
            case rcc_sai_clock_source_pllsai1p:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_pllsai1r);
                break;
            case rcc_sai_clock_source_pllsai2p:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_pllsai2r);
                break;
            case rcc_sai_clock_source_pllp:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_sysclk);
                break;
            case rcc_sai_clock_source_ext_sai1:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_extern_sai1);
                break;
            case rcc_sai_clock_source_ext_sai2:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_extern_sai2);
                break;
            default:
                break;
        }
    }
}

static inline void rcc_update_i2c_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_i2c_clock_source_e source, enum rcc_clock_tree_e clock)
{
    if(en) {
        switch(source) {
            case rcc_i2c_clock_source_apb1:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_apb1clk);
                break;
            case rcc_i2c_clock_source_sysclk:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_sysclk);
                break;
            case rcc_i2c_clock_source_hsi:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_hsi);
                break;
            default:
                break;
        }
    }
}
static inline void rcc_update_dfsdm_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_dfsdm_clock_source_e source, enum rcc_clock_tree_e clock)
{
    if(en) {
        switch(source) {
            case rcc_dfsdm_clock_source_apb2:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_apb2clk);
                break;
            case rcc_dfsdm_clock_source_sysclk:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_sysclk);
                break;
            default:
                break;
        }
    }
}

static inline void rcc_update_usart_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_usart_clock_source_e source, enum rcc_clock_tree_e clock)
{
    if(en) {
        switch(source) {
            case rcc_usart_clock_source_apb2:
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
            case rcc_lptim_clock_source_apb1:
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

static inline void rcc_update_swpmi_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_swpmi_clock_source_e source, enum rcc_clock_tree_e clock)
{
    if(en) {
        switch(source) {
            case rcc_swpmi_clock_source_apb1:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_apb1clk);
                break;
            case rcc_swpmi_clock_source_hsi:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_hsi);
                break;
            default:
                break;
        }
    }
}

static inline void rcc_update_lsco_clock(enum rcc_peripheral_clock_enable_e en, enum rcc_lsco_clock_source_e source, enum rcc_clock_tree_e clock)
{
    if(en) {
        switch(source) {
            case rcc_lsco_clock_source_lse:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_lse);
                break;
            case rcc_lsco_clock_source_lsi:
                RCC_CLOCK_TREE(clock) = RCC_CLOCK_TREE(rcc_clock_lsi);
                break;
            default:
                break;
        }
    }
}

static void rcc_update_clock_tree(const struct rcc_clock_scale_t* clock)
{
    memset(rcc_clock_tree, 0, rcc_clock_tree_max * sizeof(uint32_t));
    RCC_CLOCK_TREE(rcc_clock_lse) = clock->lse;
    RCC_CLOCK_TREE(rcc_clock_lsi) = clock->lsi;
    RCC_CLOCK_TREE(rcc_clock_msi) = clock->msi;
    RCC_CLOCK_TREE(rcc_clock_hsi) = clock->hsi;
    RCC_CLOCK_TREE(rcc_clock_hse) = clock->hse;
    RCC_CLOCK_TREE(rcc_clock_extern_sai1) = clock->extern_clock.sai1;
    RCC_CLOCK_TREE(rcc_clock_extern_sai2) = clock->extern_clock.sai2;

    rcc_update_pll_clock(&clock->pll_clock);
    rcc_update_rtc_clock(clock->clock_enable.RTCEN, &clock->rtc_clock);
    rcc_update_system_clock(&clock->system_clock);
    rcc_update_mco_clock(clock->clock_enable.MCOEN, &clock->mco_clock);
    rcc_update_clk48_clock(clock->clock_enable.CLK48EN, clock->clk48_source);
    rcc_update_adc_clock(clock->clock_enable.ADC1EN, clock->adc1_source, rcc_clock_adc1);
    rcc_update_adc_clock(clock->clock_enable.ADC2EN, clock->adc2_source, rcc_clock_adc2);
    rcc_update_adc_clock(clock->clock_enable.ADC3EN, clock->adc3_source, rcc_clock_adc3);
    rcc_update_sai_clock(clock->clock_enable.SAI1EN, clock->sai1_source, rcc_clock_sai1);
    rcc_update_sai_clock(clock->clock_enable.SAI2EN, clock->sai2_source, rcc_clock_sai2);
    rcc_update_i2c_clock(clock->clock_enable.I2C1EN, clock->i2c1_source, rcc_clock_i2c1);
    rcc_update_i2c_clock(clock->clock_enable.I2C2EN, clock->i2c2_source, rcc_clock_i2c2);
    rcc_update_i2c_clock(clock->clock_enable.I2C3EN, clock->i2c3_source, rcc_clock_i2c3);
    rcc_update_dfsdm_clock(clock->clock_enable.DFSDM1EN, clock->dfsdm1_source, rcc_clock_dfsdm1);
    rcc_update_usart_clock(clock->clock_enable.USART1EN, clock->usart1_source, rcc_clock_usart1clk);
    rcc_update_usart_clock(clock->clock_enable.USART2EN, clock->usart2_source, rcc_clock_usart2clk);
    rcc_update_usart_clock(clock->clock_enable.USART3EN, clock->usart3_source, rcc_clock_usart3clk);
    rcc_update_usart_clock(clock->clock_enable.USART4EN, clock->usart4_source, rcc_clock_usart4clk);
    rcc_update_usart_clock(clock->clock_enable.USART5EN, clock->usart5_source, rcc_clock_usart5clk);
    rcc_update_usart_clock(clock->clock_enable.LPUSART1EN, clock->lpusart1_source, rcc_clock_lpusart1clk);
    rcc_update_lptim_clock(clock->clock_enable.LPTIM1EN, clock->lptime1_source, rcc_clock_lptim1clk);
    rcc_update_lptim_clock(clock->clock_enable.LPTIM2EN, clock->lptime2_source, rcc_clock_lptim2clk);
    rcc_update_swpmi_clock(clock->clock_enable.SWPMI1EN, clock->swpmi1_source, rcc_clock_swpmi1);
    rcc_update_lsco_clock(clock->clock_enable.LSCOEN, clock->lsco_source, rcc_clock_lsco);
}

static inline void rcc_pll_clock_init(const struct rcc_pll_clock_scale_t* clock)
{
    struct hal_rcc_pll_clock_configure_t config;
    config.source = clock->pll_source;
    config.pll_mul = clock->pll_mul;
    config.pll_prescaler = clock->pll_prescaler;
    config.pllr_prescaler = clock->pllr_prescaler;
    config.pllq_prescaler = clock->pllq_prescaler;
    config.pllp_prescaler = clock->pllp_prescaler;
    config.flash_wait_time = clock->wait_cycle;
    hal_rcc_pll_clock_init(&config);
}
static inline void rcc_system_clock_init(const struct rcc_system_clock_scale_t* clock)
{
    struct hal_rcc_system_clock_configure_t config;
    config.source = clock->system_clock_source;
    config.ahb_prescaler = clock->ahb_prescaler;
    config.apb1_prescaler = clock->apb1_prescaler;
    config.apb2_prescaler = clock->apb2_prescaler;
    config.cortex_system_prescaler = clock->cortex_system_prescaler;
    config.apb1_timer_mul = clock->apb1_timer_mul;
    config.apb2_timer_mul = clock->apb2_timer_mul;
    hal_rcc_system_clock_init(&config);
}

static inline void rcc_usart1_clock_init(enum rcc_peripheral_clock_enable_e en, enum rcc_usart_clock_source_e source)
{
    if(en) {
        struct hal_rcc_usart_clock_configure_t config;
        config.usart = hal_rcc_usart_type_1;
        config.source = source;
        hal_rcc_usart_clock_init(&config);
    }
}
void rcc_clock_setup_init(const struct rcc_clock_scale_t* clock)
{
    hal_rcc_clock_init(hal_rcc_clock_source_lse, clock->lse);
    hal_rcc_clock_init(hal_rcc_clock_source_lsi, clock->lsi);
    hal_rcc_clock_init(hal_rcc_clock_source_msi, clock->msi);
    hal_rcc_clock_init(hal_rcc_clock_source_hsi, clock->hsi);
    hal_rcc_clock_init(hal_rcc_clock_source_hse, clock->hse);

    rcc_pll_clock_init(&clock->pll_clock);
    rcc_system_clock_init(&clock->system_clock);
    rcc_usart1_clock_init(clock->clock_enable.USART1EN, clock->usart1_source);

    hal_rcc_clock_enable(hal_rcc_clock_usart1);
    hal_rcc_clock_enable(hal_rcc_clock_gpioa);
    hal_rcc_clock_enable(hal_rcc_clock_gpiob);
    hal_rcc_clock_enable(hal_rcc_clock_gpioc);
    hal_rcc_clock_enable(hal_rcc_clock_gpiod);
    hal_rcc_clock_enable(hal_rcc_clock_gpioe);
    hal_rcc_clock_enable(hal_rcc_clock_gpiof);
    hal_rcc_clock_enable(hal_rcc_clock_gpiog);
    hal_rcc_clock_enable(hal_rcc_clock_gpioh);
    hal_rcc_clock_enable(hal_rcc_clock_afio);
    hal_rcc_clock_enable(hal_rcc_clock_can1);

    rcc_update_clock_tree(clock);
}

void rcc_clock_scale_init(struct rcc_clock_scale_t* clock)
{
    if(clock) {
    }
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
    rcc_print_clock_freq_func(rcc_clock_extern_sai1);
    rcc_print_clock_freq_func(rcc_clock_extern_sai2);
    
    rcc_print_clock_freq_func(rcc_clock_pll);
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

    rcc_print_clock_freq_func(rcc_clock_clk48);
    rcc_print_clock_freq_func(rcc_clock_adc1);
    rcc_print_clock_freq_func(rcc_clock_adc2);
    rcc_print_clock_freq_func(rcc_clock_adc3);

    rcc_print_clock_freq_func(rcc_clock_sai1);
    rcc_print_clock_freq_func(rcc_clock_sai2);

    rcc_print_clock_freq_func(rcc_clock_i2c1);
    rcc_print_clock_freq_func(rcc_clock_i2c2);
    rcc_print_clock_freq_func(rcc_clock_i2c3);

    rcc_print_clock_freq_func(rcc_clock_dfsdm1);
    rcc_print_clock_freq_func(rcc_clock_swpmi1);
    rcc_print_clock_freq_func(rcc_clock_mco);
    rcc_print_clock_freq_func(rcc_clock_lsco);
}
