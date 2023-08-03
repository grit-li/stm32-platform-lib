#include "hw/hw_rcc.h"
#include "hw/hw_flash.h"
#include "hal_rcc.h"

static uint32_t hal_rcc_conv_msi_clock_speed(uint32_t speed)
{
    uint32_t bRet = RCC_CR_MSIRANGE_6;
    switch(speed) {
        case KHZ(100):
            bRet = RCC_CR_MSIRANGE_0;
            break;
        case KHZ(200):
            bRet = RCC_CR_MSIRANGE_1;
            break;
        case KHZ(400):
            bRet = RCC_CR_MSIRANGE_2;
            break;
        case KHZ(800):
            bRet = RCC_CR_MSIRANGE_3;
            break;
        case MHZ(1):
            bRet = RCC_CR_MSIRANGE_4;
            break;
        case MHZ(2):
            bRet = RCC_CR_MSIRANGE_5;
            break;
        case MHZ(4):
            bRet = RCC_CR_MSIRANGE_6;
            break;
        case MHZ(8):
            bRet = RCC_CR_MSIRANGE_7;
            break;
        case MHZ(16):
            bRet = RCC_CR_MSIRANGE_8;
            break;
        case MHZ(24):
            bRet = RCC_CR_MSIRANGE_9;
            break;
        case MHZ(32):
            bRet = RCC_CR_MSIRANGE_10;
            break;
        case MHZ(48):
            bRet = RCC_CR_MSIRANGE_11;
            break;
        default:
            break;
    }
    return bRet;
}

static uint32_t clock_init(enum hal_rcc_clock_source_e clock, uint32_t speed)
{
    switch(clock) {
        case hal_rcc_clock_source_lse:
            hw_rcc_set_lse_clock_enable();
            hw_rcc_lse_clock_wait_ready();
            break;
        case hal_rcc_clock_source_lsi:
            hw_rcc_set_lsi_clock_enable();
            hw_rcc_lsi_clock_wait_ready();
            break;
        case hal_rcc_clock_source_msi:
            hw_rcc_set_msi_clock_ranges(hal_rcc_conv_msi_clock_speed(speed));
            hw_rcc_set_msi_clock_enable();
            hw_rcc_msi_clock_wait_ready();
            break;
        case hal_rcc_clock_source_hsi:
            hw_rcc_set_hsi_clock_enable();
            hw_rcc_hsi_clock_wait_ready();
            break;
        case hal_rcc_clock_source_hse:
            hw_rcc_set_hse_clock_enable();
            hw_rcc_hse_clock_wait_ready();
            break;
        default:
            break;
    }
    return stm32_errcode_success;
}

static uint32_t clock_deinit(enum hal_rcc_clock_source_e clock)
{
    switch(clock) {
        case hal_rcc_clock_source_lse:
            hw_rcc_set_lse_clock_disable();
            break;
        case hal_rcc_clock_source_lsi:
            hw_rcc_set_lsi_clock_disable();
            break;
        case hal_rcc_clock_source_msi:
            hw_rcc_set_msi_clock_disable();
            break;
        case hal_rcc_clock_source_hsi:
            hw_rcc_set_hsi_clock_disable();
            break;
        case hal_rcc_clock_source_hse:
            hw_rcc_set_hse_clock_disable();
            break;
        default:
            break;
    }
    return stm32_errcode_success;
}

uint32_t hal_rcc_clock_init(enum hal_rcc_clock_source_e clock, uint32_t speed)
{
    return (speed != 0) ? clock_init(clock, speed) : clock_deinit(clock);
}

uint32_t hal_rcc_pll_clock_select(enum rcc_pll_clock_source_e source)
{
    switch(source) {
        case rcc_pll_clock_source_msi:
            hw_rcc_set_main_clock_source(RCC_PLLCFGR_PLLSRC_MSI);
            break;
        case rcc_pll_clock_source_hsi:
            hw_rcc_set_main_clock_source(RCC_PLLCFGR_PLLSRC_HSI);
            break;
        case rcc_pll_clock_source_hse:
            hw_rcc_set_main_clock_source(RCC_PLLCFGR_PLLSRC_HSE);
            break;
        default:
            break;
    }
    return stm32_errcode_success;
}

uint32_t hal_rcc_pll_clock_configure(const struct hal_rcc_pll_configure_t* config)
{
    if(config) {
        hw_rcc_set_pll_clock_disable();
        if(config->pllm_prescaler <= rcc_clock_prescaler_8) {
            hw_rcc_set_division_factor_for_main_pll(config->pllm_prescaler << RCC_PLLCFGR_PLLM_Pos);
        }
        hw_rcc_set_multiplication_factor_for_main_pll(config->pll_mul << RCC_PLLCFGR_PLLN_Pos);
        switch(config->pllr_prescaler) {
            case rcc_clock_prescaler_2:
                hw_rcc_set_main_pll_division_factor_for_pllclk(RCC_PLLCFGR_PLLR_0);
                break;
            case rcc_clock_prescaler_4:
                hw_rcc_set_main_pll_division_factor_for_pllclk(RCC_PLLCFGR_PLLR_1);
                break;
            case rcc_clock_prescaler_6:
                hw_rcc_set_main_pll_division_factor_for_pllclk(RCC_PLLCFGR_PLLR_2);
                break;
            case rcc_clock_prescaler_8:
                hw_rcc_set_main_pll_division_factor_for_pllclk(RCC_PLLCFGR_PLLR_3);
                break;
            default:
                break;
        }
        hw_rcc_set_main_pll_clock_output_enable();
        hw_rcc_set_pll_clock_enable();
        hw_rcc_pll_clock_wait_ready();
        hw_flash_set_latency(FLASH_ACR_LATENCY_4WS);
    }
    return stm32_errcode_success;
}

uint32_t hal_rcc_system_clock_select(enum rcc_system_clock_source_e source)
{
    switch(source) {
        case rcc_system_clock_source_msi:
            hw_rcc_set_system_clock_source(RCC_CFGR_SW_MSI);
            break;
        case rcc_system_clock_source_hsi:
            hw_rcc_set_system_clock_source(RCC_CFGR_SW_HSI);
            break;
        case rcc_system_clock_source_hse:
            hw_rcc_set_system_clock_source(RCC_CFGR_SW_HSE);
            break;
        case rcc_system_clock_source_pllclk:
            hw_rcc_set_system_clock_source(RCC_CFGR_SW_PLL);
            break;
        default:
            break;
    }
    return stm32_errcode_success;
}

uint32_t hal_rcc_gpio_clock_enable(void)
{
    hw_rcc_set_gpioa_clock_enable();
    hw_rcc_set_gpiob_clock_enable();
    hw_rcc_set_gpioc_clock_enable();
    hw_rcc_set_gpiod_clock_enable();
    hw_rcc_set_gpioe_clock_enable();
    hw_rcc_set_gpiof_clock_enable();
    hw_rcc_set_gpiog_clock_enable();
    hw_rcc_set_gpioh_clock_enable();
    return stm32_errcode_success;
}