#include "common.h"
#include "hw_can.h"

typedef struct
{
    __IO uint32_t TIR;  /*!< CAN TX mailbox identifier register */
    __IO uint32_t TDTR; /*!< CAN mailbox data length control and time stamp register */
    __IO uint32_t TDLR; /*!< CAN mailbox data low register */
    __IO uint32_t TDHR; /*!< CAN mailbox data high register */
} CAN_TxMailBox_TypeDef;

typedef struct
{
  __IO uint32_t RIR;  /*!< CAN receive FIFO mailbox identifier register */
  __IO uint32_t RDTR; /*!< CAN receive FIFO mailbox data length control and time stamp register */
  __IO uint32_t RDLR; /*!< CAN receive FIFO mailbox data low register */
  __IO uint32_t RDHR; /*!< CAN receive FIFO mailbox data high register */
} CAN_FIFOMailBox_TypeDef;

typedef struct
{
  __IO uint32_t FR1; /*!< CAN Filter bank register 1 */
  __IO uint32_t FR2; /*!< CAN Filter bank register 2 */
} CAN_FilterRegister_TypeDef;

struct CAN_TypeDef
{
    __IO uint32_t              MCR;                 /*!< CAN master control register,         Address offset: 0x00          */
    __IO uint32_t              MSR;                 /*!< CAN master status register,          Address offset: 0x04          */
    __IO uint32_t              TSR;                 /*!< CAN transmit status register,        Address offset: 0x08          */
    __IO uint32_t              RF0R;                /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
    __IO uint32_t              RF1R;                /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
    __IO uint32_t              IER;                 /*!< CAN interrupt enable register,       Address offset: 0x14          */
    __IO uint32_t              ESR;                 /*!< CAN error status register,           Address offset: 0x18          */
    __IO uint32_t              BTR;                 /*!< CAN bit timing register,             Address offset: 0x1C          */
    uint32_t                   RESERVED0[88];       /*!< Reserved, 0x020 - 0x17F                                            */
    CAN_TxMailBox_TypeDef      sTxMailBox[3];       /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
    CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];     /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
    uint32_t                   RESERVED1[12];       /*!< Reserved, 0x1D0 - 0x1FF                                            */
    __IO uint32_t              FMR;                 /*!< CAN filter master register,          Address offset: 0x200         */
    __IO uint32_t              FM1R;                /*!< CAN filter mode register,            Address offset: 0x204         */
    uint32_t                   RESERVED2;           /*!< Reserved, 0x208                                                    */
    __IO uint32_t              FS1R;                /*!< CAN filter scale register,           Address offset: 0x20C         */
    uint32_t                   RESERVED3;           /*!< Reserved, 0x210                                                    */
    __IO uint32_t              FFA1R;               /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
    uint32_t                   RESERVED4;           /*!< Reserved, 0x218                                                    */
    __IO uint32_t              FA1R;                /*!< CAN filter activation register,      Address offset: 0x21C         */
    uint32_t                   RESERVED5[8];        /*!< Reserved, 0x220-0x23F                                              */
    CAN_FilterRegister_TypeDef sFilterRegister[28]; /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */
};

#define CAN1                   ((struct CAN_TypeDef *) CAN1_BASE)

#define __GET_CAN_MCR__(CANx)                   (CANx->MCR)
#define __GET_CAN_MSR__(CANx)                   (CANx->MSR)
#define __GET_CAN_TSR__(CANx)                   (CANx->TSR)
#define __GET_CAN_RF0R__(CANx)                  (CANx->RF0R)
#define __GET_CAN_RF1R__(CANx)                  (CANx->RF1R)
#define __GET_CAN_IER__(CANx)                   (CANx->IER)
#define __GET_CAN_ESR__(CANx)                   (CANx->ESR)
#define __GET_CAN_BTR__(CANx)                   (CANx->BTR)
#define __GET_CAN_sTxMailBox__(CANx, n)         (CANx->sTxMailBox[n])
#define __GET_CAN_sFIFOMailBox__(CANx, n)       (CANx->sFIFOMailBox[n])
#define __GET_CAN_FMR__(CANx)                   (CANx->FMR)
#define __GET_CAN_FM1R__(CANx)                  (CANx->FM1R)
#define __GET_CAN_FS1R__(CANx)                  (CANx->FS1R)
#define __GET_CAN_FFA1R__(CANx)                 (CANx->FFA1R)
#define __GET_CAN_FA1R__(CANx)                  (CANx->FA1R)
#define __GET_CAN_sFilterRegister__(CANx, n)    (CANx->sFilterRegister[n])

#define INAK_TIMEOUT        ((uint32_t)0x0000FFFF)

/*!< CAN control and status registers */
/*******************  Bit definition for CAN_MCR register  ********************/
#define  CAN_MCR_INRQ                        ((uint16_t)0x0001)            /*!< Initialization Request */
#define  CAN_MCR_SLEEP                       ((uint16_t)0x0002)            /*!< Sleep Mode Request */
#define  CAN_MCR_TXFP                        ((uint16_t)0x0004)            /*!< Transmit FIFO Priority */
#define  CAN_MCR_RFLM                        ((uint16_t)0x0008)            /*!< Receive FIFO Locked Mode */
#define  CAN_MCR_NART                        ((uint16_t)0x0010)            /*!< No Automatic Retransmission */
#define  CAN_MCR_AWUM                        ((uint16_t)0x0020)            /*!< Automatic Wakeup Mode */
#define  CAN_MCR_ABOM                        ((uint16_t)0x0040)            /*!< Automatic Bus-Off Management */
#define  CAN_MCR_TTCM                        ((uint16_t)0x0080)            /*!< Time Triggered Communication Mode */
#define  CAN_MCR_RESET                       ((uint16_t)0x8000)            /*!< CAN software master reset */

/*******************  Bit definition for CAN_MSR register  ********************/
#define  CAN_MSR_INAK                        ((uint16_t)0x0001)            /*!< Initialization Acknowledge */
#define  CAN_MSR_SLAK                        ((uint16_t)0x0002)            /*!< Sleep Acknowledge */
#define  CAN_MSR_ERRI                        ((uint16_t)0x0004)            /*!< Error Interrupt */
#define  CAN_MSR_WKUI                        ((uint16_t)0x0008)            /*!< Wakeup Interrupt */
#define  CAN_MSR_SLAKI                       ((uint16_t)0x0010)            /*!< Sleep Acknowledge Interrupt */
#define  CAN_MSR_TXM                         ((uint16_t)0x0100)            /*!< Transmit Mode */
#define  CAN_MSR_RXM                         ((uint16_t)0x0200)            /*!< Receive Mode */
#define  CAN_MSR_SAMP                        ((uint16_t)0x0400)            /*!< Last Sample Point */
#define  CAN_MSR_RX                          ((uint16_t)0x0800)            /*!< CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define  CAN_TSR_RQCP0                       ((uint32_t)0x00000001)        /*!< Request Completed Mailbox0 */
#define  CAN_TSR_TXOK0                       ((uint32_t)0x00000002)        /*!< Transmission OK of Mailbox0 */
#define  CAN_TSR_ALST0                       ((uint32_t)0x00000004)        /*!< Arbitration Lost for Mailbox0 */
#define  CAN_TSR_TERR0                       ((uint32_t)0x00000008)        /*!< Transmission Error of Mailbox0 */
#define  CAN_TSR_ABRQ0                       ((uint32_t)0x00000080)        /*!< Abort Request for Mailbox0 */
#define  CAN_TSR_RQCP1                       ((uint32_t)0x00000100)        /*!< Request Completed Mailbox1 */
#define  CAN_TSR_TXOK1                       ((uint32_t)0x00000200)        /*!< Transmission OK of Mailbox1 */
#define  CAN_TSR_ALST1                       ((uint32_t)0x00000400)        /*!< Arbitration Lost for Mailbox1 */
#define  CAN_TSR_TERR1                       ((uint32_t)0x00000800)        /*!< Transmission Error of Mailbox1 */
#define  CAN_TSR_ABRQ1                       ((uint32_t)0x00008000)        /*!< Abort Request for Mailbox 1 */
#define  CAN_TSR_RQCP2                       ((uint32_t)0x00010000)        /*!< Request Completed Mailbox2 */
#define  CAN_TSR_TXOK2                       ((uint32_t)0x00020000)        /*!< Transmission OK of Mailbox 2 */
#define  CAN_TSR_ALST2                       ((uint32_t)0x00040000)        /*!< Arbitration Lost for mailbox 2 */
#define  CAN_TSR_TERR2                       ((uint32_t)0x00080000)        /*!< Transmission Error of Mailbox 2 */
#define  CAN_TSR_ABRQ2                       ((uint32_t)0x00800000)        /*!< Abort Request for Mailbox 2 */
#define  CAN_TSR_CODE                        ((uint32_t)0x03000000)        /*!< Mailbox Code */

#define  CAN_TSR_TME                         ((uint32_t)0x1C000000)        /*!< TME[2:0] bits */
#define  CAN_TSR_TME0                        ((uint32_t)0x04000000)        /*!< Transmit Mailbox 0 Empty */
#define  CAN_TSR_TME1                        ((uint32_t)0x08000000)        /*!< Transmit Mailbox 1 Empty */
#define  CAN_TSR_TME2                        ((uint32_t)0x10000000)        /*!< Transmit Mailbox 2 Empty */

#define  CAN_TSR_LOW                         ((uint32_t)0xE0000000)        /*!< LOW[2:0] bits */
#define  CAN_TSR_LOW0                        ((uint32_t)0x20000000)        /*!< Lowest Priority Flag for Mailbox 0 */
#define  CAN_TSR_LOW1                        ((uint32_t)0x40000000)        /*!< Lowest Priority Flag for Mailbox 1 */
#define  CAN_TSR_LOW2                        ((uint32_t)0x80000000)        /*!< Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define  CAN_RF0R_FMP0                       ((uint8_t)0x03)               /*!< FIFO 0 Message Pending */
#define  CAN_RF0R_FULL0                      ((uint8_t)0x08)               /*!< FIFO 0 Full */
#define  CAN_RF0R_FOVR0                      ((uint8_t)0x10)               /*!< FIFO 0 Overrun */
#define  CAN_RF0R_RFOM0                      ((uint8_t)0x20)               /*!< Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define  CAN_RF1R_FMP1                       ((uint8_t)0x03)               /*!< FIFO 1 Message Pending */
#define  CAN_RF1R_FULL1                      ((uint8_t)0x08)               /*!< FIFO 1 Full */
#define  CAN_RF1R_FOVR1                      ((uint8_t)0x10)               /*!< FIFO 1 Overrun */
#define  CAN_RF1R_RFOM1                      ((uint8_t)0x20)               /*!< Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define  CAN_IER_TMEIE                       ((uint32_t)0x00000001)        /*!< Transmit Mailbox Empty Interrupt Enable */
#define  CAN_IER_FMPIE0                      ((uint32_t)0x00000002)        /*!< FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE0                       ((uint32_t)0x00000004)        /*!< FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE0                      ((uint32_t)0x00000008)        /*!< FIFO Overrun Interrupt Enable */
#define  CAN_IER_FMPIE1                      ((uint32_t)0x00000010)        /*!< FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE1                       ((uint32_t)0x00000020)        /*!< FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE1                      ((uint32_t)0x00000040)        /*!< FIFO Overrun Interrupt Enable */
#define  CAN_IER_EWGIE                       ((uint32_t)0x00000100)        /*!< Error Warning Interrupt Enable */
#define  CAN_IER_EPVIE                       ((uint32_t)0x00000200)        /*!< Error Passive Interrupt Enable */
#define  CAN_IER_BOFIE                       ((uint32_t)0x00000400)        /*!< Bus-Off Interrupt Enable */
#define  CAN_IER_LECIE                       ((uint32_t)0x00000800)        /*!< Last Error Code Interrupt Enable */
#define  CAN_IER_ERRIE                       ((uint32_t)0x00008000)        /*!< Error Interrupt Enable */
#define  CAN_IER_WKUIE                       ((uint32_t)0x00010000)        /*!< Wakeup Interrupt Enable */
#define  CAN_IER_SLKIE                       ((uint32_t)0x00020000)        /*!< Sleep Interrupt Enable */

/********************  Bit definition for CAN_ESR register  *******************/
#define  CAN_ESR_EWGF                        ((uint32_t)0x00000001)        /*!< Error Warning Flag */
#define  CAN_ESR_EPVF                        ((uint32_t)0x00000002)        /*!< Error Passive Flag */
#define  CAN_ESR_BOFF                        ((uint32_t)0x00000004)        /*!< Bus-Off Flag */

#define  CAN_ESR_LEC                         ((uint32_t)0x00000070)        /*!< LEC[2:0] bits (Last Error Code) */
#define  CAN_ESR_LEC_0                       ((uint32_t)0x00000010)        /*!< Bit 0 */
#define  CAN_ESR_LEC_1                       ((uint32_t)0x00000020)        /*!< Bit 1 */
#define  CAN_ESR_LEC_2                       ((uint32_t)0x00000040)        /*!< Bit 2 */

#define  CAN_ESR_TEC                         ((uint32_t)0x00FF0000)        /*!< Least significant byte of the 9-bit Transmit Error Counter */
#define  CAN_ESR_REC                         ((uint32_t)0xFF000000)        /*!< Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define  CAN_BTR_BRP                         ((uint32_t)0x000003FF)        /*!< Baud Rate Prescaler */
#define  CAN_BTR_TS1                         ((uint32_t)0x000F0000)        /*!< Time Segment 1 */
#define  CAN_BTR_TS2                         ((uint32_t)0x00700000)        /*!< Time Segment 2 */
#define  CAN_BTR_SJW                         ((uint32_t)0x03000000)        /*!< Resynchronization Jump Width */
#define  CAN_BTR_LBKM                        ((uint32_t)0x40000000)        /*!< Loop Back Mode (Debug) */
#define  CAN_BTR_SILM                        ((uint32_t)0x80000000)        /*!< Silent Mode */

#define TMIDxR_TXRQ  ((uint32_t)0x00000001) /* Transmit mailbox request */

static void hw_can_init(struct CAN_TypeDef* CANx)
{
    uint32_t wait_timeout = 0x00000000;
    __BIT_RESET__(__GET_CAN_MCR__(CANx), CAN_MCR_SLEEP);
    __BIT_OR__(__GET_CAN_MCR__(CANx), CAN_MCR_INRQ);
    while(((__GET_CAN_MCR__(CANx) & CAN_MSR_INAK) != CAN_MSR_INAK) && (wait_timeout != INAK_TIMEOUT)) {
        wait_timeout++;
    }

    if(((__GET_CAN_MCR__(CANx) & CAN_MSR_INAK) == CAN_MSR_INAK)) {
        __BIT_RESET__(__GET_CAN_MCR__(CANx), CAN_MCR_TTCM);
        __BIT_RESET__(__GET_CAN_MCR__(CANx), CAN_MCR_ABOM);
        __BIT_RESET__(__GET_CAN_MCR__(CANx), CAN_MCR_AWUM);
        __BIT_RESET__(__GET_CAN_MCR__(CANx), CAN_MCR_NART);
        __BIT_RESET__(__GET_CAN_MCR__(CANx), CAN_MCR_RFLM);
        __BIT_RESET__(__GET_CAN_MCR__(CANx), CAN_MCR_TXFP);
        
        __BIT_SET__(__GET_CAN_BTR__(CANx), 0x01350003);
        __BIT_RESET__(__GET_CAN_MCR__(CANx), CAN_MCR_INRQ);

        wait_timeout = 0x00000000;
        while(((__GET_CAN_MCR__(CANx) & CAN_MSR_INAK) == CAN_MSR_INAK) && (wait_timeout != INAK_TIMEOUT)) {
            wait_timeout++;
        }
    }
}
uint8_t hw_can_transmit(struct CAN_TypeDef* CANx, const struct hw_can_frame_t* message)
{
    uint8_t transmit_mailbox = 0x04;

    if((__GET_CAN_TSR__(CANx) & CAN_TSR_TME0) == CAN_TSR_TME0) {
        transmit_mailbox = 0;
    } else if((__GET_CAN_TSR__(CANx) & CAN_TSR_TME1) == CAN_TSR_TME1) {
        transmit_mailbox = 1;
    } else if((__GET_CAN_TSR__(CANx) & CAN_TSR_TME2) == CAN_TSR_TME2) {
        transmit_mailbox = 2;
    }
    if(transmit_mailbox != 0x04) {
        /* Set up the Id */
        CANx->sTxMailBox[transmit_mailbox].TIR &= TMIDxR_TXRQ;
        if (message->IDE == 0) {
            CANx->sTxMailBox[transmit_mailbox].TIR |= ((message->id << 21));
        } else {
            CANx->sTxMailBox[transmit_mailbox].TIR |= ((message->id << 3) | message->IDE);
        }

        /* Set up the DLC */
        CANx->sTxMailBox[transmit_mailbox].TDTR &= (uint32_t)0xFFFFFFF0;
        CANx->sTxMailBox[transmit_mailbox].TDTR |= (message->DLC & (uint8_t)0x0000000F);

        /* Set up the data field */
        CANx->sTxMailBox[transmit_mailbox].TDLR = (((uint32_t)message->DATA[3] << 24) | 
                                                ((uint32_t)message->DATA[2] << 16) |
                                                ((uint32_t)message->DATA[1] << 8) | 
                                                ((uint32_t)message->DATA[0]));
        CANx->sTxMailBox[transmit_mailbox].TDHR = (((uint32_t)message->DATA[7] << 24) | 
                                                ((uint32_t)message->DATA[6] << 16) |
                                                ((uint32_t)message->DATA[5] << 8) |
                                                ((uint32_t)message->DATA[4]));
        /* Request transmission */
        CANx->sTxMailBox[transmit_mailbox].TIR |= TMIDxR_TXRQ;
    }
    return transmit_mailbox;
}

enum hw_platform_errcode_e hw_platform_can_cmd(uint8_t type, WPARAM wParam, LPARAM lParam)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(type) {
        case HW_CAN_CMD_SET_PROP:
            hw_can_init(CAN1);
            break;
        case HW_CAN_CMD_GET_PROP:
            break;
        case HW_CAN_CMD_SEND_CMD:
            hw_can_transmit(CAN1, (const struct hw_can_frame_t *)wParam);
            break;
        default:
            bRet = hw_platform_errcode_not_support;
            break;
    }
    return bRet;
}
