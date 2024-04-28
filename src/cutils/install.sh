#!/bin/bash
CWD=$PWD

mkdir -p $INSTALL_SYSROOT_PATH/include/cutils
cp -ar $CWD/include/* $INSTALL_SYSROOT_PATH/include/cutils
cp -ar $CWD/lib $INSTALL_SYSROOT_PATH

echo "cp cutils done"