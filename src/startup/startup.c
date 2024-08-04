#include "stm32_gcc_attribute.h"
#include "tag.h"
#include "retarget.h"
#include "rtthread.h"
#include "stm32/interrupt_vector_table.h"

extern unsigned int _sidata;
extern unsigned int _sdata;
extern unsigned int _edata;
extern unsigned int _sbss;
extern unsigned int _ebss;
extern unsigned int _stack;

void boot_main(void);
#pragma weak boot_main = null_handler

static void null_handler(void)
{
}

static struct vector_table_t vector_table  = {
    .initial_sp_value = &_stack,
    .reset = null_handler,
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

static void relocate_vector(void)
{
    volatile struct vector_table_t* src = &vector_table;
    volatile struct vector_table_t* dst = (struct vector_table_t *)0x20000000;

    for(int i = 0; i < sizeof(vector_table) / sizeof(struct vector_table_t); i++) {
        *dst++ = *src++;
    }
    irq_set_vector_table(0x20000000, 0x000000);
}

__stm32_platform_section__(".isr_vector") void start_rtthread_kernel(int zero, int arch, unsigned int params)
{
    volatile unsigned char* src = (unsigned char *)params;
    volatile unsigned char* dst = (unsigned char *)STM32_TAG_ADDR;
    for(int i = 0; i < STM32_TAG_SIZE; i++) {
        *dst ++  = *src++;
    }
   
    volatile unsigned int* Src;
    volatile unsigned int* Dest;
    for(Src = &_sidata, Dest = &_sdata; Dest < &_edata;) {
        *Dest++ = *Src++;
    }

    for(Dest = &_sbss; Dest < &_ebss;) {
        *Dest++ = 0;
    }
    load_tag(STM32_TAG_ADDR);
    relocate_vector();
    boot_main();
    _retarget_init();
    rtthread_startup();
}
