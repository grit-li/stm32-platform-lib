/* RT-Thread config file */

#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

#define RT_THREAD_PRIORITY_MAX  8
#define RT_TICK_PER_SECOND  1000
#define RT_ALIGN_SIZE   4
#define RT_NAME_MAX    8
#define RT_MAIN_THREAD_STACK_SIZE     1024

// #define RT_USING_HOOK
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_STACK_SIZE  512

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE
// #define RT_USING_HEAP
#define RT_USING_SMALL_MEM

// #define RT_DEBUG

#endif
