#!/bin/bash
CWD=$PWD

source /develop/toolchain-arm-none-eabi/environment-${1}.sh

if [ -d $CWD/../../out ]
then
    rm -rf $CWD/../../out
fi

mkdir -p $CWD/../../out

cd $CWD/../../src
make rebuild
make install
cd -
