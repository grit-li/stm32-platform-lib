#!/bin/bash
CWD=$PWD

source $CWD/../../env/environment-${1}.sh
source ../build_config.sh

export LOCAL_CXXFLAGS=${EXTERN_DEFINED}
export LOCAL_CFLAGS=${EXTERN_DEFINED}
export LOCAL_ASFLAGS=${EXTERN_DEFINED}

cd $ROOT_PATH/src
make rebuild || exit -1
cd -

if [ $STM32_SUPPORT_SAMPLE -eq 1 ]; then
cd $ROOT_PATH/sample/platform/stm32
bash build_${1}.sh || exit -1
cd -
fi

bash ../build_pack.sh