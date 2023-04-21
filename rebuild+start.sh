#!/bin/bash

if [ ! -d "./build" ]; then
    mkdir build
else
    rm -rf ./build
    mkdir build
fi

cmake -G "Unix Makefiles" -B ./build -DCMAKE_EXPORT_COMPILE_COMMANDS=1 && cmake --build ./build

for app in "$@" 
do
    echo "Starting ./build/bin/vk-test_$app";
    ./build/bin/vk-test_$app
done
