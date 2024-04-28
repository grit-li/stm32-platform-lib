#ifndef __SETM32_PLATFORM_HAL_SYSTICK_H__
#define __SETM32_PLATFORM_HAL_SYSTICK_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void hal_systick_select_clock_source(void);
void hal_systick_exception_enable(void);
void hal_systick_exception_disable(void);

void hal_systick_set_reload(uint32_t value);
void hal_systick_set_value(uint32_t value);

void hal_systick_set_count_enable(void);
void hal_systick_set_count_disable(void);

#ifdef __cplusplus
}
#endif

#endif