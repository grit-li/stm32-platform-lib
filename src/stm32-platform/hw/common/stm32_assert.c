#include <clog.h>
#include "stm32_assert.h"

void stm32_assert_failed(const char* desc, const uint8_t* file, uint32_t line)
{
    STM32_LOG_COLOR_R(COLOR_HIGHT_RED, "stm32_assert:%s:%ld line -> %s", file, line, desc);
    while(1);
}

