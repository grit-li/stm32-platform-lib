#ifndef __SETM32_PLATFORM_RCC_H__
#define __SETM32_PLATFORM_RCC_H__

#include <stdint.h>
#include <stm32_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HZ(x)  (x)
#define KHZ(x) (x * 1000)
#define MHZ(x) (x * 1000000)

enum rcc_clock_tree_e
{
    rcc_clock_lse,
    rcc_clock_lsi,
    rcc_clock_msi,
    rcc_clock_hsi,
    rcc_clock_hse,

    rcc_clock_pllclk,
    rcc_clock_pllq,
    rcc_clock_pllp,

    rcc_clock_pllsai1r,
    rcc_clock_pllsai1q,
    rcc_clock_pllsai1p,

    rcc_clock_pllsai2r,
    rcc_clock_pllsai2p,

    rcc_clock_sysclk,

    rcc_clock_tree_max
};

enum rcc_msi_clock_freq_e
{
    rcc_msi_clock_freq_0     = HZ(0),
    rcc_msi_clock_freq_100   = KHZ(100),
    rcc_msi_clock_freq_200   = KHZ(200),
    rcc_msi_clock_freq_400   = KHZ(400),
    rcc_msi_clock_freq_800   = KHZ(800),
    rcc_msi_clock_freq_1000  = MHZ(1),
    rcc_msi_clock_freq_2000  = MHZ(2),
    rcc_msi_clock_freq_4000  = MHZ(4),
    rcc_msi_clock_freq_8000  = MHZ(8),
    rcc_msi_clock_freq_16000 = MHZ(16),
    rcc_msi_clock_freq_24000 = MHZ(24),
    rcc_msi_clock_freq_32000 = MHZ(32),
    rcc_msi_clock_freq_48000 = MHZ(48),
};

enum rcc_pll_mul_e
{
    rcc_pll_mul_8 = 8,
    rcc_pll_mul_9,
    rcc_pll_mul_10,
    rcc_pll_mul_11,
    rcc_pll_mul_12,
    rcc_pll_mul_13,
    rcc_pll_mul_14,
    rcc_pll_mul_15,
    rcc_pll_mul_16,
    rcc_pll_mul_17,
    rcc_pll_mul_18,
    rcc_pll_mul_19,
    rcc_pll_mul_20,
    rcc_pll_mul_21,
    rcc_pll_mul_22,
    rcc_pll_mul_23,
    rcc_pll_mul_24,
    rcc_pll_mul_25,
    rcc_pll_mul_26,
    rcc_pll_mul_27,
    rcc_pll_mul_28,
    rcc_pll_mul_29,
    rcc_pll_mul_30,
    rcc_pll_mul_31,
    rcc_pll_mul_32,
    rcc_pll_mul_33,
    rcc_pll_mul_34,
    rcc_pll_mul_35,
    rcc_pll_mul_36,
    rcc_pll_mul_37,
    rcc_pll_mul_38,
    rcc_pll_mul_39,
    rcc_pll_mul_40,
    rcc_pll_mul_41,
    rcc_pll_mul_42,
    rcc_pll_mul_43,
    rcc_pll_mul_44,
    rcc_pll_mul_45,
    rcc_pll_mul_46,
    rcc_pll_mul_47,
    rcc_pll_mul_48,
    rcc_pll_mul_49,
    rcc_pll_mul_50,
    rcc_pll_mul_51,
    rcc_pll_mul_52,
    rcc_pll_mul_53,
    rcc_pll_mul_54,
    rcc_pll_mul_55,
    rcc_pll_mul_56,
    rcc_pll_mul_57,
    rcc_pll_mul_58,
    rcc_pll_mul_59,
    rcc_pll_mul_60,
    rcc_pll_mul_61,
    rcc_pll_mul_62,
    rcc_pll_mul_63,
    rcc_pll_mul_64,
    rcc_pll_mul_65,
    rcc_pll_mul_66,
    rcc_pll_mul_67,
    rcc_pll_mul_68,
    rcc_pll_mul_69,
    rcc_pll_mul_70,
    rcc_pll_mul_71,
    rcc_pll_mul_72,
    rcc_pll_mul_73,
    rcc_pll_mul_74,
    rcc_pll_mul_75,
    rcc_pll_mul_76,
    rcc_pll_mul_77,
    rcc_pll_mul_78,
    rcc_pll_mul_79,
    rcc_pll_mul_80,
    rcc_pll_mul_81,
    rcc_pll_mul_82,
    rcc_pll_mul_83,
    rcc_pll_mul_84,
    rcc_pll_mul_85,
    rcc_pll_mul_86,
};

enum rcc_pll_clock_source_e
{
    rcc_pll_clock_source_msi,
    rcc_pll_clock_source_hsi,
    rcc_pll_clock_source_hse,
};

enum rcc_rtc_clock_source_e
{
    rcc_rtc_clock_source_hse_rtc,
    rcc_rtc_clock_source_lse,
    rcc_rtc_clock_source_lsi,
};

enum rcc_system_clock_source_e
{
    rcc_system_clock_source_msi,
    rcc_system_clock_source_hsi,
    rcc_system_clock_source_hse,
    rcc_system_clock_source_pllclk,
};

enum rcc_clk48_source_e
{
    rcc_clk48_source_pllsai1q,
    rcc_clk48_source_pllq,
    rcc_clk48_source_msi,
};

enum rcc_adc_clock_source_e
{
    rcc_adc_clock_source_pllsai1r,
    rcc_adc_clock_source_pllsai2r,
    rcc_adc_clock_source_sysclk,
};

enum rcc_sai_clock_source_e
{
    rcc_sai_clock_source_pllsai1p,
    rcc_sai_clock_source_pllsai2p,
    rcc_sai_clock_source_pllp,
    rcc_sai_clock_source_ext_sai,
};

enum rcc_i2c_clock_source_e
{
    rcc_i2c_clock_source_pclk1,
    rcc_i2c_clock_source_sysclk,
    rcc_i2c_clock_source_hsi,
};

enum rcc_dfsdm1_clock_source_e
{
    rcc_dfsdm1_clock_source_pclk2,
    rcc_dfsdm1_clock_source_sysclk,
};

enum rcc_usart_clock_source_e
{
    rcc_usart_clock_source_pclk2,
    rcc_usart_clock_source_sysclk,
    rcc_usart_clock_source_hsi,
    rcc_usart_clock_source_lse,
};

enum rcc_lptim_clock_source_e
{
    rcc_lptim_clock_source_pclk1,
    rcc_lptim_clock_source_lsi,
    rcc_lptim_clock_source_hsi,
    rcc_lptim_clock_source_lse,
};

enum rcc_swpmi1_clock_source_e
{
    rcc_swpmi1_clock_source_pclk1,
    rcc_swpmi1_clock_source_hsi,
};

enum rcc_mco_clock_source_e
{
    rcc_mco_clock_source_lse,
    rcc_mco_clock_source_lsi,
    rcc_mco_clock_source_hse,
    rcc_mco_clock_source_hsi,
    rcc_mco_clock_source_pllclk,
    rcc_mco_clock_source_sysclk,
    rcc_mco_clock_source_msi,
};

enum rcc_lsco_clock_source_e
{
    rcc_lsco_clock_source_lse,
    rcc_lsco_clock_source_lsi,
};

enum rcc_clock_prescaler_e
{
    rcc_clock_prescaler_1,
    rcc_clock_prescaler_2,
    rcc_clock_prescaler_3,
    rcc_clock_prescaler_4,
    rcc_clock_prescaler_5,
    rcc_clock_prescaler_6,
    rcc_clock_prescaler_7,
    rcc_clock_prescaler_8,
    rcc_clock_prescaler_16,
    rcc_clock_prescaler_64,
    rcc_clock_prescaler_128,
    rcc_clock_prescaler_256,
    rcc_clock_prescaler_512,
};

enum rcc_peripheral_clock_enable_e
{
    rcc_peripheral_clock_disable = 0,
    rcc_peripheral_clock_enable = 1,
};

struct rcc_clock_enable_t
{
    enum rcc_peripheral_clock_enable_e IOPAEN;
    enum rcc_peripheral_clock_enable_e IOPBEN;
    enum rcc_peripheral_clock_enable_e IOPCEN;
    enum rcc_peripheral_clock_enable_e IOPDEN;
    enum rcc_peripheral_clock_enable_e IOPEEN;
    enum rcc_peripheral_clock_enable_e IOPFEN;
    enum rcc_peripheral_clock_enable_e IOPGEN;
};

struct rcc_clock_scale_t
{
    uint32_t lse;
    uint32_t lsi;
    uint32_t msi;
    uint32_t hsi;
    uint32_t hse;

    enum rcc_pll_mul_e pll_mul;
    enum rcc_pll_mul_e pllsai1_mul;
    enum rcc_pll_mul_e pllsai2_mul;

    enum rcc_pll_clock_source_e pll_source;
    enum rcc_rtc_clock_source_e rtc_source;
    enum rcc_system_clock_source_e system_clock_source;
    enum rcc_clk48_source_e clk48_source;
    enum rcc_adc_clock_source_e adc_source;
    enum rcc_sai_clock_source_e sai1_source;
    enum rcc_sai_clock_source_e sai2_source;
    enum rcc_i2c_clock_source_e i2c1_source;
    enum rcc_i2c_clock_source_e i2c2_source;
    enum rcc_i2c_clock_source_e i2c3_source;
    enum rcc_dfsdm1_clock_source_e dfsdm1_source;
    enum rcc_usart_clock_source_e usart1_source;
    enum rcc_usart_clock_source_e usart2_source;
    enum rcc_usart_clock_source_e usart3_source;
    enum rcc_usart_clock_source_e usart4_source;
    enum rcc_usart_clock_source_e usart5_source;
    enum rcc_usart_clock_source_e lpusart1_source;
    enum rcc_lptim_clock_source_e lptime_source;
    enum rcc_swpmi1_clock_source_e swpmi1_source;
    enum rcc_mco_clock_source_e mco_source;
    enum rcc_lsco_clock_source_e lsco_source;

    enum rcc_clock_prescaler_e pllm_prescaler;
    enum rcc_clock_prescaler_e pllr_prescaler;
    enum rcc_clock_prescaler_e pllq_prescaler;
    enum rcc_clock_prescaler_e pllp_prescaler;
    enum rcc_clock_prescaler_e pllsai1r_prescaler;
    enum rcc_clock_prescaler_e pllsai1q_prescaler;
    enum rcc_clock_prescaler_e pllsai1p_prescaler;
    enum rcc_clock_prescaler_e pllsai2r_prescaler;
    enum rcc_clock_prescaler_e pllsai2p_prescaler;
    enum rcc_clock_prescaler_e ahb_prescaler;
    enum rcc_clock_prescaler_e apb1_prescaler;
    enum rcc_clock_prescaler_e apb2_prescaler;
    enum rcc_clock_prescaler_e cortex_system_prescaler;
    enum rcc_clock_prescaler_e mco_prescaler;

    struct rcc_clock_enable_t clock_enable;
};

void rcc_clock_setup_init(const struct rcc_clock_scale_t *);
void rcc_update_clock_tree(const struct rcc_clock_scale_t *);
uint32_t rcc_get_clock_freq(enum rcc_clock_tree_e);

#ifdef __cplusplus
}
#endif

#endif