#!/bin/bash
CWD=$PWD

mkdir -p $INSTALL_SYSROOT_PATH/include
mkdir -p $INSTALL_SYSROOT_PATH/ldscripts
cp -ar $CWD/stm32 $INSTALL_SYSROOT_PATH/include
cp -ar $CWD/lib $INSTALL_SYSROOT_PATH

cp -ar $CWD/../include $INSTALL_SYSROOT_PATH
cp -ar $CWD/../../ldscripts/$LDSCRIPTS_PATH $INSTALL_SYSROOT_PATH/ldscripts
cp -ar $CWD/../../BASE-VER $INSTALL_SYSROOT_PATH

echo "cp stm32-platform done"