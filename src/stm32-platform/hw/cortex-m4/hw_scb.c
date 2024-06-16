#include "common.h"
#include "hw_scb.h"

struct SCB_Type
{
    __IM  uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
    __IOM uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
    __IOM uint32_t VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
    __IOM uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
    __IOM uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
    __IOM uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
    __IOM uint8_t  SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
    __IOM uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
    __IOM uint32_t CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
    __IOM uint32_t HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
    __IOM uint32_t DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
    __IOM uint32_t MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
    __IOM uint32_t BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
    __IOM uint32_t AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
    __IM  uint32_t PFR[2U];                /*!< Offset: 0x040 (R/ )  Processor Feature Register */
    __IM  uint32_t DFR;                    /*!< Offset: 0x048 (R/ )  Debug Feature Register */
    __IM  uint32_t ADR;                    /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
    __IM  uint32_t MMFR[4U];               /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
    __IM  uint32_t ISAR[5U];               /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
          uint32_t RESERVED0[5U];
    __IOM uint32_t CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
};

#define SCB                 ((struct SCB_Type *) SCB_BASE)
static inline struct SCB_Type* __GET_SCB_REGISTER__(void)
{
    return SCB;
}

#define __GET_SCB_CPUID__           (__GET_SCB_REGISTER__()->CPUID)
#define __GET_SCB_ICSR__            (__GET_SCB_REGISTER__()->ICSR)
#define __GET_SCB_VTOR__            (__GET_SCB_REGISTER__()->VTOR)
#define __GET_SCB_AIRCR__           (__GET_SCB_REGISTER__()->AIRCR)
#define __GET_SCB_SCR__             (__GET_SCB_REGISTER__()->SCR)
#define __GET_SCB_CCR__             (__GET_SCB_REGISTER__()->CCR)
#define __GET_SCB_SHP__(n)          (__GET_SCB_REGISTER__()->SHP[n])
#define __GET_SCB_SHCSR__           (__GET_SCB_REGISTER__()->SHCSR)
#define __GET_SCB_CFSR__            (__GET_SCB_REGISTER__()->CFSR)
#define __GET_SCB_HFSR__            (__GET_SCB_REGISTER__()->HFSR)
#define __GET_SCB_DFSR__            (__GET_SCB_REGISTER__()->DFSR)
#define __GET_SCB_MMFAR__           (__GET_SCB_REGISTER__()->MMFAR)
#define __GET_SCB_BFAR__            (__GET_SCB_REGISTER__()->BFAR)
#define __GET_SCB_AFSR__            (__GET_SCB_REGISTER__()->AFSR)
#define __GET_SCB_PFR__(n)          (__GET_SCB_REGISTER__()->PFR[n])
#define __GET_SCB_DFR__             (__GET_SCB_REGISTER__()->DFR)
#define __GET_SCB_ADR__             (__GET_SCB_REGISTER__()->ADR)
#define __GET_SCB_MMFR__(n)         (__GET_SCB_REGISTER__()->MMFR[n])
#define __GET_SCB_ISAR__(n)         (__GET_SCB_REGISTER__()->ISAR[n])
#define __GET_SCB_CPACR__           (__GET_SCB_REGISTER__()->CPACR)

#define SCB_ICSR_VECTACTIVE_Pos                     (0U)
#define SCB_ICSR_VECTACTIVE_Msk                     (0x1FFUL << SCB_ICSR_VECTACTIVE_Pos)   /*!< 0x000001FF */
#define SCB_ICSR_VECTACTIVE                         SCB_ICSR_VECTACTIVE_Msk
#define SCB_ICSR_RETTOBASE_Pos                      (11U)
#define SCB_ICSR_RETTOBASE_Msk                      (0x1UL << SCB_ICSR_RETTOBASE_Pos)   /*!< 0x00000800 */
#define SCB_ICSR_RETTOBASE                          SCB_ICSR_RETTOBASE_Msk
#define SCB_ICSR_VECTPENDING_Pos                    (12U)
#define SCB_ICSR_VECTPENDING_Msk                    (0x7FUL << SCB_ICSR_VECTPENDING_Pos)   /*!< 0x0007F000 */
#define SCB_ICSR_VECTPENDING                        SCB_ICSR_VECTPENDING_Msk
#define SCB_ICSR_ISRPENDING_Pos                     (22U)
#define SCB_ICSR_ISRPENDING_Msk                     (0x1UL << SCB_ICSR_ISRPENDING_Pos)   /*!< 0x00400000 */
#define SCB_ICSR_ISRPENDING                         SCB_ICSR_ISRPENDING_Msk
#define SCB_ICSR_PENDSTCLR_Pos                      (25U)
#define SCB_ICSR_PENDSTCLR_Msk                      (0x1UL << SCB_ICSR_PENDSTCLR_Pos)   /*!< 0x02000000 */
#define SCB_ICSR_PENDSTCLR                          SCB_ICSR_PENDSTCLR_Msk
#define SCB_ICSR_PENDSTSET_Pos                      (26U)
#define SCB_ICSR_PENDSTSET_Msk                      (0x1UL << SCB_ICSR_PENDSTSET_Pos)   /*!< 0x04000000 */
#define SCB_ICSR_PENDSTSET                          SCB_ICSR_PENDSTSET_Msk
#define SCB_ICSR_PENDSVCLR_Pos                      (27U)
#define SCB_ICSR_PENDSVCLR_Msk                      (0x1UL << SCB_ICSR_PENDSVCLR_Pos)   /*!< 0x08000000 */
#define SCB_ICSR_PENDSVCLR                          SCB_ICSR_PENDSVCLR_Msk
#define SCB_ICSR_PENDSVSET_Pos                      (28U)
#define SCB_ICSR_PENDSVSET_Msk                      (0x1UL << SCB_ICSR_PENDSVSET_Pos)   /*!< 0x10000000 */
#define SCB_ICSR_PENDSVSET                          SCB_ICSR_PENDSVSET_Msk
#define SCB_ICSR_NMIPENDSET_Pos                     (31U)
#define SCB_ICSR_NMIPENDSET_Msk                     (0x1UL << SCB_ICSR_NMIPENDSET_Pos)   /*!< 0x80000000 */
#define SCB_ICSR_NMIPENDSET                         SCB_ICSR_NMIPENDSET_Msk

#define SCB_VTOR_TBLBASE_Pos                        (29U)
#define SCB_VTOR_TBLBASE_Msk                        (0x1UL << SCB_VTOR_TBLBASE_Pos)   /*!< 0x20000000 */
#define SCB_VTOR_TBLBASE                            SCB_VTOR_TBLBASE_Msk
#define SCB_VTOR_TBLOFF_Pos                         (9U)
#define SCB_VTOR_TBLOFF_Msk                         (0x1FFFFEUL << SCB_VTOR_TBLOFF_Pos)   /*!< 0x1FFFFE00 */
#define SCB_VTOR_TBLOFF                             SCB_VTOR_TBLOFF_Msk

#define SCB_AIRCR_SYSRESETREQ_Pos                   (2U)
#define SCB_AIRCR_SYSRESETREQ_Msk                   (0x1UL << SCB_AIRCR_SYSRESETREQ_Pos)   /*!< 0x00000004 */
#define SCB_AIRCR_SYSRESETREQ                       SCB_AIRCR_SYSRESETREQ_Msk
#define SCB_AIRCR_PRIGROUP_Pos                      (8U)
#define SCB_AIRCR_PRIGROUP_Msk                      (0x7UL << SCB_AIRCR_PRIGROUP_Pos)   /*!< 0x00000700 */
#define SCB_AIRCR_PRIGROUP                          SCB_AIRCR_PRIGROUP_Msk
#define SCB_AIRCR_ENDIANESS_Pos                     (15U)
#define SCB_AIRCR_ENDIANESS_Msk                     (0x1UL << SCB_AIRCR_ENDIANESS_Pos)   /*!< 0x00008000 */
#define SCB_AIRCR_ENDIANESS                         SCB_AIRCR_ENDIANESS_Msk
#define SCB_AIRCR_VECTKEY_Pos                       (16U)
#define SCB_AIRCR_VECTKEY_Msk                       (0x1UL << SCB_AIRCR_VECTKEY_Pos)   /*!< 0x00010000 */
#define SCB_AIRCR_VECTKEY                           SCB_AIRCR_VECTKEY_Msk
#define SCB_AIRCR_VECTKEYSTAT_Pos                   (16U)
#define SCB_AIRCR_VECTKEYSTAT_Msk                   (0x1UL << SCB_AIRCR_VECTKEYSTAT_Pos)   /*!< 0x00010000 */
#define SCB_AIRCR_VECTKEYSTAT                       SCB_AIRCR_VECTKEYSTAT_Msk

#define SCB_SCR_SLEEPONEXIT_Pos                     (1U)
#define SCB_SCR_SLEEPONEXIT_Msk                     (0x1UL << SCB_SCR_SLEEPONEXIT_Pos)   /*!< 0x00000002 */
#define SCB_SCR_SLEEPONEXIT                         SCB_SCR_SLEEPONEXIT_Msk
#define SCB_SCR_SLEEPDEEP_Pos                       (2U)
#define SCB_SCR_SLEEPDEEP_Msk                       (0x1UL << SCB_SCR_SLEEPDEEP_Pos)   /*!< 0x00000004 */
#define SCB_SCR_SLEEPDEEP                           SCB_SCR_SLEEPDEEP_Msk
#define SCB_SCR_SEVEONPEND_Pos                      (4U)
#define SCB_SCR_SEVEONPEND_Msk                      (0x1UL << SCB_SCR_SEVEONPEND_Pos)   /*!< 0x00000008 */
#define SCB_SCR_SEVEONPEND                          SCB_SCR_SEVEONPEND_Msk

#define SCB_CCR_NONBASETHRDENA_Pos                  (0U)
#define SCB_CCR_NONBASETHRDENA_Msk                  (0x1UL << SCB_CCR_NONBASETHRDENA_Pos)   /*!< 0x00000001 */
#define SCB_CCR_NONBASETHRDENA                      SCB_CCR_NONBASETHRDENA_Msk
#define SCB_CCR_USERSETMPEND_Pos                    (1U)
#define SCB_CCR_USERSETMPEND_Msk                    (0x1UL << SCB_CCR_USERSETMPEND_Pos)   /*!< 0x00000002 */
#define SCB_CCR_USERSETMPEND                        SCB_CCR_USERSETMPEND_Msk
#define SCB_CCR_UNALIGN_TRP_Pos                     (3U)
#define SCB_CCR_UNALIGN_TRP_Msk                     (0x1UL << SCB_CCR_UNALIGN_TRP_Pos)   /*!< 0x00000008 */
#define SCB_CCR_UNALIGN_TRP                         SCB_CCR_UNALIGN_TRP_Msk
#define SCB_CCR_DIV_0_TRP_Pos                       (4U)
#define SCB_CCR_DIV_0_TRP_Msk                       (0x1UL << SCB_CCR_DIV_0_TRP_Pos)   /*!< 0x00000010 */
#define SCB_CCR_DIV_0_TRP                           SCB_CCR_DIV_0_TRP_Msk
#define SCB_CCR_BFHFNMIGN_Pos                       (8U)
#define SCB_CCR_BFHFNMIGN_Msk                       (0x1UL << SCB_CCR_BFHFNMIGN_Pos)   /*!< 0x00000100 */
#define SCB_CCR_BFHFNMIGN                           SCB_CCR_BFHFNMIGN_Msk
#define SCB_CCR_STKALIGN_Pos                        (9U)
#define SCB_CCR_STKALIGN_Msk                        (0x1UL << SCB_CCR_STKALIGN_Pos)   /*!< 0x00000200 */
#define SCB_CCR_STKALIGN                            SCB_CCR_STKALIGN_Msk

#define AIRCR_VECTKEY_MASK           ((uint32_t)0x05FA0000)

uint32_t hw_scb_get_cpuid(void)
{
    return __GET_SCB_CPUID__;
}

void hw_scb_reset_system(void)
{
    __BIT_SET__(__GET_SCB_AIRCR__, AIRCR_VECTKEY_MASK | SCB_AIRCR_SYSRESETREQ);
    while(1);
}

void hw_scb_keep_priority_reset_system(void)
{
    __BIT_SET__(__GET_SCB_AIRCR__, AIRCR_VECTKEY_MASK | (__GET_SCB_AIRCR__ & SCB_AIRCR_PRIGROUP) | SCB_AIRCR_SYSRESETREQ);
    stm32_cortex_dsb();
    while(1);
}

void hw_scb_reset_cortex_kernel(void)
{
    __BIT_SET__(__GET_SCB_AIRCR__, AIRCR_VECTKEY_MASK | SCB_AIRCR_VECTKEY);
    while(1);
}

uint32_t hw_scb_get_data_endianness_bit(void)
{
    return (__GET_SCB_AIRCR__ & SCB_AIRCR_ENDIANESS);
}

void hw_scb_set_div_0_trp_enable(void)
{
    __BIT_OR__(__GET_SCB_CCR__, SCB_CCR_DIV_0_TRP);
}

void hw_scb_set_div_0_trp_disable(void)
{
    __BIT_RESET__(__GET_SCB_CCR__, SCB_CCR_DIV_0_TRP);
}

uint32_t hw_scb_get_div_0_trp_enable(void)
{
    return (__GET_SCB_CCR__ & SCB_CCR_DIV_0_TRP);
}

void hw_scb_set_vector_table_to_flash(uint32_t offset)
{
    __BIT_COVER_SET__(__GET_SCB_VTOR__, SCB_VTOR_TBLBASE | SCB_VTOR_TBLOFF, offset);
}

void hw_scb_set_vector_table_to_ram(uint32_t offset)
{
    __BIT_COVER_SET__(__GET_SCB_VTOR__, SCB_VTOR_TBLBASE | SCB_VTOR_TBLOFF, SCB_VTOR_TBLBASE | offset);
}

uint32_t hw_scb_get_vector_table(void)
{
    return (__GET_SCB_VTOR__ & (SCB_VTOR_TBLBASE | SCB_VTOR_TBLOFF));
}

