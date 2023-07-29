#include "cortex_m.h"

uint32_t stm32_cortex_get_psp(void)
{
    uint32_t result = 0;
    __asm volatile ("MRS %0, psp\n\t" 
                    "MOV r0, %0 \n\t"
                    "BX  lr     \n\t"  : "=r" (result));
    return result;
}

void stm32_cortex_set_psp(uint32_t topOfProcStack)
{
    __asm volatile ("MSR psp, %0\n\t"
                    "BX  lr     \n\t" : : "r" (topOfProcStack));
}

uint32_t stm32_cortex_get_msp(void)
{
    uint32_t result = 0;
    __asm volatile ("MRS %0, msp\n\t" 
                    "MOV r0, %0 \n\t"
                    "BX  lr     \n\t"  : "=r" (result));
    return result;
}

void stm32_cortex_set_msp(uint32_t topOfMainStack)
{
    __asm volatile ("MSR msp, %0\n\t"
                    "BX  lr     \n\t" : : "r" (topOfMainStack));
}

uint32_t stm32_cortex_get_basepri(void)
{
    uint32_t result = 0;
    __asm volatile ("MRS %0, basepri_max" : "=r" (result));
    return result;
}

void stm32_cortex_set_basepri(uint32_t value)
{
    __asm volatile ("MSR basepri, %0" : : "r" (value));
}

uint32_t stm32_cortex_get_primask(void)
{
    uint32_t result = 0;
    __asm volatile ("MRS %0, primask" : "=r" (result));
    return result;
}

void stm32_cortex_set_primask(uint32_t priMask)
{
    __asm volatile ("MSR primask, %0" : : "r" (priMask));
}

uint32_t stm32_cortex_get_faultmask(void)
{
    uint32_t result = 0;
    __asm volatile ("MRS %0, faultmask" : "=r" (result));
    return result;
}

void stm32_cortex_set_faultmask(uint32_t faultMask)
{
    __asm volatile ("MSR faultmask, %0" : : "r" (faultMask));
}

uint32_t stm32_cortex_rev(uint32_t value)
{
    uint32_t result = 0;
    __asm volatile ("rev %0, %1" : "=r" (result) : "r" (value));
    return result;
}

uint32_t stm32_cortex_rev16(uint16_t value)
{
    uint32_t result = 0;
    __asm volatile ("rev16 %0, %1" : "=r" (result) : "r" (value));
    return result;
}

int32_t stm32_cortex_revsh(int16_t value)
{
    uint32_t result = 0;
    __asm volatile ("revsh %0, %1" : "=r" (result) : "r" (value));
    return result;
}

uint32_t stm32_cortex_rbit(uint32_t value)
{
    uint32_t result = 0;
    __asm volatile ("rbit %0, %1" : "=r" (result) : "r" (value));
    return result;
}

uint8_t stm32_cortex_ldrexb(uint8_t *addr)
{
    uint8_t result = 0;
    __asm volatile ("ldrexb %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

uint16_t stm32_cortex_ldrexh(uint16_t *addr)
{
    uint16_t result = 0;
    __asm volatile ("ldrexh %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

uint32_t stm32_cortex_ldrexw(uint32_t *addr)
{
    uint32_t result = 0;
    __asm volatile ("ldrex %0, [%1]" : "=r" (result) : "r" (addr));
    return result;
}

uint32_t stm32_cortex_strexb(uint8_t value, uint8_t *addr)
{
    uint32_t result = 0;
    __asm volatile ("strexb %0, %2, [%1]" : "=&r" (result) : "r" (addr), "r" (value));
    return result;
}

uint32_t stm32_cortex_strexh(uint16_t value, uint16_t *addr)
{
    uint32_t result = 0;
    __asm volatile ("strexh %0, %2, [%1]" : "=&r" (result) : "r" (addr), "r" (value));
    return result;
}

uint32_t stm32_cortex_strexw(uint32_t value, uint32_t *addr)
{
    uint32_t result = 0;
    __asm volatile ("strex %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value));
    return result;
}

uint32_t stm32_cortex_get_control(void)
{
    uint32_t result = 0;
    __asm volatile ("MRS %0, control" : "=r" (result));
    return result;
}

void stm32_cortex_set_control(uint32_t control)
{
    __asm volatile ("MSR control, %0" : : "r" (control));
}
