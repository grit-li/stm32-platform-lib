#ifndef __SETM32_PLATFORM_HW_NVIC_H__
#define __SETM32_PLATFORM_HW_NVIC_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum hw_nvic_irq_type_e
{
    hw_nvic_irq_type_systick,
    hw_nvic_irq_type_can1_rx0,
    hw_nvic_irq_type_max,
};

enum hw_nvic_enable_e
{
    hw_nvic_enable,
    hw_nvic_disable,
};

enum hw_nvic_active_e
{
    hw_nvic_active_unknow,
};

enum hw_nvic_priority_group_e
{
    hw_nvic_priority_group_0,
    hw_nvic_priority_group_1,
    hw_nvic_priority_group_2,
    hw_nvic_priority_group_3,
    hw_nvic_priority_group_4,
};
struct hw_nvic_priority_t
{
    uint8_t preempt_priority;
    uint8_t sub_priority;
};
enum hw_nvic_cmd_e
{
    HW_NVIC_CMD_SET_ENABLE, /*< WPARAM: enum hw_irqn_type_e, LPARAM: enum hw_nvic_enable_e >*/
    HW_NVIC_CMD_GET_ENABLE, /*< WPARAM: enum hw_irqn_type_e, LPARAM: enum hw_nvic_enable_e * >*/

    HW_NVIC_CMD_SET_PENDING, /*< WPARAM: enum hw_irqn_type_e, LPARAM: enum hw_nvic_enable_e >*/
    HW_NVIC_CMD_GET_PENDING, /*< WPARAM: enum hw_irqn_type_e, LPARAM: enum hw_nvic_enable_e * >*/

    HW_NVIC_CMD_GET_ACTIVE, /*< WPARAM: enum hw_irqn_type_e, LPARAM: enum hw_nvic_active_e * >*/

    HW_NVIC_CMD_SET_GROUP, /*< WPARAM: enum hw_nvic_priority_group_e >*/
    HW_NVIC_CMD_GET_GROUP, /*< WPARAM: enum hw_nvic_priority_group_e * >*/

    HW_NVIC_CMD_SET_PRIORITY, /*< WPARAM: enum hw_irqn_type_e, LPARAM: const struct hw_nvic_priority_t * >*/
    HW_NVIC_CMD_GET_PRIORITY, /*< WPARAM: enum hw_irqn_type_e, LPARAM: const struct hw_nvic_priority_t * >*/
};

#ifdef __cplusplus
}
#endif

#endif
