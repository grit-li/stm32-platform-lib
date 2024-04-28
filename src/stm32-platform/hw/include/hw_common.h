#ifndef __SETM32_PLATFORM_HW_COMMON_H__
#define __SETM32_PLATFORM_HW_COMMON_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uintptr_t WPARAM;
typedef uintptr_t LPARAM;

enum hw_platform_errcode_e
{
    hw_platform_errcode_success         =  0,
    hw_platform_errcode_failed          = -1,
    hw_platform_errcode_param_invaild   = -2,
    hw_platform_errcode_unkwon_plarform = -3,
    hw_platform_errcode_not_support     = -4,
};

enum hw_platform_type_e
{
    hw_platform_gpio,
    hw_platform_systick,
    hw_platform_usart,
    hw_platform_nvic,
    hw_platform_rcc,
    hw_platform_can,
};

struct hw_platform_cmd_t
{
    uint8_t type;
    WPARAM wParam;
    LPARAM lParam;
};

enum hw_platform_errcode_e hw_platform_send_cmd(enum hw_platform_type_e, uint8_t, WPARAM, LPARAM);
const char* hw_platform_errcode_to_string(enum hw_platform_errcode_e);

#ifdef __cplusplus
}
#endif

#endif
