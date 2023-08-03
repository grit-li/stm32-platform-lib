#!/bin/bash
CWD=$PWD

source /develop/toolchain-arm-none-eabi-minimum/environment-${1}.sh

cd $CWD/../../src
make rebuild

if [ -d $CWD/../../sample ]
then
    cd $CWD/../../sample
    make clean --no-print-directory
    make all --no-print-directory
    cp bin/* /mnt/hgfs/share/stm32
    cd -
fi
