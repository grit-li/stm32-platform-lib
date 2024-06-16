TOP := ..

TARGET := lib$(BUILD_PLATFORM_ID)

SOURCES += hw/common/hw_common.c
SOURCES += hw/common/stm32_assert.c

include hw/$(ARM_CPU_ARCH)/sources.in

SOURCES += hal/hal_rcc.c
SOURCES += hal/hal_gpio.c
SOURCES += hal/hal_usart.c
SOURCES += hal/hal_systick.c
SOURCES += hal/hal_interrupt_vector_table.c
SOURCES += hal/hal_can.c

SOURCES += src/rcc.c
SOURCES += src/gpio.c
SOURCES += src/usart.c
SOURCES += src/systick.c
SOURCES += src/interrupt_vector_table.c
SOURCES += src/can.c

LOCAL_CFLAGS += -I$(TOP)/include -I$(TOP)/stm32-platform -I$(TOP)/stm32-platform/hw/include -I$(TOP)/stm32-platform/hw/common

include $(TOP)/Makefile.include
