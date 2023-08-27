#!/bin/bash

export BUILD_PLATFORM_ID=stm32l475

bash ../build_stm32.sh $BUILD_PLATFORM_ID
bash ../build_pack.sh
