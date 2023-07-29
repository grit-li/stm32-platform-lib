#ifndef __SETM32_PLATFORM_HW_RCC_H__
#define __SETM32_PLATFORM_HW_RCC_H__

#include <stdint.h>
#include <stdbool.h>
#include "cortex_m.h"
#include "stm32_hw_reg_map.h"
#include "stm32_bitops.h"

#ifdef __cplusplus
extern "C" {
#endif

struct RCC_TypeDef
{
    __IO uint32_t CR;          /*!< RCC clock control register,                                              Address offset: 0x00 */
    __IO uint32_t ICSCR;       /*!< RCC internal clock sources calibration register,                         Address offset: 0x04 */
    __IO uint32_t CFGR;        /*!< RCC clock configuration register,                                        Address offset: 0x08 */
    __IO uint32_t PLLCFGR;     /*!< RCC system PLL configuration register,                                   Address offset: 0x0C */
    __IO uint32_t PLLSAI1CFGR; /*!< RCC PLL SAI1 configuration register,                                     Address offset: 0x10 */
    __IO uint32_t PLLSAI2CFGR; /*!< RCC PLL SAI2 configuration register,                                     Address offset: 0x14 */
    __IO uint32_t CIER;        /*!< RCC clock interrupt enable register,                                     Address offset: 0x18 */
    __IO uint32_t CIFR;        /*!< RCC clock interrupt flag register,                                       Address offset: 0x1C */
    __IO uint32_t CICR;        /*!< RCC clock interrupt clear register,                                      Address offset: 0x20 */
    uint32_t      RESERVED0;   /*!< Reserved,                                                                Address offset: 0x24 */
    __IO uint32_t AHB1RSTR;    /*!< RCC AHB1 peripheral reset register,                                      Address offset: 0x28 */
    __IO uint32_t AHB2RSTR;    /*!< RCC AHB2 peripheral reset register,                                      Address offset: 0x2C */
    __IO uint32_t AHB3RSTR;    /*!< RCC AHB3 peripheral reset register,                                      Address offset: 0x30 */
    uint32_t      RESERVED1;   /*!< Reserved,                                                                Address offset: 0x34 */
    __IO uint32_t APB1RSTR1;   /*!< RCC APB1 peripheral reset register 1,                                    Address offset: 0x38 */
    __IO uint32_t APB1RSTR2;   /*!< RCC APB1 peripheral reset register 2,                                    Address offset: 0x3C */
    __IO uint32_t APB2RSTR;    /*!< RCC APB2 peripheral reset register,                                      Address offset: 0x40 */
    uint32_t      RESERVED2;   /*!< Reserved,                                                                Address offset: 0x44 */
    __IO uint32_t AHB1ENR;     /*!< RCC AHB1 peripheral clocks enable register,                              Address offset: 0x48 */
    __IO uint32_t AHB2ENR;     /*!< RCC AHB2 peripheral clocks enable register,                              Address offset: 0x4C */
    __IO uint32_t AHB3ENR;     /*!< RCC AHB3 peripheral clocks enable register,                              Address offset: 0x50 */
    uint32_t      RESERVED3;   /*!< Reserved,                                                                Address offset: 0x54 */
    __IO uint32_t APB1ENR1;    /*!< RCC APB1 peripheral clocks enable register 1,                            Address offset: 0x58 */
    __IO uint32_t APB1ENR2;    /*!< RCC APB1 peripheral clocks enable register 2,                            Address offset: 0x5C */
    __IO uint32_t APB2ENR;     /*!< RCC APB2 peripheral clocks enable register,                              Address offset: 0x60 */
    uint32_t      RESERVED4;   /*!< Reserved,                                                                Address offset: 0x64 */
    __IO uint32_t AHB1SMENR;   /*!< RCC AHB1 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x68 */
    __IO uint32_t AHB2SMENR;   /*!< RCC AHB2 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x6C */
    __IO uint32_t AHB3SMENR;   /*!< RCC AHB3 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x70 */
    uint32_t      RESERVED5;   /*!< Reserved,                                                                Address offset: 0x74 */
    __IO uint32_t APB1SMENR1;  /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1, Address offset: 0x78 */
    __IO uint32_t APB1SMENR2;  /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2, Address offset: 0x7C */
    __IO uint32_t APB2SMENR;   /*!< RCC APB2 peripheral clocks enable in sleep mode and stop modes register, Address offset: 0x80 */
    uint32_t      RESERVED6;   /*!< Reserved,                                                                Address offset: 0x84 */
    __IO uint32_t CCIPR;       /*!< RCC peripherals independent clock configuration register,                Address offset: 0x88 */
    uint32_t      RESERVED7;   /*!< Reserved,                                                                Address offset: 0x8C */
    __IO uint32_t BDCR;        /*!< RCC backup domain control register,                                      Address offset: 0x90 */
    __IO uint32_t CSR;         /*!< RCC clock control & status register,                                     Address offset: 0x94 */
};

#define RCC                 ((struct RCC_TypeDef *) RCC_BASE)
static inline struct RCC_TypeDef* __GET_RCC_REGISTER__(void)
{
    return RCC;
}

#define __GET_RCC_CR__          (__GET_RCC_REGISTER__()->CR)
#define __GET_RCC_ICSCR__       (__GET_RCC_REGISTER__()->ICSCR)
#define __GET_RCC_CFGR__        (__GET_RCC_REGISTER__()->CFGR)
#define __GET_RCC_PLLCFGR__     (__GET_RCC_REGISTER__()->PLLCFGR)
#define __GET_RCC_PLLSAI1CFGR__ (__GET_RCC_REGISTER__()->PLLSAI1CFGR)
#define __GET_RCC_PLLSAI2CFGR__ (__GET_RCC_REGISTER__()->PLLSAI2CFGR)
#define __GET_RCC_CIER__        (__GET_RCC_REGISTER__()->CIER)
#define __GET_RCC_CIFR__        (__GET_RCC_REGISTER__()->CIFR)
#define __GET_RCC_CICR__        (__GET_RCC_REGISTER__()->CICR)
#define __GET_RCC_AHB1RSTR__    (__GET_RCC_REGISTER__()->AHB1RSTR)
#define __GET_RCC_AHB2RSTR__    (__GET_RCC_REGISTER__()->AHB2RSTR)
#define __GET_RCC_AHB3RSTR__    (__GET_RCC_REGISTER__()->AHB3RSTR)
#define __GET_RCC_APB1RSTR1__   (__GET_RCC_REGISTER__()->APB1RSTR1)
#define __GET_RCC_APB1RSTR2__   (__GET_RCC_REGISTER__()->APB1RSTR2)
#define __GET_RCC_APB2RSTR__    (__GET_RCC_REGISTER__()->APB2RSTR)
#define __GET_RCC_AHB1ENR__     (__GET_RCC_REGISTER__()->AHB1ENR)
#define __GET_RCC_AHB2ENR__     (__GET_RCC_REGISTER__()->AHB2ENR)
#define __GET_RCC_AHB3ENR__     (__GET_RCC_REGISTER__()->AHB3ENR)
#define __GET_RCC_APB1ENR1__    (__GET_RCC_REGISTER__()->APB1ENR1)
#define __GET_RCC_APB1ENR2__    (__GET_RCC_REGISTER__()->APB1ENR2)
#define __GET_RCC_APB2ENR__     (__GET_RCC_REGISTER__()->APB2ENR)
#define __GET_RCC_AHB1SMENR__   (__GET_RCC_REGISTER__()->AHB1SMENR)
#define __GET_RCC_AHB2SMENR__   (__GET_RCC_REGISTER__()->AHB2SMENR)
#define __GET_RCC_AHB3SMENR__   (__GET_RCC_REGISTER__()->AHB3SMENR)
#define __GET_RCC_APB1SMENR1__  (__GET_RCC_REGISTER__()->APB1SMENR1)
#define __GET_RCC_APB1SMENR2__  (__GET_RCC_REGISTER__()->APB1SMENR2)
#define __GET_RCC_APB2SMENR__   (__GET_RCC_REGISTER__()->APB2SMENR)
#define __GET_RCC_CCIPR__       (__GET_RCC_REGISTER__()->CCIPR)
#define __GET_RCC_BDCR__        (__GET_RCC_REGISTER__()->BDCR)
#define __GET_RCC_CSR__         (__GET_RCC_REGISTER__()->CSR)

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/*
* @brief Specific device feature definitions  (not present on all devices in the STM32L4 serie)
*/
#define RCC_PLLSAI1_SUPPORT
#define RCC_PLLP_SUPPORT
#define RCC_PLLSAI2_SUPPORT

/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_MSION_Pos                     (0U)
#define RCC_CR_MSION_Msk                     (0x1UL << RCC_CR_MSION_Pos)       /*!< 0x00000001 */
#define RCC_CR_MSION                         RCC_CR_MSION_Msk                  /*!< Internal Multi Speed oscillator (MSI) clock enable */
#define RCC_CR_MSIRDY_Pos                    (1U)
#define RCC_CR_MSIRDY_Msk                    (0x1UL << RCC_CR_MSIRDY_Pos)      /*!< 0x00000002 */
#define RCC_CR_MSIRDY                        RCC_CR_MSIRDY_Msk                 /*!< Internal Multi Speed oscillator (MSI) clock ready flag */
#define RCC_CR_MSIPLLEN_Pos                  (2U)
#define RCC_CR_MSIPLLEN_Msk                  (0x1UL << RCC_CR_MSIPLLEN_Pos)    /*!< 0x00000004 */
#define RCC_CR_MSIPLLEN                      RCC_CR_MSIPLLEN_Msk               /*!< Internal Multi Speed oscillator (MSI) PLL enable */
#define RCC_CR_MSIRGSEL_Pos                  (3U)
#define RCC_CR_MSIRGSEL_Msk                  (0x1UL << RCC_CR_MSIRGSEL_Pos)    /*!< 0x00000008 */
#define RCC_CR_MSIRGSEL                      RCC_CR_MSIRGSEL_Msk               /*!< Internal Multi Speed oscillator (MSI) range selection */

/*!< MSIRANGE configuration : 12 frequency ranges available */
#define RCC_CR_MSIRANGE_Pos                  (4U)
#define RCC_CR_MSIRANGE_Msk                  (0xFUL << RCC_CR_MSIRANGE_Pos)    /*!< 0x000000F0 */
#define RCC_CR_MSIRANGE                      RCC_CR_MSIRANGE_Msk               /*!< Internal Multi Speed oscillator (MSI) clock Range */
#define RCC_CR_MSIRANGE_0                    (0x0UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000000 */
#define RCC_CR_MSIRANGE_1                    (0x1UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000010 */
#define RCC_CR_MSIRANGE_2                    (0x2UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000020 */
#define RCC_CR_MSIRANGE_3                    (0x3UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000030 */
#define RCC_CR_MSIRANGE_4                    (0x4UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000040 */
#define RCC_CR_MSIRANGE_5                    (0x5UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000050 */
#define RCC_CR_MSIRANGE_6                    (0x6UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000060 */
#define RCC_CR_MSIRANGE_7                    (0x7UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000070 */
#define RCC_CR_MSIRANGE_8                    (0x8UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000080 */
#define RCC_CR_MSIRANGE_9                    (0x9UL << RCC_CR_MSIRANGE_Pos)    /*!< 0x00000090 */
#define RCC_CR_MSIRANGE_10                   (0xAUL << RCC_CR_MSIRANGE_Pos)    /*!< 0x000000A0 */
#define RCC_CR_MSIRANGE_11                   (0xBUL << RCC_CR_MSIRANGE_Pos)    /*!< 0x000000B0 */

#define RCC_CR_HSION_Pos                     (8U)
#define RCC_CR_HSION_Msk                     (0x1UL << RCC_CR_HSION_Pos)       /*!< 0x00000100 */
#define RCC_CR_HSION                         RCC_CR_HSION_Msk                  /*!< Internal High Speed oscillator (HSI16) clock enable */
#define RCC_CR_HSIKERON_Pos                  (9U)
#define RCC_CR_HSIKERON_Msk                  (0x1UL << RCC_CR_HSIKERON_Pos)    /*!< 0x00000200 */
#define RCC_CR_HSIKERON                      RCC_CR_HSIKERON_Msk               /*!< Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel */
#define RCC_CR_HSIRDY_Pos                    (10U)
#define RCC_CR_HSIRDY_Msk                    (0x1UL << RCC_CR_HSIRDY_Pos)      /*!< 0x00000400 */
#define RCC_CR_HSIRDY                        RCC_CR_HSIRDY_Msk                 /*!< Internal High Speed oscillator (HSI16) clock ready flag */
#define RCC_CR_HSIASFS_Pos                   (11U)
#define RCC_CR_HSIASFS_Msk                   (0x1UL << RCC_CR_HSIASFS_Pos)     /*!< 0x00000800 */
#define RCC_CR_HSIASFS                       RCC_CR_HSIASFS_Msk                /*!< HSI16 Automatic Start from Stop */

#define RCC_CR_HSEON_Pos                     (16U)
#define RCC_CR_HSEON_Msk                     (0x1UL << RCC_CR_HSEON_Pos)       /*!< 0x00010000 */
#define RCC_CR_HSEON                         RCC_CR_HSEON_Msk                  /*!< External High Speed oscillator (HSE) clock enable */
#define RCC_CR_HSERDY_Pos                    (17U)
#define RCC_CR_HSERDY_Msk                    (0x1UL << RCC_CR_HSERDY_Pos)      /*!< 0x00020000 */
#define RCC_CR_HSERDY                        RCC_CR_HSERDY_Msk                 /*!< External High Speed oscillator (HSE) clock ready */
#define RCC_CR_HSEBYP_Pos                    (18U)
#define RCC_CR_HSEBYP_Msk                    (0x1UL << RCC_CR_HSEBYP_Pos)      /*!< 0x00040000 */
#define RCC_CR_HSEBYP                        RCC_CR_HSEBYP_Msk                 /*!< External High Speed oscillator (HSE) clock bypass */
#define RCC_CR_CSSON_Pos                     (19U)
#define RCC_CR_CSSON_Msk                     (0x1UL << RCC_CR_CSSON_Pos)       /*!< 0x00080000 */
#define RCC_CR_CSSON                         RCC_CR_CSSON_Msk                  /*!< HSE Clock Security System enable */

#define RCC_CR_PLLON_Pos                     (24U)
#define RCC_CR_PLLON_Msk                     (0x1UL << RCC_CR_PLLON_Pos)       /*!< 0x01000000 */
#define RCC_CR_PLLON                         RCC_CR_PLLON_Msk                  /*!< System PLL clock enable */
#define RCC_CR_PLLRDY_Pos                    (25U)
#define RCC_CR_PLLRDY_Msk                    (0x1UL << RCC_CR_PLLRDY_Pos)      /*!< 0x02000000 */
#define RCC_CR_PLLRDY                        RCC_CR_PLLRDY_Msk                 /*!< System PLL clock ready */
#define RCC_CR_PLLSAI1ON_Pos                 (26U)
#define RCC_CR_PLLSAI1ON_Msk                 (0x1UL << RCC_CR_PLLSAI1ON_Pos)   /*!< 0x04000000 */
#define RCC_CR_PLLSAI1ON                     RCC_CR_PLLSAI1ON_Msk              /*!< SAI1 PLL enable */
#define RCC_CR_PLLSAI1RDY_Pos                (27U)
#define RCC_CR_PLLSAI1RDY_Msk                (0x1UL << RCC_CR_PLLSAI1RDY_Pos)  /*!< 0x08000000 */
#define RCC_CR_PLLSAI1RDY                    RCC_CR_PLLSAI1RDY_Msk             /*!< SAI1 PLL ready */
#define RCC_CR_PLLSAI2ON_Pos                 (28U)
#define RCC_CR_PLLSAI2ON_Msk                 (0x1UL << RCC_CR_PLLSAI2ON_Pos)   /*!< 0x10000000 */
#define RCC_CR_PLLSAI2ON                     RCC_CR_PLLSAI2ON_Msk              /*!< SAI2 PLL enable */
#define RCC_CR_PLLSAI2RDY_Pos                (29U)
#define RCC_CR_PLLSAI2RDY_Msk                (0x1UL << RCC_CR_PLLSAI2RDY_Pos)  /*!< 0x20000000 */
#define RCC_CR_PLLSAI2RDY                    RCC_CR_PLLSAI2RDY_Msk             /*!< SAI2 PLL ready */

/********************  Bit definition for RCC_ICSCR register  ***************/
/*!< MSICAL configuration */
#define RCC_ICSCR_MSICAL_Pos                 (0U)
#define RCC_ICSCR_MSICAL_Msk                 (0xFFUL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x000000FF */
#define RCC_ICSCR_MSICAL                     RCC_ICSCR_MSICAL_Msk              /*!< MSICAL[7:0] bits */
#define RCC_ICSCR_MSICAL_0                   (0x01UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000001 */
#define RCC_ICSCR_MSICAL_1                   (0x02UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000002 */
#define RCC_ICSCR_MSICAL_2                   (0x04UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000004 */
#define RCC_ICSCR_MSICAL_3                   (0x08UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000008 */
#define RCC_ICSCR_MSICAL_4                   (0x10UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000010 */
#define RCC_ICSCR_MSICAL_5                   (0x20UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000020 */
#define RCC_ICSCR_MSICAL_6                   (0x40UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000040 */
#define RCC_ICSCR_MSICAL_7                   (0x80UL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x00000080 */

/*!< MSITRIM configuration */
#define RCC_ICSCR_MSITRIM_Pos                (8U)
#define RCC_ICSCR_MSITRIM_Msk                (0xFFUL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x0000FF00 */
#define RCC_ICSCR_MSITRIM                    RCC_ICSCR_MSITRIM_Msk             /*!< MSITRIM[7:0] bits */
#define RCC_ICSCR_MSITRIM_0                  (0x01UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00000100 */
#define RCC_ICSCR_MSITRIM_1                  (0x02UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00000200 */
#define RCC_ICSCR_MSITRIM_2                  (0x04UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00000400 */
#define RCC_ICSCR_MSITRIM_3                  (0x08UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00000800 */
#define RCC_ICSCR_MSITRIM_4                  (0x10UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00001000 */
#define RCC_ICSCR_MSITRIM_5                  (0x20UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00002000 */
#define RCC_ICSCR_MSITRIM_6                  (0x40UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00004000 */
#define RCC_ICSCR_MSITRIM_7                  (0x80UL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x00008000 */

/*!< HSICAL configuration */
#define RCC_ICSCR_HSICAL_Pos                 (16U)
#define RCC_ICSCR_HSICAL_Msk                 (0xFFUL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00FF0000 */
#define RCC_ICSCR_HSICAL                     RCC_ICSCR_HSICAL_Msk              /*!< HSICAL[7:0] bits */
#define RCC_ICSCR_HSICAL_0                   (0x01UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00010000 */
#define RCC_ICSCR_HSICAL_1                   (0x02UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00020000 */
#define RCC_ICSCR_HSICAL_2                   (0x04UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00040000 */
#define RCC_ICSCR_HSICAL_3                   (0x08UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00080000 */
#define RCC_ICSCR_HSICAL_4                   (0x10UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00100000 */
#define RCC_ICSCR_HSICAL_5                   (0x20UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00200000 */
#define RCC_ICSCR_HSICAL_6                   (0x40UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00400000 */
#define RCC_ICSCR_HSICAL_7                   (0x80UL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00800000 */

/*!< HSITRIM configuration */
#define RCC_ICSCR_HSITRIM_Pos                (24U)
#define RCC_ICSCR_HSITRIM_Msk                (0x1FUL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x1F000000 */
#define RCC_ICSCR_HSITRIM                    RCC_ICSCR_HSITRIM_Msk             /*!< HSITRIM[4:0] bits */
#define RCC_ICSCR_HSITRIM_0                  (0x01UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x01000000 */
#define RCC_ICSCR_HSITRIM_1                  (0x02UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x02000000 */
#define RCC_ICSCR_HSITRIM_2                  (0x04UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x04000000 */
#define RCC_ICSCR_HSITRIM_3                  (0x08UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x08000000 */
#define RCC_ICSCR_HSITRIM_4                  (0x10UL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x10000000 */

/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                      (0U)
#define RCC_CFGR_SW_Msk                      (0x3UL << RCC_CFGR_SW_Pos)        /*!< 0x00000003 */
#define RCC_CFGR_SW                          RCC_CFGR_SW_Msk                   /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                        (0x1UL << RCC_CFGR_SW_Pos)        /*!< 0x00000001 */
#define RCC_CFGR_SW_1                        (0x2UL << RCC_CFGR_SW_Pos)        /*!< 0x00000002 */

#define RCC_CFGR_SW_MSI                      (0x00000000UL)                    /*!< MSI oscillator selection as system clock */
#define RCC_CFGR_SW_HSI                      (0x00000001UL)                    /*!< HSI16 oscillator selection as system clock */
#define RCC_CFGR_SW_HSE                      (0x00000002UL)                    /*!< HSE oscillator selection as system clock */
#define RCC_CFGR_SW_PLL                      (0x00000003UL)                    /*!< PLL selection as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                     (2U)
#define RCC_CFGR_SWS_Msk                     (0x3UL << RCC_CFGR_SWS_Pos)       /*!< 0x0000000C */
#define RCC_CFGR_SWS                         RCC_CFGR_SWS_Msk                  /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                       (0x1UL << RCC_CFGR_SWS_Pos)       /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                       (0x2UL << RCC_CFGR_SWS_Pos)       /*!< 0x00000008 */

#define RCC_CFGR_SWS_MSI                     (0x00000000UL)                    /*!< MSI oscillator used as system clock */
#define RCC_CFGR_SWS_HSI                     (0x00000004UL)                    /*!< HSI16 oscillator used as system clock */
#define RCC_CFGR_SWS_HSE                     (0x00000008UL)                    /*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL                     (0x0000000CUL)                    /*!< PLL used as system clock */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                    (4U)
#define RCC_CFGR_HPRE_Msk                    (0xFUL << RCC_CFGR_HPRE_Pos)      /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                        RCC_CFGR_HPRE_Msk                 /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                      (0x1UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                      (0x2UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                      (0x4UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                      (0x8UL << RCC_CFGR_HPRE_Pos)      /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1                   (0x00000000UL)                    /*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2                   (0x00000080UL)                    /*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4                   (0x00000090UL)                    /*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8                   (0x000000A0UL)                    /*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16                  (0x000000B0UL)                    /*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64                  (0x000000C0UL)                    /*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128                 (0x000000D0UL)                    /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256                 (0x000000E0UL)                    /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512                 (0x000000F0UL)                    /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                   (8U)
#define RCC_CFGR_PPRE1_Msk                   (0x7UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000700 */
#define RCC_CFGR_PPRE1                       RCC_CFGR_PPRE1_Msk                /*!< PRE1[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE1_0                     (0x1UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000100 */
#define RCC_CFGR_PPRE1_1                     (0x2UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000200 */
#define RCC_CFGR_PPRE1_2                     (0x4UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000400 */

#define RCC_CFGR_PPRE1_DIV1                  (0x00000000UL)                    /*!< HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2                  (0x00000400UL)                    /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4                  (0x00000500UL)                    /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8                  (0x00000600UL)                    /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16                 (0x00000700UL)                    /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                   (11U)
#define RCC_CFGR_PPRE2_Msk                   (0x7UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00003800 */
#define RCC_CFGR_PPRE2                       RCC_CFGR_PPRE2_Msk                /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                     (0x1UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00000800 */
#define RCC_CFGR_PPRE2_1                     (0x2UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00001000 */
#define RCC_CFGR_PPRE2_2                     (0x4UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00002000 */

#define RCC_CFGR_PPRE2_DIV1                  (0x00000000UL)                    /*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2                  (0x00002000UL)                    /*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4                  (0x00002800UL)                    /*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8                  (0x00003000UL)                    /*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16                 (0x00003800UL)                    /*!< HCLK divided by 16 */

#define RCC_CFGR_STOPWUCK_Pos                (15U)
#define RCC_CFGR_STOPWUCK_Msk                (0x1UL << RCC_CFGR_STOPWUCK_Pos)  /*!< 0x00008000 */
#define RCC_CFGR_STOPWUCK                    RCC_CFGR_STOPWUCK_Msk             /*!< Wake Up from stop and CSS backup clock selection */

/*!< MCOSEL configuration */
#define RCC_CFGR_MCOSEL_Pos                  (24U)
#define RCC_CFGR_MCOSEL_Msk                  (0x7UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x07000000 */
#define RCC_CFGR_MCOSEL                      RCC_CFGR_MCOSEL_Msk               /*!< MCOSEL [2:0] bits (Clock output selection) */
#define RCC_CFGR_MCOSEL_0                    (0x1UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x01000000 */
#define RCC_CFGR_MCOSEL_1                    (0x2UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x02000000 */
#define RCC_CFGR_MCOSEL_2                    (0x4UL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x04000000 */

#define RCC_CFGR_MCOPRE_Pos                  (28U)
#define RCC_CFGR_MCOPRE_Msk                  (0x7UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x70000000 */
#define RCC_CFGR_MCOPRE                      RCC_CFGR_MCOPRE_Msk               /*!< MCO prescaler */
#define RCC_CFGR_MCOPRE_0                    (0x1UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x10000000 */
#define RCC_CFGR_MCOPRE_1                    (0x2UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x20000000 */
#define RCC_CFGR_MCOPRE_2                    (0x4UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x40000000 */

#define RCC_CFGR_MCOPRE_DIV1                 (0x00000000UL)                    /*!< MCO is divided by 1 */
#define RCC_CFGR_MCOPRE_DIV2                 (0x10000000UL)                    /*!< MCO is divided by 2 */
#define RCC_CFGR_MCOPRE_DIV4                 (0x20000000UL)                    /*!< MCO is divided by 4 */
#define RCC_CFGR_MCOPRE_DIV8                 (0x30000000UL)                    /*!< MCO is divided by 8 */
#define RCC_CFGR_MCOPRE_DIV16                (0x40000000UL)                    /*!< MCO is divided by 16 */

/* Legacy aliases */
#define RCC_CFGR_MCO_PRE                     RCC_CFGR_MCOPRE
#define RCC_CFGR_MCO_PRE_1                   RCC_CFGR_MCOPRE_DIV1
#define RCC_CFGR_MCO_PRE_2                   RCC_CFGR_MCOPRE_DIV2
#define RCC_CFGR_MCO_PRE_4                   RCC_CFGR_MCOPRE_DIV4
#define RCC_CFGR_MCO_PRE_8                   RCC_CFGR_MCOPRE_DIV8
#define RCC_CFGR_MCO_PRE_16                  RCC_CFGR_MCOPRE_DIV16

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLSRC_Pos               (0U)
#define RCC_PLLCFGR_PLLSRC_Msk               (0x3UL << RCC_PLLCFGR_PLLSRC_Pos) /*!< 0x00000003 */
#define RCC_PLLCFGR_PLLSRC                   RCC_PLLCFGR_PLLSRC_Msk

#define RCC_PLLCFGR_PLLSRC_MSI_Pos           (0U)
#define RCC_PLLCFGR_PLLSRC_MSI_Msk           (0x1UL << RCC_PLLCFGR_PLLSRC_MSI_Pos) /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLSRC_MSI               RCC_PLLCFGR_PLLSRC_MSI_Msk        /*!< MSI oscillator source clock selected */
#define RCC_PLLCFGR_PLLSRC_HSI_Pos           (1U)
#define RCC_PLLCFGR_PLLSRC_HSI_Msk           (0x1UL << RCC_PLLCFGR_PLLSRC_HSI_Pos) /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLSRC_HSI               RCC_PLLCFGR_PLLSRC_HSI_Msk        /*!< HSI16 oscillator source clock selected */
#define RCC_PLLCFGR_PLLSRC_HSE_Pos           (0U)
#define RCC_PLLCFGR_PLLSRC_HSE_Msk           (0x3UL << RCC_PLLCFGR_PLLSRC_HSE_Pos) /*!< 0x00000003 */
#define RCC_PLLCFGR_PLLSRC_HSE               RCC_PLLCFGR_PLLSRC_HSE_Msk        /*!< HSE oscillator source clock selected */

#define RCC_PLLCFGR_PLLM_Pos                 (4U)
#define RCC_PLLCFGR_PLLM_Msk                 (0x7UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000070 */
#define RCC_PLLCFGR_PLLM                     RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0                   (0x1UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_1                   (0x2UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000020 */
#define RCC_PLLCFGR_PLLM_2                   (0x4UL << RCC_PLLCFGR_PLLM_Pos)   /*!< 0x00000040 */

#define RCC_PLLCFGR_PLLN_Pos                 (8U)
#define RCC_PLLCFGR_PLLN_Msk                 (0x7FUL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00007F00 */
#define RCC_PLLCFGR_PLLN                     RCC_PLLCFGR_PLLN_Msk
#define RCC_PLLCFGR_PLLN_0                   (0x01UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_1                   (0x02UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_2                   (0x04UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_3                   (0x08UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_4                   (0x10UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_5                   (0x20UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_6                   (0x40UL << RCC_PLLCFGR_PLLN_Pos)  /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLPEN_Pos               (16U)
#define RCC_PLLCFGR_PLLPEN_Msk               (0x1UL << RCC_PLLCFGR_PLLPEN_Pos) /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLPEN                   RCC_PLLCFGR_PLLPEN_Msk
#define RCC_PLLCFGR_PLLP_Pos                 (17U)
#define RCC_PLLCFGR_PLLP_Msk                 (0x1UL << RCC_PLLCFGR_PLLP_Pos)   /*!< 0x00020000 */
#define RCC_PLLCFGR_PLLP                     RCC_PLLCFGR_PLLP_Msk
#define RCC_PLLCFGR_PLLQEN_Pos               (20U)
#define RCC_PLLCFGR_PLLQEN_Msk               (0x1UL << RCC_PLLCFGR_PLLQEN_Pos) /*!< 0x00100000 */
#define RCC_PLLCFGR_PLLQEN                   RCC_PLLCFGR_PLLQEN_Msk

#define RCC_PLLCFGR_PLLQ_Pos                 (21U)
#define RCC_PLLCFGR_PLLQ_Msk                 (0x3UL << RCC_PLLCFGR_PLLQ_Pos)   /*!< 0x00600000 */
#define RCC_PLLCFGR_PLLQ                     RCC_PLLCFGR_PLLQ_Msk
#define RCC_PLLCFGR_PLLQ_0                   (0x1UL << RCC_PLLCFGR_PLLQ_Pos)   /*!< 0x00200000 */
#define RCC_PLLCFGR_PLLQ_1                   (0x2UL << RCC_PLLCFGR_PLLQ_Pos)   /*!< 0x00400000 */

#define RCC_PLLCFGR_PLLREN_Pos               (24U)
#define RCC_PLLCFGR_PLLREN_Msk               (0x1UL << RCC_PLLCFGR_PLLREN_Pos) /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLREN                   RCC_PLLCFGR_PLLREN_Msk
#define RCC_PLLCFGR_PLLR_Pos                 (25U)
#define RCC_PLLCFGR_PLLR_Msk                 (0x3UL << RCC_PLLCFGR_PLLR_Pos)   /*!< 0x06000000 */
#define RCC_PLLCFGR_PLLR                     RCC_PLLCFGR_PLLR_Msk
#define RCC_PLLCFGR_PLLR_0                   (0x1UL << RCC_PLLCFGR_PLLR_Pos)   /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLR_1                   (0x2UL << RCC_PLLCFGR_PLLR_Pos)   /*!< 0x04000000 */

/********************  Bit definition for RCC_PLLSAI1CFGR register  ************/
#define RCC_PLLSAI1CFGR_PLLSAI1N_Pos         (8U)
#define RCC_PLLSAI1CFGR_PLLSAI1N_Msk         (0x7FUL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00007F00 */
#define RCC_PLLSAI1CFGR_PLLSAI1N             RCC_PLLSAI1CFGR_PLLSAI1N_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1N_0           (0x01UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00000100 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_1           (0x02UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00000200 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_2           (0x04UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00000400 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_3           (0x08UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00000800 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_4           (0x10UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00001000 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_5           (0x20UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00002000 */
#define RCC_PLLSAI1CFGR_PLLSAI1N_6           (0x40UL << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) /*!< 0x00004000 */

#define RCC_PLLSAI1CFGR_PLLSAI1PEN_Pos       (16U)
#define RCC_PLLSAI1CFGR_PLLSAI1PEN_Msk       (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1PEN_Pos) /*!< 0x00010000 */
#define RCC_PLLSAI1CFGR_PLLSAI1PEN           RCC_PLLSAI1CFGR_PLLSAI1PEN_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1P_Pos         (17U)
#define RCC_PLLSAI1CFGR_PLLSAI1P_Msk         (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1P_Pos) /*!< 0x00020000 */
#define RCC_PLLSAI1CFGR_PLLSAI1P             RCC_PLLSAI1CFGR_PLLSAI1P_Msk

#define RCC_PLLSAI1CFGR_PLLSAI1QEN_Pos       (20U)
#define RCC_PLLSAI1CFGR_PLLSAI1QEN_Msk       (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1QEN_Pos) /*!< 0x00100000 */
#define RCC_PLLSAI1CFGR_PLLSAI1QEN           RCC_PLLSAI1CFGR_PLLSAI1QEN_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1Q_Pos         (21U)
#define RCC_PLLSAI1CFGR_PLLSAI1Q_Msk         (0x3UL << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) /*!< 0x00600000 */
#define RCC_PLLSAI1CFGR_PLLSAI1Q             RCC_PLLSAI1CFGR_PLLSAI1Q_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1Q_0           (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) /*!< 0x00200000 */
#define RCC_PLLSAI1CFGR_PLLSAI1Q_1           (0x2UL << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) /*!< 0x00400000 */

#define RCC_PLLSAI1CFGR_PLLSAI1REN_Pos       (24U)
#define RCC_PLLSAI1CFGR_PLLSAI1REN_Msk       (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1REN_Pos) /*!< 0x01000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1REN           RCC_PLLSAI1CFGR_PLLSAI1REN_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1R_Pos         (25U)
#define RCC_PLLSAI1CFGR_PLLSAI1R_Msk         (0x3UL << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) /*!< 0x06000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1R             RCC_PLLSAI1CFGR_PLLSAI1R_Msk
#define RCC_PLLSAI1CFGR_PLLSAI1R_0           (0x1UL << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) /*!< 0x02000000 */
#define RCC_PLLSAI1CFGR_PLLSAI1R_1           (0x2UL << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) /*!< 0x04000000 */

/********************  Bit definition for RCC_PLLSAI2CFGR register  ************/
#define RCC_PLLSAI2CFGR_PLLSAI2N_Pos         (8U)
#define RCC_PLLSAI2CFGR_PLLSAI2N_Msk         (0x7FUL << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) /*!< 0x00007F00 */
#define RCC_PLLSAI2CFGR_PLLSAI2N             RCC_PLLSAI2CFGR_PLLSAI2N_Msk
#define RCC_PLLSAI2CFGR_PLLSAI2N_0           (0x01UL << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) /*!< 0x00000100 */
#define RCC_PLLSAI2CFGR_PLLSAI2N_1           (0x02UL << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) /*!< 0x00000200 */
#define RCC_PLLSAI2CFGR_PLLSAI2N_2           (0x04UL << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) /*!< 0x00000400 */
#define RCC_PLLSAI2CFGR_PLLSAI2N_3           (0x08UL << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) /*!< 0x00000800 */
#define RCC_PLLSAI2CFGR_PLLSAI2N_4           (0x10UL << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) /*!< 0x00001000 */
#define RCC_PLLSAI2CFGR_PLLSAI2N_5           (0x20UL << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) /*!< 0x00002000 */
#define RCC_PLLSAI2CFGR_PLLSAI2N_6           (0x40UL << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) /*!< 0x00004000 */

#define RCC_PLLSAI2CFGR_PLLSAI2PEN_Pos       (16U)
#define RCC_PLLSAI2CFGR_PLLSAI2PEN_Msk       (0x1UL << RCC_PLLSAI2CFGR_PLLSAI2PEN_Pos) /*!< 0x00010000 */
#define RCC_PLLSAI2CFGR_PLLSAI2PEN           RCC_PLLSAI2CFGR_PLLSAI2PEN_Msk
#define RCC_PLLSAI2CFGR_PLLSAI2P_Pos         (17U)
#define RCC_PLLSAI2CFGR_PLLSAI2P_Msk         (0x1UL << RCC_PLLSAI2CFGR_PLLSAI2P_Pos) /*!< 0x00020000 */
#define RCC_PLLSAI2CFGR_PLLSAI2P             RCC_PLLSAI2CFGR_PLLSAI2P_Msk

#define RCC_PLLSAI2CFGR_PLLSAI2REN_Pos       (24U)
#define RCC_PLLSAI2CFGR_PLLSAI2REN_Msk       (0x1UL << RCC_PLLSAI2CFGR_PLLSAI2REN_Pos) /*!< 0x01000000 */
#define RCC_PLLSAI2CFGR_PLLSAI2REN           RCC_PLLSAI2CFGR_PLLSAI2REN_Msk
#define RCC_PLLSAI2CFGR_PLLSAI2R_Pos         (25U)
#define RCC_PLLSAI2CFGR_PLLSAI2R_Msk         (0x3UL << RCC_PLLSAI2CFGR_PLLSAI2R_Pos) /*!< 0x06000000 */
#define RCC_PLLSAI2CFGR_PLLSAI2R             RCC_PLLSAI2CFGR_PLLSAI2R_Msk
#define RCC_PLLSAI2CFGR_PLLSAI2R_0           (0x1UL << RCC_PLLSAI2CFGR_PLLSAI2R_Pos) /*!< 0x02000000 */
#define RCC_PLLSAI2CFGR_PLLSAI2R_1           (0x2UL << RCC_PLLSAI2CFGR_PLLSAI2R_Pos) /*!< 0x04000000 */

/********************  Bit definition for RCC_CIER register  ******************/
#define RCC_CIER_LSIRDYIE_Pos                (0U)
#define RCC_CIER_LSIRDYIE_Msk                (0x1UL << RCC_CIER_LSIRDYIE_Pos)  /*!< 0x00000001 */
#define RCC_CIER_LSIRDYIE                    RCC_CIER_LSIRDYIE_Msk
#define RCC_CIER_LSERDYIE_Pos                (1U)
#define RCC_CIER_LSERDYIE_Msk                (0x1UL << RCC_CIER_LSERDYIE_Pos)  /*!< 0x00000002 */
#define RCC_CIER_LSERDYIE                    RCC_CIER_LSERDYIE_Msk
#define RCC_CIER_MSIRDYIE_Pos                (2U)
#define RCC_CIER_MSIRDYIE_Msk                (0x1UL << RCC_CIER_MSIRDYIE_Pos)  /*!< 0x00000004 */
#define RCC_CIER_MSIRDYIE                    RCC_CIER_MSIRDYIE_Msk
#define RCC_CIER_HSIRDYIE_Pos                (3U)
#define RCC_CIER_HSIRDYIE_Msk                (0x1UL << RCC_CIER_HSIRDYIE_Pos)  /*!< 0x00000008 */
#define RCC_CIER_HSIRDYIE                    RCC_CIER_HSIRDYIE_Msk
#define RCC_CIER_HSERDYIE_Pos                (4U)
#define RCC_CIER_HSERDYIE_Msk                (0x1UL << RCC_CIER_HSERDYIE_Pos)  /*!< 0x00000010 */
#define RCC_CIER_HSERDYIE                    RCC_CIER_HSERDYIE_Msk
#define RCC_CIER_PLLRDYIE_Pos                (5U)
#define RCC_CIER_PLLRDYIE_Msk                (0x1UL << RCC_CIER_PLLRDYIE_Pos)  /*!< 0x00000020 */
#define RCC_CIER_PLLRDYIE                    RCC_CIER_PLLRDYIE_Msk
#define RCC_CIER_PLLSAI1RDYIE_Pos            (6U)
#define RCC_CIER_PLLSAI1RDYIE_Msk            (0x1UL << RCC_CIER_PLLSAI1RDYIE_Pos) /*!< 0x00000040 */
#define RCC_CIER_PLLSAI1RDYIE                RCC_CIER_PLLSAI1RDYIE_Msk
#define RCC_CIER_PLLSAI2RDYIE_Pos            (7U)
#define RCC_CIER_PLLSAI2RDYIE_Msk            (0x1UL << RCC_CIER_PLLSAI2RDYIE_Pos) /*!< 0x00000080 */
#define RCC_CIER_PLLSAI2RDYIE                RCC_CIER_PLLSAI2RDYIE_Msk
#define RCC_CIER_LSECSSIE_Pos                (9U)
#define RCC_CIER_LSECSSIE_Msk                (0x1UL << RCC_CIER_LSECSSIE_Pos)  /*!< 0x00000200 */
#define RCC_CIER_LSECSSIE                    RCC_CIER_LSECSSIE_Msk

/********************  Bit definition for RCC_CIFR register  ******************/
#define RCC_CIFR_LSIRDYF_Pos                 (0U)
#define RCC_CIFR_LSIRDYF_Msk                 (0x1UL << RCC_CIFR_LSIRDYF_Pos)   /*!< 0x00000001 */
#define RCC_CIFR_LSIRDYF                     RCC_CIFR_LSIRDYF_Msk
#define RCC_CIFR_LSERDYF_Pos                 (1U)
#define RCC_CIFR_LSERDYF_Msk                 (0x1UL << RCC_CIFR_LSERDYF_Pos)   /*!< 0x00000002 */
#define RCC_CIFR_LSERDYF                     RCC_CIFR_LSERDYF_Msk
#define RCC_CIFR_MSIRDYF_Pos                 (2U)
#define RCC_CIFR_MSIRDYF_Msk                 (0x1UL << RCC_CIFR_MSIRDYF_Pos)   /*!< 0x00000004 */
#define RCC_CIFR_MSIRDYF                     RCC_CIFR_MSIRDYF_Msk
#define RCC_CIFR_HSIRDYF_Pos                 (3U)
#define RCC_CIFR_HSIRDYF_Msk                 (0x1UL << RCC_CIFR_HSIRDYF_Pos)   /*!< 0x00000008 */
#define RCC_CIFR_HSIRDYF                     RCC_CIFR_HSIRDYF_Msk
#define RCC_CIFR_HSERDYF_Pos                 (4U)
#define RCC_CIFR_HSERDYF_Msk                 (0x1UL << RCC_CIFR_HSERDYF_Pos)   /*!< 0x00000010 */
#define RCC_CIFR_HSERDYF                     RCC_CIFR_HSERDYF_Msk
#define RCC_CIFR_PLLRDYF_Pos                 (5U)
#define RCC_CIFR_PLLRDYF_Msk                 (0x1UL << RCC_CIFR_PLLRDYF_Pos)   /*!< 0x00000020 */
#define RCC_CIFR_PLLRDYF                     RCC_CIFR_PLLRDYF_Msk
#define RCC_CIFR_PLLSAI1RDYF_Pos             (6U)
#define RCC_CIFR_PLLSAI1RDYF_Msk             (0x1UL << RCC_CIFR_PLLSAI1RDYF_Pos) /*!< 0x00000040 */
#define RCC_CIFR_PLLSAI1RDYF                 RCC_CIFR_PLLSAI1RDYF_Msk
#define RCC_CIFR_PLLSAI2RDYF_Pos             (7U)
#define RCC_CIFR_PLLSAI2RDYF_Msk             (0x1UL << RCC_CIFR_PLLSAI2RDYF_Pos) /*!< 0x00000080 */
#define RCC_CIFR_PLLSAI2RDYF                 RCC_CIFR_PLLSAI2RDYF_Msk
#define RCC_CIFR_CSSF_Pos                    (8U)
#define RCC_CIFR_CSSF_Msk                    (0x1UL << RCC_CIFR_CSSF_Pos)      /*!< 0x00000100 */
#define RCC_CIFR_CSSF                        RCC_CIFR_CSSF_Msk
#define RCC_CIFR_LSECSSF_Pos                 (9U)
#define RCC_CIFR_LSECSSF_Msk                 (0x1UL << RCC_CIFR_LSECSSF_Pos)   /*!< 0x00000200 */
#define RCC_CIFR_LSECSSF                     RCC_CIFR_LSECSSF_Msk

/********************  Bit definition for RCC_CICR register  ******************/
#define RCC_CICR_LSIRDYC_Pos                 (0U)
#define RCC_CICR_LSIRDYC_Msk                 (0x1UL << RCC_CICR_LSIRDYC_Pos)   /*!< 0x00000001 */
#define RCC_CICR_LSIRDYC                     RCC_CICR_LSIRDYC_Msk
#define RCC_CICR_LSERDYC_Pos                 (1U)
#define RCC_CICR_LSERDYC_Msk                 (0x1UL << RCC_CICR_LSERDYC_Pos)   /*!< 0x00000002 */
#define RCC_CICR_LSERDYC                     RCC_CICR_LSERDYC_Msk
#define RCC_CICR_MSIRDYC_Pos                 (2U)
#define RCC_CICR_MSIRDYC_Msk                 (0x1UL << RCC_CICR_MSIRDYC_Pos)   /*!< 0x00000004 */
#define RCC_CICR_MSIRDYC                     RCC_CICR_MSIRDYC_Msk
#define RCC_CICR_HSIRDYC_Pos                 (3U)
#define RCC_CICR_HSIRDYC_Msk                 (0x1UL << RCC_CICR_HSIRDYC_Pos)   /*!< 0x00000008 */
#define RCC_CICR_HSIRDYC                     RCC_CICR_HSIRDYC_Msk
#define RCC_CICR_HSERDYC_Pos                 (4U)
#define RCC_CICR_HSERDYC_Msk                 (0x1UL << RCC_CICR_HSERDYC_Pos)   /*!< 0x00000010 */
#define RCC_CICR_HSERDYC                     RCC_CICR_HSERDYC_Msk
#define RCC_CICR_PLLRDYC_Pos                 (5U)
#define RCC_CICR_PLLRDYC_Msk                 (0x1UL << RCC_CICR_PLLRDYC_Pos)   /*!< 0x00000020 */
#define RCC_CICR_PLLRDYC                     RCC_CICR_PLLRDYC_Msk
#define RCC_CICR_PLLSAI1RDYC_Pos             (6U)
#define RCC_CICR_PLLSAI1RDYC_Msk             (0x1UL << RCC_CICR_PLLSAI1RDYC_Pos) /*!< 0x00000040 */
#define RCC_CICR_PLLSAI1RDYC                 RCC_CICR_PLLSAI1RDYC_Msk
#define RCC_CICR_PLLSAI2RDYC_Pos             (7U)
#define RCC_CICR_PLLSAI2RDYC_Msk             (0x1UL << RCC_CICR_PLLSAI2RDYC_Pos) /*!< 0x00000080 */
#define RCC_CICR_PLLSAI2RDYC                 RCC_CICR_PLLSAI2RDYC_Msk
#define RCC_CICR_CSSC_Pos                    (8U)
#define RCC_CICR_CSSC_Msk                    (0x1UL << RCC_CICR_CSSC_Pos)      /*!< 0x00000100 */
#define RCC_CICR_CSSC                        RCC_CICR_CSSC_Msk
#define RCC_CICR_LSECSSC_Pos                 (9U)
#define RCC_CICR_LSECSSC_Msk                 (0x1UL << RCC_CICR_LSECSSC_Pos)   /*!< 0x00000200 */
#define RCC_CICR_LSECSSC                     RCC_CICR_LSECSSC_Msk

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_DMA1RST_Pos             (0U)
#define RCC_AHB1RSTR_DMA1RST_Msk             (0x1UL << RCC_AHB1RSTR_DMA1RST_Pos) /*!< 0x00000001 */
#define RCC_AHB1RSTR_DMA1RST                 RCC_AHB1RSTR_DMA1RST_Msk
#define RCC_AHB1RSTR_DMA2RST_Pos             (1U)
#define RCC_AHB1RSTR_DMA2RST_Msk             (0x1UL << RCC_AHB1RSTR_DMA2RST_Pos) /*!< 0x00000002 */
#define RCC_AHB1RSTR_DMA2RST                 RCC_AHB1RSTR_DMA2RST_Msk
#define RCC_AHB1RSTR_FLASHRST_Pos            (8U)
#define RCC_AHB1RSTR_FLASHRST_Msk            (0x1UL << RCC_AHB1RSTR_FLASHRST_Pos) /*!< 0x00000100 */
#define RCC_AHB1RSTR_FLASHRST                RCC_AHB1RSTR_FLASHRST_Msk
#define RCC_AHB1RSTR_CRCRST_Pos              (12U)
#define RCC_AHB1RSTR_CRCRST_Msk              (0x1UL << RCC_AHB1RSTR_CRCRST_Pos) /*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST                  RCC_AHB1RSTR_CRCRST_Msk
#define RCC_AHB1RSTR_TSCRST_Pos              (16U)
#define RCC_AHB1RSTR_TSCRST_Msk              (0x1UL << RCC_AHB1RSTR_TSCRST_Pos) /*!< 0x00010000 */
#define RCC_AHB1RSTR_TSCRST                  RCC_AHB1RSTR_TSCRST_Msk

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_GPIOARST_Pos            (0U)
#define RCC_AHB2RSTR_GPIOARST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOARST_Pos) /*!< 0x00000001 */
#define RCC_AHB2RSTR_GPIOARST                RCC_AHB2RSTR_GPIOARST_Msk
#define RCC_AHB2RSTR_GPIOBRST_Pos            (1U)
#define RCC_AHB2RSTR_GPIOBRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOBRST_Pos) /*!< 0x00000002 */
#define RCC_AHB2RSTR_GPIOBRST                RCC_AHB2RSTR_GPIOBRST_Msk
#define RCC_AHB2RSTR_GPIOCRST_Pos            (2U)
#define RCC_AHB2RSTR_GPIOCRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOCRST_Pos) /*!< 0x00000004 */
#define RCC_AHB2RSTR_GPIOCRST                RCC_AHB2RSTR_GPIOCRST_Msk
#define RCC_AHB2RSTR_GPIODRST_Pos            (3U)
#define RCC_AHB2RSTR_GPIODRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIODRST_Pos) /*!< 0x00000008 */
#define RCC_AHB2RSTR_GPIODRST                RCC_AHB2RSTR_GPIODRST_Msk
#define RCC_AHB2RSTR_GPIOERST_Pos            (4U)
#define RCC_AHB2RSTR_GPIOERST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOERST_Pos) /*!< 0x00000010 */
#define RCC_AHB2RSTR_GPIOERST                RCC_AHB2RSTR_GPIOERST_Msk
#define RCC_AHB2RSTR_GPIOFRST_Pos            (5U)
#define RCC_AHB2RSTR_GPIOFRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOFRST_Pos) /*!< 0x00000020 */
#define RCC_AHB2RSTR_GPIOFRST                RCC_AHB2RSTR_GPIOFRST_Msk
#define RCC_AHB2RSTR_GPIOGRST_Pos            (6U)
#define RCC_AHB2RSTR_GPIOGRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOGRST_Pos) /*!< 0x00000040 */
#define RCC_AHB2RSTR_GPIOGRST                RCC_AHB2RSTR_GPIOGRST_Msk
#define RCC_AHB2RSTR_GPIOHRST_Pos            (7U)
#define RCC_AHB2RSTR_GPIOHRST_Msk            (0x1UL << RCC_AHB2RSTR_GPIOHRST_Pos) /*!< 0x00000080 */
#define RCC_AHB2RSTR_GPIOHRST                RCC_AHB2RSTR_GPIOHRST_Msk
#define RCC_AHB2RSTR_OTGFSRST_Pos            (12U)
#define RCC_AHB2RSTR_OTGFSRST_Msk            (0x1UL << RCC_AHB2RSTR_OTGFSRST_Pos) /*!< 0x00001000 */
#define RCC_AHB2RSTR_OTGFSRST                RCC_AHB2RSTR_OTGFSRST_Msk
#define RCC_AHB2RSTR_ADCRST_Pos              (13U)
#define RCC_AHB2RSTR_ADCRST_Msk              (0x1UL << RCC_AHB2RSTR_ADCRST_Pos) /*!< 0x00002000 */
#define RCC_AHB2RSTR_ADCRST                  RCC_AHB2RSTR_ADCRST_Msk
#define RCC_AHB2RSTR_RNGRST_Pos              (18U)
#define RCC_AHB2RSTR_RNGRST_Msk              (0x1UL << RCC_AHB2RSTR_RNGRST_Pos) /*!< 0x00040000 */
#define RCC_AHB2RSTR_RNGRST                  RCC_AHB2RSTR_RNGRST_Msk

/********************  Bit definition for RCC_AHB3RSTR register  **************/
#define RCC_AHB3RSTR_FMCRST_Pos              (0U)
#define RCC_AHB3RSTR_FMCRST_Msk              (0x1UL << RCC_AHB3RSTR_FMCRST_Pos) /*!< 0x00000001 */
#define RCC_AHB3RSTR_FMCRST                  RCC_AHB3RSTR_FMCRST_Msk
#define RCC_AHB3RSTR_QSPIRST_Pos             (8U)
#define RCC_AHB3RSTR_QSPIRST_Msk             (0x1UL << RCC_AHB3RSTR_QSPIRST_Pos) /*!< 0x00000100 */
#define RCC_AHB3RSTR_QSPIRST                 RCC_AHB3RSTR_QSPIRST_Msk

/********************  Bit definition for RCC_APB1RSTR1 register  **************/
#define RCC_APB1RSTR1_TIM2RST_Pos            (0U)
#define RCC_APB1RSTR1_TIM2RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM2RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR1_TIM2RST                RCC_APB1RSTR1_TIM2RST_Msk
#define RCC_APB1RSTR1_TIM3RST_Pos            (1U)
#define RCC_APB1RSTR1_TIM3RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM3RST_Pos) /*!< 0x00000002 */
#define RCC_APB1RSTR1_TIM3RST                RCC_APB1RSTR1_TIM3RST_Msk
#define RCC_APB1RSTR1_TIM4RST_Pos            (2U)
#define RCC_APB1RSTR1_TIM4RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM4RST_Pos) /*!< 0x00000004 */
#define RCC_APB1RSTR1_TIM4RST                RCC_APB1RSTR1_TIM4RST_Msk
#define RCC_APB1RSTR1_TIM5RST_Pos            (3U)
#define RCC_APB1RSTR1_TIM5RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM5RST_Pos) /*!< 0x00000008 */
#define RCC_APB1RSTR1_TIM5RST                RCC_APB1RSTR1_TIM5RST_Msk
#define RCC_APB1RSTR1_TIM6RST_Pos            (4U)
#define RCC_APB1RSTR1_TIM6RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM6RST_Pos) /*!< 0x00000010 */
#define RCC_APB1RSTR1_TIM6RST                RCC_APB1RSTR1_TIM6RST_Msk
#define RCC_APB1RSTR1_TIM7RST_Pos            (5U)
#define RCC_APB1RSTR1_TIM7RST_Msk            (0x1UL << RCC_APB1RSTR1_TIM7RST_Pos) /*!< 0x00000020 */
#define RCC_APB1RSTR1_TIM7RST                RCC_APB1RSTR1_TIM7RST_Msk
#define RCC_APB1RSTR1_SPI2RST_Pos            (14U)
#define RCC_APB1RSTR1_SPI2RST_Msk            (0x1UL << RCC_APB1RSTR1_SPI2RST_Pos) /*!< 0x00004000 */
#define RCC_APB1RSTR1_SPI2RST                RCC_APB1RSTR1_SPI2RST_Msk
#define RCC_APB1RSTR1_SPI3RST_Pos            (15U)
#define RCC_APB1RSTR1_SPI3RST_Msk            (0x1UL << RCC_APB1RSTR1_SPI3RST_Pos) /*!< 0x00008000 */
#define RCC_APB1RSTR1_SPI3RST                RCC_APB1RSTR1_SPI3RST_Msk
#define RCC_APB1RSTR1_USART2RST_Pos          (17U)
#define RCC_APB1RSTR1_USART2RST_Msk          (0x1UL << RCC_APB1RSTR1_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR1_USART2RST              RCC_APB1RSTR1_USART2RST_Msk
#define RCC_APB1RSTR1_USART3RST_Pos          (18U)
#define RCC_APB1RSTR1_USART3RST_Msk          (0x1UL << RCC_APB1RSTR1_USART3RST_Pos) /*!< 0x00040000 */
#define RCC_APB1RSTR1_USART3RST              RCC_APB1RSTR1_USART3RST_Msk
#define RCC_APB1RSTR1_UART4RST_Pos           (19U)
#define RCC_APB1RSTR1_UART4RST_Msk           (0x1UL << RCC_APB1RSTR1_UART4RST_Pos) /*!< 0x00080000 */
#define RCC_APB1RSTR1_UART4RST               RCC_APB1RSTR1_UART4RST_Msk
#define RCC_APB1RSTR1_UART5RST_Pos           (20U)
#define RCC_APB1RSTR1_UART5RST_Msk           (0x1UL << RCC_APB1RSTR1_UART5RST_Pos) /*!< 0x00100000 */
#define RCC_APB1RSTR1_UART5RST               RCC_APB1RSTR1_UART5RST_Msk
#define RCC_APB1RSTR1_I2C1RST_Pos            (21U)
#define RCC_APB1RSTR1_I2C1RST_Msk            (0x1UL << RCC_APB1RSTR1_I2C1RST_Pos) /*!< 0x00200000 */
#define RCC_APB1RSTR1_I2C1RST                RCC_APB1RSTR1_I2C1RST_Msk
#define RCC_APB1RSTR1_I2C2RST_Pos            (22U)
#define RCC_APB1RSTR1_I2C2RST_Msk            (0x1UL << RCC_APB1RSTR1_I2C2RST_Pos) /*!< 0x00400000 */
#define RCC_APB1RSTR1_I2C2RST                RCC_APB1RSTR1_I2C2RST_Msk
#define RCC_APB1RSTR1_I2C3RST_Pos            (23U)
#define RCC_APB1RSTR1_I2C3RST_Msk            (0x1UL << RCC_APB1RSTR1_I2C3RST_Pos) /*!< 0x00800000 */
#define RCC_APB1RSTR1_I2C3RST                RCC_APB1RSTR1_I2C3RST_Msk
#define RCC_APB1RSTR1_CAN1RST_Pos            (25U)
#define RCC_APB1RSTR1_CAN1RST_Msk            (0x1UL << RCC_APB1RSTR1_CAN1RST_Pos) /*!< 0x02000000 */
#define RCC_APB1RSTR1_CAN1RST                RCC_APB1RSTR1_CAN1RST_Msk
#define RCC_APB1RSTR1_PWRRST_Pos             (28U)
#define RCC_APB1RSTR1_PWRRST_Msk             (0x1UL << RCC_APB1RSTR1_PWRRST_Pos) /*!< 0x10000000 */
#define RCC_APB1RSTR1_PWRRST                 RCC_APB1RSTR1_PWRRST_Msk
#define RCC_APB1RSTR1_DAC1RST_Pos            (29U)
#define RCC_APB1RSTR1_DAC1RST_Msk            (0x1UL << RCC_APB1RSTR1_DAC1RST_Pos) /*!< 0x20000000 */
#define RCC_APB1RSTR1_DAC1RST                RCC_APB1RSTR1_DAC1RST_Msk
#define RCC_APB1RSTR1_OPAMPRST_Pos           (30U)
#define RCC_APB1RSTR1_OPAMPRST_Msk           (0x1UL << RCC_APB1RSTR1_OPAMPRST_Pos) /*!< 0x40000000 */
#define RCC_APB1RSTR1_OPAMPRST               RCC_APB1RSTR1_OPAMPRST_Msk
#define RCC_APB1RSTR1_LPTIM1RST_Pos          (31U)
#define RCC_APB1RSTR1_LPTIM1RST_Msk          (0x1UL << RCC_APB1RSTR1_LPTIM1RST_Pos) /*!< 0x80000000 */
#define RCC_APB1RSTR1_LPTIM1RST              RCC_APB1RSTR1_LPTIM1RST_Msk

/********************  Bit definition for RCC_APB1RSTR2 register  **************/
#define RCC_APB1RSTR2_LPUART1RST_Pos         (0U)
#define RCC_APB1RSTR2_LPUART1RST_Msk         (0x1UL << RCC_APB1RSTR2_LPUART1RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR2_LPUART1RST             RCC_APB1RSTR2_LPUART1RST_Msk
#define RCC_APB1RSTR2_SWPMI1RST_Pos          (2U)
#define RCC_APB1RSTR2_SWPMI1RST_Msk          (0x1UL << RCC_APB1RSTR2_SWPMI1RST_Pos) /*!< 0x00000004 */
#define RCC_APB1RSTR2_SWPMI1RST              RCC_APB1RSTR2_SWPMI1RST_Msk
#define RCC_APB1RSTR2_LPTIM2RST_Pos          (5U)
#define RCC_APB1RSTR2_LPTIM2RST_Msk          (0x1UL << RCC_APB1RSTR2_LPTIM2RST_Pos) /*!< 0x00000020 */
#define RCC_APB1RSTR2_LPTIM2RST              RCC_APB1RSTR2_LPTIM2RST_Msk

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_SYSCFGRST_Pos           (0U)
#define RCC_APB2RSTR_SYSCFGRST_Msk           (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos) /*!< 0x00000001 */
#define RCC_APB2RSTR_SYSCFGRST               RCC_APB2RSTR_SYSCFGRST_Msk
#define RCC_APB2RSTR_SDMMC1RST_Pos           (10U)
#define RCC_APB2RSTR_SDMMC1RST_Msk           (0x1UL << RCC_APB2RSTR_SDMMC1RST_Pos) /*!< 0x00000400 */
#define RCC_APB2RSTR_SDMMC1RST               RCC_APB2RSTR_SDMMC1RST_Msk
#define RCC_APB2RSTR_TIM1RST_Pos             (11U)
#define RCC_APB2RSTR_TIM1RST_Msk             (0x1UL << RCC_APB2RSTR_TIM1RST_Pos) /*!< 0x00000800 */
#define RCC_APB2RSTR_TIM1RST                 RCC_APB2RSTR_TIM1RST_Msk
#define RCC_APB2RSTR_SPI1RST_Pos             (12U)
#define RCC_APB2RSTR_SPI1RST_Msk             (0x1UL << RCC_APB2RSTR_SPI1RST_Pos) /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST                 RCC_APB2RSTR_SPI1RST_Msk
#define RCC_APB2RSTR_TIM8RST_Pos             (13U)
#define RCC_APB2RSTR_TIM8RST_Msk             (0x1UL << RCC_APB2RSTR_TIM8RST_Pos) /*!< 0x00002000 */
#define RCC_APB2RSTR_TIM8RST                 RCC_APB2RSTR_TIM8RST_Msk
#define RCC_APB2RSTR_USART1RST_Pos           (14U)
#define RCC_APB2RSTR_USART1RST_Msk           (0x1UL << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST               RCC_APB2RSTR_USART1RST_Msk
#define RCC_APB2RSTR_TIM15RST_Pos            (16U)
#define RCC_APB2RSTR_TIM15RST_Msk            (0x1UL << RCC_APB2RSTR_TIM15RST_Pos) /*!< 0x00010000 */
#define RCC_APB2RSTR_TIM15RST                RCC_APB2RSTR_TIM15RST_Msk
#define RCC_APB2RSTR_TIM16RST_Pos            (17U)
#define RCC_APB2RSTR_TIM16RST_Msk            (0x1UL << RCC_APB2RSTR_TIM16RST_Pos) /*!< 0x00020000 */
#define RCC_APB2RSTR_TIM16RST                RCC_APB2RSTR_TIM16RST_Msk
#define RCC_APB2RSTR_TIM17RST_Pos            (18U)
#define RCC_APB2RSTR_TIM17RST_Msk            (0x1UL << RCC_APB2RSTR_TIM17RST_Pos) /*!< 0x00040000 */
#define RCC_APB2RSTR_TIM17RST                RCC_APB2RSTR_TIM17RST_Msk
#define RCC_APB2RSTR_SAI1RST_Pos             (21U)
#define RCC_APB2RSTR_SAI1RST_Msk             (0x1UL << RCC_APB2RSTR_SAI1RST_Pos) /*!< 0x00200000 */
#define RCC_APB2RSTR_SAI1RST                 RCC_APB2RSTR_SAI1RST_Msk
#define RCC_APB2RSTR_SAI2RST_Pos             (22U)
#define RCC_APB2RSTR_SAI2RST_Msk             (0x1UL << RCC_APB2RSTR_SAI2RST_Pos) /*!< 0x00400000 */
#define RCC_APB2RSTR_SAI2RST                 RCC_APB2RSTR_SAI2RST_Msk
#define RCC_APB2RSTR_DFSDM1RST_Pos           (24U)
#define RCC_APB2RSTR_DFSDM1RST_Msk           (0x1UL << RCC_APB2RSTR_DFSDM1RST_Pos) /*!< 0x01000000 */
#define RCC_APB2RSTR_DFSDM1RST               RCC_APB2RSTR_DFSDM1RST_Msk

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_DMA1EN_Pos               (0U)
#define RCC_AHB1ENR_DMA1EN_Msk               (0x1UL << RCC_AHB1ENR_DMA1EN_Pos) /*!< 0x00000001 */
#define RCC_AHB1ENR_DMA1EN                   RCC_AHB1ENR_DMA1EN_Msk
#define RCC_AHB1ENR_DMA2EN_Pos               (1U)
#define RCC_AHB1ENR_DMA2EN_Msk               (0x1UL << RCC_AHB1ENR_DMA2EN_Pos) /*!< 0x00000002 */
#define RCC_AHB1ENR_DMA2EN                   RCC_AHB1ENR_DMA2EN_Msk
#define RCC_AHB1ENR_FLASHEN_Pos              (8U)
#define RCC_AHB1ENR_FLASHEN_Msk              (0x1UL << RCC_AHB1ENR_FLASHEN_Pos) /*!< 0x00000100 */
#define RCC_AHB1ENR_FLASHEN                  RCC_AHB1ENR_FLASHEN_Msk
#define RCC_AHB1ENR_CRCEN_Pos                (12U)
#define RCC_AHB1ENR_CRCEN_Msk                (0x1UL << RCC_AHB1ENR_CRCEN_Pos)  /*!< 0x00001000 */
#define RCC_AHB1ENR_CRCEN                    RCC_AHB1ENR_CRCEN_Msk
#define RCC_AHB1ENR_TSCEN_Pos                (16U)
#define RCC_AHB1ENR_TSCEN_Msk                (0x1UL << RCC_AHB1ENR_TSCEN_Pos)  /*!< 0x00010000 */
#define RCC_AHB1ENR_TSCEN                    RCC_AHB1ENR_TSCEN_Msk

/********************  Bit definition for RCC_AHB2ENR register  ***************/
#define RCC_AHB2ENR_GPIOAEN_Pos              (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOAEN_Pos) /*!< 0x00000001 */
#define RCC_AHB2ENR_GPIOAEN                  RCC_AHB2ENR_GPIOAEN_Msk
#define RCC_AHB2ENR_GPIOBEN_Pos              (1U)
#define RCC_AHB2ENR_GPIOBEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOBEN_Pos) /*!< 0x00000002 */
#define RCC_AHB2ENR_GPIOBEN                  RCC_AHB2ENR_GPIOBEN_Msk
#define RCC_AHB2ENR_GPIOCEN_Pos              (2U)
#define RCC_AHB2ENR_GPIOCEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOCEN_Pos) /*!< 0x00000004 */
#define RCC_AHB2ENR_GPIOCEN                  RCC_AHB2ENR_GPIOCEN_Msk
#define RCC_AHB2ENR_GPIODEN_Pos              (3U)
#define RCC_AHB2ENR_GPIODEN_Msk              (0x1UL << RCC_AHB2ENR_GPIODEN_Pos) /*!< 0x00000008 */
#define RCC_AHB2ENR_GPIODEN                  RCC_AHB2ENR_GPIODEN_Msk
#define RCC_AHB2ENR_GPIOEEN_Pos              (4U)
#define RCC_AHB2ENR_GPIOEEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOEEN_Pos) /*!< 0x00000010 */
#define RCC_AHB2ENR_GPIOEEN                  RCC_AHB2ENR_GPIOEEN_Msk
#define RCC_AHB2ENR_GPIOFEN_Pos              (5U)
#define RCC_AHB2ENR_GPIOFEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOFEN_Pos) /*!< 0x00000020 */
#define RCC_AHB2ENR_GPIOFEN                  RCC_AHB2ENR_GPIOFEN_Msk
#define RCC_AHB2ENR_GPIOGEN_Pos              (6U)
#define RCC_AHB2ENR_GPIOGEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOGEN_Pos) /*!< 0x00000040 */
#define RCC_AHB2ENR_GPIOGEN                  RCC_AHB2ENR_GPIOGEN_Msk
#define RCC_AHB2ENR_GPIOHEN_Pos              (7U)
#define RCC_AHB2ENR_GPIOHEN_Msk              (0x1UL << RCC_AHB2ENR_GPIOHEN_Pos) /*!< 0x00000080 */
#define RCC_AHB2ENR_GPIOHEN                  RCC_AHB2ENR_GPIOHEN_Msk
#define RCC_AHB2ENR_OTGFSEN_Pos              (12U)
#define RCC_AHB2ENR_OTGFSEN_Msk              (0x1UL << RCC_AHB2ENR_OTGFSEN_Pos) /*!< 0x00001000 */
#define RCC_AHB2ENR_OTGFSEN                  RCC_AHB2ENR_OTGFSEN_Msk
#define RCC_AHB2ENR_ADCEN_Pos                (13U)
#define RCC_AHB2ENR_ADCEN_Msk                (0x1UL << RCC_AHB2ENR_ADCEN_Pos)  /*!< 0x00002000 */
#define RCC_AHB2ENR_ADCEN                    RCC_AHB2ENR_ADCEN_Msk
#define RCC_AHB2ENR_RNGEN_Pos                (18U)
#define RCC_AHB2ENR_RNGEN_Msk                (0x1UL << RCC_AHB2ENR_RNGEN_Pos)  /*!< 0x00040000 */
#define RCC_AHB2ENR_RNGEN                    RCC_AHB2ENR_RNGEN_Msk

/********************  Bit definition for RCC_AHB3ENR register  ***************/
#define RCC_AHB3ENR_FMCEN_Pos                (0U)
#define RCC_AHB3ENR_FMCEN_Msk                (0x1UL << RCC_AHB3ENR_FMCEN_Pos)  /*!< 0x00000001 */
#define RCC_AHB3ENR_FMCEN                    RCC_AHB3ENR_FMCEN_Msk
#define RCC_AHB3ENR_QSPIEN_Pos               (8U)
#define RCC_AHB3ENR_QSPIEN_Msk               (0x1UL << RCC_AHB3ENR_QSPIEN_Pos) /*!< 0x00000100 */
#define RCC_AHB3ENR_QSPIEN                   RCC_AHB3ENR_QSPIEN_Msk

/********************  Bit definition for RCC_APB1ENR1 register  ***************/
#define RCC_APB1ENR1_TIM2EN_Pos              (0U)
#define RCC_APB1ENR1_TIM2EN_Msk              (0x1UL << RCC_APB1ENR1_TIM2EN_Pos) /*!< 0x00000001 */
#define RCC_APB1ENR1_TIM2EN                  RCC_APB1ENR1_TIM2EN_Msk
#define RCC_APB1ENR1_TIM3EN_Pos              (1U)
#define RCC_APB1ENR1_TIM3EN_Msk              (0x1UL << RCC_APB1ENR1_TIM3EN_Pos) /*!< 0x00000002 */
#define RCC_APB1ENR1_TIM3EN                  RCC_APB1ENR1_TIM3EN_Msk
#define RCC_APB1ENR1_TIM4EN_Pos              (2U)
#define RCC_APB1ENR1_TIM4EN_Msk              (0x1UL << RCC_APB1ENR1_TIM4EN_Pos) /*!< 0x00000004 */
#define RCC_APB1ENR1_TIM4EN                  RCC_APB1ENR1_TIM4EN_Msk
#define RCC_APB1ENR1_TIM5EN_Pos              (3U)
#define RCC_APB1ENR1_TIM5EN_Msk              (0x1UL << RCC_APB1ENR1_TIM5EN_Pos) /*!< 0x00000008 */
#define RCC_APB1ENR1_TIM5EN                  RCC_APB1ENR1_TIM5EN_Msk
#define RCC_APB1ENR1_TIM6EN_Pos              (4U)
#define RCC_APB1ENR1_TIM6EN_Msk              (0x1UL << RCC_APB1ENR1_TIM6EN_Pos) /*!< 0x00000010 */
#define RCC_APB1ENR1_TIM6EN                  RCC_APB1ENR1_TIM6EN_Msk
#define RCC_APB1ENR1_TIM7EN_Pos              (5U)
#define RCC_APB1ENR1_TIM7EN_Msk              (0x1UL << RCC_APB1ENR1_TIM7EN_Pos) /*!< 0x00000020 */
#define RCC_APB1ENR1_TIM7EN                  RCC_APB1ENR1_TIM7EN_Msk
#define RCC_APB1ENR1_WWDGEN_Pos              (11U)
#define RCC_APB1ENR1_WWDGEN_Msk              (0x1UL << RCC_APB1ENR1_WWDGEN_Pos) /*!< 0x00000800 */
#define RCC_APB1ENR1_WWDGEN                  RCC_APB1ENR1_WWDGEN_Msk
#define RCC_APB1ENR1_SPI2EN_Pos              (14U)
#define RCC_APB1ENR1_SPI2EN_Msk              (0x1UL << RCC_APB1ENR1_SPI2EN_Pos) /*!< 0x00004000 */
#define RCC_APB1ENR1_SPI2EN                  RCC_APB1ENR1_SPI2EN_Msk
#define RCC_APB1ENR1_SPI3EN_Pos              (15U)
#define RCC_APB1ENR1_SPI3EN_Msk              (0x1UL << RCC_APB1ENR1_SPI3EN_Pos) /*!< 0x00008000 */
#define RCC_APB1ENR1_SPI3EN                  RCC_APB1ENR1_SPI3EN_Msk
#define RCC_APB1ENR1_USART2EN_Pos            (17U)
#define RCC_APB1ENR1_USART2EN_Msk            (0x1UL << RCC_APB1ENR1_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR1_USART2EN                RCC_APB1ENR1_USART2EN_Msk
#define RCC_APB1ENR1_USART3EN_Pos            (18U)
#define RCC_APB1ENR1_USART3EN_Msk            (0x1UL << RCC_APB1ENR1_USART3EN_Pos) /*!< 0x00040000 */
#define RCC_APB1ENR1_USART3EN                RCC_APB1ENR1_USART3EN_Msk
#define RCC_APB1ENR1_UART4EN_Pos             (19U)
#define RCC_APB1ENR1_UART4EN_Msk             (0x1UL << RCC_APB1ENR1_UART4EN_Pos) /*!< 0x00080000 */
#define RCC_APB1ENR1_UART4EN                 RCC_APB1ENR1_UART4EN_Msk
#define RCC_APB1ENR1_UART5EN_Pos             (20U)
#define RCC_APB1ENR1_UART5EN_Msk             (0x1UL << RCC_APB1ENR1_UART5EN_Pos) /*!< 0x00100000 */
#define RCC_APB1ENR1_UART5EN                 RCC_APB1ENR1_UART5EN_Msk
#define RCC_APB1ENR1_I2C1EN_Pos              (21U)
#define RCC_APB1ENR1_I2C1EN_Msk              (0x1UL << RCC_APB1ENR1_I2C1EN_Pos) /*!< 0x00200000 */
#define RCC_APB1ENR1_I2C1EN                  RCC_APB1ENR1_I2C1EN_Msk
#define RCC_APB1ENR1_I2C2EN_Pos              (22U)
#define RCC_APB1ENR1_I2C2EN_Msk              (0x1UL << RCC_APB1ENR1_I2C2EN_Pos) /*!< 0x00400000 */
#define RCC_APB1ENR1_I2C2EN                  RCC_APB1ENR1_I2C2EN_Msk
#define RCC_APB1ENR1_I2C3EN_Pos              (23U)
#define RCC_APB1ENR1_I2C3EN_Msk              (0x1UL << RCC_APB1ENR1_I2C3EN_Pos) /*!< 0x00800000 */
#define RCC_APB1ENR1_I2C3EN                  RCC_APB1ENR1_I2C3EN_Msk
#define RCC_APB1ENR1_CAN1EN_Pos              (25U)
#define RCC_APB1ENR1_CAN1EN_Msk              (0x1UL << RCC_APB1ENR1_CAN1EN_Pos) /*!< 0x02000000 */
#define RCC_APB1ENR1_CAN1EN                  RCC_APB1ENR1_CAN1EN_Msk
#define RCC_APB1ENR1_PWREN_Pos               (28U)
#define RCC_APB1ENR1_PWREN_Msk               (0x1UL << RCC_APB1ENR1_PWREN_Pos) /*!< 0x10000000 */
#define RCC_APB1ENR1_PWREN                   RCC_APB1ENR1_PWREN_Msk
#define RCC_APB1ENR1_DAC1EN_Pos              (29U)
#define RCC_APB1ENR1_DAC1EN_Msk              (0x1UL << RCC_APB1ENR1_DAC1EN_Pos) /*!< 0x20000000 */
#define RCC_APB1ENR1_DAC1EN                  RCC_APB1ENR1_DAC1EN_Msk
#define RCC_APB1ENR1_OPAMPEN_Pos             (30U)
#define RCC_APB1ENR1_OPAMPEN_Msk             (0x1UL << RCC_APB1ENR1_OPAMPEN_Pos) /*!< 0x40000000 */
#define RCC_APB1ENR1_OPAMPEN                 RCC_APB1ENR1_OPAMPEN_Msk
#define RCC_APB1ENR1_LPTIM1EN_Pos            (31U)
#define RCC_APB1ENR1_LPTIM1EN_Msk            (0x1UL << RCC_APB1ENR1_LPTIM1EN_Pos) /*!< 0x80000000 */
#define RCC_APB1ENR1_LPTIM1EN                RCC_APB1ENR1_LPTIM1EN_Msk

/********************  Bit definition for RCC_APB1RSTR2 register  **************/
#define RCC_APB1ENR2_LPUART1EN_Pos           (0U)
#define RCC_APB1ENR2_LPUART1EN_Msk           (0x1UL << RCC_APB1ENR2_LPUART1EN_Pos) /*!< 0x00000001 */
#define RCC_APB1ENR2_LPUART1EN               RCC_APB1ENR2_LPUART1EN_Msk
#define RCC_APB1ENR2_SWPMI1EN_Pos            (2U)
#define RCC_APB1ENR2_SWPMI1EN_Msk            (0x1UL << RCC_APB1ENR2_SWPMI1EN_Pos) /*!< 0x00000004 */
#define RCC_APB1ENR2_SWPMI1EN                RCC_APB1ENR2_SWPMI1EN_Msk
#define RCC_APB1ENR2_LPTIM2EN_Pos            (5U)
#define RCC_APB1ENR2_LPTIM2EN_Msk            (0x1UL << RCC_APB1ENR2_LPTIM2EN_Pos) /*!< 0x00000020 */
#define RCC_APB1ENR2_LPTIM2EN                RCC_APB1ENR2_LPTIM2EN_Msk

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_SYSCFGEN_Pos             (0U)
#define RCC_APB2ENR_SYSCFGEN_Msk             (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos) /*!< 0x00000001 */
#define RCC_APB2ENR_SYSCFGEN                 RCC_APB2ENR_SYSCFGEN_Msk
#define RCC_APB2ENR_FWEN_Pos                 (7U)
#define RCC_APB2ENR_FWEN_Msk                 (0x1UL << RCC_APB2ENR_FWEN_Pos)   /*!< 0x00000080 */
#define RCC_APB2ENR_FWEN                     RCC_APB2ENR_FWEN_Msk
#define RCC_APB2ENR_SDMMC1EN_Pos             (10U)
#define RCC_APB2ENR_SDMMC1EN_Msk             (0x1UL << RCC_APB2ENR_SDMMC1EN_Pos) /*!< 0x00000400 */
#define RCC_APB2ENR_SDMMC1EN                 RCC_APB2ENR_SDMMC1EN_Msk
#define RCC_APB2ENR_TIM1EN_Pos               (11U)
#define RCC_APB2ENR_TIM1EN_Msk               (0x1UL << RCC_APB2ENR_TIM1EN_Pos) /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN                   RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_SPI1EN_Pos               (12U)
#define RCC_APB2ENR_SPI1EN_Msk               (0x1UL << RCC_APB2ENR_SPI1EN_Pos) /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                   RCC_APB2ENR_SPI1EN_Msk
#define RCC_APB2ENR_TIM8EN_Pos               (13U)
#define RCC_APB2ENR_TIM8EN_Msk               (0x1UL << RCC_APB2ENR_TIM8EN_Pos) /*!< 0x00002000 */
#define RCC_APB2ENR_TIM8EN                   RCC_APB2ENR_TIM8EN_Msk
#define RCC_APB2ENR_USART1EN_Pos             (14U)
#define RCC_APB2ENR_USART1EN_Msk             (0x1UL << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                 RCC_APB2ENR_USART1EN_Msk
#define RCC_APB2ENR_TIM15EN_Pos              (16U)
#define RCC_APB2ENR_TIM15EN_Msk              (0x1UL << RCC_APB2ENR_TIM15EN_Pos) /*!< 0x00010000 */
#define RCC_APB2ENR_TIM15EN                  RCC_APB2ENR_TIM15EN_Msk
#define RCC_APB2ENR_TIM16EN_Pos              (17U)
#define RCC_APB2ENR_TIM16EN_Msk              (0x1UL << RCC_APB2ENR_TIM16EN_Pos) /*!< 0x00020000 */
#define RCC_APB2ENR_TIM16EN                  RCC_APB2ENR_TIM16EN_Msk
#define RCC_APB2ENR_TIM17EN_Pos              (18U)
#define RCC_APB2ENR_TIM17EN_Msk              (0x1UL << RCC_APB2ENR_TIM17EN_Pos) /*!< 0x00040000 */
#define RCC_APB2ENR_TIM17EN                  RCC_APB2ENR_TIM17EN_Msk
#define RCC_APB2ENR_SAI1EN_Pos               (21U)
#define RCC_APB2ENR_SAI1EN_Msk               (0x1UL << RCC_APB2ENR_SAI1EN_Pos) /*!< 0x00200000 */
#define RCC_APB2ENR_SAI1EN                   RCC_APB2ENR_SAI1EN_Msk
#define RCC_APB2ENR_SAI2EN_Pos               (22U)
#define RCC_APB2ENR_SAI2EN_Msk               (0x1UL << RCC_APB2ENR_SAI2EN_Pos) /*!< 0x00400000 */
#define RCC_APB2ENR_SAI2EN                   RCC_APB2ENR_SAI2EN_Msk
#define RCC_APB2ENR_DFSDM1EN_Pos             (24U)
#define RCC_APB2ENR_DFSDM1EN_Msk             (0x1UL << RCC_APB2ENR_DFSDM1EN_Pos) /*!< 0x01000000 */
#define RCC_APB2ENR_DFSDM1EN                 RCC_APB2ENR_DFSDM1EN_Msk

/********************  Bit definition for RCC_AHB1SMENR register  ***************/
#define RCC_AHB1SMENR_DMA1SMEN_Pos           (0U)
#define RCC_AHB1SMENR_DMA1SMEN_Msk           (0x1UL << RCC_AHB1SMENR_DMA1SMEN_Pos) /*!< 0x00000001 */
#define RCC_AHB1SMENR_DMA1SMEN               RCC_AHB1SMENR_DMA1SMEN_Msk
#define RCC_AHB1SMENR_DMA2SMEN_Pos           (1U)
#define RCC_AHB1SMENR_DMA2SMEN_Msk           (0x1UL << RCC_AHB1SMENR_DMA2SMEN_Pos) /*!< 0x00000002 */
#define RCC_AHB1SMENR_DMA2SMEN               RCC_AHB1SMENR_DMA2SMEN_Msk
#define RCC_AHB1SMENR_FLASHSMEN_Pos          (8U)
#define RCC_AHB1SMENR_FLASHSMEN_Msk          (0x1UL << RCC_AHB1SMENR_FLASHSMEN_Pos) /*!< 0x00000100 */
#define RCC_AHB1SMENR_FLASHSMEN              RCC_AHB1SMENR_FLASHSMEN_Msk
#define RCC_AHB1SMENR_SRAM1SMEN_Pos          (9U)
#define RCC_AHB1SMENR_SRAM1SMEN_Msk          (0x1UL << RCC_AHB1SMENR_SRAM1SMEN_Pos) /*!< 0x00000200 */
#define RCC_AHB1SMENR_SRAM1SMEN              RCC_AHB1SMENR_SRAM1SMEN_Msk
#define RCC_AHB1SMENR_CRCSMEN_Pos            (12U)
#define RCC_AHB1SMENR_CRCSMEN_Msk            (0x1UL << RCC_AHB1SMENR_CRCSMEN_Pos) /*!< 0x00001000 */
#define RCC_AHB1SMENR_CRCSMEN                RCC_AHB1SMENR_CRCSMEN_Msk
#define RCC_AHB1SMENR_TSCSMEN_Pos            (16U)
#define RCC_AHB1SMENR_TSCSMEN_Msk            (0x1UL << RCC_AHB1SMENR_TSCSMEN_Pos) /*!< 0x00010000 */
#define RCC_AHB1SMENR_TSCSMEN                RCC_AHB1SMENR_TSCSMEN_Msk

/********************  Bit definition for RCC_AHB2SMENR register  *************/
#define RCC_AHB2SMENR_GPIOASMEN_Pos          (0U)
#define RCC_AHB2SMENR_GPIOASMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOASMEN_Pos) /*!< 0x00000001 */
#define RCC_AHB2SMENR_GPIOASMEN              RCC_AHB2SMENR_GPIOASMEN_Msk
#define RCC_AHB2SMENR_GPIOBSMEN_Pos          (1U)
#define RCC_AHB2SMENR_GPIOBSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOBSMEN_Pos) /*!< 0x00000002 */
#define RCC_AHB2SMENR_GPIOBSMEN              RCC_AHB2SMENR_GPIOBSMEN_Msk
#define RCC_AHB2SMENR_GPIOCSMEN_Pos          (2U)
#define RCC_AHB2SMENR_GPIOCSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOCSMEN_Pos) /*!< 0x00000004 */
#define RCC_AHB2SMENR_GPIOCSMEN              RCC_AHB2SMENR_GPIOCSMEN_Msk
#define RCC_AHB2SMENR_GPIODSMEN_Pos          (3U)
#define RCC_AHB2SMENR_GPIODSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIODSMEN_Pos) /*!< 0x00000008 */
#define RCC_AHB2SMENR_GPIODSMEN              RCC_AHB2SMENR_GPIODSMEN_Msk
#define RCC_AHB2SMENR_GPIOESMEN_Pos          (4U)
#define RCC_AHB2SMENR_GPIOESMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOESMEN_Pos) /*!< 0x00000010 */
#define RCC_AHB2SMENR_GPIOESMEN              RCC_AHB2SMENR_GPIOESMEN_Msk
#define RCC_AHB2SMENR_GPIOFSMEN_Pos          (5U)
#define RCC_AHB2SMENR_GPIOFSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOFSMEN_Pos) /*!< 0x00000020 */
#define RCC_AHB2SMENR_GPIOFSMEN              RCC_AHB2SMENR_GPIOFSMEN_Msk
#define RCC_AHB2SMENR_GPIOGSMEN_Pos          (6U)
#define RCC_AHB2SMENR_GPIOGSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOGSMEN_Pos) /*!< 0x00000040 */
#define RCC_AHB2SMENR_GPIOGSMEN              RCC_AHB2SMENR_GPIOGSMEN_Msk
#define RCC_AHB2SMENR_GPIOHSMEN_Pos          (7U)
#define RCC_AHB2SMENR_GPIOHSMEN_Msk          (0x1UL << RCC_AHB2SMENR_GPIOHSMEN_Pos) /*!< 0x00000080 */
#define RCC_AHB2SMENR_GPIOHSMEN              RCC_AHB2SMENR_GPIOHSMEN_Msk
#define RCC_AHB2SMENR_SRAM2SMEN_Pos          (9U)
#define RCC_AHB2SMENR_SRAM2SMEN_Msk          (0x1UL << RCC_AHB2SMENR_SRAM2SMEN_Pos) /*!< 0x00000200 */
#define RCC_AHB2SMENR_SRAM2SMEN              RCC_AHB2SMENR_SRAM2SMEN_Msk
#define RCC_AHB2SMENR_OTGFSSMEN_Pos          (12U)
#define RCC_AHB2SMENR_OTGFSSMEN_Msk          (0x1UL << RCC_AHB2SMENR_OTGFSSMEN_Pos) /*!< 0x00001000 */
#define RCC_AHB2SMENR_OTGFSSMEN              RCC_AHB2SMENR_OTGFSSMEN_Msk
#define RCC_AHB2SMENR_ADCSMEN_Pos            (13U)
#define RCC_AHB2SMENR_ADCSMEN_Msk            (0x1UL << RCC_AHB2SMENR_ADCSMEN_Pos) /*!< 0x00002000 */
#define RCC_AHB2SMENR_ADCSMEN                RCC_AHB2SMENR_ADCSMEN_Msk
#define RCC_AHB2SMENR_RNGSMEN_Pos            (18U)
#define RCC_AHB2SMENR_RNGSMEN_Msk            (0x1UL << RCC_AHB2SMENR_RNGSMEN_Pos) /*!< 0x00040000 */
#define RCC_AHB2SMENR_RNGSMEN                RCC_AHB2SMENR_RNGSMEN_Msk

/********************  Bit definition for RCC_AHB3SMENR register  *************/
#define RCC_AHB3SMENR_FMCSMEN_Pos            (0U)
#define RCC_AHB3SMENR_FMCSMEN_Msk            (0x1UL << RCC_AHB3SMENR_FMCSMEN_Pos) /*!< 0x00000001 */
#define RCC_AHB3SMENR_FMCSMEN                RCC_AHB3SMENR_FMCSMEN_Msk
#define RCC_AHB3SMENR_QSPISMEN_Pos           (8U)
#define RCC_AHB3SMENR_QSPISMEN_Msk           (0x1UL << RCC_AHB3SMENR_QSPISMEN_Pos) /*!< 0x00000100 */
#define RCC_AHB3SMENR_QSPISMEN               RCC_AHB3SMENR_QSPISMEN_Msk

/********************  Bit definition for RCC_APB1SMENR1 register  *************/
#define RCC_APB1SMENR1_TIM2SMEN_Pos          (0U)
#define RCC_APB1SMENR1_TIM2SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM2SMEN_Pos) /*!< 0x00000001 */
#define RCC_APB1SMENR1_TIM2SMEN              RCC_APB1SMENR1_TIM2SMEN_Msk
#define RCC_APB1SMENR1_TIM3SMEN_Pos          (1U)
#define RCC_APB1SMENR1_TIM3SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM3SMEN_Pos) /*!< 0x00000002 */
#define RCC_APB1SMENR1_TIM3SMEN              RCC_APB1SMENR1_TIM3SMEN_Msk
#define RCC_APB1SMENR1_TIM4SMEN_Pos          (2U)
#define RCC_APB1SMENR1_TIM4SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM4SMEN_Pos) /*!< 0x00000004 */
#define RCC_APB1SMENR1_TIM4SMEN              RCC_APB1SMENR1_TIM4SMEN_Msk
#define RCC_APB1SMENR1_TIM5SMEN_Pos          (3U)
#define RCC_APB1SMENR1_TIM5SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM5SMEN_Pos) /*!< 0x00000008 */
#define RCC_APB1SMENR1_TIM5SMEN              RCC_APB1SMENR1_TIM5SMEN_Msk
#define RCC_APB1SMENR1_TIM6SMEN_Pos          (4U)
#define RCC_APB1SMENR1_TIM6SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM6SMEN_Pos) /*!< 0x00000010 */
#define RCC_APB1SMENR1_TIM6SMEN              RCC_APB1SMENR1_TIM6SMEN_Msk
#define RCC_APB1SMENR1_TIM7SMEN_Pos          (5U)
#define RCC_APB1SMENR1_TIM7SMEN_Msk          (0x1UL << RCC_APB1SMENR1_TIM7SMEN_Pos) /*!< 0x00000020 */
#define RCC_APB1SMENR1_TIM7SMEN              RCC_APB1SMENR1_TIM7SMEN_Msk
#define RCC_APB1SMENR1_WWDGSMEN_Pos          (11U)
#define RCC_APB1SMENR1_WWDGSMEN_Msk          (0x1UL << RCC_APB1SMENR1_WWDGSMEN_Pos) /*!< 0x00000800 */
#define RCC_APB1SMENR1_WWDGSMEN              RCC_APB1SMENR1_WWDGSMEN_Msk
#define RCC_APB1SMENR1_SPI2SMEN_Pos          (14U)
#define RCC_APB1SMENR1_SPI2SMEN_Msk          (0x1UL << RCC_APB1SMENR1_SPI2SMEN_Pos) /*!< 0x00004000 */
#define RCC_APB1SMENR1_SPI2SMEN              RCC_APB1SMENR1_SPI2SMEN_Msk
#define RCC_APB1SMENR1_SPI3SMEN_Pos          (15U)
#define RCC_APB1SMENR1_SPI3SMEN_Msk          (0x1UL << RCC_APB1SMENR1_SPI3SMEN_Pos) /*!< 0x00008000 */
#define RCC_APB1SMENR1_SPI3SMEN              RCC_APB1SMENR1_SPI3SMEN_Msk
#define RCC_APB1SMENR1_USART2SMEN_Pos        (17U)
#define RCC_APB1SMENR1_USART2SMEN_Msk        (0x1UL << RCC_APB1SMENR1_USART2SMEN_Pos) /*!< 0x00020000 */
#define RCC_APB1SMENR1_USART2SMEN            RCC_APB1SMENR1_USART2SMEN_Msk
#define RCC_APB1SMENR1_USART3SMEN_Pos        (18U)
#define RCC_APB1SMENR1_USART3SMEN_Msk        (0x1UL << RCC_APB1SMENR1_USART3SMEN_Pos) /*!< 0x00040000 */
#define RCC_APB1SMENR1_USART3SMEN            RCC_APB1SMENR1_USART3SMEN_Msk
#define RCC_APB1SMENR1_UART4SMEN_Pos         (19U)
#define RCC_APB1SMENR1_UART4SMEN_Msk         (0x1UL << RCC_APB1SMENR1_UART4SMEN_Pos) /*!< 0x00080000 */
#define RCC_APB1SMENR1_UART4SMEN             RCC_APB1SMENR1_UART4SMEN_Msk
#define RCC_APB1SMENR1_UART5SMEN_Pos         (20U)
#define RCC_APB1SMENR1_UART5SMEN_Msk         (0x1UL << RCC_APB1SMENR1_UART5SMEN_Pos) /*!< 0x00100000 */
#define RCC_APB1SMENR1_UART5SMEN             RCC_APB1SMENR1_UART5SMEN_Msk
#define RCC_APB1SMENR1_I2C1SMEN_Pos          (21U)
#define RCC_APB1SMENR1_I2C1SMEN_Msk          (0x1UL << RCC_APB1SMENR1_I2C1SMEN_Pos) /*!< 0x00200000 */
#define RCC_APB1SMENR1_I2C1SMEN              RCC_APB1SMENR1_I2C1SMEN_Msk
#define RCC_APB1SMENR1_I2C2SMEN_Pos          (22U)
#define RCC_APB1SMENR1_I2C2SMEN_Msk          (0x1UL << RCC_APB1SMENR1_I2C2SMEN_Pos) /*!< 0x00400000 */
#define RCC_APB1SMENR1_I2C2SMEN              RCC_APB1SMENR1_I2C2SMEN_Msk
#define RCC_APB1SMENR1_I2C3SMEN_Pos          (23U)
#define RCC_APB1SMENR1_I2C3SMEN_Msk          (0x1UL << RCC_APB1SMENR1_I2C3SMEN_Pos) /*!< 0x00800000 */
#define RCC_APB1SMENR1_I2C3SMEN              RCC_APB1SMENR1_I2C3SMEN_Msk
#define RCC_APB1SMENR1_CAN1SMEN_Pos          (25U)
#define RCC_APB1SMENR1_CAN1SMEN_Msk          (0x1UL << RCC_APB1SMENR1_CAN1SMEN_Pos) /*!< 0x02000000 */
#define RCC_APB1SMENR1_CAN1SMEN              RCC_APB1SMENR1_CAN1SMEN_Msk
#define RCC_APB1SMENR1_PWRSMEN_Pos           (28U)
#define RCC_APB1SMENR1_PWRSMEN_Msk           (0x1UL << RCC_APB1SMENR1_PWRSMEN_Pos) /*!< 0x10000000 */
#define RCC_APB1SMENR1_PWRSMEN               RCC_APB1SMENR1_PWRSMEN_Msk
#define RCC_APB1SMENR1_DAC1SMEN_Pos          (29U)
#define RCC_APB1SMENR1_DAC1SMEN_Msk          (0x1UL << RCC_APB1SMENR1_DAC1SMEN_Pos) /*!< 0x20000000 */
#define RCC_APB1SMENR1_DAC1SMEN              RCC_APB1SMENR1_DAC1SMEN_Msk
#define RCC_APB1SMENR1_OPAMPSMEN_Pos         (30U)
#define RCC_APB1SMENR1_OPAMPSMEN_Msk         (0x1UL << RCC_APB1SMENR1_OPAMPSMEN_Pos) /*!< 0x40000000 */
#define RCC_APB1SMENR1_OPAMPSMEN             RCC_APB1SMENR1_OPAMPSMEN_Msk
#define RCC_APB1SMENR1_LPTIM1SMEN_Pos        (31U)
#define RCC_APB1SMENR1_LPTIM1SMEN_Msk        (0x1UL << RCC_APB1SMENR1_LPTIM1SMEN_Pos) /*!< 0x80000000 */
#define RCC_APB1SMENR1_LPTIM1SMEN            RCC_APB1SMENR1_LPTIM1SMEN_Msk

/********************  Bit definition for RCC_APB1SMENR2 register  *************/
#define RCC_APB1SMENR2_LPUART1SMEN_Pos       (0U)
#define RCC_APB1SMENR2_LPUART1SMEN_Msk       (0x1UL << RCC_APB1SMENR2_LPUART1SMEN_Pos) /*!< 0x00000001 */
#define RCC_APB1SMENR2_LPUART1SMEN           RCC_APB1SMENR2_LPUART1SMEN_Msk
#define RCC_APB1SMENR2_SWPMI1SMEN_Pos        (2U)
#define RCC_APB1SMENR2_SWPMI1SMEN_Msk        (0x1UL << RCC_APB1SMENR2_SWPMI1SMEN_Pos) /*!< 0x00000004 */
#define RCC_APB1SMENR2_SWPMI1SMEN            RCC_APB1SMENR2_SWPMI1SMEN_Msk
#define RCC_APB1SMENR2_LPTIM2SMEN_Pos        (5U)
#define RCC_APB1SMENR2_LPTIM2SMEN_Msk        (0x1UL << RCC_APB1SMENR2_LPTIM2SMEN_Pos) /*!< 0x00000020 */
#define RCC_APB1SMENR2_LPTIM2SMEN            RCC_APB1SMENR2_LPTIM2SMEN_Msk

/********************  Bit definition for RCC_APB2SMENR register  *************/
#define RCC_APB2SMENR_SYSCFGSMEN_Pos         (0U)
#define RCC_APB2SMENR_SYSCFGSMEN_Msk         (0x1UL << RCC_APB2SMENR_SYSCFGSMEN_Pos) /*!< 0x00000001 */
#define RCC_APB2SMENR_SYSCFGSMEN             RCC_APB2SMENR_SYSCFGSMEN_Msk
#define RCC_APB2SMENR_SDMMC1SMEN_Pos         (10U)
#define RCC_APB2SMENR_SDMMC1SMEN_Msk         (0x1UL << RCC_APB2SMENR_SDMMC1SMEN_Pos) /*!< 0x00000400 */
#define RCC_APB2SMENR_SDMMC1SMEN             RCC_APB2SMENR_SDMMC1SMEN_Msk
#define RCC_APB2SMENR_TIM1SMEN_Pos           (11U)
#define RCC_APB2SMENR_TIM1SMEN_Msk           (0x1UL << RCC_APB2SMENR_TIM1SMEN_Pos) /*!< 0x00000800 */
#define RCC_APB2SMENR_TIM1SMEN               RCC_APB2SMENR_TIM1SMEN_Msk
#define RCC_APB2SMENR_SPI1SMEN_Pos           (12U)
#define RCC_APB2SMENR_SPI1SMEN_Msk           (0x1UL << RCC_APB2SMENR_SPI1SMEN_Pos) /*!< 0x00001000 */
#define RCC_APB2SMENR_SPI1SMEN               RCC_APB2SMENR_SPI1SMEN_Msk
#define RCC_APB2SMENR_TIM8SMEN_Pos           (13U)
#define RCC_APB2SMENR_TIM8SMEN_Msk           (0x1UL << RCC_APB2SMENR_TIM8SMEN_Pos) /*!< 0x00002000 */
#define RCC_APB2SMENR_TIM8SMEN               RCC_APB2SMENR_TIM8SMEN_Msk
#define RCC_APB2SMENR_USART1SMEN_Pos         (14U)
#define RCC_APB2SMENR_USART1SMEN_Msk         (0x1UL << RCC_APB2SMENR_USART1SMEN_Pos) /*!< 0x00004000 */
#define RCC_APB2SMENR_USART1SMEN             RCC_APB2SMENR_USART1SMEN_Msk
#define RCC_APB2SMENR_TIM15SMEN_Pos          (16U)
#define RCC_APB2SMENR_TIM15SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM15SMEN_Pos) /*!< 0x00010000 */
#define RCC_APB2SMENR_TIM15SMEN              RCC_APB2SMENR_TIM15SMEN_Msk
#define RCC_APB2SMENR_TIM16SMEN_Pos          (17U)
#define RCC_APB2SMENR_TIM16SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM16SMEN_Pos) /*!< 0x00020000 */
#define RCC_APB2SMENR_TIM16SMEN              RCC_APB2SMENR_TIM16SMEN_Msk
#define RCC_APB2SMENR_TIM17SMEN_Pos          (18U)
#define RCC_APB2SMENR_TIM17SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM17SMEN_Pos) /*!< 0x00040000 */
#define RCC_APB2SMENR_TIM17SMEN              RCC_APB2SMENR_TIM17SMEN_Msk
#define RCC_APB2SMENR_SAI1SMEN_Pos           (21U)
#define RCC_APB2SMENR_SAI1SMEN_Msk           (0x1UL << RCC_APB2SMENR_SAI1SMEN_Pos) /*!< 0x00200000 */
#define RCC_APB2SMENR_SAI1SMEN               RCC_APB2SMENR_SAI1SMEN_Msk
#define RCC_APB2SMENR_SAI2SMEN_Pos           (22U)
#define RCC_APB2SMENR_SAI2SMEN_Msk           (0x1UL << RCC_APB2SMENR_SAI2SMEN_Pos) /*!< 0x00400000 */
#define RCC_APB2SMENR_SAI2SMEN               RCC_APB2SMENR_SAI2SMEN_Msk
#define RCC_APB2SMENR_DFSDM1SMEN_Pos         (24U)
#define RCC_APB2SMENR_DFSDM1SMEN_Msk         (0x1UL << RCC_APB2SMENR_DFSDM1SMEN_Pos) /*!< 0x01000000 */
#define RCC_APB2SMENR_DFSDM1SMEN             RCC_APB2SMENR_DFSDM1SMEN_Msk

/********************  Bit definition for RCC_CCIPR register  ******************/
#define RCC_CCIPR_USART1SEL_Pos              (0U)
#define RCC_CCIPR_USART1SEL_Msk              (0x3UL << RCC_CCIPR_USART1SEL_Pos) /*!< 0x00000003 */
#define RCC_CCIPR_USART1SEL                  RCC_CCIPR_USART1SEL_Msk
#define RCC_CCIPR_USART1SEL_0                (0x1UL << RCC_CCIPR_USART1SEL_Pos) /*!< 0x00000001 */
#define RCC_CCIPR_USART1SEL_1                (0x2UL << RCC_CCIPR_USART1SEL_Pos) /*!< 0x00000002 */

#define RCC_CCIPR_USART2SEL_Pos              (2U)
#define RCC_CCIPR_USART2SEL_Msk              (0x3UL << RCC_CCIPR_USART2SEL_Pos) /*!< 0x0000000C */
#define RCC_CCIPR_USART2SEL                  RCC_CCIPR_USART2SEL_Msk
#define RCC_CCIPR_USART2SEL_0                (0x1UL << RCC_CCIPR_USART2SEL_Pos) /*!< 0x00000004 */
#define RCC_CCIPR_USART2SEL_1                (0x2UL << RCC_CCIPR_USART2SEL_Pos) /*!< 0x00000008 */

#define RCC_CCIPR_USART3SEL_Pos              (4U)
#define RCC_CCIPR_USART3SEL_Msk              (0x3UL << RCC_CCIPR_USART3SEL_Pos) /*!< 0x00000030 */
#define RCC_CCIPR_USART3SEL                  RCC_CCIPR_USART3SEL_Msk
#define RCC_CCIPR_USART3SEL_0                (0x1UL << RCC_CCIPR_USART3SEL_Pos) /*!< 0x00000010 */
#define RCC_CCIPR_USART3SEL_1                (0x2UL << RCC_CCIPR_USART3SEL_Pos) /*!< 0x00000020 */

#define RCC_CCIPR_UART4SEL_Pos               (6U)
#define RCC_CCIPR_UART4SEL_Msk               (0x3UL << RCC_CCIPR_UART4SEL_Pos) /*!< 0x000000C0 */
#define RCC_CCIPR_UART4SEL                   RCC_CCIPR_UART4SEL_Msk
#define RCC_CCIPR_UART4SEL_0                 (0x1UL << RCC_CCIPR_UART4SEL_Pos) /*!< 0x00000040 */
#define RCC_CCIPR_UART4SEL_1                 (0x2UL << RCC_CCIPR_UART4SEL_Pos) /*!< 0x00000080 */

#define RCC_CCIPR_UART5SEL_Pos               (8U)
#define RCC_CCIPR_UART5SEL_Msk               (0x3UL << RCC_CCIPR_UART5SEL_Pos) /*!< 0x00000300 */
#define RCC_CCIPR_UART5SEL                   RCC_CCIPR_UART5SEL_Msk
#define RCC_CCIPR_UART5SEL_0                 (0x1UL << RCC_CCIPR_UART5SEL_Pos) /*!< 0x00000100 */
#define RCC_CCIPR_UART5SEL_1                 (0x2UL << RCC_CCIPR_UART5SEL_Pos) /*!< 0x00000200 */

#define RCC_CCIPR_LPUART1SEL_Pos             (10U)
#define RCC_CCIPR_LPUART1SEL_Msk             (0x3UL << RCC_CCIPR_LPUART1SEL_Pos) /*!< 0x00000C00 */
#define RCC_CCIPR_LPUART1SEL                 RCC_CCIPR_LPUART1SEL_Msk
#define RCC_CCIPR_LPUART1SEL_0               (0x1UL << RCC_CCIPR_LPUART1SEL_Pos) /*!< 0x00000400 */
#define RCC_CCIPR_LPUART1SEL_1               (0x2UL << RCC_CCIPR_LPUART1SEL_Pos) /*!< 0x00000800 */

#define RCC_CCIPR_I2C1SEL_Pos                (12U)
#define RCC_CCIPR_I2C1SEL_Msk                (0x3UL << RCC_CCIPR_I2C1SEL_Pos)  /*!< 0x00003000 */
#define RCC_CCIPR_I2C1SEL                    RCC_CCIPR_I2C1SEL_Msk
#define RCC_CCIPR_I2C1SEL_0                  (0x1UL << RCC_CCIPR_I2C1SEL_Pos)  /*!< 0x00001000 */
#define RCC_CCIPR_I2C1SEL_1                  (0x2UL << RCC_CCIPR_I2C1SEL_Pos)  /*!< 0x00002000 */

#define RCC_CCIPR_I2C2SEL_Pos                (14U)
#define RCC_CCIPR_I2C2SEL_Msk                (0x3UL << RCC_CCIPR_I2C2SEL_Pos)  /*!< 0x0000C000 */
#define RCC_CCIPR_I2C2SEL                    RCC_CCIPR_I2C2SEL_Msk
#define RCC_CCIPR_I2C2SEL_0                  (0x1UL << RCC_CCIPR_I2C2SEL_Pos)  /*!< 0x00004000 */
#define RCC_CCIPR_I2C2SEL_1                  (0x2UL << RCC_CCIPR_I2C2SEL_Pos)  /*!< 0x00008000 */

#define RCC_CCIPR_I2C3SEL_Pos                (16U)
#define RCC_CCIPR_I2C3SEL_Msk                (0x3UL << RCC_CCIPR_I2C3SEL_Pos)  /*!< 0x00030000 */
#define RCC_CCIPR_I2C3SEL                    RCC_CCIPR_I2C3SEL_Msk
#define RCC_CCIPR_I2C3SEL_0                  (0x1UL << RCC_CCIPR_I2C3SEL_Pos)  /*!< 0x00010000 */
#define RCC_CCIPR_I2C3SEL_1                  (0x2UL << RCC_CCIPR_I2C3SEL_Pos)  /*!< 0x00020000 */

#define RCC_CCIPR_LPTIM1SEL_Pos              (18U)
#define RCC_CCIPR_LPTIM1SEL_Msk              (0x3UL << RCC_CCIPR_LPTIM1SEL_Pos) /*!< 0x000C0000 */
#define RCC_CCIPR_LPTIM1SEL                  RCC_CCIPR_LPTIM1SEL_Msk
#define RCC_CCIPR_LPTIM1SEL_0                (0x1UL << RCC_CCIPR_LPTIM1SEL_Pos) /*!< 0x00040000 */
#define RCC_CCIPR_LPTIM1SEL_1                (0x2UL << RCC_CCIPR_LPTIM1SEL_Pos) /*!< 0x00080000 */

#define RCC_CCIPR_LPTIM2SEL_Pos              (20U)
#define RCC_CCIPR_LPTIM2SEL_Msk              (0x3UL << RCC_CCIPR_LPTIM2SEL_Pos) /*!< 0x00300000 */
#define RCC_CCIPR_LPTIM2SEL                  RCC_CCIPR_LPTIM2SEL_Msk
#define RCC_CCIPR_LPTIM2SEL_0                (0x1UL << RCC_CCIPR_LPTIM2SEL_Pos) /*!< 0x00100000 */
#define RCC_CCIPR_LPTIM2SEL_1                (0x2UL << RCC_CCIPR_LPTIM2SEL_Pos) /*!< 0x00200000 */

#define RCC_CCIPR_SAI1SEL_Pos                (22U)
#define RCC_CCIPR_SAI1SEL_Msk                (0x3UL << RCC_CCIPR_SAI1SEL_Pos)  /*!< 0x00C00000 */
#define RCC_CCIPR_SAI1SEL                    RCC_CCIPR_SAI1SEL_Msk
#define RCC_CCIPR_SAI1SEL_0                  (0x1UL << RCC_CCIPR_SAI1SEL_Pos)  /*!< 0x00400000 */
#define RCC_CCIPR_SAI1SEL_1                  (0x2UL << RCC_CCIPR_SAI1SEL_Pos)  /*!< 0x00800000 */

#define RCC_CCIPR_SAI2SEL_Pos                (24U)
#define RCC_CCIPR_SAI2SEL_Msk                (0x3UL << RCC_CCIPR_SAI2SEL_Pos)  /*!< 0x03000000 */
#define RCC_CCIPR_SAI2SEL                    RCC_CCIPR_SAI2SEL_Msk
#define RCC_CCIPR_SAI2SEL_0                  (0x1UL << RCC_CCIPR_SAI2SEL_Pos)  /*!< 0x01000000 */
#define RCC_CCIPR_SAI2SEL_1                  (0x2UL << RCC_CCIPR_SAI2SEL_Pos)  /*!< 0x02000000 */

#define RCC_CCIPR_CLK48SEL_Pos               (26U)
#define RCC_CCIPR_CLK48SEL_Msk               (0x3UL << RCC_CCIPR_CLK48SEL_Pos) /*!< 0x0C000000 */
#define RCC_CCIPR_CLK48SEL                   RCC_CCIPR_CLK48SEL_Msk
#define RCC_CCIPR_CLK48SEL_0                 (0x1UL << RCC_CCIPR_CLK48SEL_Pos) /*!< 0x04000000 */
#define RCC_CCIPR_CLK48SEL_1                 (0x2UL << RCC_CCIPR_CLK48SEL_Pos) /*!< 0x08000000 */

#define RCC_CCIPR_ADCSEL_Pos                 (28U)
#define RCC_CCIPR_ADCSEL_Msk                 (0x3UL << RCC_CCIPR_ADCSEL_Pos)   /*!< 0x30000000 */
#define RCC_CCIPR_ADCSEL                     RCC_CCIPR_ADCSEL_Msk
#define RCC_CCIPR_ADCSEL_0                   (0x1UL << RCC_CCIPR_ADCSEL_Pos)   /*!< 0x10000000 */
#define RCC_CCIPR_ADCSEL_1                   (0x2UL << RCC_CCIPR_ADCSEL_Pos)   /*!< 0x20000000 */

#define RCC_CCIPR_SWPMI1SEL_Pos              (30U)
#define RCC_CCIPR_SWPMI1SEL_Msk              (0x1UL << RCC_CCIPR_SWPMI1SEL_Pos) /*!< 0x40000000 */
#define RCC_CCIPR_SWPMI1SEL                  RCC_CCIPR_SWPMI1SEL_Msk

#define RCC_CCIPR_DFSDM1SEL_Pos              (31U)
#define RCC_CCIPR_DFSDM1SEL_Msk              (0x1UL << RCC_CCIPR_DFSDM1SEL_Pos) /*!< 0x80000000 */
#define RCC_CCIPR_DFSDM1SEL                  RCC_CCIPR_DFSDM1SEL_Msk

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                   (0U)
#define RCC_BDCR_LSEON_Msk                   (0x1UL << RCC_BDCR_LSEON_Pos)     /*!< 0x00000001 */
#define RCC_BDCR_LSEON                       RCC_BDCR_LSEON_Msk
#define RCC_BDCR_LSERDY_Pos                  (1U)
#define RCC_BDCR_LSERDY_Msk                  (0x1UL << RCC_BDCR_LSERDY_Pos)    /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                      RCC_BDCR_LSERDY_Msk
#define RCC_BDCR_LSEBYP_Pos                  (2U)
#define RCC_BDCR_LSEBYP_Msk                  (0x1UL << RCC_BDCR_LSEBYP_Pos)    /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                      RCC_BDCR_LSEBYP_Msk

#define RCC_BDCR_LSEDRV_Pos                  (3U)
#define RCC_BDCR_LSEDRV_Msk                  (0x3UL << RCC_BDCR_LSEDRV_Pos)    /*!< 0x00000018 */
#define RCC_BDCR_LSEDRV                      RCC_BDCR_LSEDRV_Msk
#define RCC_BDCR_LSEDRV_0                    (0x1UL << RCC_BDCR_LSEDRV_Pos)    /*!< 0x00000008 */
#define RCC_BDCR_LSEDRV_1                    (0x2UL << RCC_BDCR_LSEDRV_Pos)    /*!< 0x00000010 */

#define RCC_BDCR_LSECSSON_Pos                (5U)
#define RCC_BDCR_LSECSSON_Msk                (0x1UL << RCC_BDCR_LSECSSON_Pos)  /*!< 0x00000020 */
#define RCC_BDCR_LSECSSON                    RCC_BDCR_LSECSSON_Msk
#define RCC_BDCR_LSECSSD_Pos                 (6U)
#define RCC_BDCR_LSECSSD_Msk                 (0x1UL << RCC_BDCR_LSECSSD_Pos)   /*!< 0x00000040 */
#define RCC_BDCR_LSECSSD                     RCC_BDCR_LSECSSD_Msk

#define RCC_BDCR_RTCSEL_Pos                  (8U)
#define RCC_BDCR_RTCSEL_Msk                  (0x3UL << RCC_BDCR_RTCSEL_Pos)    /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                      RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0                    (0x1UL << RCC_BDCR_RTCSEL_Pos)    /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                    (0x2UL << RCC_BDCR_RTCSEL_Pos)    /*!< 0x00000200 */

#define RCC_BDCR_RTCEN_Pos                   (15U)
#define RCC_BDCR_RTCEN_Msk                   (0x1UL << RCC_BDCR_RTCEN_Pos)     /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                       RCC_BDCR_RTCEN_Msk
#define RCC_BDCR_BDRST_Pos                   (16U)
#define RCC_BDCR_BDRST_Msk                   (0x1UL << RCC_BDCR_BDRST_Pos)     /*!< 0x00010000 */
#define RCC_BDCR_BDRST                       RCC_BDCR_BDRST_Msk
#define RCC_BDCR_LSCOEN_Pos                  (24U)
#define RCC_BDCR_LSCOEN_Msk                  (0x1UL << RCC_BDCR_LSCOEN_Pos)    /*!< 0x01000000 */
#define RCC_BDCR_LSCOEN                      RCC_BDCR_LSCOEN_Msk
#define RCC_BDCR_LSCOSEL_Pos                 (25U)
#define RCC_BDCR_LSCOSEL_Msk                 (0x1UL << RCC_BDCR_LSCOSEL_Pos)   /*!< 0x02000000 */
#define RCC_BDCR_LSCOSEL                     RCC_BDCR_LSCOSEL_Msk

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos                    (0U)
#define RCC_CSR_LSION_Msk                    (0x1UL << RCC_CSR_LSION_Pos)      /*!< 0x00000001 */
#define RCC_CSR_LSION                        RCC_CSR_LSION_Msk
#define RCC_CSR_LSIRDY_Pos                   (1U)
#define RCC_CSR_LSIRDY_Msk                   (0x1UL << RCC_CSR_LSIRDY_Pos)     /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                       RCC_CSR_LSIRDY_Msk

#define RCC_CSR_MSISRANGE_Pos                (8U)
#define RCC_CSR_MSISRANGE_Msk                (0xFUL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000F00 */
#define RCC_CSR_MSISRANGE                    RCC_CSR_MSISRANGE_Msk
#define RCC_CSR_MSISRANGE_1                  (0x4UL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000400 */
#define RCC_CSR_MSISRANGE_2                  (0x5UL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000500 */
#define RCC_CSR_MSISRANGE_4                  (0x6UL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000600 */
#define RCC_CSR_MSISRANGE_8                  (0x7UL << RCC_CSR_MSISRANGE_Pos)  /*!< 0x00000700 */

#define RCC_CSR_RMVF_Pos                     (23U)
#define RCC_CSR_RMVF_Msk                     (0x1UL << RCC_CSR_RMVF_Pos)       /*!< 0x00800000 */
#define RCC_CSR_RMVF                         RCC_CSR_RMVF_Msk
#define RCC_CSR_FWRSTF_Pos                   (24U)
#define RCC_CSR_FWRSTF_Msk                   (0x1UL << RCC_CSR_FWRSTF_Pos)     /*!< 0x01000000 */
#define RCC_CSR_FWRSTF                       RCC_CSR_FWRSTF_Msk
#define RCC_CSR_OBLRSTF_Pos                  (25U)
#define RCC_CSR_OBLRSTF_Msk                  (0x1UL << RCC_CSR_OBLRSTF_Pos)    /*!< 0x02000000 */
#define RCC_CSR_OBLRSTF                      RCC_CSR_OBLRSTF_Msk
#define RCC_CSR_PINRSTF_Pos                  (26U)
#define RCC_CSR_PINRSTF_Msk                  (0x1UL << RCC_CSR_PINRSTF_Pos)    /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                      RCC_CSR_PINRSTF_Msk
#define RCC_CSR_BORRSTF_Pos                  (27U)
#define RCC_CSR_BORRSTF_Msk                  (0x1UL << RCC_CSR_BORRSTF_Pos)    /*!< 0x08000000 */
#define RCC_CSR_BORRSTF                      RCC_CSR_BORRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos                  (28U)
#define RCC_CSR_SFTRSTF_Msk                  (0x1UL << RCC_CSR_SFTRSTF_Pos)    /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                      RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos                 (29U)
#define RCC_CSR_IWDGRSTF_Msk                 (0x1UL << RCC_CSR_IWDGRSTF_Pos)   /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                     RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos                 (30U)
#define RCC_CSR_WWDGRSTF_Msk                 (0x1UL << RCC_CSR_WWDGRSTF_Pos)   /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                     RCC_CSR_WWDGRSTF_Msk
#define RCC_CSR_LPWRRSTF_Pos                 (31U)
#define RCC_CSR_LPWRRSTF_Msk                 (0x1UL << RCC_CSR_LPWRRSTF_Pos)   /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                     RCC_CSR_LPWRRSTF_Msk

void hw_rcc_set_msi_clock_enable(void);
void hw_rcc_set_msi_clock_disable(void);
uint32_t hw_rcc_get_msi_clock_enable(void);
uint32_t hw_rcc_msi_clock_ready_status(void);
void hw_rcc_msi_clock_wait_ready(void);
void hw_rcc_set_msi_clock_pll_enable(void);
void hw_rcc_set_msi_clock_pll_disable(void);
uint32_t hw_rcc_get_msi_clock_pll_enable(void);
void hw_rcc_switch_msi_clock_range(void);
uint32_t hw_rcc_get_msi_clock_range_selection(void);
void hw_rcc_set_msi_clock_ranges(uint32_t range);
uint32_t hw_rcc_get_msi_clock_ranges(void);
void hw_rcc_set_hsi_clock_enable(void);
void hw_rcc_set_hsi_clock_disable(void);
uint32_t hw_rcc_get_hsi_clock_enable(void);
void hw_rcc_set_hsi_clock_enable_for_peripheral_kernels(void);
void hw_rcc_set_hsi_clock_disable_for_peripheral_kernels(void);
uint32_t hw_rcc_get_hsi_clock_enable_for_peripheral_kernels(void);
uint32_t hw_rcc_hsi_clock_ready_status(void);
void hw_rcc_hsi_clock_wait_ready(void);
void hw_rcc_open_hsi_clock_automatic_start_from_stop(void);
void hw_rcc_close_hsi_clock_automatic_start_from_stop(void);
uint32_t hw_rcc_get_hsi_clock_automatic_start_from_stop(void);
void hw_rcc_set_hse_clock_enable(void);
void hw_rcc_set_hse_clock_disable(void);
uint32_t hw_rcc_get_hse_clock_enable(void);
uint32_t hw_rcc_hse_clock_ready_status(void);
void hw_rcc_hse_clock_wait_ready(void);
void hw_rcc_hse_clock_bypass_enadble(void);
void hw_rcc_hse_clock_bypass_disadble(void);
uint32_t hw_rcc_hse_clock_bypass(void);
void hw_rcc_set_clock_security_system_enable(void);
uint32_t hw_rcc_get_clock_security_system_enable(void);
void hw_rcc_set_pll_clock_enable(void);
void hw_rcc_set_pll_clock_disable(void);
uint32_t hw_rcc_get_pll_clock_enable(void);
uint32_t hw_rcc_pll_clock_ready_status(void);
void hw_rcc_pll_clock_wait_ready(void);
void hw_rcc_set_pll_sai1_clock_enable(void);
void hw_rcc_set_pll_sai1_clock_disable(void);
uint32_t hw_rcc_get_pll_sai1_clock_enable(void);
uint32_t hw_rcc_pll_sai1_clock_ready_status(void);
void hw_rcc_pll_sai1_clock_wait_ready(void);
void hw_rcc_set_pll_sai2_clock_enable(void);
void hw_rcc_set_pll_sai2_clock_disable(void);
uint32_t hw_rcc_get_pll_sai2_clock_enable(void);
uint32_t hw_rcc_pll_sai2_clock_ready_status(void);
void hw_rcc_pll_sai2_clock_wait_ready(void);
uint32_t hw_rcc_msi_clock_calibration(void);
void hw_rcc_set_msi_clock_trimming(uint32_t trimming);
uint32_t hw_rcc_get_msi_clock_trimming(void);
uint32_t hw_rcc_hsi_clock_calibration(void);
void hw_rcc_set_hsi_clock_trimming(uint32_t trimming);
uint32_t hw_rcc_get_hsi_clock_trimming(void);
void hw_rcc_set_system_clock_source(uint32_t source);
uint32_t hw_rcc_get_system_clock_source(void);
uint32_t hw_rcc_get_system_clock_source_status(void);
void hw_rcc_set_ahb_clock_prescaler(uint32_t prescaler);
uint32_t hw_rcc_get_ahb_clock_prescaler(void);
void hw_rcc_set_apb1_clock_prescaler(uint32_t prescaler);
uint32_t hw_rcc_get_apb1_clock_prescaler(void);
void hw_rcc_set_apb2_clock_prescaler(uint32_t prescaler);
uint32_t hw_rcc_get_apb2_clock_prescaler(void);
void hw_rcc_select_wakeup_from_stop_css_buckup_clock(uint32_t select);
uint32_t hw_rcc_wakeup_from_stop_css_buckup_clock(void);
void hw_rcc_select_microcontroller_clock_output(uint32_t select);
uint32_t hw_rcc_microcontroller_clock_output(void);
void hw_rcc_set_microcontroller_clock_output_prescaler(uint32_t prescaler);
uint32_t hw_rcc_microcontroller_clock_output_prescaler(void);
void hw_rcc_set_main_clock_source(uint32_t source);
uint32_t hw_rcc_get_main_clock_source(void);
void hw_rcc_set_division_factor_for_main_pll(uint32_t factor);
uint32_t hw_rcc_get_division_factor_for_main_pll(void);
void hw_rcc_set_main_pll_multiplication_factor_for_vco(uint32_t factor);
uint32_t hw_rcc_get_main_pll_multiplication_factor_for_vco(void);
void hw_rcc_set_main_pll_sai3_clock_output_enable(void);
void hw_rcc_set_main_pll_sai3_clock_output_disable(void);
uint32_t hw_rcc_get_main_pll_sai3_clock_output_enable(void);
void hw_rcc_set_main_pll_division_factor_for_pllsai3clk(uint32_t factor);
uint32_t hw_rcc_get_main_pll_division_factor_for_pllsai3clk(void);
void hw_rcc_set_main_pll_pll48m1_clock_output_enable(void);
void hw_rcc_set_main_pll_pll48m1_clock_output_disable(void);
uint32_t hw_rcc_get_main_pll_pll48m1_clock_output_enable(void);
void hw_rcc_set_main_pll_pll48m1_division_factor(uint32_t factor);
uint32_t hw_rcc_get_main_pll_pll48m1_division_factor(void);
void hw_rcc_set_main_pll_clock_output_enable(void);
void hw_rcc_set_main_pll_clock_output_disable(void);
uint32_t hw_rcc_get_main_pll_clock_output_enable(void);
void hw_rcc_set_main_pll_division_factor_for_pllclk(uint32_t factor);
uint32_t hw_rcc_get_main_pll_division_factor_for_pllclk(void);
void hw_rcc_set_pll_sai1_multiplication_factor_for_vco(uint32_t factor);
uint32_t hw_rcc_get_pll_sai1_multiplication_factor_for_vco(void);
void hw_rcc_set_pll_sai1_pllsai1clk_enable(void);
void hw_rcc_set_pll_sai1_pllsai1clk_disable(void);
uint32_t hw_rcc_get_pll_sai1_pllsai1clk_enable(void);
void hw_rcc_set_pll_sai1_division_factor_for_pllsai1clk(uint32_t factor);
uint32_t hw_rcc_get_pll_sai1_division_factor_for_pllsai1clk(void);
void hw_rcc_set_pll_sai1_pll48m2clk_output_enable(void);
void hw_rcc_set_pll_sai1_pll48m2clk_output_disable(void);
uint32_t hw_rcc_get_pll_sai1_pll48m2clk_output_enable(void);
void hw_rcc_set_pll_sai1_division_factor_for_pll48m2clk(uint32_t factor);
uint32_t hw_rcc_get_pll_sai1_division_factor_for_pll48m2clk(void);
void hw_rcc_set_pll_sai1_plladc1clk_output_enable(void);
void hw_rcc_set_pll_sai1_plladc1clk_output_disable(void);
uint32_t hw_rcc_get_pll_sai1_plladc1clk_output_enable(void);
void hw_rcc_set_pll_sai1_division_factor_for_plladc1clk(uint32_t factor);
uint32_t hw_rcc_get_pll_sai1_division_factor_for_plladc1clk(void);
void hw_rcc_set_pll_sai2_multiplication_factor_for_vco(uint32_t factor);
uint32_t hw_rcc_get_pll_sai2_multiplication_factor_for_vco(void);
void hw_rcc_set_pll_sai2_pllsai2clk_enable(void);
void hw_rcc_set_pll_sai2_pllsai2clk_disable(void);
uint32_t hw_rcc_get_pll_sai2_pllsai2clk_enable(void);
void hw_rcc_set_pll_sai2_division_factor_for_pllsai2clk(uint32_t factor);
uint32_t hw_rcc_get_pll_sai2_division_factor_for_pllsai2clk(void);
void hw_rcc_set_pll_sai2_plladc2clk_output_enable(void);
void hw_rcc_set_pll_sai2_plladc2clk_output_disable(void);
uint32_t hw_rcc_get_pll_sai2_plladc2clk_output_enable(void);
void hw_rcc_set_pll_sai2_division_factor_for_plladc2clk(uint32_t factor);
uint32_t hw_rcc_get_pll_sai2_division_factor_for_plladc2clk(void);
void hw_rcc_set_lsi_ready_interrupt_enable(void);
void hw_rcc_set_lsi_ready_interrupt_disable(void);
uint32_t hw_rcc_get_lsi_ready_interrupt_enable(void);
void hw_rcc_set_lse_ready_interrupt_enable(void);
void hw_rcc_set_lse_ready_interrupt_disable(void);
uint32_t hw_rcc_get_lse_ready_interrupt_enable(void);
void hw_rcc_set_msi_ready_interrupt_enable(void);
void hw_rcc_set_msi_ready_interrupt_disable(void);
uint32_t hw_rcc_get_msi_ready_interrupt_enable(void);
void hw_rcc_set_hsi_ready_interrupt_enable(void);
void hw_rcc_set_hsi_ready_interrupt_disable(void);
uint32_t hw_rcc_get_hsi_ready_interrupt_enable(void);
void hw_rcc_set_hse_ready_interrupt_enable(void);
void hw_rcc_set_hse_ready_interrupt_disable(void);
uint32_t hw_rcc_get_hse_ready_interrupt_enable(void);
void hw_rcc_set_pll_ready_interrupt_enable(void);
void hw_rcc_set_pll_ready_interrupt_disable(void);
uint32_t hw_rcc_get_pll_ready_interrupt_enable(void);
void hw_rcc_set_pllsai1_ready_interrupt_enable(void);
void hw_rcc_set_pllsai1_ready_interrupt_disable(void);
uint32_t hw_rcc_get_pllsai1_ready_interrupt_enable(void);
void hw_rcc_set_pllsai2_ready_interrupt_enable(void);
void hw_rcc_set_pllsai2_ready_interrupt_disable(void);
uint32_t hw_rcc_get_pllsai2_ready_interrupt_enable(void);
void hw_rcc_set_lse_css_ready_interrupt_enable(void);
void hw_rcc_set_lse_css_ready_interrupt_disable(void);
uint32_t hw_rcc_lsi_ready_interrupt_flag(void);
uint32_t hw_rcc_lse_ready_interrupt_flag(void);
uint32_t hw_rcc_msi_ready_interrupt_flag(void);
uint32_t hw_rcc_hsi_ready_interrupt_flag(void);
uint32_t hw_rcc_hse_ready_interrupt_flag(void);
uint32_t hw_rcc_pll_ready_interrupt_flag(void);
uint32_t hw_rcc_pll_sai1_ready_interrupt_flag(void);
uint32_t hw_rcc_pll_sai2_ready_interrupt_flag(void);
uint32_t hw_rcc_css_interrupt_flag(void);
uint32_t hw_rcc_lse_css_interrupt_flag(void);
void hw_rcc_clear_lsi_ready_interrupt_flag(void);
void hw_rcc_clear_lse_ready_interrupt_flag(void);
void hw_rcc_clear_msi_ready_interrupt_flag(void);
void hw_rcc_clear_hsi_ready_interrupt_flag(void);
void hw_rcc_clear_hse_ready_interrupt_flag(void);
void hw_rcc_clear_pll_ready_interrupt_flag(void);
void hw_rcc_clear_pll_sai1_ready_interrupt_flag(void);
void hw_rcc_clear_pll_sai2_ready_interrupt_flag(void);
void hw_rcc_clear_css_interrupt_flag(void);
void hw_rcc_clear_lse_css_interrupt_flag(void);
void hw_rcc_set_dma1_reset(void);
void hw_rcc_wait_dma1_reset(void);
void hw_rcc_set_dma2_reset(void);
void hw_rcc_wait_dma2_reset(void);
void hw_rcc_set_flash_reset(void);
void hw_rcc_wait_flash_reset(void);
void hw_rcc_set_crc_reset(void);
void hw_rcc_wait_crc_reset(void);
void hw_rcc_set_tsc_reset(void);
void hw_rcc_wait_tsc_reset(void);
void hw_rcc_set_gpioa_reset(void);
void hw_rcc_wait_gpioa_reset(void);
void hw_rcc_set_gpiob_reset(void);
void hw_rcc_wait_gpiob_reset(void);
void hw_rcc_set_gpioc_reset(void);
void hw_rcc_wait_gpioc_reset(void);
void hw_rcc_set_gpiod_reset(void);
void hw_rcc_wait_gpiod_reset(void);
void hw_rcc_set_gpioe_reset(void);
void hw_rcc_wait_gpioe_reset(void);
void hw_rcc_set_gpiof_reset(void);
void hw_rcc_wait_gpiof_reset(void);
void hw_rcc_set_gpiog_reset(void);
void hw_rcc_wait_gpiog_reset(void);
void hw_rcc_set_gpioh_reset(void);
void hw_rcc_wait_gpioh_reset(void);
void hw_rcc_set_adc_reset(void);
void hw_rcc_wait_adc_reset(void);
void hw_rcc_set_rng_reset(void);
void hw_rcc_wait_rng_reset(void);
void hw_rcc_set_fmc_reset(void);
void hw_rcc_wait_fmc_reset(void);
void hw_rcc_set_qspi_reset(void);
void hw_rcc_wait_qspi_reset(void);
void hw_rcc_set_tim2_reset(void);
void hw_rcc_wait_tim2_reset(void);
void hw_rcc_set_tim3_reset(void);
void hw_rcc_wait_tim3_reset(void);
void hw_rcc_set_tim4_reset(void);
void hw_rcc_wait_tim4_reset(void);
void hw_rcc_set_tim5_reset(void);
void hw_rcc_wait_tim5_reset(void);
void hw_rcc_set_tim6_reset(void);
void hw_rcc_wait_tim6_reset(void);
void hw_rcc_set_tim7_reset(void);
void hw_rcc_wait_tim7_reset(void);
void hw_rcc_set_spi2_reset(void);
void hw_rcc_wait_spi2_reset(void);
void hw_rcc_set_spi3_reset(void);
void hw_rcc_wait_spi3_reset(void);
void hw_rcc_set_usart2_reset(void);
void hw_rcc_wait_usart2_reset(void);
void hw_rcc_set_usart3_reset(void);
void hw_rcc_wait_usart3_reset(void);
void hw_rcc_set_uart4_reset(void);
void hw_rcc_wait_uart4_reset(void);
void hw_rcc_set_uart5_reset(void);
void hw_rcc_wait_uart5_reset(void);
void hw_rcc_set_i2c1_reset(void);
void hw_rcc_wait_i2c1_reset(void);
void hw_rcc_set_i2c2_reset(void);
void hw_rcc_wait_i2c2_reset(void);
void hw_rcc_set_i2c3_reset(void);
void hw_rcc_wait_i2c3_reset(void);
void hw_rcc_set_can1_reset(void);
void hw_rcc_wait_can1_reset(void);
void hw_rcc_set_power_reset(void);
void hw_rcc_wait_power_reset(void);
void hw_rcc_set_dac1_reset(void);
void hw_rcc_wait_dac1_reset(void);
void hw_rcc_set_opamp_reset(void);
void hw_rcc_wait_opamp_reset(void);
void hw_rcc_set_lptim1_reset(void);
void hw_rcc_wait_lptim1_reset(void);
void hw_rcc_set_lpuart1_reset(void);
void hw_rcc_wait_lpuart1_reset(void);
void hw_rcc_set_swpmi1_reset(void);
void hw_rcc_wait_swpmi1_reset(void);
void hw_rcc_set_lptim2_reset(void);
void hw_rcc_wait_lptim2_reset(void);
void hw_rcc_set_syscfg_reset(void);
void hw_rcc_wait_syscfg_reset(void);
void hw_rcc_set_sdmmc1_reset(void);
void hw_rcc_wait_sdmmc1_reset(void);
void hw_rcc_set_tim1_reset(void);
void hw_rcc_wait_tim1_reset(void);
void hw_rcc_set_spi1_reset(void);
void hw_rcc_wait_spi1_reset(void);
void hw_rcc_set_tim8_reset(void);
void hw_rcc_wait_tim8_reset(void);
void hw_rcc_set_usart1_reset(void);
void hw_rcc_wait_usart1_reset(void);
void hw_rcc_set_tim15_reset(void);
void hw_rcc_wait_tim15_reset(void);
void hw_rcc_set_tim16_reset(void);
void hw_rcc_wait_tim16_reset(void);
void hw_rcc_set_tim17_reset(void);
void hw_rcc_wait_tim17_reset(void);
void hw_rcc_set_sai1_reset(void);
void hw_rcc_wait_sai1_reset(void);
void hw_rcc_set_sai2_reset(void);
void hw_rcc_wait_sai2_reset(void);
void hw_rcc_set_dfsdm1_reset(void);
void hw_rcc_wait_dfsdm1_reset(void);
void hw_rcc_set_dma1_clock_enable(void);
void hw_rcc_set_dma1_clock_disable(void);
uint32_t hw_rcc_get_dma1_clock_enable(void);
void hw_rcc_set_dma2_clock_enable(void);
void hw_rcc_set_dma2_clock_disable(void);
uint32_t hw_rcc_get_dma2_clock_enable(void);
void hw_rcc_set_flash_clock_enable(void);
void hw_rcc_set_flash_clock_disable(void);
uint32_t hw_rcc_get_flash_clock_enable(void);
void hw_rcc_set_crc_clock_enable(void);
void hw_rcc_set_crc_clock_disable(void);
uint32_t hw_rcc_get_crc_clock_enable(void);
void hw_rcc_set_tsc_clock_enable(void);
void hw_rcc_set_tsc_clock_disable(void);
uint32_t hw_rcc_get_tsc_clock_enable(void);
void hw_rcc_set_gpioa_clock_enable(void);
void hw_rcc_set_gpioa_clock_disable(void);
uint32_t hw_rcc_get_gpioa_clock_enable(void);
void hw_rcc_set_gpiob_clock_enable(void);
void hw_rcc_set_gpiob_clock_disable(void);
uint32_t hw_rcc_get_gpiob_clock_enable(void);
void hw_rcc_set_gpioc_clock_enable(void);
void hw_rcc_set_gpioc_clock_disable(void);
uint32_t hw_rcc_get_gpioc_clock_enable(void);
void hw_rcc_set_gpiod_clock_enable(void);
void hw_rcc_set_gpiod_clock_disable(void);
uint32_t hw_rcc_get_gpiod_clock_enable(void);
void hw_rcc_set_gpioe_clock_enable(void);
void hw_rcc_set_gpioe_clock_disable(void);
uint32_t hw_rcc_get_gpioe_clock_enable(void);
void hw_rcc_set_gpiof_clock_enable(void);
void hw_rcc_set_gpiof_clock_disable(void);
uint32_t hw_rcc_get_gpiof_clock_enable(void);
void hw_rcc_set_gpiog_clock_enable(void);
void hw_rcc_set_gpiog_clock_disable(void);
uint32_t hw_rcc_get_gpiog_clock_enable(void);
void hw_rcc_set_gpioh_clock_enable(void);
void hw_rcc_set_gpioh_clock_disable(void);
uint32_t hw_rcc_get_gpioh_clock_enable(void);
void hw_rcc_set_adc_clock_enable(void);
void hw_rcc_set_adc_clock_disable(void);
uint32_t hw_rcc_get_adc_clock_enable(void);
void hw_rcc_set_rng_clock_enable(void);
void hw_rcc_set_rng_clock_disable(void);
uint32_t hw_rcc_get_rng_clock_enable(void);
void hw_rcc_set_fmc_clock_enable(void);
void hw_rcc_set_fmc_clock_disable(void);
uint32_t hw_rcc_get_fmc_clock_enable(void);
void hw_rcc_set_qspi_clock_enable(void);
void hw_rcc_set_qspi_clock_disable(void);
uint32_t hw_rcc_get_qspi_clock_enable(void);
void hw_rcc_set_tim2_clock_enable(void);
void hw_rcc_set_tim2_clock_disable(void);
uint32_t hw_rcc_get_tim2_clock_enable(void);
void hw_rcc_set_tim3_clock_enable(void);
void hw_rcc_set_tim3_clock_disable(void);
uint32_t hw_rcc_get_tim3_clock_enable(void);
void hw_rcc_set_tim4_clock_enable(void);
void hw_rcc_set_tim4_clock_disable(void);
uint32_t hw_rcc_get_tim4_clock_enable(void);
void hw_rcc_set_tim5_clock_enable(void);
void hw_rcc_set_tim5_clock_disable(void);
uint32_t hw_rcc_get_tim5_clock_enable(void);
void hw_rcc_set_tim6_clock_enable(void);
void hw_rcc_set_tim6_clock_disable(void);
uint32_t hw_rcc_get_tim6_clock_enable(void);
void hw_rcc_set_tim7_clock_enable(void);
void hw_rcc_set_tim7_clock_disable(void);
uint32_t hw_rcc_get_tim7_clock_enable(void);
void hw_rcc_set_wwdg_clock_enable(void);
void hw_rcc_set_wwdg_clock_disable(void);
uint32_t hw_rcc_get_wwdg_clock_enable(void);
void hw_rcc_set_spi2_clock_enable(void);
void hw_rcc_set_spi2_clock_disable(void);
uint32_t hw_rcc_get_spi2_clock_enable(void);
void hw_rcc_set_spi3_clock_enable(void);
void hw_rcc_set_spi3_clock_disable(void);
uint32_t hw_rcc_get_spi3_clock_enable(void);
void hw_rcc_set_usart2_clock_enable(void);
void hw_rcc_set_usart2_clock_disable(void);
uint32_t hw_rcc_get_usart2_clock_enable(void);
void hw_rcc_set_usart3_clock_enable(void);
void hw_rcc_set_usart3_clock_disable(void);
uint32_t hw_rcc_get_usart3_clock_enable(void);
void hw_rcc_set_uart4_clock_enable(void);
void hw_rcc_set_uart4_clock_disable(void);
uint32_t hw_rcc_get_uart4_clock_enable(void);
void hw_rcc_set_uart5_clock_enable(void);
void hw_rcc_set_uart5_clock_disable(void);
uint32_t hw_rcc_get_uart5_clock_enable(void);
void hw_rcc_set_i2c1_clock_enable(void);
void hw_rcc_set_i2c1_clock_disable(void);
uint32_t hw_rcc_get_i2c1_clock_enable(void);
void hw_rcc_set_i2c2_clock_enable(void);
void hw_rcc_set_i2c2_clock_disable(void);
uint32_t hw_rcc_get_i2c2_clock_enable(void);
void hw_rcc_set_i2c3_clock_enable(void);
void hw_rcc_set_i2c3_clock_disable(void);
uint32_t hw_rcc_get_i2c3_clock_enable(void);
void hw_rcc_set_can1_clock_enable(void);
void hw_rcc_set_can1_clock_disable(void);
uint32_t hw_rcc_get_can1_clock_enable(void);
void hw_rcc_set_power_clock_enable(void);
void hw_rcc_set_power_clock_disable(void);
uint32_t hw_rcc_get_power_clock_enable(void);
void hw_rcc_set_dac1_clock_enable(void);
void hw_rcc_set_dac1_clock_disable(void);
uint32_t hw_rcc_get_dac1_clock_enable(void);
void hw_rcc_set_opamp_clock_enable(void);
void hw_rcc_set_opamp_clock_disable(void);
uint32_t hw_rcc_get_opamp_clock_enable(void);
void hw_rcc_set_lptim1_clock_enable(void);
void hw_rcc_set_lptim1_clock_disable(void);
uint32_t hw_rcc_get_lptim1_clock_enable(void);
void hw_rcc_set_lpuart1_clock_enable(void);
void hw_rcc_set_lpuart1_clock_disable(void);
uint32_t hw_rcc_get_lpuart1_clock_enable(void);
void hw_rcc_set_swpmi1_clock_enable(void);
void hw_rcc_set_swpmi1_clock_disable(void);
uint32_t hw_rcc_get_swpmi1_clock_enable(void);
void hw_rcc_set_lptim2_clock_enable(void);
void hw_rcc_set_lptim2_clock_disable(void);
uint32_t hw_rcc_get_lptim2_clock_enable(void);
void hw_rcc_set_syscfg_clock_enable(void);
void hw_rcc_set_syscfg_clock_disable(void);
uint32_t hw_rcc_get_syscfg_clock_enable(void);
void hw_rcc_set_firewall_clock_enable(void);
void hw_rcc_set_firewall_clock_disable(void);
uint32_t hw_rcc_get_firewall_clock_enable(void);
void hw_rcc_set_sdmmc1_clock_enable(void);
void hw_rcc_set_sdmmc1_clock_disable(void);
uint32_t hw_rcc_get_sdmmc1_clock_enable(void);
void hw_rcc_set_tim1_clock_enable(void);
void hw_rcc_set_tim1_clock_disable(void);
uint32_t hw_rcc_get_tim1_clock_enable(void);
void hw_rcc_set_spi1_clock_enable(void);
void hw_rcc_set_spi1_clock_disable(void);
uint32_t hw_rcc_get_spi1_clock_enable(void);
void hw_rcc_set_tim8_clock_enable(void);
void hw_rcc_set_tim8_clock_disable(void);
uint32_t hw_rcc_get_tim8_clock_enable(void);
void hw_rcc_set_usart1_clock_enable(void);
void hw_rcc_set_usart1_clock_disable(void);
uint32_t hw_rcc_get_usart1_clock_enable(void);
void hw_rcc_set_tim15_clock_enable(void);
void hw_rcc_set_tim15_clock_disable(void);
uint32_t hw_rcc_get_tim15_clock_enable(void);
void hw_rcc_set_tim16_clock_enable(void);
void hw_rcc_set_tim16_clock_disable(void);
uint32_t hw_rcc_get_tim16_clock_enable(void);
void hw_rcc_set_tim17_clock_enable(void);
void hw_rcc_set_tim17_clock_disable(void);
uint32_t hw_rcc_get_tim17_clock_enable(void);
void hw_rcc_set_sai1_clock_enable(void);
void hw_rcc_set_sai1_clock_disable(void);
uint32_t hw_rcc_get_sai1_clock_enable(void);
void hw_rcc_set_sai2_clock_enable(void);
void hw_rcc_set_sai2_clock_disable(void);
uint32_t hw_rcc_get_sai2_clock_enable(void);
void hw_rcc_set_dfsam1_clock_enable(void);
void hw_rcc_set_dfsam1_clock_disable(void);
uint32_t hw_rcc_get_dfsam1_clock_enable(void);
void hw_rcc_set_dma1sm_clock_enable(void);
void hw_rcc_set_dma1sm_clock_disable(void);
uint32_t hw_rcc_get_dma1sm_clock_enable(void);
void hw_rcc_set_dma2sm_clock_enable(void);
void hw_rcc_set_dma2sm_clock_disable(void);
uint32_t hw_rcc_get_dma2sm_clock_enable(void);
void hw_rcc_set_flashsm_clock_enable(void);
void hw_rcc_set_flashsm_clock_disable(void);
uint32_t hw_rcc_get_flashsm_clock_enable(void);
void hw_rcc_set_sram1sm_clock_enable(void);
void hw_rcc_set_sram1sm_clock_disable(void);
uint32_t hw_rcc_get_sram1sm_clock_enable(void);
void hw_rcc_set_crcsm_clock_enable(void);
void hw_rcc_set_crcsm_clock_disable(void);
uint32_t hw_rcc_get_crcsm_clock_enable(void);
void hw_rcc_set_tscsm_clock_enable(void);
void hw_rcc_set_tscsm_clock_disable(void);
uint32_t hw_rcc_get_tscsm_clock_enable(void);
void hw_rcc_set_gpioasm_clock_enable(void);
void hw_rcc_set_gpioasm_clock_disable(void);
uint32_t hw_rcc_get_gpioasm_clock_enable(void);
void hw_rcc_set_gpiobsm_clock_enable(void);
void hw_rcc_set_gpiobsm_clock_disable(void);
uint32_t hw_rcc_get_gpiobsm_clock_enable(void);
void hw_rcc_set_gpiocsm_clock_enable(void);
void hw_rcc_set_gpiocsm_clock_disable(void);
uint32_t hw_rcc_get_gpiocsm_clock_enable(void);
void hw_rcc_set_gpiodsm_clock_enable(void);
void hw_rcc_set_gpiodsm_clock_disable(void);
uint32_t hw_rcc_get_gpiodsm_clock_enable(void);
void hw_rcc_set_gpioesm_clock_enable(void);
void hw_rcc_set_gpioesm_clock_disable(void);
uint32_t hw_rcc_get_gpioesm_clock_enable(void);
void hw_rcc_set_gpiofsm_clock_enable(void);
void hw_rcc_set_gpiofsm_clock_disable(void);
uint32_t hw_rcc_get_gpiofsm_clock_enable(void);
void hw_rcc_set_gpiogsm_clock_enable(void);
void hw_rcc_set_gpiogsm_clock_disable(void);
uint32_t hw_rcc_get_gpiogsm_clock_enable(void);
void hw_rcc_set_gpiohsm_clock_enable(void);
void hw_rcc_set_gpiohsm_clock_disable(void);
uint32_t hw_rcc_get_gpiohsm_clock_enable(void);
void hw_rcc_set_sram2sm_clock_enable(void);
void hw_rcc_set_sram2sm_clock_disable(void);
uint32_t hw_rcc_get_sram2sm_clock_enable(void);
void hw_rcc_set_otgfssm_clock_enable(void);
void hw_rcc_set_otgfssm_clock_disable(void);
uint32_t hw_rcc_get_otgfssm_clock_enable(void);
void hw_rcc_set_adcsm_clock_enable(void);
void hw_rcc_set_adcsm_clock_disable(void);
uint32_t hw_rcc_get_adcsm_clock_enable(void);
void hw_rcc_set_rngsm_clock_enable(void);
void hw_rcc_set_rngsm_clock_disable(void);
uint32_t hw_rcc_get_rngsm_clock_enable(void);
void hw_rcc_set_fmcsm_clock_enable(void);
void hw_rcc_set_fmcsm_clock_disable(void);
uint32_t hw_rcc_get_fmcsm_clock_enable(void);
void hw_rcc_set_qspism_clock_enable(void);
void hw_rcc_set_qspism_clock_disable(void);
uint32_t hw_rcc_get_qspism_clock_enable(void);
void hw_rcc_set_tim2sm_clock_enable(void);
void hw_rcc_set_tim2sm_clock_disable(void);
uint32_t hw_rcc_get_tim2sm_clock_enable(void);
void hw_rcc_set_tim3sm_clock_enable(void);
void hw_rcc_set_tim3sm_clock_disable(void);
uint32_t hw_rcc_get_tim3sm_clock_enable(void);
void hw_rcc_set_tim4sm_clock_enable(void);
void hw_rcc_set_tim4sm_clock_disable(void);
uint32_t hw_rcc_get_tim4sm_clock_enable(void);
void hw_rcc_set_tim5sm_clock_enable(void);
void hw_rcc_set_tim5sm_clock_disable(void);
uint32_t hw_rcc_get_tim5sm_clock_enable(void);
void hw_rcc_set_tim6sm_clock_enable(void);
void hw_rcc_set_tim6sm_clock_disable(void);
uint32_t hw_rcc_get_tim6sm_clock_enable(void);
void hw_rcc_set_tim7sm_clock_enable(void);
void hw_rcc_set_tim7sm_clock_disable(void);
uint32_t hw_rcc_get_tim7sm_clock_enable(void);
void hw_rcc_set_wwdgsm_clock_enable(void);
void hw_rcc_set_wwdgsm_clock_disable(void);
uint32_t hw_rcc_get_wwdgsm_clock_enable(void);
void hw_rcc_set_spi2sm_clock_enable(void);
void hw_rcc_set_spi2sm_clock_disable(void);
uint32_t hw_rcc_get_spi2sm_clock_enable(void);
void hw_rcc_set_spi3sm_clock_enable(void);
void hw_rcc_set_spi3sm_clock_disable(void);
uint32_t hw_rcc_get_spi3sm_clock_enable(void);
void hw_rcc_set_usart2sm_clock_enable(void);
void hw_rcc_set_usart2sm_clock_disable(void);
uint32_t hw_rcc_get_usart2sm_clock_enable(void);
void hw_rcc_set_usart3sm_clock_enable(void);
void hw_rcc_set_usart3sm_clock_disable(void);
uint32_t hw_rcc_get_usart3sm_clock_enable(void);
void hw_rcc_set_uart4sm_clock_enable(void);
void hw_rcc_set_uart4sm_clock_disable(void);
uint32_t hw_rcc_get_uart4sm_clock_enable(void);
void hw_rcc_set_uart5sm_clock_enable(void);
void hw_rcc_set_uart5sm_clock_disable(void);
uint32_t hw_rcc_get_uart5sm_clock_enable(void);
void hw_rcc_set_i2c1sm_clock_enable(void);
void hw_rcc_set_i2c1sm_clock_disable(void);
uint32_t hw_rcc_get_i2c1sm_clock_enable(void);
void hw_rcc_set_i2c2sm_clock_enable(void);
void hw_rcc_set_i2c2sm_clock_disable(void);
uint32_t hw_rcc_get_i2c2sm_clock_enable(void);
void hw_rcc_set_i2c3sm_clock_enable(void);
void hw_rcc_set_i2c3sm_clock_disable(void);
uint32_t hw_rcc_get_i2c3sm_clock_enable(void);
void hw_rcc_set_can1sm_clock_enable(void);
void hw_rcc_set_can1sm_clock_disable(void);
uint32_t hw_rcc_get_can1sm_clock_enable(void);
void hw_rcc_set_powersm_clock_enable(void);
void hw_rcc_set_powersm_clock_disable(void);
uint32_t hw_rcc_get_powersm_clock_enable(void);
void hw_rcc_set_dac1sm_clock_enable(void);
void hw_rcc_set_dac1sm_clock_disable(void);
uint32_t hw_rcc_get_dac1sm_clock_enable(void);
void hw_rcc_set_opampsm_clock_enable(void);
void hw_rcc_set_opampsm_clock_disable(void);
uint32_t hw_rcc_get_opampsm_clock_enable(void);
void hw_rcc_set_lptim1sm_clock_enable(void);
void hw_rcc_set_lptim1sm_clock_disable(void);
uint32_t hw_rcc_get_lptim1sm_clock_enable(void);
void hw_rcc_set_lpusart1sm_clock_enable(void);
void hw_rcc_set_lpusart1sm_clock_disable(void);
uint32_t hw_rcc_get_lpusart1sm_clock_enable(void);
void hw_rcc_set_swpmi1sm_clock_enable(void);
void hw_rcc_set_swpmi1sm_clock_disable(void);
uint32_t hw_rcc_get_swpmi1sm_clock_enable(void);
void hw_rcc_set_lptim2sm_clock_enable(void);
void hw_rcc_set_lptim2sm_clock_disable(void);
uint32_t hw_rcc_get_lptim2sm_clock_enable(void);
void hw_rcc_set_syscfgsm_clock_enable(void);
void hw_rcc_set_syscfgsm_clock_disable(void);
uint32_t hw_rcc_get_syscfgsm_clock_enable(void);
void hw_rcc_set_ssmmc1sm_clock_enable(void);
void hw_rcc_set_ssmmc1sm_clock_disable(void);
uint32_t hw_rcc_get_ssmmc1sm_clock_enable(void);
void hw_rcc_set_tim1sm_clock_enable(void);
void hw_rcc_set_tim1sm_clock_disable(void);
uint32_t hw_rcc_get_tim1sm_clock_enable(void);
void hw_rcc_set_spi1sm_clock_enable(void);
void hw_rcc_set_spi1sm_clock_disable(void);
uint32_t hw_rcc_get_spi1sm_clock_enable(void);
void hw_rcc_set_tim8sm_clock_enable(void);
void hw_rcc_set_tim8sm_clock_disable(void);
uint32_t hw_rcc_get_tim8sm_clock_enable(void);
void hw_rcc_set_usart1sm_clock_enable(void);
void hw_rcc_set_usart1sm_clock_disable(void);
uint32_t hw_rcc_get_usart1sm_clock_enable(void);
void hw_rcc_set_tim15sm_clock_enable(void);
void hw_rcc_set_tim15sm_clock_disable(void);
uint32_t hw_rcc_get_tim15sm_clock_enable(void);
void hw_rcc_set_tim16sm_clock_enable(void);
void hw_rcc_set_tim16sm_clock_disable(void);
uint32_t hw_rcc_get_tim16sm_clock_enable(void);
void hw_rcc_set_tim17sm_clock_enable(void);
void hw_rcc_set_tim17sm_clock_disable(void);
uint32_t hw_rcc_get_tim17sm_clock_enable(void);
void hw_rcc_set_sai1sm_clock_enable(void);
void hw_rcc_set_sai1sm_clock_disable(void);
uint32_t hw_rcc_get_sai1sm_clock_enable(void);
void hw_rcc_set_sai2sm_clock_enable(void);
void hw_rcc_set_sai2sm_clock_disable(void);
uint32_t hw_rcc_get_sai2sm_clock_enable(void);
void hw_rcc_set_dfsdm1sm_clock_enable(void);
void hw_rcc_set_dfsdm1sm_clock_disable(void);
uint32_t hw_rcc_get_dfsdm1sm_clock_enable(void);
void hw_rcc_select_usart1_clock_source(uint32_t source);
uint32_t hw_rcc_get_usart1_clock_source(void);
void hw_rcc_select_usart2_clock_source(uint32_t source);
uint32_t hw_rcc_get_usart2_clock_source(void);
void hw_rcc_select_usart3_clock_source(uint32_t source);
uint32_t hw_rcc_get_usart3_clock_source(void);
void hw_rcc_select_uart4_clock_source(uint32_t source);
uint32_t hw_rcc_get_uart4_clock_source(void);
void hw_rcc_select_uart5_clock_source(uint32_t source);
uint32_t hw_rcc_get_uart5_clock_source(void);
void hw_rcc_select_lpuart1_clock_source(uint32_t source);
uint32_t hw_rcc_get_lpuart1_clock_source(void);
void hw_rcc_select_i2c1_clock_source(uint32_t source);
uint32_t hw_rcc_get_i2c1_clock_source(void);
void hw_rcc_select_i2c2_clock_source(uint32_t source);
uint32_t hw_rcc_get_i2c2_clock_source(void);
void hw_rcc_select_i2c3_clock_source(uint32_t source);
uint32_t hw_rcc_get_i2c3_clock_source(void);
void hw_rcc_select_lptim1_clock_source(uint32_t source);
uint32_t hw_rcc_get_lptim1_clock_source(void);
void hw_rcc_select_lptim2_clock_source(uint32_t source);
uint32_t hw_rcc_get_lptim2_clock_source(void);
void hw_rcc_select_sai1_clock_source(uint32_t source);
uint32_t hw_rcc_get_sai1_clock_source(void);
void hw_rcc_select_sai2_clock_source(uint32_t source);
uint32_t hw_rcc_get_sai2_clock_source(void);
void hw_rcc_select_clk48_clock_source(uint32_t source);
uint32_t hw_rcc_get_clk48_clock_source(void);
void hw_rcc_select_adc_clock_source(uint32_t source);
uint32_t hw_rcc_get_adc_clock_source(void);
void hw_rcc_select_swpmi1_clock_source(uint32_t source);
uint32_t hw_rcc_get_swpmi1_clock_source(void);
void hw_rcc_select_dfsdm1_clock_source(uint32_t source);
uint32_t hw_rcc_get_dfsdm1_clock_source(void);
void hw_rcc_set_lse_clock_enable(void);
void hw_rcc_set_lse_clock_disable(void);
uint32_t hw_rcc_get_lse_clock_enable(void);
uint32_t hw_rcc_lse_clock_ready_status(void);
void hw_rcc_lse_clock_wait_ready(void);
void hw_rcc_set_lse_clock_bypass(void);
void hw_rcc_set_lse_clock_no_bypass(void);
uint32_t hw_rcc_get_lse_clock_bypass_status(void);
void hw_rcc_set_lse_clock_drive_capability(uint32_t drive);
uint32_t hw_rcc_get_lse_clock_drive_capability(void);
void hw_rcc_set_css_on_lse_clock_enable(void);
void hw_rcc_set_css_on_lse_clock_disable(void);
uint32_t hw_rcc_get_css_on_lse_clock_enable(void);
uint32_t hw_rcc_detect_css_on_lse_clock_failure_status(void);
void hw_rcc_select_rtc_clock_source(uint32_t source);
uint32_t hw_rcc_get_rtc_clock_source(void);
void hw_rcc_set_rtc_clock_enable(void);
void hw_rcc_set_rtc_clock_disable(void);
uint32_t hw_rcc_get_rtc_clock_enable(void);
void hw_rcc_set_backup_domain_reset(void);
void hw_rcc_wait_backup_domain_reset(void);
void hw_rcc_set_low_speed_clock_output_enable(void);
void hw_rcc_set_low_speed_clock_output_disable(void);
uint32_t hw_rcc_get_low_speed_clock_output_enable(void);
void hw_rcc_select_low_speed_clock_output_source(uint32_t source);
uint32_t hw_rcc_get_low_speed_clock_output_source(void);
void hw_rcc_set_lsi_clock_enable(void);
void hw_rcc_set_lsi_clock_disable(void);
uint32_t hw_rcc_get_lsi_clock_enable(void);
uint32_t hw_rcc_lsi_clock_ready_status(void);
void hw_rcc_lsi_clock_wait_ready(void);
void hw_rcc_select_msi_range_after_standby_mode(uint32_t mode);
uint32_t hw_rcc_get_msi_range_after_standby_mode(uint32_t source);
void hw_rcc_clear_reset_flag(void);
uint32_t hw_rcc_firewall_reset_flag(void);
uint32_t hw_rcc_option_byte_loader_reset_flag(void);
uint32_t hw_rcc_pin_reset_flag(void);
uint32_t hw_rcc_bor_reset_flag(void);
uint32_t hw_rcc_software_reset_flag(void);
uint32_t hw_rcc_iwatchdog_reset_flag(void);
uint32_t hw_rcc_wwatchdog_reset_flag(void);
uint32_t hw_rcc_low_power_reset_flag(void);

#ifdef __cplusplus
}
#endif

#endif