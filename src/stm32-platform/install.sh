#!/bin/bash
CWD=$PWD

INSTALL_PATH=$CWD/../../out/sysroot

mkdir -p $INSTALL_PATH/include
mkdir -p $INSTALL_PATH/ldscripts
cp -ar $CWD/stm32 $INSTALL_PATH/include
cp -ar $CWD/lib $INSTALL_PATH

cp -ar $CWD/../include $INSTALL_PATH
cp -ar $CWD/../../ldscripts $INSTALL_PATH
cp -ar $CWD/../../BASE-VER $INSTALL_PATH

echo "cp stm32-platform done"