#ifndef __STM32_TYPES_H__
#define __STM32_TYPES_H__

enum stm32_bool_e
{
    stm32_false,
    stm32_true = !stm32_false,
};

enum stm32_enable_e
{
    stm32_disabele = 0,
    stm32_enable   = 1,
};

enum stm32_errcode_e
{
    stm32_errcode_success       =  0,
    stm32_errcode_fail          = -1,
    stm32_errcode_param_error   = -2,
};

#endif