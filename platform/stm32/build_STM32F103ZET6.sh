#!/bin/bash

export BUILD_PLATFORM_ID=STM32F103
export BUILD_PLATFORM_CHIP=STM32F103ZET6
export LDSCRIPTS_PATH=STM32F103ZETx_FLASH.ld
export ARM_CPU_ARCH=cortex-m3

export STM32_SUPPORT_SAMPLE=1

export STM32_TAG_ADDR=0x20000000
export STM32_TAG_SIZE=1024

bash ../build_stm32.sh $BUILD_PLATFORM_ID