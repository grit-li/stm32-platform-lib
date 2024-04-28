#ifndef __SETM32_PLATFORM_HAL_CAN_H__
#define __SETM32_PLATFORM_HAL_CAN_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t hal_can_init(uint32_t);
uint32_t hal_can_send_data(uint32_t id, uint8_t IDE, uint8_t DLC, const uint8_t* DATA);
uint32_t hal_can_recv_data(uint32_t* id, uint8_t* IDE, uint8_t* DLC, uint8_t* DATA);

#ifdef __cplusplus
}
#endif

#endif
