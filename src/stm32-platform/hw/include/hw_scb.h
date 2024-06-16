#ifndef __SETM32_PLATFORM_HW_SCB_H__
#define __SETM32_PLATFORM_HW_SCB_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
    
uint32_t hw_scb_get_cpuid(void);
void hw_scb_reset_system(void);
void hw_scb_keep_priority_reset_system(void);
void hw_scb_reset_cortex_kernel(void);
uint32_t hw_scb_get_data_endianness_bit(void);
void hw_scb_set_div_0_trp_enable(void);
void hw_scb_set_div_0_trp_disable(void);
uint32_t hw_scb_get_div_0_trp_enable(void);
void hw_scb_set_vector_table_to_flash(uint32_t offset);
void hw_scb_set_vector_table_to_ram(uint32_t offset);
uint32_t hw_scb_get_vector_table(void);

#ifdef __cplusplus
}
#endif

#endif
