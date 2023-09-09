#include <stdio.h>
#include <rtthread.h>
#include <rthw.h>
#include "cpuusage.h"

#define CPU_USAGE_CALC_TICK    1000
#define CPU_USAGE_LOOP        100

static ALIGN(8) rt_uint8_t cpu_use_stack[1024];
static struct rt_thread get_cpu_use_thread;

static rt_uint8_t cpu_usage_major = 0, cpu_usage_minor= 0;
static rt_uint32_t total_count = 0;

static void cpu_usage_idle_hook(void)
{
    rt_tick_t tick;
    rt_uint32_t count;
    volatile rt_uint32_t loop;

    if(total_count == 0) {
        /* get total count */
        rt_enter_critical();
        tick = rt_tick_get();
        while(rt_tick_get() - tick < CPU_USAGE_CALC_TICK) {
            total_count++;
            loop = 0;
            while(loop < CPU_USAGE_LOOP) loop++;
        }
        rt_exit_critical();
    }

    count = 0;
    /* get CPU usage */
    tick = rt_tick_get();
    while(rt_tick_get() - tick < CPU_USAGE_CALC_TICK) {
        count++;
        loop = 0;
        while(loop < CPU_USAGE_LOOP) loop++;
    }

    /* calculate major and minor */
    if(count < total_count) {
        count = total_count - count;
        cpu_usage_major = (count * 100) / total_count;
        cpu_usage_minor = ((count * 100) % total_count) * 100 / total_count;
    } else {
        total_count = count;
        cpu_usage_major = 0;
        cpu_usage_minor = 0;
    }
}

void cpu_usage_get(rt_uint8_t *major, rt_uint8_t *minor)
{
    RT_ASSERT(major != RT_NULL);
    RT_ASSERT(minor != RT_NULL);
    *major = cpu_usage_major;
    *minor = cpu_usage_minor;
}

static void get_cpu_use_thread_entry(void* parameter)
{
    rt_uint8_t major = 0;
    rt_uint8_t minor = 0;
    rt_thread_idle_sethook(cpu_usage_idle_hook);
    while(1)
    {
        cpu_usage_get(&major, &minor);
        rt_thread_mdelay(1000);
    }
}

int cpu_usage_init(void)
{
    rt_thread_init(&get_cpu_use_thread, "get cpu usage", get_cpu_use_thread_entry, RT_NULL, cpu_use_stack, sizeof(cpu_use_stack), 5, 20);
    rt_thread_startup(&get_cpu_use_thread);
    return 0;
}
INIT_APP_EXPORT(cpu_usage_init);
