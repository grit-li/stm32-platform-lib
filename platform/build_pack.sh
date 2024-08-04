#!/bin/bash

if [ -z $BUILD_OUTPUT_PATH ]; then
export BUILD_OUTPUT_PATH=$ROOT_PATH/out
fi

if [ -d $BUILD_OUTPUT_PATH ]
then
    rm -rf $BUILD_OUTPUT_PATH
fi

export SYSROOT_PATH=${BUILD_OUTPUT_PATH}/sysroot
export SYSROOT_INCLUDE_PATH=${SYSROOT_PATH}/include
export SYSROOT_LIB_PATH=${SYSROOT_PATH}/lib
export SYSROOT_LDSCRIPTS_PATH=${SYSROOT_PATH}/ldscripts
export SYSROOT_SAMPLE_PATH=${SYSROOT_PATH}/sample

mkdir -p $BUILD_OUTPUT_PATH
mkdir -p $SYSROOT_INCLUDE_PATH
mkdir -p $SYSROOT_LIB_PATH
mkdir -p $SYSROOT_LDSCRIPTS_PATH

# copy include file.
mkdir -p $SYSROOT_INCLUDE_PATH/cutils
cp $ROOT_PATH/src/cutils/include/*.h  $SYSROOT_INCLUDE_PATH/cutils

mkdir -p $SYSROOT_INCLUDE_PATH/rtthread-nano/
cp $ROOT_PATH/src/rtthread-nano/include/*.h  $SYSROOT_INCLUDE_PATH/rtthread-nano

mkdir -p $SYSROOT_INCLUDE_PATH/rtthread-nano/components/cpuusage
cp $ROOT_PATH/src/rtthread-nano/components/cpuusage/*.h  $SYSROOT_INCLUDE_PATH/rtthread-nano/components/cpuusage

cp -r $ROOT_PATH/src/stm32-platform/stm32 $SYSROOT_INCLUDE_PATH
cp -r $ROOT_PATH/src/include/*.h $SYSROOT_INCLUDE_PATH

# copy library file.
cp $ROOT_PATH/src/cutils/lib/*.a $SYSROOT_LIB_PATH
cp $ROOT_PATH/src/rtthread-nano/lib/*.a $SYSROOT_LIB_PATH
cp $ROOT_PATH/src/stm32-platform/lib/*.a $SYSROOT_LIB_PATH
cp $ROOT_PATH/src/startup/lib/*.a $SYSROOT_LIB_PATH

# copy ldscripts file.
cp $ROOT_PATH/ldscripts/$LDSCRIPTS_PATH $SYSROOT_LDSCRIPTS_PATH

if [ $STM32_SUPPORT_SAMPLE -eq 1 ]; then
export PACK_SAMPLE=sysroot/sample
mkdir -p $SYSROOT_SAMPLE_PATH
cp $ROOT_PATH/sample/bin/*.hex $SYSROOT_SAMPLE_PATH
fi

echo "generate stm32 platform changelog"
echo "build chip:       ${BUILD_PLATFORM_CHIP}" > changelog
echo "build date:       "$(date --date="+12 hours" "+%Y-%m-%d %H:%M:%S") >> changelog
echo "build branch:     ${STM32_PLARFORM_BRANCH}" >> changelog
echo "build hash:       ${STM32_PLARFORM_HASH}" >> changelog
echo "[changelog]" >> changelog
git log --oneline --no-merges --abbrev=8 >> changelog
mv changelog $SYSROOT_LIB_PATH
# pack
PACK_VER=$(grep STM32_PLATFORM_VERSION $ROOT_PATH/src/include/stm32_version.h | awk -F '["]' '{ print $2 }')
BUILD_DATE=$(date --date="+12 hours" +%Y%m%d)
PACK_NAME=${BUILD_PLATFORM_ID}_${PACK_VER}_${BUILD_DATE}

cd $BUILD_OUTPUT_PATH
find sysroot -type f -exec md5sum {} \; > md5sums.txt
mv md5sums.txt $SYSROOT_LIB_PATH
tar -czf $PACK_NAME.tar.gz sysroot/include sysroot/lib sysroot/ldscripts $PACK_SAMPLE
md5sum $PACK_NAME.tar.gz
cd -