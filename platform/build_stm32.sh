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

bash ../build_pack.sh