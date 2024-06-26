#ifndef __STM32_ASSERT_H__
#define __STM32_ASSERT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifdef USE_STM32_ASSERT
void stm32_assert_failed(const char* desc, uint8_t* file, uint32_t line);
#define stm32_assert(expr, desc) ((expr) ? (void)0 : stm32_assert_failed(desc, (uint8_t *)__FILE__, __LINE__))
#else
#define stm32_assert(expr, desc) ((void)0)
#endif

#ifdef __cplusplus
}
#endif

#endif
