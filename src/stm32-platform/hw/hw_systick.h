#ifndef __SETM32_PLATFORM_HW_SYSTICK_H__
#define __SETM32_PLATFORM_HW_SYSTICK_H__

#include <stdint.h>
#include "cortex_m.h"
#include "stm32_hw_reg_map.h"
#include "stm32_bitops.h"

#ifdef __cplusplus
extern "C" {
#endif

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


uint32_t hw_systick_get_count_flag(void);
void hw_systick_select_clock_source(uint32_t source);
void hw_systick_exception_request_enable(void);
void hw_systick_exception_request_disable(void);
uint32_t hw_systick_get_exception_request_enable(void);
void hw_systick_counter_enable(void);
void hw_systick_counter_disable(void);
uint32_t hw_systick_get_counter_enable(void);
void hw_systick_set_reload_value(uint32_t value);
uint32_t hw_systick_get_reload_value(void);
void hw_systick_set_current_value(uint32_t value);
uint32_t hw_systick_get_current_value(void);
uint32_t hw_systick_get_noref_flag(void);
uint32_t hw_systick_get_skew_flag(void);
uint32_t hw_systick_get_calibration_value(void);

#ifdef __cplusplus
}
#endif

#endif