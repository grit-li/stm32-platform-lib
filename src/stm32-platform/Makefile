TOP := ..

TARGET := libstm32l475

SOURCES += hw/stm32_assert.c
SOURCES += hw/cortex_m.c
SOURCES += hw/hw_rcc.c
SOURCES += hw/hw_nvic.c
SOURCES += hw/hw_scb.c
SOURCES += hw/hw_scs.c
SOURCES += hw/hw_flash.c

CFLAGS += -I$(TOP)/include -I$(TOP)/micro-libc/include

include $(TOP)/Makefile.include
