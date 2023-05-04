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

if [ $projects ]; then
    cmake   -S src \
            -G "Unix Makefiles" \
            -B build \
            -DENABLE_PROJECT_LIST=$projects \
            && \
    cmake   --build \
            build \
            -j ${nproc}
else
    echo "No projects to build specified"
fi

if [ $run ]; then
    for app in "$run" 
    do
        echo "Starting ./build/bin/$app";
        ./build/bin/$app
    done
fi
