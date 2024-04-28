#include "common.h"
#include "hw_systick.h"

struct SysTick_Type
{
    __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
    __IOM uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
    __IOM uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
    __IM  uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
};

#define SysTick                 ((struct SysTick_Type *) SysTick_BASE)
static inline struct SysTick_Type* __GET_SYSTICK_REGISTER__(void)
{
    return SysTick;
}

#define __GET_SYSTICK_CTRL__        (__GET_SYSTICK_REGISTER__()->CTRL)
#define __GET_SYSTICK_LOAD__        (__GET_SYSTICK_REGISTER__()->LOAD)
#define __GET_SYSTICK_VAL__         (__GET_SYSTICK_REGISTER__()->VAL)
#define __GET_SYSTICK_CALIB__       (__GET_SYSTICK_REGISTER__()->CALIB)

/* SysTick Control / Status Register Definitions */
#define SysTick_CTRL_COUNTFLAG_Pos         16U                                            /*!< SysTick CTRL: COUNTFLAG Position */
#define SysTick_CTRL_COUNTFLAG_Msk         (1UL << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG Mask */
#define SysTick_CTRL_COUNTFLAG             SysTick_CTRL_COUNTFLAG_Msk

#define SysTick_CTRL_CLKSOURCE_Pos          2U                                            /*!< SysTick CTRL: CLKSOURCE Position */
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE Mask */
#define SysTick_CTRL_CLKSOURCE             SysTick_CTRL_CLKSOURCE_Msk

#define SysTick_CTRL_TICKINT_Pos            1U                                            /*!< SysTick CTRL: TICKINT Position */
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */
#define SysTick_CTRL_TICKINT               SysTick_CTRL_TICKINT_Msk

#define SysTick_CTRL_ENABLE_Pos             0U                                            /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL << SysTick_CTRL_ENABLE_Pos)               /*!< SysTick CTRL: ENABLE Mask */
#define SysTick_CTRL_ENABLE                SysTick_CTRL_ENABLE_Msk

/* SysTick Reload Register Definitions */
#define SysTick_LOAD_RELOAD_Pos             0U                                            /*!< SysTick LOAD: RELOAD Position */
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFUL << SysTick_LOAD_RELOAD_Pos)        /*!< SysTick LOAD: RELOAD Mask */
#define SysTick_LOAD_RELOAD                SysTick_LOAD_RELOAD_Msk

/* SysTick Current Register Definitions */
#define SysTick_VAL_CURRENT_Pos             0U                                            /*!< SysTick VAL: CURRENT Position */
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFUL << SysTick_VAL_CURRENT_Pos)        /*!< SysTick VAL: CURRENT Mask */
#define SysTick_VAL_CURRENT                SysTick_VAL_CURRENT_Msk

/* SysTick Calibration Register Definitions */
#define SysTick_CALIB_NOREF_Pos            31U                                            /*!< SysTick CALIB: NOREF Position */
#define SysTick_CALIB_NOREF_Msk            (1UL << SysTick_CALIB_NOREF_Pos)               /*!< SysTick CALIB: NOREF Mask */
#define SysTick_CALIB_NOREF                SysTick_CALIB_NOREF_Msk

#define SysTick_CALIB_SKEW_Pos             30U                                            /*!< SysTick CALIB: SKEW Position */
#define SysTick_CALIB_SKEW_Msk             (1UL << SysTick_CALIB_SKEW_Pos)                /*!< SysTick CALIB: SKEW Mask */
#define SysTick_CALIB_SKEW                 SysTick_CALIB_SKEW_Msk

#define SysTick_CALIB_TENMS_Pos             0U                                            /*!< SysTick CALIB: TENMS Position */
#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFUL << SysTick_CALIB_TENMS_Pos)        /*!< SysTick CALIB: TENMS Mask */
#define SysTick_CALIB_TENMS                SysTick_CALIB_TENMS_Msk

uint32_t hw_systick_get_count_flag(void)
{
    return (__GET_SYSTICK_CTRL__ & SysTick_CTRL_COUNTFLAG);
}

void hw_systick_select_fclock_source(void)
{
    __BIT_OR__(__GET_SYSTICK_CTRL__, SysTick_CTRL_CLKSOURCE);
}
void hw_systick_select_stclock_source(void)
{
    __BIT_RESET__(__GET_SYSTICK_CTRL__, SysTick_CTRL_CLKSOURCE);
}

static void hw_systick_exception_enable(void)
{
    __BIT_OR__(__GET_SYSTICK_CTRL__, SysTick_CTRL_TICKINT);
}

static void hw_systick_exception_disable(void)
{
    __BIT_RESET__(__GET_SYSTICK_CTRL__, SysTick_CTRL_TICKINT);
}

static uint32_t hw_systick_get_exception_enable(void)
{
    return (__GET_SYSTICK_CTRL__ & SysTick_CTRL_TICKINT);
}

void hw_systick_counter_enable(void)
{
    __BIT_OR__(__GET_SYSTICK_CTRL__, SysTick_CTRL_ENABLE);
}

void hw_systick_counter_disable(void)
{
    __BIT_RESET__(__GET_SYSTICK_CTRL__, SysTick_CTRL_ENABLE);
}

uint32_t hw_systick_get_counter_enable(void)
{
    return (__GET_SYSTICK_CTRL__ & SysTick_CTRL_ENABLE);
}

void hw_systick_set_reload_value(uint32_t value)
{
    __BIT_COVER_SET__(__GET_SYSTICK_LOAD__, SysTick_LOAD_RELOAD, value);
}

uint32_t hw_systick_get_reload_value(void)
{
    return (__GET_SYSTICK_LOAD__ & SysTick_LOAD_RELOAD);
}

void hw_systick_set_current_value(uint32_t value)
{
    __BIT_COVER_SET__(__GET_SYSTICK_VAL__, SysTick_VAL_CURRENT, value);
}

uint32_t hw_systick_get_current_value(void)
{
    return (__GET_SYSTICK_VAL__ & SysTick_VAL_CURRENT);
}

uint32_t hw_systick_get_noref_flag(void)
{
    return (__GET_SYSTICK_CALIB__ & SysTick_CALIB_NOREF);
}

uint32_t hw_systick_get_skew_flag(void)
{
    return (__GET_SYSTICK_CALIB__ & SysTick_CALIB_SKEW);
}

uint32_t hw_systick_get_calibration_value(void)
{
    return (__GET_SYSTICK_CALIB__ & SysTick_CALIB_TENMS);
}

static void hw_systick_select_clock_source(enum hw_systick_clock_source_e source)
{
    switch(source) {
        case hw_systick_clock_source_fclock: hw_systick_select_fclock_source(); break;
        case hw_systick_clock_source_stclock: hw_systick_select_stclock_source(); break;
        default: break;
    }
}
static void hw_systick_set_exception_request(enum hw_systick_exception_request_e en)
{
    switch(en) {
        case hw_systick_exception_request_enable: hw_systick_exception_enable(); break;
        case hw_systick_exception_request_disable: hw_systick_exception_disable(); break;
        default: break;
    }
}
static void hw_systick_set_counter(enum hw_systick_enable_e en)
{
    switch(en) {
        case hw_systick_enable: hw_systick_counter_enable(); break;
        case hw_systick_disable: hw_systick_counter_disable(); break;
        default: break;
    }
}
enum hw_platform_errcode_e hw_platform_systick_cmd(uint8_t type, WPARAM wParam, LPARAM lParam)
{
    enum hw_platform_errcode_e bRet = hw_platform_errcode_success;
    switch(type) {    
        case HW_SYSTICK_CMD_SET_CLOCK_SOURCE:
            hw_systick_select_clock_source(wParam);
            break;
        case HW_SYSTICK_CMD_GET_CLOCK_SOURCE:
            *(enum hw_systick_clock_source_e *)wParam = hw_systick_clock_source_fclock;
            break;
        case HW_SYSTICK_CMD_SET_EXCEPTION_REQUEST:
            hw_systick_set_exception_request(wParam);
            break;
        case HW_SYSTICK_CMD_GET_EXCEPTION_REQUEST:
            *(enum hw_systick_exception_request_e *)wParam = hw_systick_get_exception_enable();
            break;
        case HW_SYSTICK_CMD_SET_ENABLE:
            hw_systick_set_counter(wParam);
            break;
        case HW_SYSTICK_CMD_GET_ENABLE:
            *(enum hw_systick_enable_e *)wParam = hw_systick_get_counter_enable();
            break;
        case HW_SYSTICK_CMD_SET_RELOAD_VALUE:
            hw_systick_set_reload_value(wParam);
            break;
        case HW_SYSTICK_CMD_GET_RELOAD_VALUE:
            *(uint32_t *)wParam = hw_systick_get_reload_value();
            break;
        case HW_SYSTICK_CMD_SET_COUNTER_VALUE:
            hw_systick_set_current_value(wParam);
            break;
        case HW_SYSTICK_CMD_GET_COUNTER_VALUE:
            *(uint32_t *) wParam = hw_systick_get_current_value();
            break;
        default:
            bRet = hw_platform_errcode_not_support;
            break;
    }
    return bRet;


}



