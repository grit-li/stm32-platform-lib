#!/bin/bash

source $ROOT_PATH/sample/env/environment-sysroot-$BUILD_PLATFORM_ID.sh
export EXTERN_DEFINED="-D__$BUILD_PLATFORM_ID "

export LOCAL_CXXFLAGS=${EXTERN_DEFINED}
export LOCAL_CFLAGS=${EXTERN_DEFINED}
export LOCAL_ASFLAGS=${EXTERN_DEFINED}
export LOCAL_LDFLAGS=

cd $ROOT_PATH/sample
make clean
make all
cd -