#include "common.h"
#include "hw_rcc.h"

struct FLASH_TypeDef
{
    __IO uint32_t ACR;              /*!< FLASH access control register,            Address offset: 0x00 */
};

#define FLASH                 ((struct FLASH_TypeDef *) FLASH_R_BASE)
static inline struct FLASH_TypeDef* __GET_FLASH_REGISTER__(void)
{
    return FLASH;
}

#define __GET_FLASH_ACR__               (__GET_FLASH_REGISTER__()->ACR)

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos             (0U)
#define FLASH_ACR_LATENCY_Msk             (0x3UL << FLASH_ACR_LATENCY_Pos)     /*!< 0x00000007 */
#define FLASH_ACR_LATENCY                 FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0WS             (0x00000000UL)
#define FLASH_ACR_LATENCY_1WS             (0x00000001UL)
#define FLASH_ACR_LATENCY_2WS             (0x00000002UL)

void hw_rcc_set_flash_wait_time(uint32_t latency)
{
    __BIT_COVER_SET__(__GET_FLASH_ACR__, FLASH_ACR_LATENCY, latency);
}

struct RCC_TypeDef
{
    __IO uint32_t CR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t APB2RSTR;
    __IO uint32_t APB1RSTR;
    __IO uint32_t AHBENR;
    __IO uint32_t APB2ENR;
    __IO uint32_t APB1ENR;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
    __IO uint32_t AHBRSTR;
    __IO uint32_t CFGR2;
};

#define RCC                 ((struct RCC_TypeDef *) RCC_BASE)
static inline struct RCC_TypeDef* __GET_RCC_REGISTER__(void)
{
    return RCC;
}

#define __GET_RCC_CR__          (__GET_RCC_REGISTER__()->CR)
#define __GET_RCC_CFGR__        (__GET_RCC_REGISTER__()->CFGR)
#define __GET_RCC_CIR__         (__GET_RCC_REGISTER__()->CIR)
#define __GET_RCC_APB2RSTR__    (__GET_RCC_REGISTER__()->APB2RSTR)
#define __GET_RCC_APB1RSTR__    (__GET_RCC_REGISTER__()->APB1RSTR)
#define __GET_RCC_AHBENR__      (__GET_RCC_REGISTER__()->AHBENR)
#define __GET_RCC_APB2ENR__     (__GET_RCC_REGISTER__()->APB2ENR)
#define __GET_RCC_APB1ENR__     (__GET_RCC_REGISTER__()->APB1ENR)
#define __GET_RCC_BDCR__        (__GET_RCC_REGISTER__()->BDCR)
#define __GET_RCC_CSR__         (__GET_RCC_REGISTER__()->CSR)
#define __GET_RCC_AHBRSTR__     (__GET_RCC_REGISTER__()->AHBRSTR)
#define __GET_RCC_CFGR2__       (__GET_RCC_REGISTER__()->CFGR2)

#define RCC_CR_HSION                        ((uint32_t)0x00000001)        /*!< Internal High Speed clock enable */
#define RCC_CR_HSIRDY                       ((uint32_t)0x00000002)        /*!< Internal High Speed clock ready flag */
#define RCC_CR_HSITRIM                      ((uint32_t)0x000000F8)        /*!< Internal High Speed clock trimming */
#define RCC_CR_HSICAL                       ((uint32_t)0x0000FF00)        /*!< Internal High Speed clock Calibration */
#define RCC_CR_HSEON                        ((uint32_t)0x00010000)        /*!< External High Speed clock enable */
#define RCC_CR_HSERDY                       ((uint32_t)0x00020000)        /*!< External High Speed clock ready flag */
#define RCC_CR_HSEBYP                       ((uint32_t)0x00040000)        /*!< External High Speed clock Bypass */
#define RCC_CR_CSSON                        ((uint32_t)0x00080000)        /*!< Clock Security System enable */
#define RCC_CR_PLLON                        ((uint32_t)0x01000000)        /*!< PLL enable */
#define RCC_CR_PLLRDY                       ((uint32_t)0x02000000)        /*!< PLL clock ready flag */
#define RCC_CR_PLL2ON                       ((uint32_t)0x04000000)        /*!< PLL2 enable */
#define RCC_CR_PLL2RDY                      ((uint32_t)0x08000000)        /*!< PLL2 clock ready flag */
#define RCC_CR_PLL3ON                       ((uint32_t)0x10000000)        /*!< PLL3 enable */
#define RCC_CR_PLL3RDY                      ((uint32_t)0x20000000)        /*!< PLL3 clock ready flag */

#define RCC_CFGR_SW                         ((uint32_t)0x00000003)        /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SWS                        ((uint32_t)0x0000000C)        /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_HPRE                       ((uint32_t)0x000000F0)        /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_PPRE1                      ((uint32_t)0x00000700)        /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE2                      ((uint32_t)0x00003800)        /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_ADCPRE                     ((uint32_t)0x0000C000)        /*!< ADCPRE[1:0] bits (ADC prescaler) */
#define RCC_CFGR_PLLSRC                     ((uint32_t)0x00010000)        /*!< PLL entry clock source */
#define RCC_CFGR_PLLXTPRE                   ((uint32_t)0x00020000)        /*!< HSE divider for PLL entry */
#define RCC_CFGR_PLLMULL                    ((uint32_t)0x003C0000)        /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define RCC_CFGR_OTGFSPRE                   ((uint32_t)0x00400000)        /*!< USB OTG FS prescaler */
#define RCC_CFGR_USBPRE                     ((uint32_t)0x00400000)        /*!< USB Device prescaler */
#define RCC_CFGR_MCO                        ((uint32_t)0x0F000000)        /*!< MCO[3:0] bits (Microcontroller Clock Output) */

#define RCC_CIR_LSIRDYF                     ((uint32_t)0x00000001)        /*!< LSI Ready Interrupt flag */
#define RCC_CIR_LSERDYF                     ((uint32_t)0x00000002)        /*!< LSE Ready Interrupt flag */
#define RCC_CIR_HSIRDYF                     ((uint32_t)0x00000004)        /*!< HSI Ready Interrupt flag */
#define RCC_CIR_HSERDYF                     ((uint32_t)0x00000008)        /*!< HSE Ready Interrupt flag */
#define RCC_CIR_PLLRDYF                     ((uint32_t)0x00000010)        /*!< PLL Ready Interrupt flag */
#define RCC_CIR_CSSF                        ((uint32_t)0x00000080)        /*!< Clock Security System Interrupt flag */
#define RCC_CIR_LSIRDYIE                    ((uint32_t)0x00000100)        /*!< LSI Ready Interrupt Enable */
#define RCC_CIR_LSERDYIE                    ((uint32_t)0x00000200)        /*!< LSE Ready Interrupt Enable */
#define RCC_CIR_HSIRDYIE                    ((uint32_t)0x00000400)        /*!< HSI Ready Interrupt Enable */
#define RCC_CIR_HSERDYIE                    ((uint32_t)0x00000800)        /*!< HSE Ready Interrupt Enable */
#define RCC_CIR_PLLRDYIE                    ((uint32_t)0x00001000)        /*!< PLL Ready Interrupt Enable */
#define RCC_CIR_LSIRDYC                     ((uint32_t)0x00010000)        /*!< LSI Ready Interrupt Clear */
#define RCC_CIR_LSERDYC                     ((uint32_t)0x00020000)        /*!< LSE Ready Interrupt Clear */
#define RCC_CIR_HSIRDYC                     ((uint32_t)0x00040000)        /*!< HSI Ready Interrupt Clear */
#define RCC_CIR_HSERDYC                     ((uint32_t)0x00080000)        /*!< HSE Ready Interrupt Clear */
#define RCC_CIR_PLLRDYC                     ((uint32_t)0x00100000)        /*!< PLL Ready Interrupt Clear */
#define RCC_CIR_CSSC                        ((uint32_t)0x00800000)        /*!< Clock Security System Interrupt Clear */
#define RCC_CIR_PLL2RDYF                    ((uint32_t)0x00000020)        /*!< PLL2 Ready Interrupt flag */
#define RCC_CIR_PLL3RDYF                    ((uint32_t)0x00000040)        /*!< PLL3 Ready Interrupt flag */
#define RCC_CIR_PLL2RDYIE                   ((uint32_t)0x00002000)        /*!< PLL2 Ready Interrupt Enable */
#define RCC_CIR_PLL3RDYIE                   ((uint32_t)0x00004000)        /*!< PLL3 Ready Interrupt Enable */
#define RCC_CIR_PLL2RDYC                    ((uint32_t)0x00200000)        /*!< PLL2 Ready Interrupt Clear */
#define RCC_CIR_PLL3RDYC                    ((uint32_t)0x00400000)        /*!< PLL3 Ready Interrupt Clear */

#define RCC_APB2RSTR_AFIORST                ((uint32_t)0x00000001)        /*!< Alternate Function I/O reset */
#define RCC_APB2RSTR_IOPARST                ((uint32_t)0x00000004)        /*!< I/O port A reset */
#define RCC_APB2RSTR_IOPBRST                ((uint32_t)0x00000008)        /*!< I/O port B reset */
#define RCC_APB2RSTR_IOPCRST                ((uint32_t)0x00000010)        /*!< I/O port C reset */
#define RCC_APB2RSTR_IOPDRST                ((uint32_t)0x00000020)        /*!< I/O port D reset */
#define RCC_APB2RSTR_IOPERST                ((uint32_t)0x00000040)        /*!< I/O port E reset */
#define RCC_APB2RSTR_IOPFRST                ((uint32_t)0x00000080)        /*!< I/O port F reset */
#define RCC_APB2RSTR_IOPGRST                ((uint32_t)0x00000100)        /*!< I/O port G reset */
#define RCC_APB2RSTR_ADC1RST                ((uint32_t)0x00000200)        /*!< ADC 1 interface reset */
#define RCC_APB2RSTR_ADC2RST                ((uint32_t)0x00000400)        /*!< ADC 2 interface reset */
#define RCC_APB2RSTR_TIM1RST                ((uint32_t)0x00000800)        /*!< TIM1 Timer reset */
#define RCC_APB2RSTR_SPI1RST                ((uint32_t)0x00001000)        /*!< SPI 1 reset */
#define RCC_APB2RSTR_USART1RST              ((uint32_t)0x00004000)        /*!< USART1 reset */
#define RCC_APB2RSTR_TIM8RST                ((uint32_t)0x00002000)        /*!< TIM8 Timer reset */
#define RCC_APB2RSTR_ADC3RST                ((uint32_t)0x00008000)        /*!< ADC3 interface reset */

#define RCC_APB1RSTR_TIM2RST                ((uint32_t)0x00000001)        /*!< Timer 2 reset */
#define RCC_APB1RSTR_TIM3RST                ((uint32_t)0x00000002)        /*!< Timer 3 reset */
#define RCC_APB1RSTR_WWDGRST                ((uint32_t)0x00000800)        /*!< Window Watchdog reset */
#define RCC_APB1RSTR_USART2RST              ((uint32_t)0x00020000)        /*!< USART 2 reset */
#define RCC_APB1RSTR_I2C1RST                ((uint32_t)0x00200000)        /*!< I2C 1 reset */
#define RCC_APB1RSTR_CAN1RST                ((uint32_t)0x02000000)        /*!< CAN1 reset */
#define RCC_APB1RSTR_BKPRST                 ((uint32_t)0x08000000)        /*!< Backup interface reset */
#define RCC_APB1RSTR_PWRRST                 ((uint32_t)0x10000000)        /*!< Power interface reset */

#define RCC_APB1RSTR_TIM4RST                ((uint32_t)0x00000004)        /*!< Timer 4 reset */
#define RCC_APB1RSTR_SPI2RST                ((uint32_t)0x00004000)        /*!< SPI 2 reset */
#define RCC_APB1RSTR_USART3RST              ((uint32_t)0x00040000)        /*!< RUSART 3 reset */
#define RCC_APB1RSTR_I2C2RST                ((uint32_t)0x00400000)        /*!< I2C 2 reset */
#define RCC_APB1RSTR_USBRST                 ((uint32_t)0x00800000)        /*!< USB Device reset */
#define RCC_APB1RSTR_TIM5RST                ((uint32_t)0x00000008)        /*!< Timer 5 reset */
#define RCC_APB1RSTR_TIM6RST                ((uint32_t)0x00000010)        /*!< Timer 6 reset */
#define RCC_APB1RSTR_TIM7RST                ((uint32_t)0x00000020)        /*!< Timer 7 reset */
#define RCC_APB1RSTR_SPI3RST                ((uint32_t)0x00008000)        /*!< SPI 3 reset */
#define RCC_APB1RSTR_UART4RST               ((uint32_t)0x00080000)        /*!< UART 4 reset */
#define RCC_APB1RSTR_UART5RST               ((uint32_t)0x00100000)        /*!< UART 5 reset */
#define RCC_APB1RSTR_DACRST                 ((uint32_t)0x20000000)        /*!< DAC interface reset */
#define RCC_APB1RSTR_CAN2RST                ((uint32_t)0x08000000)        /*!< CAN2 reset */

#define RCC_AHBENR_DMA1EN                   ((uint32_t)0x00000001)        /*!< DMA1 clock enable */
#define RCC_AHBENR_SRAMEN                   ((uint32_t)0x00000004)        /*!< SRAM interface clock enable */
#define RCC_AHBENR_FLITFEN                  ((uint32_t)0x00000010)        /*!< FLITF clock enable */
#define RCC_AHBENR_CRCEN                    ((uint32_t)0x00000040)        /*!< CRC clock enable */
#define RCC_AHBENR_DMA2EN                   ((uint32_t)0x00000002)        /*!< DMA2 clock enable */
#define RCC_AHBENR_FSMCEN                   ((uint32_t)0x00000100)        /*!< FSMC clock enable */
#define RCC_AHBENR_SDIOEN                   ((uint32_t)0x00000400)        /*!< SDIO clock enable */
#define RCC_AHBENR_OTGFSEN                  ((uint32_t)0x00001000)        /*!< USB OTG FS clock enable */
#define RCC_AHBENR_ETHMACEN                 ((uint32_t)0x00004000)        /*!< ETHERNET MAC clock enable */
#define RCC_AHBENR_ETHMACTXEN               ((uint32_t)0x00008000)        /*!< ETHERNET MAC Tx clock enable */
#define RCC_AHBENR_ETHMACRXEN               ((uint32_t)0x00010000)        /*!< ETHERNET MAC Rx clock enable */

#define RCC_APB2ENR_AFIOEN                  ((uint32_t)0x00000001)        /*!< Alternate Function I/O clock enable */
#define RCC_APB2ENR_IOPAEN                  ((uint32_t)0x00000004)        /*!< I/O port A clock enable */
#define RCC_APB2ENR_IOPBEN                  ((uint32_t)0x00000008)        /*!< I/O port B clock enable */
#define RCC_APB2ENR_IOPCEN                  ((uint32_t)0x00000010)        /*!< I/O port C clock enable */
#define RCC_APB2ENR_IOPDEN                  ((uint32_t)0x00000020)        /*!< I/O port D clock enable */
#define RCC_APB2ENR_ADC1EN                  ((uint32_t)0x00000200)        /*!< ADC 1 interface clock enable */
#define RCC_APB2ENR_ADC2EN                  ((uint32_t)0x00000400)        /*!< ADC 2 interface clock enable */
#define RCC_APB2ENR_TIM1EN                  ((uint32_t)0x00000800)        /*!< TIM1 Timer clock enable */
#define RCC_APB2ENR_SPI1EN                  ((uint32_t)0x00001000)        /*!< SPI 1 clock enable */
#define RCC_APB2ENR_USART1EN                ((uint32_t)0x00004000)        /*!< USART1 clock enable */
#define RCC_APB2ENR_IOPEEN                  ((uint32_t)0x00000040)        /*!< I/O port E clock enable */
#define RCC_APB2ENR_IOPFEN                  ((uint32_t)0x00000080)        /*!< I/O port F clock enable */
#define RCC_APB2ENR_IOPGEN                  ((uint32_t)0x00000100)        /*!< I/O port G clock enable */
#define RCC_APB2ENR_TIM8EN                  ((uint32_t)0x00002000)        /*!< TIM8 Timer clock enable */
#define RCC_APB2ENR_ADC3EN                  ((uint32_t)0x00008000)        /*!< DMA1 clock enable */

#define RCC_APB1ENR_TIM2EN                  ((uint32_t)0x00000001)        /*!< Timer 2 clock enabled*/
#define RCC_APB1ENR_TIM3EN                  ((uint32_t)0x00000002)        /*!< Timer 3 clock enable */
#define RCC_APB1ENR_WWDGEN                  ((uint32_t)0x00000800)        /*!< Window Watchdog clock enable */
#define RCC_APB1ENR_USART2EN                ((uint32_t)0x00020000)        /*!< USART 2 clock enable */
#define RCC_APB1ENR_I2C1EN                  ((uint32_t)0x00200000)        /*!< I2C 1 clock enable */
#define RCC_APB1ENR_CAN1EN                  ((uint32_t)0x02000000)        /*!< CAN1 clock enable */
#define RCC_APB1ENR_BKPEN                   ((uint32_t)0x08000000)        /*!< Backup interface clock enable */
#define RCC_APB1ENR_PWREN                   ((uint32_t)0x10000000)        /*!< Power interface clock enable */
#define RCC_APB1ENR_TIM4EN                  ((uint32_t)0x00000004)        /*!< Timer 4 clock enable */
#define RCC_APB1ENR_SPI2EN                  ((uint32_t)0x00004000)        /*!< SPI 2 clock enable */
#define RCC_APB1ENR_USART3EN                ((uint32_t)0x00040000)        /*!< USART 3 clock enable */
#define RCC_APB1ENR_I2C2EN                  ((uint32_t)0x00400000)        /*!< I2C 2 clock enable */
#define RCC_APB1ENR_USBEN                   ((uint32_t)0x00800000)        /*!< USB Device clock enable */
#define RCC_APB1ENR_TIM5EN                  ((uint32_t)0x00000008)        /*!< Timer 5 clock enable */
#define RCC_APB1ENR_TIM6EN                  ((uint32_t)0x00000010)        /*!< Timer 6 clock enable */
#define RCC_APB1ENR_TIM7EN                  ((uint32_t)0x00000020)        /*!< Timer 7 clock enable */
#define RCC_APB1ENR_SPI3EN                  ((uint32_t)0x00008000)        /*!< SPI 3 clock enable */
#define RCC_APB1ENR_UART4EN                 ((uint32_t)0x00080000)        /*!< UART 4 clock enable */
#define RCC_APB1ENR_UART5EN                 ((uint32_t)0x00100000)        /*!< UART 5 clock enable */
#define RCC_APB1ENR_DACEN                   ((uint32_t)0x20000000)        /*!< DAC interface clock enable */
#define RCC_APB1ENR_CAN2EN                  ((uint32_t)0x08000000)        /*!< CAN2 clock enable */

#define RCC_BDCR_LSEON                      ((uint32_t)0x00000001)        /*!< External Low Speed oscillator enable */
#define RCC_BDCR_LSERDY                     ((uint32_t)0x00000002)        /*!< External Low Speed oscillator Ready */
#define RCC_BDCR_LSEBYP                     ((uint32_t)0x00000004)        /*!< External Low Speed oscillator Bypass */
#define RCC_BDCR_RTCSEL                     ((uint32_t)0x00000300)        /*!< RTCSEL[1:0] bits (RTC clock source selection) */
#define RCC_BDCR_RTCEN                      ((uint32_t)0x00008000)        /*!< RTC clock enable */
#define RCC_BDCR_BDRST                      ((uint32_t)0x00010000)        /*!< Backup domain software reset  */

#define RCC_CSR_LSION                       ((uint32_t)0x00000001)        /*!< Internal Low Speed oscillator enable */
#define RCC_CSR_LSIRDY                      ((uint32_t)0x00000002)        /*!< Internal Low Speed oscillator Ready */
#define RCC_CSR_RMVF                        ((uint32_t)0x01000000)        /*!< Remove reset flag */
#define RCC_CSR_PINRSTF                     ((uint32_t)0x04000000)        /*!< PIN reset flag */
#define RCC_CSR_PORRSTF                     ((uint32_t)0x08000000)        /*!< POR/PDR reset flag */
#define RCC_CSR_SFTRSTF                     ((uint32_t)0x10000000)        /*!< Software Reset flag */
#define RCC_CSR_IWDGRSTF                    ((uint32_t)0x20000000)        /*!< Independent Watchdog reset flag */
#define RCC_CSR_WWDGRSTF                    ((uint32_t)0x40000000)        /*!< Window watchdog reset flag */
#define RCC_CSR_LPWRRSTF                    ((uint32_t)0x80000000)        /*!< Low-Power reset flag */

#define RCC_AHBRSTR_OTGFSRST                ((uint32_t)0x00001000)        /*!< USB OTG FS reset */
#define RCC_AHBRSTR_ETHMACRST               ((uint32_t)0x00004000)        /*!< ETHERNET MAC reset */
#define RCC_CFGR2_PREDIV1                   ((uint32_t)0x0000000F)        /*!< PREDIV1[3:0] bits */
#define RCC_CFGR2_PREDIV2                   ((uint32_t)0x000000F0)        /*!< PREDIV2[3:0] bits */
#define RCC_CFGR2_PLL2MUL                   ((uint32_t)0x00000F00)        /*!< PLL2MUL[3:0] bits */
#define RCC_CFGR2_PLL3MUL                   ((uint32_t)0x0000F000)        /*!< PLL3MUL[3:0] bits */
#define RCC_CFGR2_PREDIV1SRC                ((uint32_t)0x00010000)        /*!< PREDIV1 entry clock source */
#define RCC_CFGR2_I2S2SRC                   ((uint32_t)0x00020000)        /*!< I2S2 entry clock source */
#define RCC_CFGR2_I2S3SRC                   ((uint32_t)0x00040000)        /*!< I2S3 clock source */

#define RCC_PLLSource_HSI_Div2              ((uint32_t)0x00000000)
#define RCC_PLLSource_HSE                   ((uint32_t)0x00010000)

#define RCC_CFGR_SW_HSI                      ((uint32_t)0x00000000)                    /*!< HSI16 oscillator selection as system clock */
#define RCC_CFGR_SW_HSE                      ((uint32_t)0x00000001)                    /*!< HSE oscillator selection as system clock */
#define RCC_CFGR_SW_PLL                      ((uint32_t)0x00000002)            /*!< PLL selection as system clock */

#define RCC_PLLMul_2                        ((uint32_t)0x00000000)
#define RCC_PLLMul_3                        ((uint32_t)0x00040000)
#define RCC_PLLMul_4                        ((uint32_t)0x00080000)
#define RCC_PLLMul_5                        ((uint32_t)0x000C0000)
#define RCC_PLLMul_6                        ((uint32_t)0x00100000)
#define RCC_PLLMul_7                        ((uint32_t)0x00140000)
#define RCC_PLLMul_8                        ((uint32_t)0x00180000)
#define RCC_PLLMul_9                        ((uint32_t)0x001C0000)
#define RCC_PLLMul_10                       ((uint32_t)0x00200000)
#define RCC_PLLMul_11                       ((uint32_t)0x00240000)
#define RCC_PLLMul_12                       ((uint32_t)0x00280000)
#define RCC_PLLMul_13                       ((uint32_t)0x002C0000)
#define RCC_PLLMul_14                       ((uint32_t)0x00300000)
#define RCC_PLLMul_15                       ((uint32_t)0x00340000)
#define RCC_PLLMul_16                       ((uint32_t)0x00380000)

static void hw_rcc_lse_clock_wait_ready(void)
{
    while(!(__GET_RCC_BDCR__ & RCC_BDCR_LSERDY));
}
static void hw_rcc_set_lse_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_BDCR__, RCC_BDCR_LSEON);
}

static void hw_rcc_set_lse_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_BDCR__, RCC_BDCR_LSEON);
}

static void hw_rcc_lsi_clock_wait_ready(void)
{
    while(!(__GET_RCC_CSR__ & RCC_CSR_LSIRDY));
}

static void hw_rcc_set_lsi_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CSR__, RCC_CSR_LSION);
}

static void hw_rcc_set_lsi_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CSR__, RCC_CSR_LSION);
}

static void hw_rcc_set_hsi_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_HSION);
}

static void hw_rcc_set_hsi_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_HSION);
}

static void hw_rcc_hsi_clock_wait_ready(void)
{
    while(!(__GET_RCC_CR__ & RCC_CR_HSIRDY));
}

static void hw_rcc_set_hse_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_HSEON);
}

static void hw_rcc_set_hse_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_HSEON);
}

static void hw_rcc_hse_clock_wait_ready(void)
{
    while(!(__GET_RCC_CR__ & RCC_CR_HSERDY));
}

static void hw_rcc_set_pll_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_CR__, RCC_CR_PLLON);
}

static void hw_rcc_set_pll_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_CR__, RCC_CR_PLLON);
}

static void hw_rcc_pll_clock_wait_ready(void)
{
    while(!(__GET_RCC_CR__ & RCC_CR_PLLRDY));
}

static void hw_rcc_set_clock_freq(enum hw_rcc_clock_source_e source, uint32_t freq)
{
    switch(source) {
        case hw_rcc_clock_source_lse:
            hw_rcc_set_lse_clock_enable();
            hw_rcc_lse_clock_wait_ready();
            break;
        case hw_rcc_clock_source_lsi:
            hw_rcc_set_lsi_clock_enable();
            hw_rcc_lsi_clock_wait_ready();
            break;
        case hw_rcc_clock_source_msi:
            break;
        case hw_rcc_clock_source_hsi:
            hw_rcc_set_hsi_clock_enable();
            hw_rcc_hsi_clock_wait_ready();
            break;
        case hw_rcc_clock_source_hse:
            hw_rcc_set_hse_clock_enable();
            hw_rcc_hse_clock_wait_ready();
            break;
        case hw_rcc_clock_source_pll:
            hw_rcc_set_pll_clock_enable();
            hw_rcc_pll_clock_wait_ready();
            break;
        default:
            break;
    }
}

static void hw_rcc_set_clock_enable(enum hw_rcc_clock_source_e source, enum hw_rcc_clock_enable_e en)
{
    switch(source) {
        case hw_rcc_clock_source_lse:
            en == hw_rcc_clock_enable ? hw_rcc_set_lse_clock_enable() : hw_rcc_set_lse_clock_disable();
            break;
        case hw_rcc_clock_source_lsi:
            en == hw_rcc_clock_enable ? hw_rcc_set_lsi_clock_enable() : hw_rcc_set_lsi_clock_disable();
            break;
        case hw_rcc_clock_source_msi:
            break;
        case hw_rcc_clock_source_hsi:
            en == hw_rcc_clock_enable ? hw_rcc_set_hsi_clock_enable() : hw_rcc_set_hsi_clock_disable();
            break;
        case hw_rcc_clock_source_hse:
            en == hw_rcc_clock_enable ? hw_rcc_set_hse_clock_enable() : hw_rcc_set_hse_clock_disable();
            break;
        case hw_rcc_clock_source_pll:
            en == hw_rcc_clock_enable ? hw_rcc_set_pll_clock_enable() : hw_rcc_set_pll_clock_disable();
            break;
        default:
            break;
    }
}

static void hw_rcc_set_usart1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_USART1EN);
}

static void hw_rcc_set_usart1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_USART1EN);
}

static uint32_t hw_rcc_get_usart1_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_USART1EN);
}

static void hw_rcc_set_gpioa_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPAEN);
}

static void hw_rcc_set_gpioa_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPAEN);
}

static uint32_t hw_rcc_get_gpioa_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_IOPAEN);
}

static void hw_rcc_set_gpiob_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPBEN);
}

static void hw_rcc_set_gpiob_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPBEN);
}

static uint32_t hw_rcc_get_gpiob_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_IOPBEN);
}

static void hw_rcc_set_gpioc_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPCEN);
}

static void hw_rcc_set_gpioc_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPCEN);
}

static uint32_t hw_rcc_get_gpioc_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_IOPCEN);
}

static void hw_rcc_set_gpiod_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPDEN);
}

static void hw_rcc_set_gpiod_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPDEN);
}

static uint32_t hw_rcc_get_gpiod_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_IOPDEN);
}

static void hw_rcc_set_gpioe_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPEEN);
}

static void hw_rcc_set_gpioe_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPEEN);
}

static uint32_t hw_rcc_get_gpioe_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_IOPEEN);
}

static void hw_rcc_set_gpiof_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPFEN);
}

static void hw_rcc_set_gpiof_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPFEN);
}

static uint32_t hw_rcc_get_gpiof_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_IOPFEN);
}

static void hw_rcc_set_gpiog_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPGEN);
}

static void hw_rcc_set_gpiog_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_IOPGEN);
}

static uint32_t hw_rcc_get_gpiog_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_IOPGEN);
}

static void hw_rcc_set_afio_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB2ENR__, RCC_APB2ENR_AFIOEN);
}

static void hw_rcc_set_afio_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB2ENR__, RCC_APB2ENR_AFIOEN);
}

static uint32_t hw_rcc_get_afio_clock_enable(void)
{
    return (__GET_RCC_APB2ENR__ & RCC_APB2ENR_AFIOEN);
}

static void hw_rcc_set_can1_clock_enable(void)
{
    __BIT_OR__(__GET_RCC_APB1ENR__, RCC_APB1ENR_CAN1EN);
}

static void hw_rcc_set_can1_clock_disable(void)
{
    __BIT_RESET__(__GET_RCC_APB1ENR__, RCC_APB1ENR_CAN1EN);
}

static uint32_t hw_rcc_get_can1_clock_enable(void)
{
    return (__GET_RCC_APB1ENR__ & RCC_APB1ENR_CAN1EN);
}

static void hw_rcc_set_peripheral_clock_enable(enum hw_rcc_peripheral_clock_enable_e source, enum hw_rcc_clock_enable_e en)
{
    switch(source) {
        case hw_rcc_peripheral_clock_usart1:
            en == hw_rcc_clock_enable ? hw_rcc_set_usart1_clock_enable() : hw_rcc_set_usart1_clock_disable();
            break;
        case hw_rcc_peripheral_clock_gpioa:
            en == hw_rcc_clock_enable ? hw_rcc_set_gpioa_clock_enable() : hw_rcc_set_gpioa_clock_disable();
            break;
        case hw_rcc_peripheral_clock_gpiob:
            en == hw_rcc_clock_enable ? hw_rcc_set_gpiob_clock_enable() : hw_rcc_set_gpiob_clock_disable();
            break;
        case hw_rcc_peripheral_clock_gpioc:
            en == hw_rcc_clock_enable ? hw_rcc_set_gpioc_clock_enable() : hw_rcc_set_gpioc_clock_disable();
            break;
        case hw_rcc_peripheral_clock_gpiod:
            en == hw_rcc_clock_enable ? hw_rcc_set_gpiod_clock_enable() : hw_rcc_set_gpiod_clock_disable();
            break;
        case hw_rcc_peripheral_clock_gpioe:
            en == hw_rcc_clock_enable ? hw_rcc_set_gpioe_clock_enable() : hw_rcc_set_gpioe_clock_disable();
            break;
        case hw_rcc_peripheral_clock_gpiof:
            en == hw_rcc_clock_enable ? hw_rcc_set_gpiof_clock_enable() : hw_rcc_set_gpiof_clock_disable();
            break;
        case hw_rcc_peripheral_clock_gpiog:
            en == hw_rcc_clock_enable ? hw_rcc_set_gpiog_clock_enable() : hw_rcc_set_gpiog_clock_disable();
            break;
        case hw_rcc_peripheral_clock_afio:
            en == hw_rcc_clock_enable ? hw_rcc_set_afio_clock_enable() : hw_rcc_set_afio_clock_disable();
            break;
        case hw_rcc_peripheral_clock_can1:
            en == hw_rcc_clock_enable ? hw_rcc_set_can1_clock_enable() : hw_rcc_set_can1_clock_disable();
            break;
        default:
            break;
    }
}

static void hw_rcc_set_main_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLSRC, source);
}

static void hw_rcc_select_system_clock_source(uint32_t source)
{
    __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_SW, source);
}

static void hw_rcc_set_pll_multiplication_factor(uint32_t mul)
{
    switch(mul) {
    case 2: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_2); break;
    case 3: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_3); break;
    case 4: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_4); break;
    case 5: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_5); break;
    case 6: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_6); break;
    case 7: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_7); break;
    case 8: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_8); break;
    case 9: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_9); break;
    case 10: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_10); break;
    case 11: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_11); break;
    case 12: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_12); break;
    case 13: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_13); break;
    case 14: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_14); break;
    case 15: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_15); break;
    case 16: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PLLMULL, RCC_PLLMul_16); break;
    }
}

static void hw_rcc_set_apb1_prescaler(uint32_t per)
{
    switch(per) {
    case 2: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PPRE1, ((uint32_t)0x00000400)); break;
    case 4: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PPRE1, ((uint32_t)0x00000500)); break;
    case 8: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PPRE1, ((uint32_t)0x00000600)); break;
    case 16: __BIT_COVER_SET__(__GET_RCC_CFGR__, RCC_CFGR_PPRE1, ((uint32_t)0x00000700)); break;
    }
}

enum hw_platform_errcode_e hw_platform_rcc_cmd(uint8_t type, WPARAM wParam, LPARAM lParam)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(type) {
        case HW_RCC_CMD_SET_CLOCK_FREQ:
            hw_rcc_set_clock_freq(wParam, lParam);
           break;
        case HW_RCC_CMD_SET_CLOCK_ENABLE:
            hw_rcc_set_clock_enable(wParam, lParam);
            break;
        case HW_RCC_CMD_SET_PERIPHERAL_CLOCK_ENABLE:
            hw_rcc_set_peripheral_clock_enable(wParam, lParam);
            break;
        case HW_RCC_CMD_SET_PLL_CLOCK_SOURCE:
            if(wParam == hw_rcc_pll_clock_source_hse) {
                hw_rcc_set_main_clock_source(RCC_PLLSource_HSE);
            } else if(wParam == hw_rcc_pll_clock_source_hsi) {
                hw_rcc_set_main_clock_source(RCC_PLLSource_HSI_Div2);
            }
            break;
        case HW_RCC_CMD_GET_PLL_CLOCK_SOURCE:
            *(enum hw_rcc_pll_clock_source_e *)wParam = hw_rcc_pll_clock_source_hsi;
            break;
        case HW_RCC_CMD_SET_SYSTEM_CLOCK_SOURCE:
            if(wParam == hw_rcc_system_clock_source_hsi) {
                hw_rcc_select_system_clock_source(RCC_CFGR_SW_HSI);
            } else if(wParam == hw_rcc_system_clock_source_hse) {
                hw_rcc_select_system_clock_source(RCC_CFGR_SW_HSE);
            } else if(wParam == hw_rcc_system_clock_source_pllclk) {
                hw_rcc_select_system_clock_source(RCC_CFGR_SW_PLL);
            }
            break;
        case HW_RCC_CMD_GET_SYSTEM_CLOCK_SOURCE:
            *(enum hw_rcc_system_clock_source_e *)wParam = hw_rcc_system_clock_source_hsi;
            break;
        case HW_RCC_CMD_SET_USART_CLOCK_SOURCE:
            break;
        case HW_RCC_CMD_GET_USART_CLOCK_SOURCE:
            *(enum hw_rcc_usart_clock_source_e *)wParam = hw_rcc_usart_clock_source_sysclk;
            break;
        case HW_RCC_CMD_SET_MASTER_CLOCK_ENABLE:
//            lParam == hw_rcc_clock_enable ? hw_rcc_set_main_pll_clock_output_enable() : hw_rcc_set_main_pll_clock_output_disable();
            break;
        case HW_RCC_CMD_SET_FREQ_MULTIPLIER:
            if(wParam == hw_rcc_clock_source_pll) {
                hw_rcc_set_pll_multiplication_factor(lParam);
            }
            break;
        case HW_RCC_CMD_SET_PRESCALER:
            if(wParam == hw_rcc_prescaler_clock_apb1) {
                hw_rcc_set_apb1_prescaler(lParam);
            }
            break;
        case HW_RCC_CMD_SET_FLASH_WAIT_TIME:
            hw_rcc_set_flash_wait_time(wParam);
            break;
        default: 
            bRet = hw_platform_errcode_not_support;
            break;
    }
    return bRet;
}

