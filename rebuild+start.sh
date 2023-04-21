#!/bin/bash

if [ ! -d "./build" ]; then
    mkdir build
else
    rm -rf ./build
    mkdir build
fi

cmake -G "Unix Makefiles" -B ./build -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug && cmake --build ./build

./build/bin/vk-test_physx
./build/bin/vk-test_vk
./build/bin/vk-test_sdl