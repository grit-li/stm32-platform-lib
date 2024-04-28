#!/bin/bash
CWD=$PWD

source /develop/toolchain-arm-none-eabi/env/environment-${1}.sh
source ../build_config.sh

export LOCAL_CXXFLAGS=${EXTERN_DEFINED}
export LOCAL_CFLAGS=${EXTERN_DEFINED}
export LOCAL_ASFLAGS=${EXTERN_DEFINED}

if [ -z $BUILD_OUTPUT_PATH ]; then
export BUILD_OUTPUT_PATH=$CWD/../../out
fi

if [ -d $BUILD_OUTPUT_PATH ]
then
    rm -rf $BUILD_OUTPUT_PATH
fi

export INSTALL_SYSROOT_PATH=${BUILD_OUTPUT_PATH}/sysroot/${BUILD_PLATFORM_ID}
mkdir -p $BUILD_OUTPUT_PATH
mkdir -p $INSTALL_SYSROOT_PATH

cd $CWD/../../src
make rebuild || exit -1
make install || exit -2
cd -

bash ../build_pack.sh