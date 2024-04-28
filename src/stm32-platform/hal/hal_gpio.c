#include "hw_common.h"
#include "hw_gpio.h"
#include "hal_gpio.h"

int32_t hal_gpio_set_prop(uint32_t gpio, uint32_t mode)
{
    return hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_PROP, gpio, mode);
}
int32_t hal_gpio_set_mode(uint32_t gpio, enum hal_gpio_mode_e mode)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(mode) {
        case hal_gpio_mode_input:       bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_MODE, gpio, hw_gpio_mode_input);        break;
        case hal_gpio_mode_output:      bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_MODE, gpio, hw_gpio_mode_output);       break;
        case hal_gpio_mode_alternate:   bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_MODE, gpio, hw_gpio_mode_alternate);    break;
        case hal_gpio_mode_analog:      bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_MODE, gpio, hw_gpio_mode_analog);       break;
        default: break;
    }
    return bRet;
}
int32_t hal_gpio_set_output_mode(uint32_t gpio, enum hal_gpio_output_mode_e mode)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(mode) {
        case hal_gpio_output_mode_pp: bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_OUTPUT_MODE, gpio, hw_gpio_output_mode_push_pull);  break;
        case hal_gpio_output_mode_od: bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_OUTPUT_MODE, gpio, hw_gpio_output_mode_open_drain); break;
        default: break;
    }
    return bRet;
}

int32_t hal_gpio_set_output_speed(uint32_t gpio, enum hal_gpio_speed_e speed)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(speed) {
        case hal_gpio_speed_low:        bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_OUTPUT_SPEED, gpio, hw_gpio_output_speed_low);      break;
        case hal_gpio_speed_medium:     bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_OUTPUT_SPEED, gpio, hw_gpio_output_speed_medium);   break;
        case hal_gpio_speed_high:       bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_OUTPUT_SPEED, gpio, hw_gpio_output_speed_high);     break;
        case hal_gpio_speed_very_high:  bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_OUTPUT_SPEED, gpio, hw_gpio_output_speed_very_high);break;
        default: break;
    }
    return bRet;
}
int32_t hal_gpio_set_pupd_mode(uint32_t gpio, enum hal_gpio_pupd_e pupd)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(pupd) {
        case hal_gpio_pupd_nopull:      bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_PUPD_MODE, gpio, hw_gpio_pupd_nopull);      break;
        case hal_gpio_pupd_pull_up:     bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_PUPD_MODE, gpio, hw_gpio_pupd_pull_up);     break;
        case hal_gpio_pupd_pull_down:   bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_PUPD_MODE, gpio, hw_gpio_pupd_pull_down);   break;
        default: break;
    }
    return bRet;
}

int32_t hal_gpio_set_alternate(uint32_t gpio, uint8_t af)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_ALTERNATE, gpio, af);
    return bRet;
}
int32_t hal_gpio_set_status(uint32_t gpio, enum hal_gpio_status_e status)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(status) {
        case hal_gpio_status_low:   bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_STATUS, gpio, hw_gpio_status_low);      break;
        case hal_gpio_status_high:  bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_SET_STATUS, gpio, hw_gpio_status_high);    break;
        default: break;
    }
    return bRet;
}
enum hal_gpio_status_e hal_gpio_get_status(uint32_t gpio)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    enum hw_gpio_status_e state = hw_gpio_status_null;
    enum hal_gpio_status_e hal_gpio_state = hal_gpio_status_null;
    bRet = hw_platform_send_cmd(hw_platform_gpio, HW_GPIO_CMD_GET_STATUS, gpio, (LPARAM)&state);
    switch(state) {
        case hw_gpio_status_low: hal_gpio_state = hal_gpio_status_low; break;
        case hw_gpio_status_high: hal_gpio_state = hal_gpio_status_high; break;
        default: break;
    }
    return hal_gpio_state;
}
int32_t hal_gpio_toggle_status(uint32_t gpio)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    return bRet;
}

