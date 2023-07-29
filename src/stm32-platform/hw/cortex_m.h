#ifndef __CORTEX_M_H__
#define __CORTEX_M_H__

#include <stdint.h>
#include <stm32_gcc_attribute.h>

#ifdef __cplusplus
extern "C" {
#endif 

#ifdef __cplusplus
#define __I     volatile                  /*!< defines 'read only' permissions      */
#else
#define __I     volatile const            /*!< defines 'read only' permissions      */
#endif
#define __O     volatile                  /*!< defines 'write only' permissions     */
#define __IO    volatile                  /*!< defines 'read / write' permissions   */

/* following defines should be used for structure members */
#define __IM     volatile const           /*! Defines 'read only' structure member permissions */
#define __OM     volatile                 /*! Defines 'write only' structure member permissions */
#define __IOM    volatile                 /*! Defines 'read / write' structure member permissions */

/* ###################  Compiler specific Intrinsics  ########################### */
static inline void stm32_cortex_enable_irq(void)
{
    __asm volatile ("cpsie i");
}

static inline void stm32_cortex_disable_irq(void)
{
    __asm volatile ("cpsid i");
}

static inline void stm32_cortex_enable_fault_irq(void)
{
    __asm volatile ("cpsie f");
}

static inline void stm32_cortex_disable_fault_irq(void)
{
    __asm volatile ("cpsid f");
}

static inline void stm32_cortex_nop(void)
{
    __asm volatile ("nop");
}

static inline void stm32_cortex_wfi(void)
{
    __asm volatile ("wfi");
}

static inline void stm32_cortex_wfe(void)
{
    __asm volatile ("wfe");
}

static inline void stm32_cortex_sev(void)
{
    __asm volatile ("sev");
}

static inline void stm32_cortex_isb(void)
{
    __asm volatile ("isb");
}

static inline void stm32_cortex_dsb(void)
{
    __asm volatile ("dsb");
}

static inline void stm32_cortex_dmb(void)
{
    __asm volatile ("dmb");
}

static inline void stm32_cortex_clrex(void)
{
    __asm volatile ("clrex");
}

uint32_t stm32_cortex_get_psp(void) __stm32_platform_naked__;
void stm32_cortex_set_psp(uint32_t) __stm32_platform_naked__;
uint32_t stm32_cortex_get_msp(void) __stm32_platform_naked__;
void stm32_cortex_set_msp(uint32_t) __stm32_platform_naked__;
uint32_t stm32_cortex_get_basepri(void);
void stm32_cortex_set_basepri(uint32_t);
uint32_t stm32_cortex_get_primask(void);
void stm32_cortex_set_primask(uint32_t);
uint32_t stm32_cortex_get_faultmask(void);
void stm32_cortex_set_faultmask(uint32_t);
uint32_t stm32_cortex_get_control(void);
void stm32_cortex_set_control(uint32_t control);
uint32_t stm32_cortex_rev(uint32_t value);
uint32_t stm32_cortex_rev16(uint16_t value);
int32_t stm32_cortex_revsh(int16_t value);
uint32_t stm32_cortex_rbit(uint32_t value);
uint8_t stm32_cortex_ldrexb(uint8_t *addr);
uint16_t stm32_cortex_ldrexh(uint16_t *addr);
uint32_t stm32_cortex_ldrexw(uint32_t *addr);
uint32_t stm32_cortex_strexb(uint8_t value, uint8_t *addr);
uint32_t stm32_cortex_strexh(uint16_t value, uint16_t *addr);
uint32_t stm32_cortex_strexw(uint32_t value, uint32_t *addr);

#ifdef __cplusplus
}
#endif

#endif
