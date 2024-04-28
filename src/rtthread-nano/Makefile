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
SOURCES += src/device.c

SOURCES += libcpu/arm/common/backtrace.c
SOURCES += libcpu/arm/common/showmem.c

SOURCES += libcpu/arm/$(ARM_CPU_ARCH)/context_gcc.s
SOURCES += libcpu/arm/$(ARM_CPU_ARCH)/cpuport.c

SOURCES += bsp/drivers/drv_gpio.c
SOURCES += bsp/board_$(BUILD_PLATFORM_ID).c

SOURCES += components/cpuusage/cpuusage.c

SOURCES += components/finsh/cmd.c
SOURCES += components/finsh/shell.c
SOURCES += components/finsh/msh.c
SOURCES += components/finsh/msh_parse.c

SOURCES += components/syslogd/datacache.c
SOURCES += components/syslogd/syslogd.c

SOURCES += components/dfs/filesystems/devfs/devfs.c
SOURCES += components/dfs/src/dfs_file.c
SOURCES += components/dfs/src/dfs_posix.c
SOURCES += components/dfs/src/dfs.c
SOURCES += components/dfs/src/dfs_fs.c
SOURCES += components/dfs/src/msh_cmd.c

SOURCES += components/drivers/misc/pin.c

LOCAL_CFLAGS += -I$(TOP)/include -I$(TOP)/stm32-platform -I$(TOP)/rtthread-nano/include
LOCAL_CFLAGS += -I$(TOP)/rtthread-nano/components/dfs/include
LOCAL_CFLAGS += -I$(TOP)/rtthread-nano/components/drivers/include
LOCAL_CFLAGS += -I$(TOP)/rtthread-nano/components/finsh

include $(TOP)/Makefile.include
