#!/bin/bash

if [ ! -d "build" ]; then
    mkdir build
else
    rm -rf build
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
    cmake   -G "Unix Makefiles" \
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
        echo "Starting bin/$app";
        bin/$app
    done
fi
