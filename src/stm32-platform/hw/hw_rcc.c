#include "hw_rcc.h"
#include "stm32_assert.h"

void hw_rcc_set_msi_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_MSION);
}

void hw_rcc_set_msi_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_MSION);
}

uint32_t hw_rcc_get_msi_clock_enable(void)
{
    return (__GET_RCC_CR__ & RCC_CR_MSION);
}

uint32_t hw_rcc_msi_clock_ready_status(void)
{
    return (__GET_RCC_CR__ & RCC_CR_MSIRDY);
}

void hw_rcc_msi_clock_wait_ready(void)
{
    while(!(__GET_RCC_CR__ & RCC_CR_MSIRDY));
}

void hw_rcc_set_msi_clock_pll_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_MSIPLLEN);
}

void hw_rcc_set_msi_clock_pll_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_MSIPLLEN);
}

uint32_t hw_rcc_get_msi_clock_pll_enable(void)
{
    return (__GET_RCC_CR__ & RCC_CR_MSIPLLEN);
}

void hw_rcc_switch_msi_clock_range(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_MSIRGSEL);
}

uint32_t hw_rcc_get_msi_clock_range_selection(void)
{
    return (__GET_RCC_CR__ & RCC_CR_MSIRGSEL);
}

void hw_rcc_set_msi_clock_ranges(uint32_t range)
{
    __BIT_COVER_SET__(__GET_RCC_CR__, RCC_CR_MSIRANGE, range);
}

uint32_t hw_rcc_get_msi_clock_ranges(void)
{
    return (__GET_RCC_CR__ & RCC_CR_MSIRANGE);
}

void hw_rcc_set_hsi_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_HSION);
}

void hw_rcc_set_hsi_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_HSION);
}

uint32_t hw_rcc_get_hsi_clock_enable(void)
{
    return (__GET_RCC_CR__ & RCC_CR_HSION);
}

void hw_rcc_set_hsi_clock_enable_for_peripheral_kernels(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_HSIKERON);
}

void hw_rcc_set_hsi_clock_disable_for_peripheral_kernels(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_HSIKERON);
}

uint32_t hw_rcc_get_hsi_clock_enable_for_peripheral_kernels(void)
{
    return (__GET_RCC_CR__ & RCC_CR_HSIKERON);
}

uint32_t hw_rcc_hsi_clock_ready_status(void)
{
    return (__GET_RCC_CR__ & RCC_CR_HSIRDY);
}

void hw_rcc_hsi_clock_wait_ready(void)
{
    while(!(__GET_RCC_CR__ & RCC_CR_HSIRDY));
}

void hw_rcc_open_hsi_clock_automatic_start_from_stop(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_HSIASFS);
}

void hw_rcc_close_hsi_clock_automatic_start_from_stop(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_HSIASFS);
}

uint32_t hw_rcc_get_hsi_clock_automatic_start_from_stop(void)
{
    return (__GET_RCC_CR__ & RCC_CR_HSIASFS);
}

void hw_rcc_set_hse_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_HSEON);
}

void hw_rcc_set_hse_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_HSEON);
}

uint32_t hw_rcc_get_hse_clock_enable(void)
{
    return (__GET_RCC_CR__ & RCC_CR_HSEON);
}

uint32_t hw_rcc_hse_clock_ready_status(void)
{
    return (__GET_RCC_CR__ & RCC_CR_HSERDY);
}

void hw_rcc_hse_clock_wait_ready(void)
{
    while(!(__GET_RCC_CR__ & RCC_CR_HSERDY));
}

void hw_rcc_hse_clock_bypass_enadble(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_HSEBYP);
}

void hw_rcc_hse_clock_bypass_disadble(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_HSEBYP);
}

uint32_t hw_rcc_hse_clock_bypass(void)
{
    return (__GET_RCC_CR__ & RCC_CR_HSEBYP);
}

void hw_rcc_set_clock_security_system_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_CSSON);
}

uint32_t hw_rcc_get_clock_security_system_enable(void)
{
    return (__GET_RCC_CR__ & RCC_CR_CSSON);
}

void hw_rcc_set_pll_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_PLLON);
}

void hw_rcc_set_pll_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_PLLON);
}

uint32_t hw_rcc_get_pll_clock_enable(void)
{
    return (__GET_RCC_CR__ & RCC_CR_PLLON);
}

uint32_t hw_rcc_pll_clock_ready_status(void)
{
    return (__GET_RCC_CR__ & RCC_CR_PLLRDY);
}

void hw_rcc_pll_clock_wait_ready(void)
{
    while(!(__GET_RCC_CR__ & RCC_CR_PLLRDY));
}

void hw_rcc_set_pll_sai1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_PLLSAI1ON);
}

void hw_rcc_set_pll_sai1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_PLLSAI1ON);
}

uint32_t hw_rcc_get_pll_sai1_clock_enable(void)
{
    return (__GET_RCC_CR__ & RCC_CR_PLLSAI1ON);
}

uint32_t hw_rcc_pll_sai1_clock_ready_status(void)
{
    return (__GET_RCC_CR__ & RCC_CR_PLLSAI1RDY);
}

void hw_rcc_pll_sai1_clock_wait_ready(void)
{
    while(!(__GET_RCC_CR__ & RCC_CR_PLLSAI1RDY));
}

void hw_rcc_set_pll_sai2_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_PLLSAI2ON);
}

void hw_rcc_set_pll_sai2_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_PLLSAI2ON);
}

uint32_t hw_rcc_get_pll_sai2_clock_enable(void)
{
    return (__GET_RCC_CR__ & RCC_CR_PLLSAI2ON);
}

uint32_t hw_rcc_pll_sai2_clock_ready_status(void)
{
    return (__GET_RCC_CR__ & RCC_CR_PLLSAI2RDY);
}

void hw_rcc_pll_sai2_clock_wait_ready(void)
{
    while(!(__GET_RCC_CR__ & RCC_CR_PLLSAI2RDY));
}

uint32_t hw_rcc_msi_clock_calibration(void)
{
    return (__GET_RCC_ICSCR__ & RCC_ICSCR_MSICAL);
}

void hw_rcc_set_msi_clock_trimming(uint32_t trimming)
{
    __BIT_COVER_SET__(__GET_RCC_ICSCR__, RCC_ICSCR_MSITRIM, trimming);
}

uint32_t hw_rcc_get_msi_clock_trimming(void)
{
    return (__GET_RCC_ICSCR__ & RCC_ICSCR_MSITRIM);
}

uint32_t hw_rcc_hsi_clock_calibration(void)
{
    return (__GET_RCC_ICSCR__ & RCC_ICSCR_HSICAL);
}

void hw_rcc_set_hsi_clock_trimming(uint32_t trimming)
{
    __BIT_COVER_SET__(__GET_RCC_ICSCR__, RCC_ICSCR_HSITRIM, trimming);
}

uint32_t hw_rcc_get_hsi_clock_trimming(void)
{
    return (__GET_RCC_ICSCR__ & RCC_ICSCR_HSITRIM);
}

void hw_rcc_set_system_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_SW, source);
}

uint32_t hw_rcc_get_system_clock_source(void)
{
    return (__GET_RCC_CFGR__ & RCC_CFGR_SW);
}

uint32_t hw_rcc_get_system_clock_source_status(void)
{
    return (__GET_RCC_CFGR__ & RCC_CFGR_SWS);
}

void hw_rcc_set_ahb_clock_prescaler(uint32_t prescaler)
{
    __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_HPRE, prescaler);
}

uint32_t hw_rcc_get_ahb_clock_prescaler(void)
{
    return (__GET_RCC_CFGR__ & RCC_CFGR_HPRE);
}

void hw_rcc_set_apb1_clock_prescaler(uint32_t prescaler)
{
    __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PPRE1, prescaler);
}

uint32_t hw_rcc_get_apb1_clock_prescaler(void)
{
    return (__GET_RCC_CFGR__ & RCC_CFGR_PPRE1);
}

void hw_rcc_set_apb2_clock_prescaler(uint32_t prescaler)
{
    __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PPRE2, prescaler);
}

uint32_t hw_rcc_get_apb2_clock_prescaler(void)
{
    return (__GET_RCC_CFGR__ & RCC_CFGR_PPRE2);
}

void hw_rcc_select_wakeup_from_stop_css_buckup_clock(uint32_t select)
{
    __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_STOPWUCK, select);
}

uint32_t hw_rcc_wakeup_from_stop_css_buckup_clock(void)
{
    return (__GET_RCC_CFGR__ & RCC_CFGR_STOPWUCK);
}

void hw_rcc_select_microcontroller_clock_output(uint32_t select)
{
    __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_MCOSEL, select);
}

uint32_t hw_rcc_microcontroller_clock_output(void)
{
    return (__GET_RCC_CFGR__ & RCC_CFGR_MCOSEL);
}

void hw_rcc_set_microcontroller_clock_output_prescaler(uint32_t prescaler)
{
    __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_MCOPRE, prescaler);
}

uint32_t hw_rcc_microcontroller_clock_output_prescaler(void)
{
    return (__GET_RCC_CFGR__ & RCC_CFGR_MCOPRE);
}

void hw_rcc_set_main_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLSRC, source);
}

uint32_t hw_rcc_get_main_clock_source(void)
{
    return (__GET_RCC_PLLCFGR__ & RCC_PLLCFGR_PLLSRC);
}

void hw_rcc_set_division_factor_for_main_pll(uint32_t factor)
{
    __BIT_COVER_SET__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLM, factor);
}

uint32_t hw_rcc_get_division_factor_for_main_pll(void)
{
    return (__GET_RCC_PLLCFGR__ & RCC_PLLCFGR_PLLM);
}

void hw_rcc_set_main_pll_multiplication_factor_for_vco(uint32_t factor)
{
    __BIT_COVER_SET__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLN, factor);
}

uint32_t hw_rcc_get_main_pll_multiplication_factor_for_vco(void)
{
    return (__GET_RCC_PLLCFGR__ & RCC_PLLCFGR_PLLN);
}

void hw_rcc_set_main_pll_sai3_clock_output_enable(void)
{
   __BIT_OR__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLPEN);
}

void hw_rcc_set_main_pll_sai3_clock_output_disable(void)
{
    __BIT_RESET__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLPEN);
}

uint32_t hw_rcc_get_main_pll_sai3_clock_output_enable(void)
{
    return (__GET_RCC_PLLCFGR__ & RCC_PLLCFGR_PLLPEN);
}

void hw_rcc_set_main_pll_division_factor_for_pllsai3clk(uint32_t factor)
{
   __BIT_COVER_SET__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLP, factor);
}

uint32_t hw_rcc_get_main_pll_division_factor_for_pllsai3clk(void)
{
    return (__GET_RCC_PLLCFGR__ & RCC_PLLCFGR_PLLP);
}

void hw_rcc_set_main_pll_pll48m1_clock_output_enable(void)
{
   __BIT_OR__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLQEN);
}

void hw_rcc_set_main_pll_pll48m1_clock_output_disable(void)
{
    __BIT_RESET__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLQEN);
}

uint32_t hw_rcc_get_main_pll_pll48m1_clock_output_enable(void)
{
    return (__GET_RCC_PLLCFGR__ & RCC_PLLCFGR_PLLQEN);
}

void hw_rcc_set_main_pll_pll48m1_division_factor(uint32_t factor)
{
   __BIT_COVER_SET__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLQ, factor);
}

uint32_t hw_rcc_get_main_pll_pll48m1_division_factor(void)
{
    return (__GET_RCC_PLLCFGR__ & RCC_PLLCFGR_PLLQ);
}

void hw_rcc_set_main_pll_clock_output_enable(void)
{
   __BIT_OR__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLREN);
}

void hw_rcc_set_main_pll_clock_output_disable(void)
{
    __BIT_RESET__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLREN);
}

uint32_t hw_rcc_get_main_pll_clock_output_enable(void)
{
    return (__GET_RCC_PLLCFGR__ & RCC_PLLCFGR_PLLREN);
}

void hw_rcc_set_main_pll_division_factor_for_pllclk(uint32_t factor)
{
   __BIT_COVER_SET__(__GET_RCC_PLLCFGR__, RCC_PLLCFGR_PLLR, factor);
}

uint32_t hw_rcc_get_main_pll_division_factor_for_pllclk(void)
{
    return (__GET_RCC_PLLCFGR__ & RCC_PLLCFGR_PLLR);
}

void hw_rcc_set_pll_sai1_multiplication_factor_for_vco(uint32_t factor)
{
    __BIT_COVER_SET__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1N, factor);
}

uint32_t hw_rcc_get_pll_sai1_multiplication_factor_for_vco(void)
{
    return (__GET_RCC_PLLSAI1CFGR__ & RCC_PLLSAI1CFGR_PLLSAI1N);
}

void hw_rcc_set_pll_sai1_pllsai1clk_enable(void)
{
    __BIT_OR__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1PEN);
}

void hw_rcc_set_pll_sai1_pllsai1clk_disable(void)
{
    __BIT_RESET__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1PEN);
}

uint32_t hw_rcc_get_pll_sai1_pllsai1clk_enable(void)
{
    return (__GET_RCC_PLLSAI1CFGR__ & RCC_PLLSAI1CFGR_PLLSAI1PEN);
}

void hw_rcc_set_pll_sai1_division_factor_for_pllsai1clk(uint32_t factor)
{
    __BIT_COVER_SET__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1P, factor);
}

uint32_t hw_rcc_get_pll_sai1_division_factor_for_pllsai1clk(void)
{
    return (__GET_RCC_PLLSAI1CFGR__ & RCC_PLLSAI1CFGR_PLLSAI1P);
}

void hw_rcc_set_pll_sai1_pll48m2clk_output_enable(void)
{
    __BIT_OR__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1QEN);
}

void hw_rcc_set_pll_sai1_pll48m2clk_output_disable(void)
{
    __BIT_RESET__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1QEN);
}

uint32_t hw_rcc_get_pll_sai1_pll48m2clk_output_enable(void)
{
    return (__GET_RCC_PLLSAI1CFGR__ & RCC_PLLSAI1CFGR_PLLSAI1QEN);
}

void hw_rcc_set_pll_sai1_division_factor_for_pll48m2clk(uint32_t factor)
{
    __BIT_COVER_SET__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1Q, factor);
}

uint32_t hw_rcc_get_pll_sai1_division_factor_for_pll48m2clk(void)
{
    return (__GET_RCC_PLLSAI1CFGR__ & RCC_PLLSAI1CFGR_PLLSAI1Q);
}

void hw_rcc_set_pll_sai1_plladc1clk_output_enable(void)
{
    __BIT_OR__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1REN);
}

void hw_rcc_set_pll_sai1_plladc1clk_output_disable(void)
{
    __BIT_RESET__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1REN);
}

uint32_t hw_rcc_get_pll_sai1_plladc1clk_output_enable(void)
{
    return (__GET_RCC_PLLSAI1CFGR__ & RCC_PLLSAI1CFGR_PLLSAI1REN);
}

void hw_rcc_set_pll_sai1_division_factor_for_plladc1clk(uint32_t factor)
{
    __BIT_COVER_SET__(__GET_RCC_PLLSAI1CFGR__, RCC_PLLSAI1CFGR_PLLSAI1R, factor);
}

uint32_t hw_rcc_get_pll_sai1_division_factor_for_plladc1clk(void)
{
    return (__GET_RCC_PLLSAI1CFGR__ & RCC_PLLSAI1CFGR_PLLSAI1R);
}

/////
void hw_rcc_set_pll_sai2_multiplication_factor_for_vco(uint32_t factor)
{
    __BIT_COVER_SET__(__GET_RCC_PLLSAI2CFGR__, RCC_PLLSAI2CFGR_PLLSAI2N, factor);
}

uint32_t hw_rcc_get_pll_sai2_multiplication_factor_for_vco(void)
{
    return (__GET_RCC_PLLSAI2CFGR__ & RCC_PLLSAI2CFGR_PLLSAI2N);
}

void hw_rcc_set_pll_sai2_pllsai2clk_enable(void)
{
    __BIT_OR__(__GET_RCC_PLLSAI2CFGR__, RCC_PLLSAI2CFGR_PLLSAI2PEN);
}

void hw_rcc_set_pll_sai2_pllsai2clk_disable(void)
{
    __BIT_RESET__(__GET_RCC_PLLSAI2CFGR__, RCC_PLLSAI2CFGR_PLLSAI2PEN);
}

uint32_t hw_rcc_get_pll_sai2_pllsai2clk_enable(void)
{
    return (__GET_RCC_PLLSAI2CFGR__ & RCC_PLLSAI2CFGR_PLLSAI2PEN);
}

void hw_rcc_set_pll_sai2_division_factor_for_pllsai2clk(uint32_t factor)
{
    __BIT_COVER_SET__(__GET_RCC_PLLSAI2CFGR__, RCC_PLLSAI2CFGR_PLLSAI2P, factor);
}

uint32_t hw_rcc_get_pll_sai2_division_factor_for_pllsai2clk(void)
{
    return (__GET_RCC_PLLSAI2CFGR__ & RCC_PLLSAI2CFGR_PLLSAI2P);
}

void hw_rcc_set_pll_sai2_plladc2clk_output_enable(void)
{
    __BIT_OR__(__GET_RCC_PLLSAI2CFGR__, RCC_PLLSAI2CFGR_PLLSAI2REN);
}

void hw_rcc_set_pll_sai2_plladc2clk_output_disable(void)
{
    __BIT_RESET__(__GET_RCC_PLLSAI2CFGR__, RCC_PLLSAI2CFGR_PLLSAI2REN);
}

uint32_t hw_rcc_get_pll_sai2_plladc2clk_output_enable(void)
{
    return (__GET_RCC_PLLSAI2CFGR__ & RCC_PLLSAI2CFGR_PLLSAI2REN);
}

void hw_rcc_set_pll_sai2_division_factor_for_plladc2clk(uint32_t factor)
{
    __BIT_COVER_SET__(__GET_RCC_PLLSAI2CFGR__, RCC_PLLSAI2CFGR_PLLSAI2R, factor);
}

uint32_t hw_rcc_get_pll_sai2_division_factor_for_plladc2clk(void)
{
    return (__GET_RCC_PLLSAI2CFGR__ & RCC_PLLSAI2CFGR_PLLSAI2R);
}

void hw_rcc_set_lsi_ready_interrupt_enable(void)
{
    __BIT_OR__(__GET_RCC_CIER__, RCC_CIER_LSIRDYIE);
}

void hw_rcc_set_lsi_ready_interrupt_disable(void)
{
    __BIT_RESET__(__GET_RCC_CIER__, RCC_CIER_LSIRDYIE);
}

uint32_t hw_rcc_get_lsi_ready_interrupt_enable(void)
{
    return (__GET_RCC_CIER__ & RCC_CIER_LSIRDYIE);
}

void hw_rcc_set_lse_ready_interrupt_enable(void)
{
    __BIT_OR__(__GET_RCC_CIER__, RCC_CIER_LSERDYIE);
}

void hw_rcc_set_lse_ready_interrupt_disable(void)
{
    __BIT_RESET__(__GET_RCC_CIER__, RCC_CIER_LSERDYIE);
}

uint32_t hw_rcc_get_lse_ready_interrupt_enable(void)
{
    return (__GET_RCC_CIER__ & RCC_CIER_LSERDYIE);
}

void hw_rcc_set_msi_ready_interrupt_enable(void)
{
    __BIT_OR__(__GET_RCC_CIER__, RCC_CIER_MSIRDYIE);
}

void hw_rcc_set_msi_ready_interrupt_disable(void)
{
    __BIT_RESET__(__GET_RCC_CIER__, RCC_CIER_MSIRDYIE);
}

uint32_t hw_rcc_get_msi_ready_interrupt_enable(void)
{
    return (__GET_RCC_CIER__ & RCC_CIER_MSIRDYIE);
}

void hw_rcc_set_hsi_ready_interrupt_enable(void)
{
    __BIT_OR__(__GET_RCC_CIER__, RCC_CIER_HSIRDYIE);
}

void hw_rcc_set_hsi_ready_interrupt_disable(void)
{
    __BIT_RESET__(__GET_RCC_CIER__, RCC_CIER_HSIRDYIE);
}

uint32_t hw_rcc_get_hsi_ready_interrupt_enable(void)
{
    return (__GET_RCC_CIER__ & RCC_CIER_HSIRDYIE);
}

void hw_rcc_set_hse_ready_interrupt_enable(void)
{
    __BIT_OR__(__GET_RCC_CIER__, RCC_CIER_HSERDYIE);
}

void hw_rcc_set_hse_ready_interrupt_disable(void)
{
    __BIT_RESET__(__GET_RCC_CIER__, RCC_CIER_HSERDYIE);
}

uint32_t hw_rcc_get_hse_ready_interrupt_enable(void)
{
    return (__GET_RCC_CIER__ & RCC_CIER_HSERDYIE);
}

void hw_rcc_set_pll_ready_interrupt_enable(void)
{
    __BIT_OR__(__GET_RCC_CIER__, RCC_CIER_PLLRDYIE);
}

void hw_rcc_set_pll_ready_interrupt_disable(void)
{
    __BIT_RESET__(__GET_RCC_CIER__, RCC_CIER_PLLRDYIE);
}

uint32_t hw_rcc_get_pll_ready_interrupt_enable(void)
{
    return (__GET_RCC_CIER__ & RCC_CIER_PLLRDYIE);
}

void hw_rcc_set_pllsai1_ready_interrupt_enable(void)
{
    __BIT_OR__(__GET_RCC_CIER__, RCC_CIER_PLLSAI1RDYIE);
}

void hw_rcc_set_pllsai1_ready_interrupt_disable(void)
{
    __BIT_RESET__(__GET_RCC_CIER__, RCC_CIER_PLLSAI1RDYIE);
}

uint32_t hw_rcc_get_pllsai1_ready_interrupt_enable(void)
{
    return (__GET_RCC_CIER__ & RCC_CIER_PLLSAI1RDYIE);
}

void hw_rcc_set_pllsai2_ready_interrupt_enable(void)
{
    __BIT_OR__(__GET_RCC_CIER__, RCC_CIER_PLLSAI2RDYIE);
}

void hw_rcc_set_pllsai2_ready_interrupt_disable(void)
{
    __BIT_RESET__(__GET_RCC_CIER__, RCC_CIER_PLLSAI2RDYIE);
}

uint32_t hw_rcc_get_pllsai2_ready_interrupt_enable(void)
{
    return (__GET_RCC_CIER__ & RCC_CIER_PLLSAI2RDYIE);
}

void hw_rcc_set_lse_css_ready_interrupt_enable(void)
{
    __BIT_OR__(__GET_RCC_CIER__, RCC_CIER_LSECSSIE);
}

void hw_rcc_set_lse_css_ready_interrupt_disable(void)
{
    __BIT_RESET__(__GET_RCC_CIER__, RCC_CIER_LSECSSIE);
}

uint32_t hw_rcc_lsi_ready_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_LSIRDYF);
}

uint32_t hw_rcc_lse_ready_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_LSERDYF);
}

uint32_t hw_rcc_msi_ready_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_MSIRDYF);
}

uint32_t hw_rcc_hsi_ready_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_HSIRDYF);
}

uint32_t hw_rcc_hse_ready_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_HSERDYF);
}

uint32_t hw_rcc_pll_ready_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_PLLRDYF);
}

uint32_t hw_rcc_pll_sai1_ready_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_PLLSAI1RDYF);
}

uint32_t hw_rcc_pll_sai2_ready_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_PLLSAI2RDYF);
}

uint32_t hw_rcc_css_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_CSSF);
}

uint32_t hw_rcc_lse_css_interrupt_flag(void)
{
    return (__GET_RCC_CIFR__ & RCC_CIFR_LSECSSF);
}

void hw_rcc_clear_lsi_ready_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_LSIRDYC);
}

void hw_rcc_clear_lse_ready_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_LSERDYC);
}

void hw_rcc_clear_msi_ready_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_MSIRDYC);
}

void hw_rcc_clear_hsi_ready_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_HSIRDYC);
}

void hw_rcc_clear_hse_ready_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_HSERDYC);
}

void hw_rcc_clear_pll_ready_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_PLLRDYC);
}

void hw_rcc_clear_pll_sai1_ready_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_PLLSAI1RDYC);
}

void hw_rcc_clear_pll_sai2_ready_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_PLLSAI2RDYC);
}

void hw_rcc_clear_css_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_CSSC);
}

void hw_rcc_clear_lse_css_interrupt_flag(void)
{
    __BIT_OR__(__GET_RCC_CICR__, RCC_CICR_LSECSSC);
}

void hw_rcc_set_dma1_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB1RSTR__, RCC_AHB1RSTR_DMA1RST);
}

void hw_rcc_wait_dma1_reset(void)
{
    while(__GET_RCC_AHB1RSTR__ & RCC_AHB1RSTR_DMA1RST);
}

void hw_rcc_set_dma2_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB1RSTR__, RCC_AHB1RSTR_DMA2RST);
}

void hw_rcc_wait_dma2_reset(void)
{
    while(__GET_RCC_AHB1RSTR__ & RCC_AHB1RSTR_DMA2RST);
}

void hw_rcc_set_flash_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB1RSTR__, RCC_AHB1RSTR_FLASHRST);
}

void hw_rcc_wait_flash_reset(void)
{
    while(__GET_RCC_AHB1RSTR__ & RCC_AHB1RSTR_FLASHRST);
}

void hw_rcc_set_crc_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB1RSTR__, RCC_AHB1RSTR_CRCRST);
}

void hw_rcc_wait_crc_reset(void)
{
    while(__GET_RCC_AHB1RSTR__ & RCC_AHB1RSTR_CRCRST);
}

void hw_rcc_set_tsc_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB1RSTR__, RCC_AHB1RSTR_TSCRST);
}

void hw_rcc_wait_tsc_reset(void)
{
    while(__GET_RCC_AHB1RSTR__ & RCC_AHB1RSTR_TSCRST);
}

void hw_rcc_set_gpioa_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_GPIOARST);
}

void hw_rcc_wait_gpioa_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_GPIOARST);
}

void hw_rcc_set_gpiob_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_GPIOBRST);
}

void hw_rcc_wait_gpiob_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_GPIOBRST);
}

void hw_rcc_set_gpioc_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_GPIOCRST);
}

void hw_rcc_wait_gpioc_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_GPIOCRST);
}

void hw_rcc_set_gpiod_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_GPIODRST);
}

void hw_rcc_wait_gpiod_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_GPIODRST);
}

void hw_rcc_set_gpioe_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_GPIOERST);
}

void hw_rcc_wait_gpioe_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_GPIOERST);
}

void hw_rcc_set_gpiof_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_GPIOFRST);
}

void hw_rcc_wait_gpiof_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_GPIOFRST);
}

void hw_rcc_set_gpiog_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_GPIOGRST);
}

void hw_rcc_wait_gpiog_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_GPIOGRST);
}

void hw_rcc_set_gpioh_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_GPIOHRST);
}

void hw_rcc_wait_gpioh_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_GPIOHRST);
}

void hw_rcc_set_adc_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_ADCRST);
}

void hw_rcc_wait_adc_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_ADCRST);
}

void hw_rcc_set_rng_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB2RSTR__, RCC_AHB2RSTR_RNGRST);
}

void hw_rcc_wait_rng_reset(void)
{
    while(__GET_RCC_AHB2RSTR__ & RCC_AHB2RSTR_RNGRST);
}

void hw_rcc_set_fmc_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB3RSTR__, RCC_AHB3RSTR_FMCRST);
}

void hw_rcc_wait_fmc_reset(void)
{
    while(__GET_RCC_AHB3RSTR__ & RCC_AHB3RSTR_FMCRST);
}

void hw_rcc_set_qspi_reset(void)
{
    __BIT_OR__(__GET_RCC_AHB3RSTR__, RCC_AHB3RSTR_QSPIRST);
}

void hw_rcc_wait_qspi_reset(void)
{
    while(__GET_RCC_AHB3RSTR__ & RCC_AHB3RSTR_QSPIRST);
}

void hw_rcc_set_tim2_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_TIM2RST);
}

void hw_rcc_wait_tim2_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_TIM2RST);
}

void hw_rcc_set_tim3_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_TIM3RST);
}

void hw_rcc_wait_tim3_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_TIM3RST);
}

void hw_rcc_set_tim4_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_TIM4RST);
}

void hw_rcc_wait_tim4_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_TIM4RST);
}

void hw_rcc_set_tim5_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_TIM5RST);
}

void hw_rcc_wait_tim5_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_TIM5RST);
}

void hw_rcc_set_tim6_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_TIM6RST);
}

void hw_rcc_wait_tim6_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_TIM6RST);
}

void hw_rcc_set_tim7_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_TIM7RST);
}

void hw_rcc_wait_tim7_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_TIM7RST);
}

void hw_rcc_set_spi2_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_SPI2RST);
}

void hw_rcc_wait_spi2_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_SPI2RST);
}

void hw_rcc_set_spi3_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_SPI3RST);
}

void hw_rcc_wait_spi3_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_SPI3RST);
}

void hw_rcc_set_usart2_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_USART2RST);
}

void hw_rcc_wait_usart2_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_USART2RST);
}

void hw_rcc_set_usart3_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_USART3RST);
}

void hw_rcc_wait_usart3_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_USART3RST);
}

void hw_rcc_set_uart4_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_UART4RST);
}

void hw_rcc_wait_uart4_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_UART4RST);
}

void hw_rcc_set_uart5_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_UART5RST);
}

void hw_rcc_wait_uart5_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_UART5RST);
}

void hw_rcc_set_i2c1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_I2C1RST);
}

void hw_rcc_wait_i2c1_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_I2C1RST);
}

void hw_rcc_set_i2c2_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_I2C2RST);
}

void hw_rcc_wait_i2c2_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_I2C2RST);
}

void hw_rcc_set_i2c3_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_I2C3RST);
}

void hw_rcc_wait_i2c3_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_I2C3RST);
}

void hw_rcc_set_can1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_CAN1RST);
}

void hw_rcc_wait_can1_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_CAN1RST);
}

void hw_rcc_set_power_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_PWRRST);
}

void hw_rcc_wait_power_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_PWRRST);
}

void hw_rcc_set_dac1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_DAC1RST);
}

void hw_rcc_wait_dac1_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_DAC1RST);
}

void hw_rcc_set_opamp_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_OPAMPRST);
}

void hw_rcc_wait_opamp_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_OPAMPRST);
}

void hw_rcc_set_lptim1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR1__, RCC_APB1RSTR1_LPTIM1RST);
}

void hw_rcc_wait_lptim1_reset(void)
{
    while(__GET_RCC_APB1RSTR1__ & RCC_APB1RSTR1_LPTIM1RST);
}

void hw_rcc_set_lpuart1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR2__, RCC_APB1RSTR2_LPUART1RST);
}

void hw_rcc_wait_lpuart1_reset(void)
{
    while(__GET_RCC_APB1RSTR2__ & RCC_APB1RSTR2_LPUART1RST);
}

void hw_rcc_set_swpmi1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR2__, RCC_APB1RSTR2_SWPMI1RST);
}

void hw_rcc_wait_swpmi1_reset(void)
{
    while(__GET_RCC_APB1RSTR2__ & RCC_APB1RSTR2_SWPMI1RST);
}

void hw_rcc_set_lptim2_reset(void)
{
    __BIT_OR__(__GET_RCC_APB1RSTR2__, RCC_APB1RSTR2_LPTIM2RST);
}

void hw_rcc_wait_lptim2_reset(void)
{
    while(__GET_RCC_APB1RSTR2__ & RCC_APB1RSTR2_LPTIM2RST);
}

void hw_rcc_set_syscfg_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_SYSCFGRST);
}

void hw_rcc_wait_syscfg_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_SYSCFGRST);
}

void hw_rcc_set_sdmmc1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_SDMMC1RST);
}

void hw_rcc_wait_sdmmc1_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_SDMMC1RST);
}

void hw_rcc_set_tim1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_TIM1RST);
}

void hw_rcc_wait_tim1_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_TIM1RST);
}

void hw_rcc_set_spi1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_SPI1RST);
}

void hw_rcc_wait_spi1_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_SPI1RST);
}

void hw_rcc_set_tim8_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_TIM8RST);
}

void hw_rcc_wait_tim8_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_TIM8RST);
}

void hw_rcc_set_usart1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_USART1RST);
}

void hw_rcc_wait_usart1_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_USART1RST);
}

void hw_rcc_set_tim15_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_TIM15RST);
}

void hw_rcc_wait_tim15_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_TIM15RST);
}

void hw_rcc_set_tim16_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_TIM16RST);
}

void hw_rcc_wait_tim16_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_TIM16RST);
}

void hw_rcc_set_tim17_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_TIM17RST);
}

void hw_rcc_wait_tim17_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_TIM17RST);
}

void hw_rcc_set_sai1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_SAI1RST);
}

void hw_rcc_wait_sai1_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_SAI1RST);
}

void hw_rcc_set_sai2_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_SAI2RST);
}

void hw_rcc_wait_sai2_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_SAI2RST);
}

void hw_rcc_set_dfsdm1_reset(void)
{
    __BIT_OR__(__GET_RCC_APB2RSTR__, RCC_APB2RSTR_DFSDM1RST);
}

void hw_rcc_wait_dfsdm1_reset(void)
{
    while(__GET_RCC_APB2RSTR__ & RCC_APB2RSTR_DFSDM1RST);
}

void hw_rcc_set_dma1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_DMA1EN);
}

void hw_rcc_set_dma1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_DMA1EN);
}

uint32_t hw_rcc_get_dma1_clock_enable(void)
{
    return (__GET_RCC_AHB1ENR__ & RCC_AHB1ENR_DMA1EN);
}

void hw_rcc_set_dma2_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_DMA2EN);
}

void hw_rcc_set_dma2_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_DMA2EN);
}

uint32_t hw_rcc_get_dma2_clock_enable(void)
{
    return (__GET_RCC_AHB1ENR__ & RCC_AHB1ENR_DMA2EN);
}

void hw_rcc_set_flash_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_FLASHEN);
}

void hw_rcc_set_flash_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_FLASHEN);
}

uint32_t hw_rcc_get_flash_clock_enable(void)
{
    return (__GET_RCC_AHB1ENR__ & RCC_AHB1ENR_FLASHEN);
}

void hw_rcc_set_crc_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_CRCEN);
}

void hw_rcc_set_crc_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_CRCEN);
}

uint32_t hw_rcc_get_crc_clock_enable(void)
{
    return (__GET_RCC_AHB1ENR__ & RCC_AHB1ENR_CRCEN);
}

void hw_rcc_set_tsc_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_TSCEN);
}

void hw_rcc_set_tsc_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1ENR__, RCC_AHB1ENR_TSCEN);
}

uint32_t hw_rcc_get_tsc_clock_enable(void)
{
    return (__GET_RCC_AHB1ENR__ & RCC_AHB1ENR_TSCEN);
}

void hw_rcc_set_gpioa_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOAEN);
}

void hw_rcc_set_gpioa_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOAEN);
}

uint32_t hw_rcc_get_gpioa_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_GPIOAEN);
}

void hw_rcc_set_gpiob_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOBEN);
}

void hw_rcc_set_gpiob_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOBEN);
}

uint32_t hw_rcc_get_gpiob_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_GPIOBEN);
}

void hw_rcc_set_gpioc_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOCEN);
}

void hw_rcc_set_gpioc_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOCEN);
}

uint32_t hw_rcc_get_gpioc_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_GPIOCEN);
}

void hw_rcc_set_gpiod_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIODEN);
}

void hw_rcc_set_gpiod_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIODEN);
}

uint32_t hw_rcc_get_gpiod_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_GPIODEN);
}

void hw_rcc_set_gpioe_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOEEN);
}

void hw_rcc_set_gpioe_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOEEN);
}

uint32_t hw_rcc_get_gpioe_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_GPIOEEN);
}

void hw_rcc_set_gpiof_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOFEN);
}

void hw_rcc_set_gpiof_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOFEN);
}

uint32_t hw_rcc_get_gpiof_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_GPIOFEN);
}

void hw_rcc_set_gpiog_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOGEN);
}

void hw_rcc_set_gpiog_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOGEN);
}

uint32_t hw_rcc_get_gpiog_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_GPIOGEN);
}

void hw_rcc_set_gpioh_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOHEN);
}

void hw_rcc_set_gpioh_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_GPIOHEN);
}

uint32_t hw_rcc_get_gpioh_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_GPIOHEN);
}

void hw_rcc_set_adc_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_ADCEN);
}

void hw_rcc_set_adc_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_ADCEN);
}

uint32_t hw_rcc_get_adc_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_ADCEN);
}

void hw_rcc_set_rng_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_RNGEN);
}

void hw_rcc_set_rng_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2ENR__, RCC_AHB2ENR_RNGEN);
}

uint32_t hw_rcc_get_rng_clock_enable(void)
{
    return (__GET_RCC_AHB2ENR__ & RCC_AHB2ENR_RNGEN);
}

void hw_rcc_set_fmc_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB3ENR__, RCC_AHB3ENR_FMCEN);
}

void hw_rcc_set_fmc_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB3ENR__, RCC_AHB3ENR_FMCEN);
}

uint32_t hw_rcc_get_fmc_clock_enable(void)
{
    return (__GET_RCC_AHB3ENR__ & RCC_AHB3ENR_FMCEN);
}

void hw_rcc_set_qspi_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB3ENR__, RCC_AHB3ENR_QSPIEN);
}

void hw_rcc_set_qspi_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB3ENR__, RCC_AHB3ENR_QSPIEN);
}

uint32_t hw_rcc_get_qspi_clock_enable(void)
{
    return (__GET_RCC_AHB3ENR__ & RCC_AHB3ENR_QSPIEN);
}

void hw_rcc_set_tim2_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM2EN);
}

void hw_rcc_set_tim2_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM2EN);
}

uint32_t hw_rcc_get_tim2_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_TIM2EN);
}

void hw_rcc_set_tim3_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM3EN);
}

void hw_rcc_set_tim3_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM3EN);
}

uint32_t hw_rcc_get_tim3_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_TIM3EN);
}

void hw_rcc_set_tim4_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM4EN);
}

void hw_rcc_set_tim4_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM4EN);
}

uint32_t hw_rcc_get_tim4_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_TIM4EN);
}

void hw_rcc_set_tim5_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM5EN);
}

void hw_rcc_set_tim5_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM5EN);
}

uint32_t hw_rcc_get_tim5_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_TIM5EN);
}

void hw_rcc_set_tim6_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM6EN);
}

void hw_rcc_set_tim6_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM6EN);
}

uint32_t hw_rcc_get_tim6_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_TIM6EN);
}

void hw_rcc_set_tim7_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM7EN);
}

void hw_rcc_set_tim7_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_TIM7EN);
}

uint32_t hw_rcc_get_tim7_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_TIM7EN);
}

void hw_rcc_set_wwdg_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_WWDGEN);
}

void hw_rcc_set_wwdg_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_WWDGEN);
}

uint32_t hw_rcc_get_wwdg_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_WWDGEN);
}

void hw_rcc_set_spi2_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_SPI2EN);
}

void hw_rcc_set_spi2_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_SPI2EN);
}

uint32_t hw_rcc_get_spi2_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_SPI2EN);
}

void hw_rcc_set_spi3_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_SPI3EN);
}

void hw_rcc_set_spi3_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_SPI3EN);
}

uint32_t hw_rcc_get_spi3_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_SPI3EN);
}

void hw_rcc_set_usart2_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_USART2EN);
}

void hw_rcc_set_usart2_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_USART2EN);
}

uint32_t hw_rcc_get_usart2_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_USART2EN);
}

void hw_rcc_set_usart3_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_USART3EN);
}

void hw_rcc_set_usart3_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_USART3EN);
}

uint32_t hw_rcc_get_usart3_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_USART3EN);
}

void hw_rcc_set_uart4_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_UART4EN);
}

void hw_rcc_set_uart4_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_UART4EN);
}

uint32_t hw_rcc_get_uart4_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_UART4EN);
}

void hw_rcc_set_uart5_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_UART5EN);
}

void hw_rcc_set_uart5_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_UART5EN);
}

uint32_t hw_rcc_get_uart5_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_UART5EN);
}

void hw_rcc_set_i2c1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_I2C1EN);
}

void hw_rcc_set_i2c1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_I2C1EN);
}

uint32_t hw_rcc_get_i2c1_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_I2C1EN);
}

void hw_rcc_set_i2c2_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_I2C2EN);
}

void hw_rcc_set_i2c2_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_I2C2EN);
}

uint32_t hw_rcc_get_i2c2_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_I2C2EN);
}

void hw_rcc_set_i2c3_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_I2C3EN);
}

void hw_rcc_set_i2c3_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_I2C3EN);
}

uint32_t hw_rcc_get_i2c3_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_I2C3EN);
}

void hw_rcc_set_can1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_CAN1EN);
}

void hw_rcc_set_can1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_CAN1EN);
}

uint32_t hw_rcc_get_can1_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_CAN1EN);
}

void hw_rcc_set_power_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_PWREN);
}

void hw_rcc_set_power_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_PWREN);
}

uint32_t hw_rcc_get_power_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_PWREN);
}

void hw_rcc_set_dac1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_DAC1EN);
}

void hw_rcc_set_dac1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_DAC1EN);
}

uint32_t hw_rcc_get_dac1_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_DAC1EN);
}

void hw_rcc_set_opamp_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_OPAMPEN);
}

void hw_rcc_set_opamp_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_OPAMPEN);
}

uint32_t hw_rcc_get_opamp_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_OPAMPEN);
}

void hw_rcc_set_lptim1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_LPTIM1EN);
}

void hw_rcc_set_lptim1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR1__, RCC_APB1ENR1_LPTIM1EN);
}

uint32_t hw_rcc_get_lptim1_clock_enable(void)
{
    return (__GET_RCC_APB1ENR1__ & RCC_APB1ENR1_LPTIM1EN);
}

void hw_rcc_set_lpuart1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR2__, RCC_APB1ENR2_LPUART1EN);
}

void hw_rcc_set_lpuart1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR2__, RCC_APB1ENR2_LPUART1EN);
}

uint32_t hw_rcc_get_lpuart1_clock_enable(void)
{
    return (__GET_RCC_APB1ENR2__ & RCC_APB1ENR2_LPUART1EN);
}

void hw_rcc_set_swpmi1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR2__, RCC_APB1ENR2_SWPMI1EN);
}

void hw_rcc_set_swpmi1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR2__, RCC_APB1ENR2_SWPMI1EN);
}

uint32_t hw_rcc_get_swpmi1_clock_enable(void)
{
    return (__GET_RCC_APB1ENR2__ & RCC_APB1ENR2_SWPMI1EN);
}

void hw_rcc_set_lptim2_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR2__, RCC_APB1ENR2_LPTIM2EN);
}

void hw_rcc_set_lptim2_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR2__, RCC_APB1ENR2_LPTIM2EN);
}

uint32_t hw_rcc_get_lptim2_clock_enable(void)
{
    return (__GET_RCC_APB1ENR2__ & RCC_APB1ENR2_LPTIM2EN);
}

void hw_rcc_set_syscfg_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SYSCFGEN);
}

void hw_rcc_set_syscfg_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SYSCFGEN);
}

uint32_t hw_rcc_get_syscfg_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_SYSCFGEN);
}

void hw_rcc_set_firewall_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_FWEN);
}

void hw_rcc_set_firewall_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_FWEN);
}

uint32_t hw_rcc_get_firewall_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_FWEN);
}

void hw_rcc_set_sdmmc1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SDMMC1EN);
}

void hw_rcc_set_sdmmc1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SDMMC1EN);
}

uint32_t hw_rcc_get_sdmmc1_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_SDMMC1EN);
}

void hw_rcc_set_tim1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM1EN);
}

void hw_rcc_set_tim1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM1EN);
}

uint32_t hw_rcc_get_tim1_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_TIM1EN);
}

void hw_rcc_set_spi1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SPI1EN);
}

void hw_rcc_set_spi1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SPI1EN);
}

uint32_t hw_rcc_get_spi1_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_SPI1EN);
}

void hw_rcc_set_tim8_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM8EN);
}

void hw_rcc_set_tim8_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM8EN);
}

uint32_t hw_rcc_get_tim8_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_TIM8EN);
}

void hw_rcc_set_usart1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_USART1EN);
}

void hw_rcc_set_usart1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_USART1EN);
}

uint32_t hw_rcc_get_usart1_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_USART1EN);
}

void hw_rcc_set_tim15_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM15EN);
}

void hw_rcc_set_tim15_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM15EN);
}

uint32_t hw_rcc_get_tim15_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_TIM15EN);
}

void hw_rcc_set_tim16_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM16EN);
}

void hw_rcc_set_tim16_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM16EN);
}

uint32_t hw_rcc_get_tim16_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_TIM16EN);
}

void hw_rcc_set_tim17_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM17EN);
}

void hw_rcc_set_tim17_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_TIM17EN);
}

uint32_t hw_rcc_get_tim17_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_TIM17EN);
}

void hw_rcc_set_sai1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SAI1EN);
}

void hw_rcc_set_sai1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SAI1EN);
}

uint32_t hw_rcc_get_sai1_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_SAI1EN);
}

void hw_rcc_set_sai2_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SAI2EN);
}

void hw_rcc_set_sai2_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_SAI2EN);
}

uint32_t hw_rcc_get_sai2_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_SAI2EN);
}

void hw_rcc_set_dfsam1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_DFSDM1EN);
}

void hw_rcc_set_dfsam1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_DFSDM1EN);
}

uint32_t hw_rcc_get_dfsam1_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_DFSDM1EN);
}

void hw_rcc_set_dma1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_DMA1SMEN);
}

void hw_rcc_set_dma1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_DMA1SMEN);
}

uint32_t hw_rcc_get_dma1sm_clock_enable(void)
{
    return (__GET_RCC_AHB1SMENR__ & RCC_AHB1SMENR_DMA1SMEN);
}

void hw_rcc_set_dma2sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_DMA2SMEN);
}

void hw_rcc_set_dma2sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_DMA2SMEN);
}

uint32_t hw_rcc_get_dma2sm_clock_enable(void)
{
    return (__GET_RCC_AHB1SMENR__ & RCC_AHB1SMENR_DMA2SMEN);
}

void hw_rcc_set_flashsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_FLASHSMEN);
}

void hw_rcc_set_flashsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_FLASHSMEN);
}

uint32_t hw_rcc_get_flashsm_clock_enable(void)
{
    return (__GET_RCC_AHB1SMENR__ & RCC_AHB1SMENR_FLASHSMEN);
}

void hw_rcc_set_sram1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_SRAM1SMEN);
}

void hw_rcc_set_sram1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_SRAM1SMEN);
}

uint32_t hw_rcc_get_sram1sm_clock_enable(void)
{
    return (__GET_RCC_AHB1SMENR__ & RCC_AHB1SMENR_SRAM1SMEN);
}

void hw_rcc_set_crcsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_CRCSMEN);
}

void hw_rcc_set_crcsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_CRCSMEN);
}

uint32_t hw_rcc_get_crcsm_clock_enable(void)
{
    return (__GET_RCC_AHB1SMENR__ & RCC_AHB1SMENR_CRCSMEN);
}

void hw_rcc_set_tscsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_TSCSMEN);
}

void hw_rcc_set_tscsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB1SMENR__, RCC_AHB1SMENR_TSCSMEN);
}

uint32_t hw_rcc_get_tscsm_clock_enable(void)
{
    return (__GET_RCC_AHB1SMENR__ & RCC_AHB1SMENR_TSCSMEN);
}

void hw_rcc_set_gpioasm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOASMEN);
}

void hw_rcc_set_gpioasm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOASMEN);
}

uint32_t hw_rcc_get_gpioasm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_GPIOASMEN);
}

void hw_rcc_set_gpiobsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOBSMEN);
}

void hw_rcc_set_gpiobsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOBSMEN);
}

uint32_t hw_rcc_get_gpiobsm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_GPIOBSMEN);
}

void hw_rcc_set_gpiocsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOCSMEN);
}

void hw_rcc_set_gpiocsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOCSMEN);
}

uint32_t hw_rcc_get_gpiocsm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_GPIOCSMEN);
}

void hw_rcc_set_gpiodsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIODSMEN);
}

void hw_rcc_set_gpiodsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIODSMEN);
}

uint32_t hw_rcc_get_gpiodsm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_GPIODSMEN);
}

void hw_rcc_set_gpioesm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOESMEN);
}

void hw_rcc_set_gpioesm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOESMEN);
}

uint32_t hw_rcc_get_gpioesm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_GPIOESMEN);
}

void hw_rcc_set_gpiofsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOFSMEN);
}

void hw_rcc_set_gpiofsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOFSMEN);
}

uint32_t hw_rcc_get_gpiofsm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_GPIOFSMEN);
}

void hw_rcc_set_gpiogsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOGSMEN);
}

void hw_rcc_set_gpiogsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOGSMEN);
}

uint32_t hw_rcc_get_gpiogsm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_GPIOGSMEN);
}

void hw_rcc_set_gpiohsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOHSMEN);
}

void hw_rcc_set_gpiohsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_GPIOHSMEN);
}

uint32_t hw_rcc_get_gpiohsm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_GPIOHSMEN);
}

void hw_rcc_set_sram2sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_SRAM2SMEN);
}

void hw_rcc_set_sram2sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_SRAM2SMEN);
}

uint32_t hw_rcc_get_sram2sm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_SRAM2SMEN);
}

void hw_rcc_set_otgfssm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_OTGFSSMEN);
}

void hw_rcc_set_otgfssm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_OTGFSSMEN);
}

uint32_t hw_rcc_get_otgfssm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_OTGFSSMEN);
}

void hw_rcc_set_adcsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_ADCSMEN);
}

void hw_rcc_set_adcsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_ADCSMEN);
}

uint32_t hw_rcc_get_adcsm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_ADCSMEN);
}

void hw_rcc_set_rngsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_RNGSMEN);
}

void hw_rcc_set_rngsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB2SMENR__, RCC_AHB2SMENR_RNGSMEN);
}

uint32_t hw_rcc_get_rngsm_clock_enable(void)
{
    return (__GET_RCC_AHB2SMENR__ & RCC_AHB2SMENR_RNGSMEN);
}

void hw_rcc_set_fmcsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB3SMENR__, RCC_AHB3SMENR_FMCSMEN);
}

void hw_rcc_set_fmcsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB3SMENR__, RCC_AHB3SMENR_FMCSMEN);
}

uint32_t hw_rcc_get_fmcsm_clock_enable(void)
{
    return (__GET_RCC_AHB3SMENR__ & RCC_AHB3SMENR_FMCSMEN);
}

void hw_rcc_set_qspism_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_AHB3SMENR__, RCC_AHB3SMENR_QSPISMEN);
}

void hw_rcc_set_qspism_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_AHB3SMENR__, RCC_AHB3SMENR_QSPISMEN);
}

uint32_t hw_rcc_get_qspism_clock_enable(void)
{
    return (__GET_RCC_AHB3SMENR__ & RCC_AHB3SMENR_QSPISMEN);
}

void hw_rcc_set_tim2sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM2SMEN);
}

void hw_rcc_set_tim2sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM2SMEN);
}

uint32_t hw_rcc_get_tim2sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_TIM2SMEN);
}

void hw_rcc_set_tim3sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM3SMEN);
}

void hw_rcc_set_tim3sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM3SMEN);
}

uint32_t hw_rcc_get_tim3sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_TIM3SMEN);
}

void hw_rcc_set_tim4sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM4SMEN);
}

void hw_rcc_set_tim4sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM4SMEN);
}

uint32_t hw_rcc_get_tim4sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_TIM4SMEN);
}

void hw_rcc_set_tim5sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM5SMEN);
}

void hw_rcc_set_tim5sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM5SMEN);
}

uint32_t hw_rcc_get_tim5sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_TIM5SMEN);
}

void hw_rcc_set_tim6sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM6SMEN);
}

void hw_rcc_set_tim6sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM6SMEN);
}

uint32_t hw_rcc_get_tim6sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_TIM6SMEN);
}

void hw_rcc_set_tim7sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM7SMEN);
}

void hw_rcc_set_tim7sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_TIM7SMEN);
}

uint32_t hw_rcc_get_tim7sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_TIM7SMEN);
}

void hw_rcc_set_wwdgsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_WWDGSMEN);
}

void hw_rcc_set_wwdgsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_WWDGSMEN);
}

uint32_t hw_rcc_get_wwdgsm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_WWDGSMEN);
}

void hw_rcc_set_spi2sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_SPI2SMEN);
}

void hw_rcc_set_spi2sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_SPI2SMEN);
}

uint32_t hw_rcc_get_spi2sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_SPI2SMEN);
}

void hw_rcc_set_spi3sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_SPI3SMEN);
}

void hw_rcc_set_spi3sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_SPI3SMEN);
}

uint32_t hw_rcc_get_spi3sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_SPI3SMEN);
}

void hw_rcc_set_usart2sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_USART2SMEN);
}

void hw_rcc_set_usart2sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_USART2SMEN);
}

uint32_t hw_rcc_get_usart2sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_USART2SMEN);
}

void hw_rcc_set_usart3sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_USART3SMEN);
}

void hw_rcc_set_usart3sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_USART3SMEN);
}

uint32_t hw_rcc_get_usart3sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_USART3SMEN);
}

void hw_rcc_set_uart4sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_UART4SMEN);
}

void hw_rcc_set_uart4sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_UART4SMEN);
}

uint32_t hw_rcc_get_uart4sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_UART4SMEN);
}

void hw_rcc_set_uart5sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_UART5SMEN);
}

void hw_rcc_set_uart5sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_UART5SMEN);
}

uint32_t hw_rcc_get_uart5sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_UART5SMEN);
}

void hw_rcc_set_i2c1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_I2C1SMEN);
}

void hw_rcc_set_i2c1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_I2C1SMEN);
}

uint32_t hw_rcc_get_i2c1sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_I2C1SMEN);
}

void hw_rcc_set_i2c2sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_I2C2SMEN);
}

void hw_rcc_set_i2c2sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_I2C2SMEN);
}

uint32_t hw_rcc_get_i2c2sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_I2C2SMEN);
}

void hw_rcc_set_i2c3sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_I2C3SMEN);
}

void hw_rcc_set_i2c3sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_I2C3SMEN);
}

uint32_t hw_rcc_get_i2c3sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_I2C3SMEN);
}

void hw_rcc_set_can1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_CAN1SMEN);
}

void hw_rcc_set_can1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_CAN1SMEN);
}

uint32_t hw_rcc_get_can1sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_CAN1SMEN);
}

void hw_rcc_set_powersm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_PWRSMEN);
}

void hw_rcc_set_powersm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_PWRSMEN);
}

uint32_t hw_rcc_get_powersm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_PWRSMEN);
}

void hw_rcc_set_dac1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_DAC1SMEN);
}

void hw_rcc_set_dac1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_DAC1SMEN);
}

uint32_t hw_rcc_get_dac1sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_DAC1SMEN);
}

void hw_rcc_set_opampsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_OPAMPSMEN);
}

void hw_rcc_set_opampsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_OPAMPSMEN);
}

uint32_t hw_rcc_get_opampsm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_OPAMPSMEN);
}

void hw_rcc_set_lptim1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_LPTIM1SMEN);
}

void hw_rcc_set_lptim1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR1__, RCC_APB1SMENR1_LPTIM1SMEN);
}

uint32_t hw_rcc_get_lptim1sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR1__ & RCC_APB1SMENR1_LPTIM1SMEN);
}

void hw_rcc_set_lpusart1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR2__, RCC_APB1SMENR2_LPUART1SMEN);
}

void hw_rcc_set_lpusart1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR2__, RCC_APB1SMENR2_LPUART1SMEN);
}

uint32_t hw_rcc_get_lpusart1sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR2__ & RCC_APB1SMENR2_LPUART1SMEN);
}

void hw_rcc_set_swpmi1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR2__, RCC_APB1SMENR2_SWPMI1SMEN);
}

void hw_rcc_set_swpmi1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR2__, RCC_APB1SMENR2_SWPMI1SMEN);
}

uint32_t hw_rcc_get_swpmi1sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR2__ & RCC_APB1SMENR2_SWPMI1SMEN);
}

void hw_rcc_set_lptim2sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1SMENR2__, RCC_APB1SMENR2_LPTIM2SMEN);
}

void hw_rcc_set_lptim2sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1SMENR2__, RCC_APB1SMENR2_LPTIM2SMEN);
}

uint32_t hw_rcc_get_lptim2sm_clock_enable(void)
{
    return (__GET_RCC_APB1SMENR2__ & RCC_APB1SMENR2_LPTIM2SMEN);
}

void hw_rcc_set_syscfgsm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SYSCFGSMEN);
}

void hw_rcc_set_syscfgsm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SYSCFGSMEN);
}

uint32_t hw_rcc_get_syscfgsm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_SYSCFGSMEN);
}

void hw_rcc_set_ssmmc1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SDMMC1SMEN);
}

void hw_rcc_set_ssmmc1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SDMMC1SMEN);
}

uint32_t hw_rcc_get_ssmmc1sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_SDMMC1SMEN);
}

void hw_rcc_set_tim1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM1SMEN);
}

void hw_rcc_set_tim1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM1SMEN);
}

uint32_t hw_rcc_get_tim1sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_TIM1SMEN);
}

void hw_rcc_set_spi1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SPI1SMEN);
}

void hw_rcc_set_spi1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SPI1SMEN);
}

uint32_t hw_rcc_get_spi1sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_SPI1SMEN);
}

void hw_rcc_set_tim8sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM8SMEN);
}

void hw_rcc_set_tim8sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM8SMEN);
}

uint32_t hw_rcc_get_tim8sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_TIM8SMEN);
}

void hw_rcc_set_usart1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_USART1SMEN);
}

void hw_rcc_set_usart1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_USART1SMEN);
}

uint32_t hw_rcc_get_usart1sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_USART1SMEN);
}

void hw_rcc_set_tim15sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM15SMEN);
}

void hw_rcc_set_tim15sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM15SMEN);
}

uint32_t hw_rcc_get_tim15sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_TIM15SMEN);
}

void hw_rcc_set_tim16sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM16SMEN);
}

void hw_rcc_set_tim16sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM16SMEN);
}

uint32_t hw_rcc_get_tim16sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_TIM16SMEN);
}

void hw_rcc_set_tim17sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM17SMEN);
}

void hw_rcc_set_tim17sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_TIM17SMEN);
}

uint32_t hw_rcc_get_tim17sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_TIM17SMEN);
}

void hw_rcc_set_sai1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SAI1SMEN);
}

void hw_rcc_set_sai1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SAI1SMEN);
}

uint32_t hw_rcc_get_sai1sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_SAI1SMEN);
}

void hw_rcc_set_sai2sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SAI2SMEN);
}

void hw_rcc_set_sai2sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_SAI2SMEN);
}

uint32_t hw_rcc_get_sai2sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_SAI2SMEN);
}

void hw_rcc_set_dfsdm1sm_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_DFSDM1SMEN);
}

void hw_rcc_set_dfsdm1sm_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2SMENR__, RCC_APB2SMENR_DFSDM1SMEN);
}

uint32_t hw_rcc_get_dfsdm1sm_clock_enable(void)
{
    return (__GET_RCC_APB2SMENR__ & RCC_APB2SMENR_DFSDM1SMEN);
}

void hw_rcc_select_usart1_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_USART1SEL, source);
}

uint32_t hw_rcc_get_usart1_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_USART1SEL);
}

void hw_rcc_select_usart2_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_USART2SEL, source);
}

uint32_t hw_rcc_get_usart2_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_USART2SEL);
}

void hw_rcc_select_usart3_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_USART3SEL, source);
}

uint32_t hw_rcc_get_usart3_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_USART3SEL);
}

void hw_rcc_select_uart4_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_UART4SEL, source);
}

uint32_t hw_rcc_get_uart4_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_UART4SEL);
}

void hw_rcc_select_uart5_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_UART5SEL, source);
}

uint32_t hw_rcc_get_uart5_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_UART5SEL);
}

void hw_rcc_select_lpuart1_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_LPUART1SEL, source);
}

uint32_t hw_rcc_get_lpuart1_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_LPUART1SEL);
}

void hw_rcc_select_i2c1_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_I2C1SEL, source);
}

uint32_t hw_rcc_get_i2c1_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_I2C1SEL);
}

void hw_rcc_select_i2c2_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_I2C2SEL, source);
}

uint32_t hw_rcc_get_i2c2_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_I2C2SEL);
}

void hw_rcc_select_i2c3_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_I2C3SEL, source);
}

uint32_t hw_rcc_get_i2c3_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_I2C3SEL);
}

void hw_rcc_select_lptim1_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_LPTIM1SEL, source);
}

uint32_t hw_rcc_get_lptim1_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_LPTIM1SEL);
}

void hw_rcc_select_lptim2_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_LPTIM2SEL, source);
}

uint32_t hw_rcc_get_lptim2_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_LPTIM2SEL);
}

void hw_rcc_select_sai1_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_SAI1SEL, source);
}

uint32_t hw_rcc_get_sai1_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_SAI1SEL);
}

void hw_rcc_select_sai2_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_SAI2SEL, source);
}

uint32_t hw_rcc_get_sai2_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_SAI2SEL);
}

void hw_rcc_select_clk48_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_CLK48SEL, source);
}

uint32_t hw_rcc_get_clk48_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_CLK48SEL);
}

void hw_rcc_select_adc_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_ADCSEL, source);
}

uint32_t hw_rcc_get_adc_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_ADCSEL);
}

void hw_rcc_select_swpmi1_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_SWPMI1SEL, source);
}

uint32_t hw_rcc_get_swpmi1_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_SWPMI1SEL);
}

void hw_rcc_select_dfsdm1_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CCIPR__, RCC_CCIPR_DFSDM1SEL, source);
}

uint32_t hw_rcc_get_dfsdm1_clock_source(void)
{
    return (__GET_RCC_CCIPR__ & RCC_CCIPR_DFSDM1SEL);
}

void hw_rcc_set_lse_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_BDCR__, RCC_BDCR_LSEON);
}

void hw_rcc_set_lse_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_BDCR__, RCC_BDCR_LSEON);
}

uint32_t hw_rcc_get_lse_clock_enable(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_LSEON);
}

uint32_t hw_rcc_lse_clock_ready_status(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_LSERDY);
}

void hw_rcc_lse_clock_wait_ready(void)
{
    while(!(__GET_RCC_BDCR__ & RCC_BDCR_LSERDY));
}

void hw_rcc_set_lse_clock_bypass(void)
{
    __BIT_OR__(__GET_RCC_BDCR__, RCC_BDCR_LSEBYP);
}

void hw_rcc_set_lse_clock_no_bypass(void)
{
    __BIT_RESET__(__GET_RCC_BDCR__, RCC_BDCR_LSEBYP);
}

uint32_t hw_rcc_get_lse_clock_bypass_status(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_LSEBYP);
}

void hw_rcc_set_lse_clock_drive_capability(uint32_t drive)
{
    __BIT_COVER_SET__(__GET_RCC_BDCR__, RCC_BDCR_LSEDRV, drive);
}

uint32_t hw_rcc_get_lse_clock_drive_capability(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_LSEDRV);
}

void hw_rcc_set_css_on_lse_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_BDCR__, RCC_BDCR_LSECSSON);
}

void hw_rcc_set_css_on_lse_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_BDCR__, RCC_BDCR_LSECSSON);
}

uint32_t hw_rcc_get_css_on_lse_clock_enable(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_LSECSSON);
}

uint32_t hw_rcc_detect_css_on_lse_clock_failure_status(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_LSECSSD);
}

void hw_rcc_select_rtc_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_BDCR__, RCC_BDCR_RTCSEL, source);
}

uint32_t hw_rcc_get_rtc_clock_source(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_RTCSEL);
}

void hw_rcc_set_rtc_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_BDCR__, RCC_BDCR_RTCEN);
}

void hw_rcc_set_rtc_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_BDCR__, RCC_BDCR_RTCEN);
}

uint32_t hw_rcc_get_rtc_clock_enable(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_RTCEN);
}

void hw_rcc_set_backup_domain_reset(void)
{
    __BIT_OR__(__GET_RCC_BDCR__, RCC_BDCR_BDRST);
}

void hw_rcc_wait_backup_domain_reset(void)
{
    while(__GET_RCC_BDCR__ & RCC_BDCR_BDRST);
}

void hw_rcc_set_low_speed_clock_output_enable(void)
{
    __BIT_OR__(__GET_RCC_BDCR__, RCC_BDCR_LSCOEN);
}

void hw_rcc_set_low_speed_clock_output_disable(void)
{
    __BIT_RESET__(__GET_RCC_BDCR__, RCC_BDCR_LSCOEN);
}

uint32_t hw_rcc_get_low_speed_clock_output_enable(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_LSCOEN);
}

void hw_rcc_select_low_speed_clock_output_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_BDCR__, RCC_BDCR_LSCOSEL, source);
}

uint32_t hw_rcc_get_low_speed_clock_output_source(void)
{
    return (__GET_RCC_BDCR__ & RCC_BDCR_LSCOSEL);
}

void hw_rcc_set_lsi_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CSR__, RCC_CSR_LSION);
}

void hw_rcc_set_lsi_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CSR__, RCC_CSR_LSION);
}

uint32_t hw_rcc_get_lsi_clock_enable(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_LSION);
}

uint32_t hw_rcc_lsi_clock_ready_status(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_LSIRDY);
}

void hw_rcc_lsi_clock_wait_ready(void)
{
    while(!(__GET_RCC_CSR__ & RCC_CSR_LSIRDY));
}

void hw_rcc_select_msi_range_after_standby_mode(uint32_t mode)
{
    __BIT_COVER_SET__(__GET_RCC_CSR__, RCC_CSR_MSISRANGE, mode);
}

uint32_t hw_rcc_get_msi_range_after_standby_mode(uint32_t source)
{
    return (__GET_RCC_CSR__ & RCC_CSR_MSISRANGE);
}

void hw_rcc_clear_reset_flag(void)
{
    __BIT_OR__(__GET_RCC_CSR__, RCC_CSR_RMVF);
}

uint32_t hw_rcc_firewall_reset_flag(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_FWRSTF);
}

uint32_t hw_rcc_option_byte_loader_reset_flag(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_OBLRSTF);
}

uint32_t hw_rcc_pin_reset_flag(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_PINRSTF);
}

uint32_t hw_rcc_bor_reset_flag(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_BORRSTF);
}

uint32_t hw_rcc_software_reset_flag(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_SFTRSTF);
}

uint32_t hw_rcc_iwatchdog_reset_flag(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_IWDGRSTF);
}

uint32_t hw_rcc_wwatchdog_reset_flag(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_WWDGRSTF);
}

uint32_t hw_rcc_low_power_reset_flag(void)
{
    return (__GET_RCC_CSR__ & RCC_CSR_LPWRRSTF);
}