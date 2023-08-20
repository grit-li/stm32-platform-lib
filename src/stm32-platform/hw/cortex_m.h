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


/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
enum cortex_interrupt_vector_table_e
{
    cortex_irq_non_maskable         = -14,    /*!< 2 Cortex-M4 Non Maskable Interrupt                                */
    cortex_irq_hard_fault           = -13,    /*!< 3 Cortex-M4 Hard Fault Interrupt                                  */
    cortex_irq_memory_management    = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
    cortex_irq_bus_fault            = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
    cortex_irq_usage_fault          = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
    cortex_irq_svcall               = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
    cortex_irq_debug_monitor        = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
    cortex_irq_pendsv               = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
    cortex_irq_systick              = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
};

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
