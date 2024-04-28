#include "stm32_types.h"
#include "hw_common.h"
#include "hw_nvic.h"
#include "hal_interrupt_vector_table.h"

int32_t hal_irq_set_priority_group(enum hal_irqn_priority_group_e group)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(group) {
        case hal_irqn_priority_group_0: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_GROUP, hw_nvic_priority_group_0, 0); break;
        case hal_irqn_priority_group_1: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_GROUP, hw_nvic_priority_group_1, 0); break;
        case hal_irqn_priority_group_2: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_GROUP, hw_nvic_priority_group_2, 0); break;
        case hal_irqn_priority_group_3: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_GROUP, hw_nvic_priority_group_3, 0); break;
        case hal_irqn_priority_group_4: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_GROUP, hw_nvic_priority_group_4, 0); break;
        default: break;
    }
    return bRet;
}
enum hal_irqn_priority_group_e hal_irq_get_priority_group(void)
{
    enum hw_nvic_priority_group_e group = hw_nvic_priority_group_0;
    enum hal_irqn_priority_group_e bRet = hal_irqn_priority_group_0;
    hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_GET_GROUP, (WPARAM)&group, 0);
    switch(group) {
        case hw_nvic_priority_group_0: bRet = hal_irqn_priority_group_0; break;
        case hw_nvic_priority_group_1: bRet = hal_irqn_priority_group_1; break;
        case hw_nvic_priority_group_2: bRet = hal_irqn_priority_group_2; break;
        case hw_nvic_priority_group_3: bRet = hal_irqn_priority_group_3; break;
        case hw_nvic_priority_group_4: bRet = hal_irqn_priority_group_4; break;
        default: break;
    }
    return bRet;
}
int32_t hal_irq_enable(enum hal_irqn_type_e irqn)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(irqn) {
        case hal_irqn_type_systick: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_ENABLE, hw_nvic_irq_type_systick, hw_nvic_enable); break;
        case hal_irqn_type_can1_rx0: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_ENABLE, hw_nvic_irq_type_can1_rx0, hw_nvic_enable); break;
        default: break;
    }
    return bRet;
}
int32_t hal_irq_get_enable(enum hal_irqn_type_e irqn)
{
    enum hw_nvic_enable_e en = hw_nvic_disable;
    switch(irqn) {
        case hal_irqn_type_systick: hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_GET_ENABLE, hw_nvic_irq_type_systick, (LPARAM)&en); break;
        case hal_irqn_type_can1_rx0: hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_GET_ENABLE, hw_nvic_irq_type_can1_rx0, (LPARAM)&en); break;
        default: break;
    }
    return en == hw_nvic_enable ? stm32_true : stm32_false;
}
int32_t hal_irq_disable(enum hal_irqn_type_e irqn)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(irqn) {
        case hal_irqn_type_systick: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_ENABLE, hw_nvic_irq_type_systick, hw_nvic_disable); break;
        case hal_irqn_type_can1_rx0: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_ENABLE, hw_nvic_irq_type_can1_rx0, hw_nvic_disable); break;
        default: break;
    }
    return bRet;
}
int32_t hal_irq_get_disable(enum hal_irqn_type_e irqn)
{
    enum hw_nvic_enable_e en = hw_nvic_disable;
    switch(irqn) {
        case hal_irqn_type_systick: hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_GET_ENABLE, hw_nvic_irq_type_systick, (LPARAM)&en); break;
        case hal_irqn_type_can1_rx0: hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_GET_ENABLE, hw_nvic_irq_type_can1_rx0, (LPARAM)&en); break;
        default: break;
    }
    return en == hw_nvic_disable ? stm32_true : stm32_false;
}
int32_t hal_irq_set_priority(enum hal_irqn_type_e irqn, uint8_t preempt_priority, uint8_t sub_priority)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    struct hw_nvic_priority_t priority;
    priority.preempt_priority = preempt_priority;
    priority.sub_priority = sub_priority;
    switch(irqn) {
        case hal_irqn_type_systick: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_PRIORITY, hw_nvic_irq_type_systick, (LPARAM)&priority); break;
        case hal_irqn_type_can1_rx0: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_SET_PRIORITY, hw_nvic_irq_type_can1_rx0, (LPARAM)&priority); break;
        default: break;
    }
    return bRet;
}

int32_t hal_irq_get_priority(enum hal_irqn_type_e irqn, uint8_t *const preempt_priority, uint8_t *const sub_priority)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    struct hw_nvic_priority_t priority;
    switch(irqn) {
        case hal_irqn_type_systick: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_GET_PRIORITY, hw_nvic_irq_type_systick, (LPARAM)&priority); break;
        case hal_irqn_type_can1_rx0: bRet = hw_platform_send_cmd(hw_platform_nvic, HW_NVIC_CMD_GET_PRIORITY, hw_nvic_irq_type_can1_rx0, (LPARAM)&priority); break;
        default: break;
    }
    *preempt_priority = priority.preempt_priority;
    *sub_priority = priority.sub_priority;
    return bRet;
}

