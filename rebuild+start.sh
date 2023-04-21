#!/bin/bash

if [ ! -d "./build" ]; then
    mkdir build
else
    rm -rf ./build
    mkdir build
fi

cmake -G "Unix Makefiles" -B ./build -DCMAKE_EXPORT_COMPILE_COMMANDS=1 && cmake --build ./build

./build/bin/vk-test_physx
./build/bin/vk-test_sdl

./build/bin/vk-test_vk_sdl_test_1
./build/bin/vk-test_vk_sdl_test_2
