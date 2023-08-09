TOP := ..

TARGET := libstm32l475

SOURCES += hw/stm32_assert.c
SOURCES += hw/cortex_m.c
SOURCES += hw/hw_rcc.c
SOURCES += hw/hw_nvic.c
SOURCES += hw/hw_scb.c
SOURCES += hw/hw_scs.c
SOURCES += hw/hw_flash.c
SOURCES += hw/hw_gpio.c
SOURCES += hw/hw_usart.c
SOURCES += hw/hw_systick.c

SOURCES += hal/hal_rcc.c
SOURCES += hal/hal_gpio.c
SOURCES += hal/hal_usart.c
SOURCES += hal/hal_systick.c

SOURCES += src/rcc.c
SOURCES += src/gpio.c
SOURCES += src/usart.c
SOURCES += src/systick.c

CFLAGS += -I$(TOP)/include -I$(TOP)/micro-libc/include -I$(TOP)/stm32-platform

include $(TOP)/Makefile.include
