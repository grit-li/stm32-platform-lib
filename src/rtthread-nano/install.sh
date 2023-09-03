#!/bin/bash
CWD=$PWD

INSTALL_PATH=$CWD/../../out/sysroot

mkdir -p $INSTALL_PATH/include/rtthread-nano
mkdir -p $INSTALL_PATH/include/rtthread-nano/components/cpuusage
cp -ar $CWD/include/* $INSTALL_PATH/include/rtthread-nano
cp -ar $CWD/components/cpuusage/cpuusage.h $INSTALL_PATH/include/rtthread-nano/components/cpuusage
cp -ar $CWD/lib $INSTALL_PATH

echo "cp rtthread-nano done"