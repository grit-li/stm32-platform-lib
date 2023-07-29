#include "hw_flash.h"
#include "stm32_assert.h"

void hw_flash_set_latency(uint32_t latency)
{
    __BIT_COVER_SET__(__GET_FLASH_ACR__, FLASH_ACR_LATENCY, latency);
}
