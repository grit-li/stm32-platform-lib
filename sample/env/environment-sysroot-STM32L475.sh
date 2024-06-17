export SYSROOTPATH=$ROOT_PATH/out/sysroot
export CROSS_COMPILE_DIR=/develop/toolchain-arm-none-eabi/bin
  
export PATH=$CROSS_COMPILE_DIR:$PATH

export CC="arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard "
export CXX="arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard "
export CPP="arm-none-eabi-cpp -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard "
export AS="arm-none-eabi-gcc -x assembler-with-cpp -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard "
export LD="arm-none-eabi-ld"
export GDB="arm-none-eabi-gdb-py"
export STRIP="arm-none-eabi-strip"
export RANLIB="arm-none-eabi-ranlib"
export OBJCOPY="arm-none-eabi-objcopy"
export OBJDUMP="arm-none-eabi-objdump"
export AR="arm-none-eabi-ar"
export NM="arm-none-eabi-nm"
export ASFLAGS=" -Wall -fdata-sections -ffunction-sections -Wa,-mimplicit-it=thumb "
export CFLAGS="-Og -Wall -fdata-sections -ffunction-sections -g -gdwarf-2 -I$SYSROOTPATH/include -I$SYSROOTPATH/include/rtthread-nano "
export CXXFLAGS="-Og -Wall -fdata-sections -ffunction-sections -g -gdwarf-2 "
export LDFLAGS="-Wl,--gc-sections -lc -lm --specs=nano.specs -Tldscripts/STM32L475VETx_FLASH.ld -L$SYSROOTPATH/lib -lcutils -Wl,--whole-archive -lrtthread-nano -Wl,--no-whole-archive -lSTM32L475 "
export CPPFLAGS="-g"
export ARCH=arm
export CROSS_COMPILE=arm-none-eabi-

export MAKE=make
export CAT=cat
export CP=cp
export DD=dd
export ECHO=echo
export GREP=grep
export MKDIR=mkdir
export MV=mv
export RM=rm
export SH=sh
export CD=cd
