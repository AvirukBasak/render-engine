#!/bin/bash

if ! [[ "$(basename -a $(pwd))" == "render-engine" ]]
then
    echo "build.sh: run this file from the project root 'render-engine'"
    exit 1
fi

rm build -rf; mkdir build && cd build && cmake .. && make && ls -lh lib; cd ..
