TOP := ..

TARGET := librtthread-nano

SOURCES += src/clock.c
SOURCES += src/components.c
SOURCES += src/idle.c
SOURCES += src/ipc.c
SOURCES += src/irq.c
SOURCES += src/kservice.c
SOURCES += src/mem.c
SOURCES += src/memheap.c
SOURCES += src/mempool.c
SOURCES += src/object.c
SOURCES += src/scheduler.c
SOURCES += src/thread.c
SOURCES += src/timer.c

SOURCES += libcpu/arm/common/backtrace.c
SOURCES += libcpu/arm/common/showmem.c

SOURCES += libcpu/arm/cortex-m4/context_gcc.s
SOURCES += libcpu/arm/cortex-m4/cpuport.c

SOURCES += bsp/board_stm32l475.c

SOURCES += components/cpuusage/cpuusage.c

LOCAL_CFLAGS += -I$(TOP)/include -I$(TOP)/stm32-platform -I$(TOP)/rtthread-nano/include

include $(TOP)/Makefile.include
