#!/bin/bash

cwd=$(pwd)

cmake -DBUILD_TESTS=true -S . -B ./build && cd build && make ; cd $cwd