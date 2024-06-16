#include "stm32_gcc_attribute.h"
#include "stm32/interrupt_vector_table.h"
#include <retarget.h>
#include <rtthread.h>

extern void boot_main(void);

extern unsigned int _sidata;
extern unsigned int _sdata;
extern unsigned int _edata;
extern unsigned int _sbss;
extern unsigned int _ebss;
extern unsigned int _stack;

void reset_handler(void)
{
    volatile unsigned int* Src;
    volatile unsigned int* Dest;
    for(Src = &_sidata, Dest = &_sdata; Dest < &_edata;) {
        *Dest++ = *Src++;
    }

    for(Dest = &_sbss; Dest < &_ebss;) {
        *Dest++ = 0;
    }

    boot_main();

    _retarget_init();

    rtthread_startup();
}

__stm32_platform_section__(".isr_vector") struct vector_table_t vector_table  = {
    .initial_sp_value = &_stack,
    .reset = reset_handler,
    .nmi = nmi_handler,
    .hard_fault = hard_fault_handler,
    .memory_manage_fault = mem_manage_handler,
    .bus_fault = bus_fault_handler,
    .usage_fault = usage_fault_handler,
    .svcall = svcall_handler,
    .debug_monitor = debug_monitor_handler,
    .pend_sv = pendsv_handler,
    .systick = systick_handler,
    .irq = {
        [20] = can1_rx0_handler,
    }
};

