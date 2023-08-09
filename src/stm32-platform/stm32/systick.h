#ifndef __SETM32_PLATFORM_SYSTICK_H__
#define __SETM32_PLATFORM_SYSTICK_H__

#include <stdint.h>
#include <stm32_types.h>

#ifdef __cplusplus
extern "C" {
#endif

void systick_init(void);

void systick_delay_us(uint32_t);

void systick_delay_ms(uint32_t);

#ifdef __cplusplus
}
#endif

#endif