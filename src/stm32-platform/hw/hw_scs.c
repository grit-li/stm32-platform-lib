#include "hw_scs.h"
#include "stm32_assert.h"

uint32_t hw_scs_get_interrupt_controller_type(void)
{
    return __GET_SCS_ICTR__;
}


