#ifndef __STM32_TYPES_H__
#define __STM32_TYPES_H__

enum stm32_errcode_e
{
    stm32_errcode_success       =  0,
    stm32_errcode_valid         =  0,
    stm32_errcode_invalid       = -1,
    stm32_errcode_fail          = -1,
    stm32_errcode_param_error   = -2,
};

#endif