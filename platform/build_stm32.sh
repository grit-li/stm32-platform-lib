#!/bin/bash

source /develop/toolchain-arm-none-eabi-minimum/environment-${1}.sh

cd ../../src
make rebuild
cd -
