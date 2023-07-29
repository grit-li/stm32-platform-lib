#ifndef __STM32_HW_REG_MAP_H__
#define __STM32_HW_REG_MAP_H__

#ifdef __cplusplus
 extern "C" {
#endif

#define __CM4_REV                 0x0001  /*!< Cortex-M4 revision r0p1                       */

#define FLASH_BASE            (0x08000000UL) /*!< FLASH(up to 1 MB) base address */
#define SRAM1_BASE            (0x20000000UL) /*!< SRAM1(up to 96 KB) base address */
#define SRAM2_BASE            (0x10000000UL) /*!< SRAM2(32 KB) base address */
#define PERIPH_BASE           (0x40000000UL) /*!< Peripheral base address */
#define FMC_BASE              (0x60000000UL) /*!< FMC base address */
#define QSPI_BASE             (0x90000000UL) /*!< QUADSPI memories accessible over AHB base address */

#define FMC_R_BASE            (0xA0000000UL) /*!< FMC  control registers base address */
#define QSPI_R_BASE           (0xA0001000UL) /*!< QUADSPI control registers base address */
#define SRAM1_BB_BASE         (0x22000000UL) /*!< SRAM1(96 KB) base address in the bit-band region */
#define PERIPH_BB_BASE        (0x42000000UL) /*!< Peripheral base address in the bit-band region */

#define APB1PERIPH_BASE        PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)

#define FMC_BANK1             FMC_BASE
#define FMC_BANK1_1           FMC_BANK1
#define FMC_BANK1_2           (FMC_BANK1 + 0x04000000UL)
#define FMC_BANK1_3           (FMC_BANK1 + 0x08000000UL)
#define FMC_BANK1_4           (FMC_BANK1 + 0x0C000000UL)
#define FMC_BANK3             (FMC_BASE  + 0x20000000UL)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400UL)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800UL)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00UL)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00UL)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x5C00UL)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400UL)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000UL)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400UL)
#define DAC1_BASE             (APB1PERIPH_BASE + 0x7400UL)
#define OPAMP_BASE            (APB1PERIPH_BASE + 0x7800UL)
#define OPAMP1_BASE           (APB1PERIPH_BASE + 0x7800UL)
#define OPAMP2_BASE           (APB1PERIPH_BASE + 0x7810UL)
#define LPTIM1_BASE           (APB1PERIPH_BASE + 0x7C00UL)
#define LPUART1_BASE          (APB1PERIPH_BASE + 0x8000UL)
#define SWPMI1_BASE           (APB1PERIPH_BASE + 0x8800UL)
#define LPTIM2_BASE           (APB1PERIPH_BASE + 0x9400UL)

#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x0000UL)
#define VREFBUF_BASE          (APB2PERIPH_BASE + 0x0030UL)
#define COMP1_BASE            (APB2PERIPH_BASE + 0x0200UL)
#define COMP2_BASE            (APB2PERIPH_BASE + 0x0204UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x0400UL)
#define FIREWALL_BASE         (APB2PERIPH_BASE + 0x1C00UL)
#define SDMMC1_BASE           (APB2PERIPH_BASE + 0x2800UL)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000UL)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x3400UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800UL)
#define TIM15_BASE            (APB2PERIPH_BASE + 0x4000UL)
#define TIM16_BASE            (APB2PERIPH_BASE + 0x4400UL)
#define TIM17_BASE            (APB2PERIPH_BASE + 0x4800UL)
#define SAI1_BASE             (APB2PERIPH_BASE + 0x5400UL)
#define SAI1_Block_A_BASE     (SAI1_BASE + 0x0004UL)
#define SAI1_Block_B_BASE     (SAI1_BASE + 0x0024UL)
#define SAI2_BASE             (APB2PERIPH_BASE + 0x5800UL)
#define SAI2_Block_A_BASE     (SAI2_BASE + 0x0004UL)
#define SAI2_Block_B_BASE     (SAI2_BASE + 0x0024UL)
#define DFSDM1_BASE           (APB2PERIPH_BASE + 0x6000UL)
#define DFSDM1_Channel0_BASE  (DFSDM1_BASE + 0x0000UL)
#define DFSDM1_Channel1_BASE  (DFSDM1_BASE + 0x0020UL)
#define DFSDM1_Channel2_BASE  (DFSDM1_BASE + 0x0040UL)
#define DFSDM1_Channel3_BASE  (DFSDM1_BASE + 0x0060UL)
#define DFSDM1_Channel4_BASE  (DFSDM1_BASE + 0x0080UL)
#define DFSDM1_Channel5_BASE  (DFSDM1_BASE + 0x00A0UL)
#define DFSDM1_Channel6_BASE  (DFSDM1_BASE + 0x00C0UL)
#define DFSDM1_Channel7_BASE  (DFSDM1_BASE + 0x00E0UL)
#define DFSDM1_Filter0_BASE   (DFSDM1_BASE + 0x0100UL)
#define DFSDM1_Filter1_BASE   (DFSDM1_BASE + 0x0180UL)
#define DFSDM1_Filter2_BASE   (DFSDM1_BASE + 0x0200UL)
#define DFSDM1_Filter3_BASE   (DFSDM1_BASE + 0x0280UL)

#define DMA1_BASE             (AHB1PERIPH_BASE)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x0400UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x1000UL)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x2000UL)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000UL)
#define TSC_BASE              (AHB1PERIPH_BASE + 0x4000UL)


#define DMA1_Channel1_BASE    (DMA1_BASE + 0x0008UL)
#define DMA1_Channel2_BASE    (DMA1_BASE + 0x001CUL)
#define DMA1_Channel3_BASE    (DMA1_BASE + 0x0030UL)
#define DMA1_Channel4_BASE    (DMA1_BASE + 0x0044UL)
#define DMA1_Channel5_BASE    (DMA1_BASE + 0x0058UL)
#define DMA1_Channel6_BASE    (DMA1_BASE + 0x006CUL)
#define DMA1_Channel7_BASE    (DMA1_BASE + 0x0080UL)
#define DMA1_CSELR_BASE       (DMA1_BASE + 0x00A8UL)


#define DMA2_Channel1_BASE    (DMA2_BASE + 0x0008UL)
#define DMA2_Channel2_BASE    (DMA2_BASE + 0x001CUL)
#define DMA2_Channel3_BASE    (DMA2_BASE + 0x0030UL)
#define DMA2_Channel4_BASE    (DMA2_BASE + 0x0044UL)
#define DMA2_Channel5_BASE    (DMA2_BASE + 0x0058UL)
#define DMA2_Channel6_BASE    (DMA2_BASE + 0x006CUL)
#define DMA2_Channel7_BASE    (DMA2_BASE + 0x0080UL)
#define DMA2_CSELR_BASE       (DMA2_BASE + 0x00A8UL)

#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB2PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (AHB2PERIPH_BASE + 0x1C00UL)

#define USBOTG_BASE           (AHB2PERIPH_BASE + 0x08000000UL)

#define ADC1_BASE             (AHB2PERIPH_BASE + 0x08040000UL)
#define ADC2_BASE             (AHB2PERIPH_BASE + 0x08040100UL)
#define ADC3_BASE             (AHB2PERIPH_BASE + 0x08040200UL)
#define ADC123_COMMON_BASE    (AHB2PERIPH_BASE + 0x08040300UL)

#define RNG_BASE              (AHB2PERIPH_BASE + 0x08060800UL)

#define FMC_Bank1_R_BASE      (FMC_R_BASE + 0x0000UL)
#define FMC_Bank1E_R_BASE     (FMC_R_BASE + 0x0104UL)
#define FMC_Bank3_R_BASE      (FMC_R_BASE + 0x0080UL)

#define DBGMCU_BASE                          (0xE0042000UL)
#define USB_OTG_FS_PERIPH_BASE               (0x50000000UL)
#define USB_OTG_GLOBAL_BASE                  (0x00000000UL)
#define USB_OTG_DEVICE_BASE                  (0x00000800UL)
#define USB_OTG_IN_ENDPOINT_BASE             (0x00000900UL)
#define USB_OTG_OUT_ENDPOINT_BASE            (0x00000B00UL)
#define USB_OTG_EP_REG_SIZE                  (0x00000020UL)
#define USB_OTG_HOST_BASE                    (0x00000400UL)
#define USB_OTG_HOST_PORT_BASE               (0x00000440UL)
#define USB_OTG_HOST_CHANNEL_BASE            (0x00000500UL)
#define USB_OTG_HOST_CHANNEL_SIZE            (0x00000020UL)
#define USB_OTG_PCGCCTL_BASE                 (0x00000E00UL)
#define USB_OTG_FIFO_BASE                    (0x00001000UL)
#define USB_OTG_FIFO_SIZE                    (0x00001000UL)

#define PACKAGE_BASE          (0x1FFF7500UL)        /*!< Package data register base address     */
#define UID_BASE              (0x1FFF7590UL)        /*!< Unique device ID register base address */
#define FLASHSIZE_BASE        (0x1FFF75E0UL)        /*!< Flash size data register base address  */

/* Memory mapping of Core Hardware */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define ITM_BASE            (0xE0000000UL)                            /*!< ITM Base Address */
#define DWT_BASE            (0xE0001000UL)                            /*!< DWT Base Address */
#define TPI_BASE            (0xE0040000UL)                            /*!< TPI Base Address */
#define CoreDebug_BASE      (0xE000EDF0UL)                            /*!< Core Debug Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */
#define MPU_BASE            (SCS_BASE +  0x0D90UL)                    /*!< Memory Protection Unit */
#define FPU_BASE            (SCS_BASE +  0x0F30UL)                    /*!< Floating Point Unit */

#ifdef __cplusplus
}
#endif

#endif
