#!/bin/bash
CWD=$PWD

mkdir -p $INSTALL_SYSROOT_PATH/include/rtthread-nano
mkdir -p $INSTALL_SYSROOT_PATH/include/rtthread-nano/components/cpuusage
cp -ar $CWD/include/* $INSTALL_SYSROOT_PATH/include/rtthread-nano
cp -ar $CWD/components/cpuusage/cpuusage.h $INSTALL_SYSROOT_PATH/include/rtthread-nano/components/cpuusage
cp -ar $CWD/lib $INSTALL_SYSROOT_PATH

echo "cp rtthread-nano done"