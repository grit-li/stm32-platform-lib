#!/bin/bash
CWD=$PWD

INSTALL_PATH=$CWD/../../out/sysroot

mkdir -p $INSTALL_PATH/include/cutils
cp -ar $CWD/include/* $INSTALL_PATH/include/cutils
cp -ar $CWD/lib $INSTALL_PATH

echo "cp cutils done"