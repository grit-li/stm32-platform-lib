#include "hw_scb.h"
#include "stm32_assert.h"

#define AIRCR_VECTKEY_MASK           ((uint32_t)0x05FA0000)

uint32_t hw_scb_get_cpuid(void)
{
    return __GET_SCB_CPUID__;
}

void hw_scb_reset_system(void)
{
    __BIT_SET__(__GET_SCB_AIRCR__, AIRCR_VECTKEY_MASK | SCB_AIRCR_SYSRESETREQ);
    while(1);
}

void hw_scb_keep_priority_reset_system(void)
{
    __BIT_SET__(__GET_SCB_AIRCR__, AIRCR_VECTKEY_MASK | (__GET_SCB_AIRCR__ & SCB_AIRCR_PRIGROUP) | SCB_AIRCR_SYSRESETREQ);
    stm32_cortex_dsb();
    while(1);
}

void hw_scb_reset_cortex_kernel(void)
{
    __BIT_SET__(__GET_SCB_AIRCR__, AIRCR_VECTKEY_MASK | SCB_AIRCR_VECTKEY);
    while(1);
}

void hw_scb_set_priority_group(uint32_t prioritygroup)
{
    __BIT_SET__(__GET_SCB_AIRCR__, (AIRCR_VECTKEY_MASK | prioritygroup));
}

uint32_t hw_scb_get_priority_group(void)
{
    return (__GET_SCB_AIRCR__ & SCB_AIRCR_PRIGROUP);
}

uint32_t hw_scb_get_data_endianness_bit(void)
{
    return (__GET_SCB_AIRCR__ & SCB_AIRCR_ENDIANESS);
}

void hw_scb_set_div_0_trp_enable(void)
{
    __BIT_OR__(__GET_SCB_CCR__, SCB_CCR_DIV_0_TRP);
}

void hw_scb_set_div_0_trp_disable(void)
{
    __BIT_RESET__(__GET_SCB_CCR__, SCB_CCR_DIV_0_TRP);
}

uint32_t hw_scb_get_div_0_trp_enable(void)
{
    return (__GET_SCB_CCR__ & SCB_CCR_DIV_0_TRP);
}

void hw_scb_set_vector_table_to_flash(uint32_t offset)
{
    __BIT_COVER_SET__(__GET_SCB_VTOR__, SCB_VTOR_TBLBASE | SCB_VTOR_TBLOFF, offset);
}

void hw_scb_set_vector_table_to_ram(uint32_t offset)
{
    __BIT_COVER_SET__(__GET_SCB_VTOR__, SCB_VTOR_TBLBASE | SCB_VTOR_TBLOFF, SCB_VTOR_TBLBASE | offset);
}

uint32_t hw_scb_get_vector_table(void)
{
    return (__GET_SCB_VTOR__ & (SCB_VTOR_TBLBASE | SCB_VTOR_TBLOFF));
}


