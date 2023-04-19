#!/bin/bash

if [ ! -d "./build" ]; then
    mkdir build
else
    rm -rf ./build
    mkdir build
fi

cmake -G "Unix Makefiles" -B ./build && cmake --build ./build

#-D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++

./build/bin/vk-test_physx
./build/bin/vk-test_vk
./build/bin/vk-test_sdl