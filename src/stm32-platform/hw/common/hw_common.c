#include "hw_common.h"

#define platform_send_cmd(d, t, w, l) d ## _cmd(t, w, l)
#define EXTERN_PLATFORM_SEND_CMD(d) extern enum hw_platform_errcode_e d ## _cmd(uint8_t type, WPARAM wParam, LPARAM lParam)

EXTERN_PLATFORM_SEND_CMD(hw_platform_gpio);
EXTERN_PLATFORM_SEND_CMD(hw_platform_systick);
EXTERN_PLATFORM_SEND_CMD(hw_platform_usart);
EXTERN_PLATFORM_SEND_CMD(hw_platform_nvic);
EXTERN_PLATFORM_SEND_CMD(hw_platform_rcc);
EXTERN_PLATFORM_SEND_CMD(hw_platform_can);

enum hw_platform_errcode_e hw_platform_send_cmd(enum hw_platform_type_e drive, uint8_t type, WPARAM wParam, LPARAM lParam)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(drive) {
        case hw_platform_gpio:    bRet = platform_send_cmd(hw_platform_gpio, type, wParam, lParam);     break;
        case hw_platform_systick: bRet = platform_send_cmd(hw_platform_systick, type, wParam, lParam);  break;
        case hw_platform_usart:   bRet = platform_send_cmd(hw_platform_usart, type, wParam, lParam);    break;
        case hw_platform_nvic:    bRet = platform_send_cmd(hw_platform_nvic, type, wParam, lParam);     break;
        case hw_platform_rcc:     bRet = platform_send_cmd(hw_platform_rcc, type, wParam, lParam);      break;
        case hw_platform_can:     bRet = platform_send_cmd(hw_platform_can, type, wParam, lParam);      break;
        default: bRet = hw_platform_errcode_unkwon_plarform; break;
    }
    return bRet;
}

const char* hw_platform_errcode_to_string(enum hw_platform_errcode_e code)
{
    const char* bRet = "Unknow error code!";
    switch(code) {
        case hw_platform_errcode_success:           bRet = "hw platform exec success!"; break;
        case hw_platform_errcode_failed:            bRet = "hw platform exec failed!"; break;
        case hw_platform_errcode_param_invaild:     bRet = "param is null or invaild!"; break;
        case hw_platform_errcode_unkwon_plarform:   bRet = "unkwon platform!"; break;
        default: break;
    }
    return bRet;
}
