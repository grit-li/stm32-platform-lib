#!/bin/bash
CWD=$PWD

PACK_VER=$(cat $CWD/../../BASE-VER)
BUILD_DATE=$(date +%Y-%m-%d)
PACK_NAME=${BUILD_PLATFORM_ID}_${PACK_VER}_${BUILD_DATE}

cd $CWD/../../out
find sysroot -type f -exec md5sum {} \; > md5sums.txt
tar -czf $PACK_NAME.tar.gz sysroot md5sums.txt

md5sum $PACK_NAME.tar.gz
cd -