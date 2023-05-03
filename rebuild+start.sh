#!/bin/bash

if [ ! -d "./build" ]; then
    mkdir build
else
    rm -rf ./build
    rm -rf ./.cache
    mkdir build
fi

while getopts p:r: flag
do
    case "${flag}" in
        p) projects=${OPTARG};;
        r) run=${OPTARG};;
    esac
done

cmake -G "Unix Makefiles" -B ./build -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DENABLE_PROJECT_LIST=$projects && cmake --build ./build -j8

for app in "$run" 
do
    echo "Starting ./build/bin/$app";
    ./build/bin/$app
done
