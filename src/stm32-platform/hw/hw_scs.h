#ifndef __SETM32_PLATFORM_HW_SCS_H__
#define __SETM32_PLATFORM_HW_SCS_H__

#include <stdint.h>
#include <stdbool.h>
#include "cortex_m.h"
#include "stm32_hw_reg_map.h"
#include "stm32_bitops.h"

#ifdef __cplusplus
extern "C" {
#endif

struct SCS_Type
{
          uint32_t RESERVED0[1U];
    __IM  uint32_t ICTR;                   /*!< Offset: 0x004 (R/ )  Interrupt Controller Type Register */
    __IOM uint32_t ACTLR;                  /*!< Offset: 0x008 (R/W)  Auxiliary Control Register */
};

#define SCS                 ((struct SCS_Type *) SCS_BASE)
static inline struct SCS_Type* __GET_SCS_REGISTER__(void)
{
    return SCS;
}

#define __GET_SCS_ICTR__            (__GET_SCS_REGISTER__()->ICTR)
#define __GET_SCS_ACTLR__           (__GET_SCS_REGISTER__()->ACTLR)

uint32_t hw_scs_get_interrupt_controller_type(void);

#ifdef __cplusplus
}
#endif

#endif