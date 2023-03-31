#!/bin/bash

if [ ! -d "./build" ]; then
    mkdir build
else
    rm -rf ./build
    mkdir build
fi

cmake -B ./build && cmake --build ./build

./build/bin/rx-concepts_physx
./build/bin/rx-concepts_vk
