#include "common.h"
#include "hw_usart.h"

struct USART_TypeDef
{
    __IO uint16_t SR;
    uint16_t  RESERVED0;
    __IO uint16_t DR;
    uint16_t  RESERVED1;
    __IO uint16_t BRR;
    uint16_t  RESERVED2;
    __IO uint16_t CR1;
    uint16_t  RESERVED3;
    __IO uint16_t CR2;
    uint16_t  RESERVED4;
    __IO uint16_t CR3;
    uint16_t  RESERVED5;
    __IO uint16_t GTPR;
    uint16_t  RESERVED6;
};

#define USART1              ((struct USART_TypeDef *) USART1_BASE)
#define USART2              ((struct USART_TypeDef *) USART2_BASE)
#define USART3              ((struct USART_TypeDef *) USART3_BASE)

static inline struct USART_TypeDef* __GET_USART1_REGISTER__(void)
{
    return USART1;
}

static inline struct USART_TypeDef* __GET_USART2_REGISTER__(void)
{
    return USART2;
}

static inline struct USART_TypeDef* __GET_USART3_REGISTER__(void)
{
    return USART3;
}

#define __GET_USART_REGISTER__(usart) __GET_##usart##_REGISTER__()

#define __GET_USART_SR__(USARTx)            (USARTx->SR)
#define __GET_USART_DR__(USARTx)            (USARTx->DR)
#define __GET_USART_BRR__(USARTx)           (USARTx->BRR)
#define __GET_USART_CR1__(USARTx)           (USARTx->CR1)
#define __GET_USART_CR2__(USARTx)           (USARTx->CR2)
#define __GET_USART_CR3__(USARTx)           (USARTx->CR3)
#define __GET_USART_GTPR__(USARTx)          (USARTx->GTPR)

#define USART_SR_TXE        ((uint16_t)0x0080)
#define USART_SR_RXNE       ((uint16_t)0x0020)
#define USART_SR_ORE        ((uint16_t)0x0008)

#define USART_CR1_UE        ((uint16_t)0x2000)
#define USART_CR1_M         ((uint16_t)0x1000)
#define USART_CR1_PCE       ((uint16_t)0x0400)
#define USART_CR1_PS        ((uint16_t)0x0200)
#define USART_CR1_TE        ((uint16_t)0x0008)
#define USART_CR1_RE        ((uint16_t)0x0004)

#define USART_CR2_STOP      ((uint16_t)0x3000)

#define USART_CR3_RTSE      ((uint16_t)0x0100)

static struct USART_TypeDef* hw_usart_map[] = {
    USART1,
    USART2,
    USART3,
};
static struct USART_TypeDef* hw_get_usart_typedef(uint32_t usart)
{
    stm32_assert(usart >= sizeof(hw_usart_map)/sizeof(hw_usart_map[0]), "usart overflow");
    return hw_usart_map[usart];
}

static void hw_usart_set_enable(uint32_t usart, enum hw_usart_enable_e en)
{
    if(en == hw_usart_enable) {
        __BIT_OR__(__GET_USART_CR1__(hw_get_usart_typedef(usart)), USART_CR1_UE);
    } else {
        __BIT_RESET__(__GET_USART_CR1__(hw_get_usart_typedef(usart)), USART_CR1_UE);
    }
}
static uint32_t hw_usart_get_enable(uint32_t usart)
{
    return (__GET_USART_CR1__(hw_get_usart_typedef(usart)) & USART_CR1_UE);
}

static void hw_usart_set_baud_rate(uint32_t usart, uint32_t pclk, uint32_t baud_rate)
{
    uint32_t tmpreg = 0x00000000;
    uint32_t integerdivider = 0x00000000;
    uint32_t fractionaldivider = 0x00000000;

    /* Determine the integer part */
    integerdivider = ((0x19 * pclk) / (0x04 * (baud_rate)));
    tmpreg = (integerdivider / 0x64) << 0x04;
    /* Determine the fractional part */
    fractionaldivider = integerdivider - (0x64 * (tmpreg >> 0x04));
    tmpreg |= ((((fractionaldivider * 0x10) + 0x32) / 0x64)) & ((uint8_t)0x0F);
    /* Write to USART BRR */
    __BIT_SET__(__GET_USART_BRR__(hw_get_usart_typedef(usart)), (uint16_t)tmpreg); 
}

static void hw_usart_set_word_length(uint32_t usart, enum hw_usart_word_length_e wordLength)
{
    switch(wordLength) {
        case hw_usart_word_length_7bit:
            break;
        case hw_usart_word_length_8bit:
            __BIT_RESET__(__GET_USART_CR1__(hw_get_usart_typedef(usart)), USART_CR1_M);
            break;
        case hw_usart_word_length_9bit:
            __BIT_OR__(__GET_USART_CR1__(hw_get_usart_typedef(usart)), USART_CR1_M);
            break;
        default:
            break;
    }
}
static void hw_usart_set_parity_control(uint32_t usart, enum hw_usart_parity_control_e ctl)
{
    switch(ctl) {
        case hw_usart_parity_control_none:
            __BIT_COVER_SET__(__GET_USART_CR1__(hw_get_usart_typedef(usart)), USART_CR1_PCE | USART_CR1_PS, (uint16_t)0x0000);
            break;
        default:
            break;
    }
}
static void hw_usart_set_receiver_enable(uint32_t usart)
{
    __BIT_OR__(__GET_USART_CR1__(hw_get_usart_typedef(usart)), USART_CR1_RE);
}
static void hw_usart_set_transmitter_enable(uint32_t usart)
{
    __BIT_OR__(__GET_USART_CR1__(hw_get_usart_typedef(usart)), USART_CR1_TE);
}
static void hw_usart_set_stop_bits(uint32_t usart, enum hw_usart_stop_bits_e bits)
{
    switch(bits) {
        case hw_usart_stop_bits_0_5:
            __BIT_COVER_SET__(__GET_USART_CR2__(hw_get_usart_typedef(usart)), USART_CR2_STOP, ((uint16_t)0x1000));
            break;
        case hw_usart_stop_bits_1:
            __BIT_COVER_SET__(__GET_USART_CR2__(hw_get_usart_typedef(usart)), USART_CR2_STOP, ((uint16_t)0x0000));
            break;
        case hw_usart_stop_bits_1_5:
            __BIT_COVER_SET__(__GET_USART_CR2__(hw_get_usart_typedef(usart)), USART_CR2_STOP, ((uint16_t)0x3000));
            break;
        case hw_usart_stop_bits_2:
            __BIT_COVER_SET__(__GET_USART_CR2__(hw_get_usart_typedef(usart)), USART_CR2_STOP, ((uint16_t)0x2000));
            break;
        default:
            break;
    }
}
static void hw_usart_set_flow_control(uint32_t usart, enum hw_usart_flow_control_e ctl)
{
    switch(ctl) {
        case hw_usart_flow_control_none:
            __BIT_COVER_SET__(__GET_USART_CR3__(hw_get_usart_typedef(usart)), USART_CR3_RTSE, (uint16_t)0x0000);
            break;
        case hw_usart_flow_control_rts:
            __BIT_COVER_SET__(__GET_USART_CR3__(hw_get_usart_typedef(usart)), USART_CR3_RTSE, (uint16_t)0x0100);
            break;
        case hw_usart_flow_control_cts:
            __BIT_COVER_SET__(__GET_USART_CR3__(hw_get_usart_typedef(usart)), USART_CR3_RTSE, (uint16_t)0x0200);
            break;
        case hw_usart_flow_control_rts_cts:
            __BIT_COVER_SET__(__GET_USART_CR3__(hw_get_usart_typedef(usart)), USART_CR3_RTSE, (uint16_t)0x0300);
            break;
        default:
            break;
    }
}

static void hw_usart_send_data(uint32_t usart, const struct hw_usart_send_data_t* pData)
{
    for(uint32_t i = 0; i < pData->size; i++) {
        while((__GET_USART_SR__(hw_get_usart_typedef(usart)) & USART_SR_TXE) == (uint16_t)0x0000);        
        __BIT_SET__(__GET_USART_DR__(hw_get_usart_typedef(usart)),  pData->data[i]);
    }
}

static void hw_usart_recv_data(uint32_t usart, struct hw_usart_send_data_t* pData)
{
     for(uint32_t i = 0; i < pData->size; i++) {
         while((__GET_USART_SR__(hw_get_usart_typedef(usart)) & USART_SR_RXNE) == (uint16_t)0x0000);        
         pData->data[i] = (__GET_USART_DR__(hw_get_usart_typedef(usart)) & (uint16_t)0x01FF);
     }
}

static void hw_usart_fetch_data(uint32_t usart, int32_t* pData)
{
    if((__GET_USART_SR__(hw_get_usart_typedef(usart)) & USART_SR_RXNE) != (uint16_t)0x0000) {
        *pData = (__GET_USART_DR__(hw_get_usart_typedef(usart)) & (uint16_t)0x01FF);
    }
}

enum hw_platform_errcode_e hw_platform_usart_cmd(uint8_t type, WPARAM wParam, LPARAM lParam)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(type) {
        case HW_USART_CMD_SET_ENABLE:
            hw_usart_set_enable(wParam, lParam);
            break;
        case HW_USART_CMD_GET_ENABLE:
            *(enum hw_usart_enable_e *)lParam = hw_usart_get_enable(wParam);
            break;
        case HW_USART_CMD_SET_BAUD_RATE:
        {
            const struct hw_usart_baud_rate_t* baud = (const struct hw_usart_baud_rate_t *)lParam;
            hw_usart_set_baud_rate(wParam, baud->clk, baud->baud);
        }
            break;
        case HW_USART_CMD_SET_WORD_LENGTH:
            hw_usart_set_word_length(wParam, lParam);
            break;
        case HW_USART_CMD_SET_PARITY_CONTROL:
            hw_usart_set_parity_control(wParam, lParam);
            break;
        case HW_USART_CMD_SET_TRANSPORT_MODE:
            hw_usart_set_receiver_enable(wParam);
            hw_usart_set_transmitter_enable(wParam);
            break;
        case HW_USART_CMD_SET_STOP_BITS:
            hw_usart_set_stop_bits(wParam, lParam);
            break;
        case HW_USART_CMD_SET_FLOW_CONTROL:
            hw_usart_set_flow_control(wParam, lParam);
            break;
        case HW_USART_CMD_SEND_DATA:
            hw_usart_send_data(wParam, (const struct hw_usart_send_data_t *)lParam);
            break;
        case HW_USART_CMD_RECV_DATA:
            hw_usart_recv_data(wParam, (struct hw_usart_send_data_t *)lParam);
            break;
        case HW_USART_CMD_FETCH_DATA:
            hw_usart_fetch_data(wParam, (int32_t *)lParam);
            break;
        default:
            bRet = hw_platform_errcode_not_support;
            break;
    }
    return bRet;
}

