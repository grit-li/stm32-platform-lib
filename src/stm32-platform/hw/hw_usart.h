#ifndef __SETM32_PLATFORM_HW_USART_H__
#define __SETM32_PLATFORM_HW_USART_H__

#include <stdint.h>
#include "cortex_m.h"
#include "stm32_hw_reg_map.h"
#include "stm32_bitops.h"

#ifdef __cplusplus
extern "C" {
#endif

struct USART_TypeDef
{
    __IO uint32_t CR1;         /*!< USART Control register 1,                 Address offset: 0x00 */
    __IO uint32_t CR2;         /*!< USART Control register 2,                 Address offset: 0x04 */
    __IO uint32_t CR3;         /*!< USART Control register 3,                 Address offset: 0x08 */
    __IO uint32_t BRR;         /*!< USART Baud rate register,                 Address offset: 0x0C */
    __IO uint16_t GTPR;        /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
    uint16_t  RESERVED2;       /*!< Reserved, 0x12                                                 */
    __IO uint32_t RTOR;        /*!< USART Receiver Time Out register,         Address offset: 0x14 */
    __IO uint16_t RQR;         /*!< USART Request register,                   Address offset: 0x18 */
    uint16_t  RESERVED3;       /*!< Reserved, 0x1A                                                 */
    __IO uint32_t ISR;         /*!< USART Interrupt and status register,      Address offset: 0x1C */
    __IO uint32_t ICR;         /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
    __IO uint16_t RDR;         /*!< USART Receive Data register,              Address offset: 0x24 */
    uint16_t  RESERVED4;       /*!< Reserved, 0x26                                                 */
    __IO uint16_t TDR;         /*!< USART Transmit Data register,             Address offset: 0x28 */
    uint16_t  RESERVED5;       /*!< Reserved, 0x2A                                                 */
};

#define USART1              ((struct USART_TypeDef *) USART1_BASE)
#define USART2              ((struct USART_TypeDef *) USART2_BASE)
#define USART3              ((struct USART_TypeDef *) USART3_BASE)
#define UART4               ((struct USART_TypeDef *) UART4_BASE)
#define UART5               ((struct USART_TypeDef *) UART5_BASE)
#define LPUART1             ((struct USART_TypeDef *) LPUART1_BASE)

static inline struct USART_TypeDef* __GET_USART1_REGISTER__(void)
{
    return USART1;
}

static inline struct USART_TypeDef* __GET_USART2_REGISTER__(void)
{
    return USART1;
}

static inline struct USART_TypeDef* __GET_USART3_REGISTER__(void)
{
    return USART1;
}

#define __GET_USART_REGISTER__(usart) __GET_##usart##_REGISTER__()

#define __GET_USART_CR1__(USARTx)           (USARTx->CR1)
#define __GET_USART_CR2__(USARTx)           (USARTx->CR2)
#define __GET_USART_CR3__(USARTx)           (USARTx->CR3)
#define __GET_USART_BRR__(USARTx)           (USARTx->BRR)
#define __GET_USART_GTPR__(USARTx)          (USARTx->GTPR)
#define __GET_USART_RTOR__(USARTx)          (USARTx->RTOR)
#define __GET_USART_RQR__(USARTx)           (USARTx->RQR)
#define __GET_USART_ISR__(USARTx)           (USARTx->ISR)
#define __GET_USART_ICR__(USARTx)           (USARTx->ICR)
#define __GET_USART_RDR__(USARTx)           (USARTx->RDR)
#define __GET_USART_TDR__(USARTx)           (USARTx->TDR)

/******************************************************************************/
/*                                                                            */
/*      Universal Synchronous Asynchronous Receiver Transmitter (USART)       */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CR1_UE_Pos              (0U)
#define USART_CR1_UE_Msk              (0x1UL << USART_CR1_UE_Pos)              /*!< 0x00000001 */
#define USART_CR1_UE                  USART_CR1_UE_Msk                         /*!< USART Enable */
#define USART_CR1_UESM_Pos            (1U)
#define USART_CR1_UESM_Msk            (0x1UL << USART_CR1_UESM_Pos)            /*!< 0x00000002 */
#define USART_CR1_UESM                USART_CR1_UESM_Msk                       /*!< USART Enable in STOP Mode */
#define USART_CR1_RE_Pos              (2U)
#define USART_CR1_RE_Msk              (0x1UL << USART_CR1_RE_Pos)              /*!< 0x00000004 */
#define USART_CR1_RE                  USART_CR1_RE_Msk                         /*!< Receiver Enable */
#define USART_CR1_TE_Pos              (3U)
#define USART_CR1_TE_Msk              (0x1UL << USART_CR1_TE_Pos)              /*!< 0x00000008 */
#define USART_CR1_TE                  USART_CR1_TE_Msk                         /*!< Transmitter Enable */
#define USART_CR1_IDLEIE_Pos          (4U)
#define USART_CR1_IDLEIE_Msk          (0x1UL << USART_CR1_IDLEIE_Pos)          /*!< 0x00000010 */
#define USART_CR1_IDLEIE              USART_CR1_IDLEIE_Msk                     /*!< IDLE Interrupt Enable */
#define USART_CR1_RXNEIE_Pos          (5U)
#define USART_CR1_RXNEIE_Msk          (0x1UL << USART_CR1_RXNEIE_Pos)          /*!< 0x00000020 */
#define USART_CR1_RXNEIE              USART_CR1_RXNEIE_Msk                     /*!< RXNE Interrupt Enable */
#define USART_CR1_TCIE_Pos            (6U)
#define USART_CR1_TCIE_Msk            (0x1UL << USART_CR1_TCIE_Pos)            /*!< 0x00000040 */
#define USART_CR1_TCIE                USART_CR1_TCIE_Msk                       /*!< Transmission Complete Interrupt Enable */
#define USART_CR1_TXEIE_Pos           (7U)
#define USART_CR1_TXEIE_Msk           (0x1UL << USART_CR1_TXEIE_Pos)           /*!< 0x00000080 */
#define USART_CR1_TXEIE               USART_CR1_TXEIE_Msk                      /*!< TXE Interrupt Enable */
#define USART_CR1_PEIE_Pos            (8U)
#define USART_CR1_PEIE_Msk            (0x1UL << USART_CR1_PEIE_Pos)            /*!< 0x00000100 */
#define USART_CR1_PEIE                USART_CR1_PEIE_Msk                       /*!< PE Interrupt Enable */
#define USART_CR1_PS_Pos              (9U)
#define USART_CR1_PS_Msk              (0x1UL << USART_CR1_PS_Pos)              /*!< 0x00000200 */
#define USART_CR1_PS                  USART_CR1_PS_Msk                         /*!< Parity Selection */
#define USART_CR1_PCE_Pos             (10U)
#define USART_CR1_PCE_Msk             (0x1UL << USART_CR1_PCE_Pos)             /*!< 0x00000400 */
#define USART_CR1_PCE                 USART_CR1_PCE_Msk                        /*!< Parity Control Enable */
#define USART_CR1_WAKE_Pos            (11U)
#define USART_CR1_WAKE_Msk            (0x1UL << USART_CR1_WAKE_Pos)            /*!< 0x00000800 */
#define USART_CR1_WAKE                USART_CR1_WAKE_Msk                       /*!< Receiver Wakeup method */
#define USART_CR1_M_Pos               (12U)
#define USART_CR1_M_Msk               (0x10001UL << USART_CR1_M_Pos)           /*!< 0x10001000 */
#define USART_CR1_M                   USART_CR1_M_Msk                          /*!< Word length */
#define USART_CR1_M0_Pos              (12U)
#define USART_CR1_M0_Msk              (0x1UL << USART_CR1_M0_Pos)              /*!< 0x00001000 */
#define USART_CR1_M0                  USART_CR1_M0_Msk                         /*!< Word length - Bit 0 */
#define USART_CR1_MME_Pos             (13U)
#define USART_CR1_MME_Msk             (0x1UL << USART_CR1_MME_Pos)             /*!< 0x00002000 */
#define USART_CR1_MME                 USART_CR1_MME_Msk                        /*!< Mute Mode Enable */
#define USART_CR1_CMIE_Pos            (14U)
#define USART_CR1_CMIE_Msk            (0x1UL << USART_CR1_CMIE_Pos)            /*!< 0x00004000 */
#define USART_CR1_CMIE                USART_CR1_CMIE_Msk                       /*!< Character match interrupt enable */
#define USART_CR1_OVER8_Pos           (15U)
#define USART_CR1_OVER8_Msk           (0x1UL << USART_CR1_OVER8_Pos)           /*!< 0x00008000 */
#define USART_CR1_OVER8               USART_CR1_OVER8_Msk                      /*!< Oversampling by 8-bit or 16-bit mode */
#define USART_CR1_DEDT_Pos            (16U)
#define USART_CR1_DEDT_Msk            (0x1FUL << USART_CR1_DEDT_Pos)           /*!< 0x001F0000 */
#define USART_CR1_DEDT                USART_CR1_DEDT_Msk                       /*!< DEDT[4:0] bits (Driver Enable Deassertion Time) */
#define USART_CR1_DEDT_0              (0x01UL << USART_CR1_DEDT_Pos)           /*!< 0x00010000 */
#define USART_CR1_DEDT_1              (0x02UL << USART_CR1_DEDT_Pos)           /*!< 0x00020000 */
#define USART_CR1_DEDT_2              (0x04UL << USART_CR1_DEDT_Pos)           /*!< 0x00040000 */
#define USART_CR1_DEDT_3              (0x08UL << USART_CR1_DEDT_Pos)           /*!< 0x00080000 */
#define USART_CR1_DEDT_4              (0x10UL << USART_CR1_DEDT_Pos)           /*!< 0x00100000 */
#define USART_CR1_DEAT_Pos            (21U)
#define USART_CR1_DEAT_Msk            (0x1FUL << USART_CR1_DEAT_Pos)           /*!< 0x03E00000 */
#define USART_CR1_DEAT                USART_CR1_DEAT_Msk                       /*!< DEAT[4:0] bits (Driver Enable Assertion Time) */
#define USART_CR1_DEAT_0              (0x01UL << USART_CR1_DEAT_Pos)           /*!< 0x00200000 */
#define USART_CR1_DEAT_1              (0x02UL << USART_CR1_DEAT_Pos)           /*!< 0x00400000 */
#define USART_CR1_DEAT_2              (0x04UL << USART_CR1_DEAT_Pos)           /*!< 0x00800000 */
#define USART_CR1_DEAT_3              (0x08UL << USART_CR1_DEAT_Pos)           /*!< 0x01000000 */
#define USART_CR1_DEAT_4              (0x10UL << USART_CR1_DEAT_Pos)           /*!< 0x02000000 */
#define USART_CR1_RTOIE_Pos           (26U)
#define USART_CR1_RTOIE_Msk           (0x1UL << USART_CR1_RTOIE_Pos)           /*!< 0x04000000 */
#define USART_CR1_RTOIE               USART_CR1_RTOIE_Msk                      /*!< Receive Time Out interrupt enable */
#define USART_CR1_EOBIE_Pos           (27U)
#define USART_CR1_EOBIE_Msk           (0x1UL << USART_CR1_EOBIE_Pos)           /*!< 0x08000000 */
#define USART_CR1_EOBIE               USART_CR1_EOBIE_Msk                      /*!< End of Block interrupt enable */
#define USART_CR1_M1_Pos              (28U)
#define USART_CR1_M1_Msk              (0x1UL << USART_CR1_M1_Pos)              /*!< 0x10000000 */
#define USART_CR1_M1                  USART_CR1_M1_Msk                         /*!< Word length - Bit 1 */

/******************  Bit definition for USART_CR2 register  *******************/
#define USART_CR2_ADDM7_Pos           (4U)
#define USART_CR2_ADDM7_Msk           (0x1UL << USART_CR2_ADDM7_Pos)           /*!< 0x00000010 */
#define USART_CR2_ADDM7               USART_CR2_ADDM7_Msk                      /*!< 7-bit or 4-bit Address Detection */
#define USART_CR2_LBDL_Pos            (5U)
#define USART_CR2_LBDL_Msk            (0x1UL << USART_CR2_LBDL_Pos)            /*!< 0x00000020 */
#define USART_CR2_LBDL                USART_CR2_LBDL_Msk                       /*!< LIN Break Detection Length */
#define USART_CR2_LBDIE_Pos           (6U)
#define USART_CR2_LBDIE_Msk           (0x1UL << USART_CR2_LBDIE_Pos)           /*!< 0x00000040 */
#define USART_CR2_LBDIE               USART_CR2_LBDIE_Msk                      /*!< LIN Break Detection Interrupt Enable */
#define USART_CR2_LBCL_Pos            (8U)
#define USART_CR2_LBCL_Msk            (0x1UL << USART_CR2_LBCL_Pos)            /*!< 0x00000100 */
#define USART_CR2_LBCL                USART_CR2_LBCL_Msk                       /*!< Last Bit Clock pulse */
#define USART_CR2_CPHA_Pos            (9U)
#define USART_CR2_CPHA_Msk            (0x1UL << USART_CR2_CPHA_Pos)            /*!< 0x00000200 */
#define USART_CR2_CPHA                USART_CR2_CPHA_Msk                       /*!< Clock Phase */
#define USART_CR2_CPOL_Pos            (10U)
#define USART_CR2_CPOL_Msk            (0x1UL << USART_CR2_CPOL_Pos)            /*!< 0x00000400 */
#define USART_CR2_CPOL                USART_CR2_CPOL_Msk                       /*!< Clock Polarity */
#define USART_CR2_CLKEN_Pos           (11U)
#define USART_CR2_CLKEN_Msk           (0x1UL << USART_CR2_CLKEN_Pos)           /*!< 0x00000800 */
#define USART_CR2_CLKEN               USART_CR2_CLKEN_Msk                      /*!< Clock Enable */
#define USART_CR2_STOP_Pos            (12U)
#define USART_CR2_STOP_Msk            (0x3UL << USART_CR2_STOP_Pos)            /*!< 0x00003000 */
#define USART_CR2_STOP                USART_CR2_STOP_Msk                       /*!< STOP[1:0] bits (STOP bits) */
#define USART_CR2_STOP_0_5            (0x1UL << USART_CR2_STOP_Pos)            /*!< 0x00001000 */
#define USART_CR2_STOP_1              (0x0UL << USART_CR2_STOP_Pos)            /*!< 0x00000000 */
#define USART_CR2_STOP_1_5            (0x3UL << USART_CR2_STOP_Pos)            /*!< 0x00003000 */
#define USART_CR2_STOP_2              (0x2UL << USART_CR2_STOP_Pos)            /*!< 0x00002000 */
#define USART_CR2_LINEN_Pos           (14U)
#define USART_CR2_LINEN_Msk           (0x1UL << USART_CR2_LINEN_Pos)           /*!< 0x00004000 */
#define USART_CR2_LINEN               USART_CR2_LINEN_Msk                      /*!< LIN mode enable */
#define USART_CR2_SWAP_Pos            (15U)
#define USART_CR2_SWAP_Msk            (0x1UL << USART_CR2_SWAP_Pos)            /*!< 0x00008000 */
#define USART_CR2_SWAP                USART_CR2_SWAP_Msk                       /*!< SWAP TX/RX pins */
#define USART_CR2_RXINV_Pos           (16U)
#define USART_CR2_RXINV_Msk           (0x1UL << USART_CR2_RXINV_Pos)           /*!< 0x00010000 */
#define USART_CR2_RXINV               USART_CR2_RXINV_Msk                      /*!< RX pin active level inversion */
#define USART_CR2_TXINV_Pos           (17U)
#define USART_CR2_TXINV_Msk           (0x1UL << USART_CR2_TXINV_Pos)           /*!< 0x00020000 */
#define USART_CR2_TXINV               USART_CR2_TXINV_Msk                      /*!< TX pin active level inversion */
#define USART_CR2_DATAINV_Pos         (18U)
#define USART_CR2_DATAINV_Msk         (0x1UL << USART_CR2_DATAINV_Pos)         /*!< 0x00040000 */
#define USART_CR2_DATAINV             USART_CR2_DATAINV_Msk                    /*!< Binary data inversion */
#define USART_CR2_MSBFIRST_Pos        (19U)
#define USART_CR2_MSBFIRST_Msk        (0x1UL << USART_CR2_MSBFIRST_Pos)        /*!< 0x00080000 */
#define USART_CR2_MSBFIRST            USART_CR2_MSBFIRST_Msk                   /*!< Most Significant Bit First */
#define USART_CR2_ABREN_Pos           (20U)
#define USART_CR2_ABREN_Msk           (0x1UL << USART_CR2_ABREN_Pos)           /*!< 0x00100000 */
#define USART_CR2_ABREN               USART_CR2_ABREN_Msk                      /*!< Auto Baud-Rate Enable*/
#define USART_CR2_ABRMODE_Pos         (21U)
#define USART_CR2_ABRMODE_Msk         (0x3UL << USART_CR2_ABRMODE_Pos)         /*!< 0x00600000 */
#define USART_CR2_ABRMODE             USART_CR2_ABRMODE_Msk                    /*!< ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
#define USART_CR2_ABRMODE_0           (0x1UL << USART_CR2_ABRMODE_Pos)         /*!< 0x00200000 */
#define USART_CR2_ABRMODE_1           (0x2UL << USART_CR2_ABRMODE_Pos)         /*!< 0x00400000 */
#define USART_CR2_RTOEN_Pos           (23U)
#define USART_CR2_RTOEN_Msk           (0x1UL << USART_CR2_RTOEN_Pos)           /*!< 0x00800000 */
#define USART_CR2_RTOEN               USART_CR2_RTOEN_Msk                      /*!< Receiver Time-Out enable */
#define USART_CR2_ADD_Pos             (24U)
#define USART_CR2_ADD_Msk             (0xFFUL << USART_CR2_ADD_Pos)            /*!< 0xFF000000 */
#define USART_CR2_ADD                 USART_CR2_ADD_Msk                        /*!< Address of the USART node */

/******************  Bit definition for USART_CR3 register  *******************/
#define USART_CR3_EIE_Pos             (0U)
#define USART_CR3_EIE_Msk             (0x1UL << USART_CR3_EIE_Pos)             /*!< 0x00000001 */
#define USART_CR3_EIE                 USART_CR3_EIE_Msk                        /*!< Error Interrupt Enable */
#define USART_CR3_IREN_Pos            (1U)
#define USART_CR3_IREN_Msk            (0x1UL << USART_CR3_IREN_Pos)            /*!< 0x00000002 */
#define USART_CR3_IREN                USART_CR3_IREN_Msk                       /*!< IrDA mode Enable */
#define USART_CR3_IRLP_Pos            (2U)
#define USART_CR3_IRLP_Msk            (0x1UL << USART_CR3_IRLP_Pos)            /*!< 0x00000004 */
#define USART_CR3_IRLP                USART_CR3_IRLP_Msk                       /*!< IrDA Low-Power */
#define USART_CR3_HDSEL_Pos           (3U)
#define USART_CR3_HDSEL_Msk           (0x1UL << USART_CR3_HDSEL_Pos)           /*!< 0x00000008 */
#define USART_CR3_HDSEL               USART_CR3_HDSEL_Msk                      /*!< Half-Duplex Selection */
#define USART_CR3_NACK_Pos            (4U)
#define USART_CR3_NACK_Msk            (0x1UL << USART_CR3_NACK_Pos)            /*!< 0x00000010 */
#define USART_CR3_NACK                USART_CR3_NACK_Msk                       /*!< SmartCard NACK enable */
#define USART_CR3_SCEN_Pos            (5U)
#define USART_CR3_SCEN_Msk            (0x1UL << USART_CR3_SCEN_Pos)            /*!< 0x00000020 */
#define USART_CR3_SCEN                USART_CR3_SCEN_Msk                       /*!< SmartCard mode enable */
#define USART_CR3_DMAR_Pos            (6U)
#define USART_CR3_DMAR_Msk            (0x1UL << USART_CR3_DMAR_Pos)            /*!< 0x00000040 */
#define USART_CR3_DMAR                USART_CR3_DMAR_Msk                       /*!< DMA Enable Receiver */
#define USART_CR3_DMAT_Pos            (7U)
#define USART_CR3_DMAT_Msk            (0x1UL << USART_CR3_DMAT_Pos)            /*!< 0x00000080 */
#define USART_CR3_DMAT                USART_CR3_DMAT_Msk                       /*!< DMA Enable Transmitter */
#define USART_CR3_RTSE_Pos            (8U)
#define USART_CR3_RTSE_Msk            (0x1UL << USART_CR3_RTSE_Pos)            /*!< 0x00000100 */
#define USART_CR3_RTSE                USART_CR3_RTSE_Msk                       /*!< RTS Enable */
#define USART_CR3_CTSE_Pos            (9U)
#define USART_CR3_CTSE_Msk            (0x1UL << USART_CR3_CTSE_Pos)            /*!< 0x00000200 */
#define USART_CR3_CTSE                USART_CR3_CTSE_Msk                       /*!< CTS Enable */
#define USART_CR3_CTSIE_Pos           (10U)
#define USART_CR3_CTSIE_Msk           (0x1UL << USART_CR3_CTSIE_Pos)           /*!< 0x00000400 */
#define USART_CR3_CTSIE               USART_CR3_CTSIE_Msk                      /*!< CTS Interrupt Enable */
#define USART_CR3_ONEBIT_Pos          (11U)
#define USART_CR3_ONEBIT_Msk          (0x1UL << USART_CR3_ONEBIT_Pos)          /*!< 0x00000800 */
#define USART_CR3_ONEBIT              USART_CR3_ONEBIT_Msk                     /*!< One sample bit method enable */
#define USART_CR3_OVRDIS_Pos          (12U)
#define USART_CR3_OVRDIS_Msk          (0x1UL << USART_CR3_OVRDIS_Pos)          /*!< 0x00001000 */
#define USART_CR3_OVRDIS              USART_CR3_OVRDIS_Msk                     /*!< Overrun Disable */
#define USART_CR3_DDRE_Pos            (13U)
#define USART_CR3_DDRE_Msk            (0x1UL << USART_CR3_DDRE_Pos)            /*!< 0x00002000 */
#define USART_CR3_DDRE                USART_CR3_DDRE_Msk                       /*!< DMA Disable on Reception Error */
#define USART_CR3_DEM_Pos             (14U)
#define USART_CR3_DEM_Msk             (0x1UL << USART_CR3_DEM_Pos)             /*!< 0x00004000 */
#define USART_CR3_DEM                 USART_CR3_DEM_Msk                        /*!< Driver Enable Mode */
#define USART_CR3_DEP_Pos             (15U)
#define USART_CR3_DEP_Msk             (0x1UL << USART_CR3_DEP_Pos)             /*!< 0x00008000 */
#define USART_CR3_DEP                 USART_CR3_DEP_Msk                        /*!< Driver Enable Polarity Selection */
#define USART_CR3_SCARCNT_Pos         (17U)
#define USART_CR3_SCARCNT_Msk         (0x7UL << USART_CR3_SCARCNT_Pos)         /*!< 0x000E0000 */
#define USART_CR3_SCARCNT             USART_CR3_SCARCNT_Msk                    /*!< SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
#define USART_CR3_SCARCNT_0           (0x1UL << USART_CR3_SCARCNT_Pos)         /*!< 0x00020000 */
#define USART_CR3_SCARCNT_1           (0x2UL << USART_CR3_SCARCNT_Pos)         /*!< 0x00040000 */
#define USART_CR3_SCARCNT_2           (0x4UL << USART_CR3_SCARCNT_Pos)         /*!< 0x00080000 */
#define USART_CR3_WUS_Pos             (20U)
#define USART_CR3_WUS_Msk             (0x3UL << USART_CR3_WUS_Pos)             /*!< 0x00300000 */
#define USART_CR3_WUS                 USART_CR3_WUS_Msk                        /*!< WUS[1:0] bits (Wake UP Interrupt Flag Selection) */
#define USART_CR3_WUS_0               (0x1UL << USART_CR3_WUS_Pos)             /*!< 0x00100000 */
#define USART_CR3_WUS_1               (0x2UL << USART_CR3_WUS_Pos)             /*!< 0x00200000 */
#define USART_CR3_WUFIE_Pos           (22U)
#define USART_CR3_WUFIE_Msk           (0x1UL << USART_CR3_WUFIE_Pos)           /*!< 0x00400000 */
#define USART_CR3_WUFIE               USART_CR3_WUFIE_Msk                      /*!< Wake Up Interrupt Enable */
#define USART_CR3_UCESM_Pos           (23U)
#define USART_CR3_UCESM_Msk           (0x1UL << USART_CR3_UCESM_Pos)           /*!< 0x02000000 */
#define USART_CR3_UCESM               USART_CR3_UCESM_Msk                      /*!< USART Clock enable in Stop mode */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_BRR_Pos             (0U)
#define USART_BRR_BRR_Msk             (0xFFFFUL << USART_BRR_BRR_Pos)          /*!< 0x0000FFFF */
#define USART_BRR_BRR                 USART_BRR_BRR_Msk                        /*!< USARTDIV */
#define USART_BRR_DIV_FRACTION_Pos    (0U)
#define USART_BRR_DIV_FRACTION_Msk    (0xFUL << USART_BRR_DIV_FRACTION_Pos)    /*!< 0x0000000F */
#define USART_BRR_DIV_FRACTION        USART_BRR_DIV_FRACTION_Msk               /*!< Fraction of USARTDIV */
#define USART_BRR_DIV_MANTISSA_Pos    (4U)
#define USART_BRR_DIV_MANTISSA_Msk    (0xFFFUL << USART_BRR_DIV_MANTISSA_Pos)  /*!< 0x0000FFF0 */
#define USART_BRR_DIV_MANTISSA        USART_BRR_DIV_MANTISSA_Msk               /*!< Mantissa of USARTDIV */

/******************  Bit definition for USART_GTPR register  ******************/
#define USART_GTPR_PSC_Pos            (0U)
#define USART_GTPR_PSC_Msk            (0xFFUL << USART_GTPR_PSC_Pos)           /*!< 0x000000FF */
#define USART_GTPR_PSC                USART_GTPR_PSC_Msk                       /*!< PSC[7:0] bits (Prescaler value) */
#define USART_GTPR_GT_Pos             (8U)
#define USART_GTPR_GT_Msk             (0xFFUL << USART_GTPR_GT_Pos)            /*!< 0x0000FF00 */
#define USART_GTPR_GT                 USART_GTPR_GT_Msk                        /*!< GT[7:0] bits (Guard time value) */

/*******************  Bit definition for USART_RTOR register  *****************/
#define USART_RTOR_RTO_Pos            (0U)
#define USART_RTOR_RTO_Msk            (0xFFFFFFUL << USART_RTOR_RTO_Pos)       /*!< 0x00FFFFFF */
#define USART_RTOR_RTO                USART_RTOR_RTO_Msk                       /*!< Receiver Time Out Value */
#define USART_RTOR_BLEN_Pos           (24U)
#define USART_RTOR_BLEN_Msk           (0xFFUL << USART_RTOR_BLEN_Pos)          /*!< 0xFF000000 */
#define USART_RTOR_BLEN               USART_RTOR_BLEN_Msk                      /*!< Block Length */

/*******************  Bit definition for USART_RQR register  ******************/
#define USART_RQR_ABRRQ_Pos           (0U)
#define USART_RQR_ABRRQ_Msk           (0x1UL << USART_RQR_ABRRQ_Pos)           /*!< 0x00000001 */
#define USART_RQR_ABRRQ               USART_RQR_ABRRQ_Msk                      /*!< Auto-Baud Rate Request */
#define USART_RQR_SBKRQ_Pos           (1U)
#define USART_RQR_SBKRQ_Msk           (0x1UL << USART_RQR_SBKRQ_Pos)           /*!< 0x00000002 */
#define USART_RQR_SBKRQ               USART_RQR_SBKRQ_Msk                      /*!< Send Break Request */
#define USART_RQR_MMRQ_Pos            (2U)
#define USART_RQR_MMRQ_Msk            (0x1UL << USART_RQR_MMRQ_Pos)            /*!< 0x00000004 */
#define USART_RQR_MMRQ                USART_RQR_MMRQ_Msk                       /*!< Mute Mode Request */
#define USART_RQR_RXFRQ_Pos           (3U)
#define USART_RQR_RXFRQ_Msk           (0x1UL << USART_RQR_RXFRQ_Pos)           /*!< 0x00000008 */
#define USART_RQR_RXFRQ               USART_RQR_RXFRQ_Msk                      /*!< Receive Data flush Request */
#define USART_RQR_TXFRQ_Pos           (4U)
#define USART_RQR_TXFRQ_Msk           (0x1UL << USART_RQR_TXFRQ_Pos)           /*!< 0x00000010 */
#define USART_RQR_TXFRQ               USART_RQR_TXFRQ_Msk                      /*!< Transmit data flush Request */

/*******************  Bit definition for USART_ISR register  ******************/
#define USART_ISR_PE_Pos              (0U)
#define USART_ISR_PE_Msk              (0x1UL << USART_ISR_PE_Pos)              /*!< 0x00000001 */
#define USART_ISR_PE                  USART_ISR_PE_Msk                         /*!< Parity Error */
#define USART_ISR_FE_Pos              (1U)
#define USART_ISR_FE_Msk              (0x1UL << USART_ISR_FE_Pos)              /*!< 0x00000002 */
#define USART_ISR_FE                  USART_ISR_FE_Msk                         /*!< Framing Error */
#define USART_ISR_NE_Pos              (2U)
#define USART_ISR_NE_Msk              (0x1UL << USART_ISR_NE_Pos)              /*!< 0x00000004 */
#define USART_ISR_NE                  USART_ISR_NE_Msk                         /*!< Noise Error detected Flag */
#define USART_ISR_ORE_Pos             (3U)
#define USART_ISR_ORE_Msk             (0x1UL << USART_ISR_ORE_Pos)             /*!< 0x00000008 */
#define USART_ISR_ORE                 USART_ISR_ORE_Msk                        /*!< OverRun Error */
#define USART_ISR_IDLE_Pos            (4U)
#define USART_ISR_IDLE_Msk            (0x1UL << USART_ISR_IDLE_Pos)            /*!< 0x00000010 */
#define USART_ISR_IDLE                USART_ISR_IDLE_Msk                       /*!< IDLE line detected */
#define USART_ISR_RXNE_Pos            (5U)
#define USART_ISR_RXNE_Msk            (0x1UL << USART_ISR_RXNE_Pos)            /*!< 0x00000020 */
#define USART_ISR_RXNE                USART_ISR_RXNE_Msk                       /*!< Read Data Register Not Empty */
#define USART_ISR_TC_Pos              (6U)
#define USART_ISR_TC_Msk              (0x1UL << USART_ISR_TC_Pos)              /*!< 0x00000040 */
#define USART_ISR_TC                  USART_ISR_TC_Msk                         /*!< Transmission Complete */
#define USART_ISR_TXE_Pos             (7U)
#define USART_ISR_TXE_Msk             (0x1UL << USART_ISR_TXE_Pos)             /*!< 0x00000080 */
#define USART_ISR_TXE                 USART_ISR_TXE_Msk                        /*!< Transmit Data Register Empty */
#define USART_ISR_LBDF_Pos            (8U)
#define USART_ISR_LBDF_Msk            (0x1UL << USART_ISR_LBDF_Pos)            /*!< 0x00000100 */
#define USART_ISR_LBDF                USART_ISR_LBDF_Msk                       /*!< LIN Break Detection Flag */
#define USART_ISR_CTSIF_Pos           (9U)
#define USART_ISR_CTSIF_Msk           (0x1UL << USART_ISR_CTSIF_Pos)           /*!< 0x00000200 */
#define USART_ISR_CTSIF               USART_ISR_CTSIF_Msk                      /*!< CTS interrupt flag */
#define USART_ISR_CTS_Pos             (10U)
#define USART_ISR_CTS_Msk             (0x1UL << USART_ISR_CTS_Pos)             /*!< 0x00000400 */
#define USART_ISR_CTS                 USART_ISR_CTS_Msk                        /*!< CTS flag */
#define USART_ISR_RTOF_Pos            (11U)
#define USART_ISR_RTOF_Msk            (0x1UL << USART_ISR_RTOF_Pos)            /*!< 0x00000800 */
#define USART_ISR_RTOF                USART_ISR_RTOF_Msk                       /*!< Receiver Time Out */
#define USART_ISR_EOBF_Pos            (12U)
#define USART_ISR_EOBF_Msk            (0x1UL << USART_ISR_EOBF_Pos)            /*!< 0x00001000 */
#define USART_ISR_EOBF                USART_ISR_EOBF_Msk                       /*!< End Of Block Flag */
#define USART_ISR_ABRE_Pos            (14U)
#define USART_ISR_ABRE_Msk            (0x1UL << USART_ISR_ABRE_Pos)            /*!< 0x00004000 */
#define USART_ISR_ABRE                USART_ISR_ABRE_Msk                       /*!< Auto-Baud Rate Error */
#define USART_ISR_ABRF_Pos            (15U)
#define USART_ISR_ABRF_Msk            (0x1UL << USART_ISR_ABRF_Pos)            /*!< 0x00008000 */
#define USART_ISR_ABRF                USART_ISR_ABRF_Msk                       /*!< Auto-Baud Rate Flag */
#define USART_ISR_BUSY_Pos            (16U)
#define USART_ISR_BUSY_Msk            (0x1UL << USART_ISR_BUSY_Pos)            /*!< 0x00010000 */
#define USART_ISR_BUSY                USART_ISR_BUSY_Msk                       /*!< Busy Flag */
#define USART_ISR_CMF_Pos             (17U)
#define USART_ISR_CMF_Msk             (0x1UL << USART_ISR_CMF_Pos)             /*!< 0x00020000 */
#define USART_ISR_CMF                 USART_ISR_CMF_Msk                        /*!< Character Match Flag */
#define USART_ISR_SBKF_Pos            (18U)
#define USART_ISR_SBKF_Msk            (0x1UL << USART_ISR_SBKF_Pos)            /*!< 0x00040000 */
#define USART_ISR_SBKF                USART_ISR_SBKF_Msk                       /*!< Send Break Flag */
#define USART_ISR_RWU_Pos             (19U)
#define USART_ISR_RWU_Msk             (0x1UL << USART_ISR_RWU_Pos)             /*!< 0x00080000 */
#define USART_ISR_RWU                 USART_ISR_RWU_Msk                        /*!< Receive Wake Up from mute mode Flag */
#define USART_ISR_WUF_Pos             (20U)
#define USART_ISR_WUF_Msk             (0x1UL << USART_ISR_WUF_Pos)             /*!< 0x00100000 */
#define USART_ISR_WUF                 USART_ISR_WUF_Msk                        /*!< Wake Up from stop mode Flag */
#define USART_ISR_TEACK_Pos           (21U)
#define USART_ISR_TEACK_Msk           (0x1UL << USART_ISR_TEACK_Pos)           /*!< 0x00200000 */
#define USART_ISR_TEACK               USART_ISR_TEACK_Msk                      /*!< Transmit Enable Acknowledge Flag */
#define USART_ISR_REACK_Pos           (22U)
#define USART_ISR_REACK_Msk           (0x1UL << USART_ISR_REACK_Pos)           /*!< 0x00400000 */
#define USART_ISR_REACK               USART_ISR_REACK_Msk                      /*!< Receive Enable Acknowledge Flag */

/*******************  Bit definition for USART_ICR register  ******************/
#define USART_ICR_PECF_Pos            (0U)
#define USART_ICR_PECF_Msk            (0x1UL << USART_ICR_PECF_Pos)            /*!< 0x00000001 */
#define USART_ICR_PECF                USART_ICR_PECF_Msk                       /*!< Parity Error Clear Flag */
#define USART_ICR_FECF_Pos            (1U)
#define USART_ICR_FECF_Msk            (0x1UL << USART_ICR_FECF_Pos)            /*!< 0x00000002 */
#define USART_ICR_FECF                USART_ICR_FECF_Msk                       /*!< Framing Error Clear Flag */
#define USART_ICR_NECF_Pos            (2U)
#define USART_ICR_NECF_Msk            (0x1UL << USART_ICR_NECF_Pos)            /*!< 0x00000004 */
#define USART_ICR_NECF                USART_ICR_NECF_Msk                       /*!< Noise Error detected Clear Flag */
#define USART_ICR_ORECF_Pos           (3U)
#define USART_ICR_ORECF_Msk           (0x1UL << USART_ICR_ORECF_Pos)           /*!< 0x00000008 */
#define USART_ICR_ORECF               USART_ICR_ORECF_Msk                      /*!< OverRun Error Clear Flag */
#define USART_ICR_IDLECF_Pos          (4U)
#define USART_ICR_IDLECF_Msk          (0x1UL << USART_ICR_IDLECF_Pos)          /*!< 0x00000010 */
#define USART_ICR_IDLECF              USART_ICR_IDLECF_Msk                     /*!< IDLE line detected Clear Flag */
#define USART_ICR_TCCF_Pos            (6U)
#define USART_ICR_TCCF_Msk            (0x1UL << USART_ICR_TCCF_Pos)            /*!< 0x00000040 */
#define USART_ICR_TCCF                USART_ICR_TCCF_Msk                       /*!< Transmission Complete Clear Flag */
#define USART_ICR_LBDCF_Pos           (8U)
#define USART_ICR_LBDCF_Msk           (0x1UL << USART_ICR_LBDCF_Pos)           /*!< 0x00000100 */
#define USART_ICR_LBDCF               USART_ICR_LBDCF_Msk                      /*!< LIN Break Detection Clear Flag */
#define USART_ICR_CTSCF_Pos           (9U)
#define USART_ICR_CTSCF_Msk           (0x1UL << USART_ICR_CTSCF_Pos)           /*!< 0x00000200 */
#define USART_ICR_CTSCF               USART_ICR_CTSCF_Msk                      /*!< CTS Interrupt Clear Flag */
#define USART_ICR_RTOCF_Pos           (11U)
#define USART_ICR_RTOCF_Msk           (0x1UL << USART_ICR_RTOCF_Pos)           /*!< 0x00000800 */
#define USART_ICR_RTOCF               USART_ICR_RTOCF_Msk                      /*!< Receiver Time Out Clear Flag */
#define USART_ICR_EOBCF_Pos           (12U)
#define USART_ICR_EOBCF_Msk           (0x1UL << USART_ICR_EOBCF_Pos)           /*!< 0x00001000 */
#define USART_ICR_EOBCF               USART_ICR_EOBCF_Msk                      /*!< End Of Block Clear Flag */
#define USART_ICR_CMCF_Pos            (17U)
#define USART_ICR_CMCF_Msk            (0x1UL << USART_ICR_CMCF_Pos)            /*!< 0x00020000 */
#define USART_ICR_CMCF                USART_ICR_CMCF_Msk                       /*!< Character Match Clear Flag */
#define USART_ICR_WUCF_Pos            (20U)
#define USART_ICR_WUCF_Msk            (0x1UL << USART_ICR_WUCF_Pos)            /*!< 0x00100000 */
#define USART_ICR_WUCF                USART_ICR_WUCF_Msk                       /*!< Wake Up from stop mode Clear Flag */

/* Legacy defines */
#define USART_ICR_NCF_Pos             USART_ICR_NECF_Pos
#define USART_ICR_NCF_Msk             USART_ICR_NECF_Msk
#define USART_ICR_NCF                 USART_ICR_NECF

/*******************  Bit definition for USART_RDR register  ******************/
#define USART_RDR_RDR_Pos             (0U)
#define USART_RDR_RDR_Msk             (0x1FFUL << USART_RDR_RDR_Pos)           /*!< 0x000001FF */
#define USART_RDR_RDR                 USART_RDR_RDR_Msk                        /*!< RDR[8:0] bits (Receive Data value) */

/*******************  Bit definition for USART_TDR register  ******************/
#define USART_TDR_TDR_Pos             (0U)
#define USART_TDR_TDR_Msk             (0x1FFUL << USART_TDR_TDR_Pos)           /*!< 0x000001FF */
#define USART_TDR_TDR                 USART_TDR_TDR_Msk                        /*!< TDR[8:0] bits (Transmit Data value) */

void hw_usart_set_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_stop_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_stop_mode_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_stop_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_receiver_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_receiver_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_receiver_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_transmitter_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_transmitter_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_transmitter_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_idle_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_idle_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_idle_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_m1(struct USART_TypeDef* USARTx, uint32_t m1);
uint32_t hw_usart_get_m1(struct USART_TypeDef* USARTx);
void hw_usart_set_end_of_block_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_end_of_block_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_end_of_block_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_receiver_timeout_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_receiver_timeout_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_receiver_timeout_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_driver_enable_assertion_time(struct USART_TypeDef* USARTx, uint32_t time);
uint32_t hw_usart_get_driver_enable_assertion_time(struct USART_TypeDef* USARTx);
void hw_usart_set_driver_enable_de_assertion_time(struct USART_TypeDef* USARTx, uint32_t time);
uint32_t hw_usart_get_driver_enable_de_assertion_time(struct USART_TypeDef* USARTx);
void hw_usart_set_oversampling_mode(struct USART_TypeDef* USARTx, uint32_t mode);
uint32_t hw_usart_get_oversampling_mode(struct USART_TypeDef* USARTx);
void hw_usart_set_character_match_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_character_match_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_character_match_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_mute_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_mute_mode_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_mute_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_m0(struct USART_TypeDef* USARTx, uint32_t m0);
uint32_t hw_usart_get_m0(struct USART_TypeDef* USARTx);
void hw_usart_set_receiver_wakeup_method(struct USART_TypeDef* USARTx, uint32_t method);
uint32_t hw_usart_receiver_wakeup_method(struct USART_TypeDef* USARTx);
void hw_usart_set_parity_control_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_parity_control_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_parity_control_enable(struct USART_TypeDef* USARTx);
void hw_usart_parity_selection(struct USART_TypeDef* USARTx, uint32_t parity);
uint32_t hw_usart_parity(struct USART_TypeDef* USARTx);
void hw_usart_set_pe_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_pe_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_pe_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_transmission_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_transmission_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_transmission_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_transmission_complete_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_transmission_complete_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_transmission_complete_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_rxne_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_rxne_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_rxne_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_address_of_node(struct USART_TypeDef* USARTx, uint32_t node);
uint32_t hw_usart_get_address_of_node(struct USART_TypeDef* USARTx);
void hw_usart_set_receiver_timeout_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_receiver_timeout_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_receiver_timeout_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_auto_baud_rate_mode(struct USART_TypeDef* USARTx, uint32_t mode);
uint32_t hw_usart_get_auto_baud_rate_mode(struct USART_TypeDef* USARTx);
void hw_usart_set_auto_baud_rate_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_auto_baud_rate_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_auto_baud_rate_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_most_significant_bit_first(struct USART_TypeDef* USARTx, uint32_t bit);
uint32_t hw_usart_get_most_significant_bit_first(struct USART_TypeDef* USARTx);
void hw_usart_set_binary_data_inversion(struct USART_TypeDef* USARTx, uint32_t inversion);
uint32_t hw_usart_get_binary_data_inversion(struct USART_TypeDef* USARTx);
void hw_usart_set_tx_pin_active_level_inversion(struct USART_TypeDef* USARTx, uint32_t inversion);
uint32_t hw_usart_get_tx_pin_active_level_inversion(struct USART_TypeDef* USARTx);
void hw_usart_set_rx_pin_active_level_inversion(struct USART_TypeDef* USARTx, uint32_t inversion);
uint32_t hw_usart_get_rx_pin_active_level_inversion(struct USART_TypeDef* USARTx);
void hw_usart_set_swap_rx_tx(struct USART_TypeDef* USARTx, uint32_t swap);
uint32_t hw_usart_get_swap_rx_tx(struct USART_TypeDef* USARTx);
void hw_usart_set_lin_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_lin_mode_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_lin_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_stop_bit(struct USART_TypeDef* USARTx, uint32_t stop_bit);
uint32_t hw_usart_get_stop_bit(struct USART_TypeDef* USARTx);
void hw_usart_set_clock_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_clock_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_clock_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_clock_polarity(struct USART_TypeDef* USARTx, uint32_t polarity);
uint32_t hw_usart_get_clock_polarity(struct USART_TypeDef* USARTx);
void hw_usart_set_clock_phase(struct USART_TypeDef* USARTx, uint32_t phase);
uint32_t hw_usart_get_clock_phase(struct USART_TypeDef* USARTx);
void hw_usart_set_last_bit_clock_pulse(struct USART_TypeDef* USARTx, uint32_t pulse);
uint32_t hw_usart_get_last_bit_clock_pulse(struct USART_TypeDef* USARTx);
void hw_usart_set_lin_break_detection_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_lin_break_detection_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_lin_break_detection_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_lin_break_detection_length(struct USART_TypeDef* USARTx, uint32_t length);
uint32_t hw_usart_get_lin_break_detection_length(struct USART_TypeDef* USARTx);
void hw_usart_set_address_detection_mode(struct USART_TypeDef* USARTx, uint32_t mode);
uint32_t hw_usart_get_address_detection_mode(struct USART_TypeDef* USARTx);
void hw_usart_set_clock_enable_in_stop_mode(struct USART_TypeDef* USARTx);
void hw_usart_set_clock_disable_in_stop_mode(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_clock_enable_in_stop_mode(struct USART_TypeDef* USARTx);
void hw_usart_set_wakeup_from_stop_mode_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_wakeup_from_stop_mode_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_wakeup_from_stop_mode_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_wakeup_from_stop_mode_interrupt_flag(struct USART_TypeDef* USARTx, uint32_t flag);
uint32_t hw_usart_get_wakeup_from_stop_mode_interrupt_flag(struct USART_TypeDef* USARTx);
void hw_usart_set_smartcard_auto_retry_count(struct USART_TypeDef* USARTx, uint32_t count);
uint32_t hw_usart_get_smartcard_auto_retry_count(struct USART_TypeDef* USARTx);
void hw_usart_set_driver_enable_polarity(struct USART_TypeDef* USARTx, uint32_t mode);
uint32_t hw_usart_get_driver_enable_polarity(struct USART_TypeDef* USARTx);
void hw_usart_set_de_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_de_mode_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_de_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_dma_disable_on_reception_error(struct USART_TypeDef* USARTx, uint32_t mode);
uint32_t hw_usart_get_dma_disable_on_reception_error(struct USART_TypeDef* USARTx);
void hw_usart_set_overrun_disable(struct USART_TypeDef* USARTx, uint32_t mode);
uint32_t hw_usart_get_overrun_disable(struct USART_TypeDef* USARTx);
void hw_usart_set_sample_bit_method(struct USART_TypeDef* USARTx, uint32_t method);
uint32_t hw_usart_get_sample_bit_method(struct USART_TypeDef* USARTx);
void hw_usart_set_cts_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_cts_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_cts_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_cts_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_cts_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_cts_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_rts_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_rts_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_rts_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_dma_transmitter_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_dma_transmitter_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_dma_transmitter_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_dma_receiver_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_dma_receiver_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_dma_receiver_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_smartcard_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_smartcard_mode_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_smartcard_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_smartcard_nack_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_smartcard_nack_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_smartcard_nack_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_half_duplex_mode(struct USART_TypeDef* USARTx, uint32_t mode);
uint32_t hw_usart_get_half_duplex_mode(struct USART_TypeDef* USARTx);
void hw_usart_set_irda_mode(struct USART_TypeDef* USARTx, uint32_t mode);
uint32_t hw_usart_get_irda_mode(struct USART_TypeDef* USARTx);
void hw_usart_set_irda_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_irda_mode_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_irda_mode_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_error_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_error_interrupt_disable(struct USART_TypeDef* USARTx);
uint32_t hw_usart_get_error_interrupt_enable(struct USART_TypeDef* USARTx);
void hw_usart_set_baud_rate(struct USART_TypeDef* USARTx, uint32_t baud_rate);
uint32_t hw_usart_get_baud_rate(struct USART_TypeDef* USARTx);
void hw_usart_set_guard_time(struct USART_TypeDef* USARTx, uint16_t time);
uint32_t hw_usart_get_guard_time(struct USART_TypeDef* USARTx);
void hw_usart_set_prescaler_value(struct USART_TypeDef* USARTx, uint16_t prescaler);
uint32_t hw_usart_get_prescaler_value(struct USART_TypeDef* USARTx);
void hw_usart_set_block_length(struct USART_TypeDef* USARTx, uint16_t length);
uint32_t hw_usart_get_block_length(struct USART_TypeDef* USARTx);
void hw_usart_set_receiver_timeout_value(struct USART_TypeDef* USARTx, uint16_t timeout);
uint32_t hw_usart_get_receiver_timeout_value(struct USART_TypeDef* USARTx);
void hw_usart_set_auto_baud_rate_request(struct USART_TypeDef* USARTx);
void hw_usart_set_send_break_request(struct USART_TypeDef* USARTx);
void hw_usart_set_mute_mode_request(struct USART_TypeDef* USARTx);
void hw_usart_set_receive_data_flush_request(struct USART_TypeDef* USARTx);
void hw_usart_set_transmit_data_flush_request(struct USART_TypeDef* USARTx);
uint32_t hw_usart_parity_error_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_framing_error_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_start_bit_noise_detection_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_overrun_error_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_idle_line_detected_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_read_data_register_not_empty_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_transmission_complete_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_transmit_data_register_empty_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_lin_break_detection_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_cts_interrupt_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_cts_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_receiver_timeout_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_end_of_block_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_auto_baud_rate_error_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_auto_baud_rate_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_busy_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_character_match_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_send_break_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_receiver_wakeup_from_mute_mode_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_wakeup_from_stop_mode_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_transmit_enable_acknowledge_flag(struct USART_TypeDef* USARTx);
uint32_t hw_usart_receive_enable_acknowledge_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_wakeup_from_stop_mode_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_character_match_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_end_of_block_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_receiver_timeout_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_cts_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_lin_break_detection_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_transmission_complete_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_idle_line_detected_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_overrun_error_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_noise_detected_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_framing_error_flag(struct USART_TypeDef* USARTx);
void hw_usart_clear_parity_error_flag(struct USART_TypeDef* USARTx);
uint8_t hw_usart_receive_data(struct USART_TypeDef* USARTx);
void hw_usart_transmit_data(struct USART_TypeDef* USARTx, const uint8_t data);

#ifdef __cplusplus
}
#endif

#endif