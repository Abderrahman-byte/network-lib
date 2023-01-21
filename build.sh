#!/bin/bash


BASE=$(dirname $BASE_SOURCE[0])

cmake -DBUILD_TESTS=true -S $BASE -B $BASE/build && cmake --build $BASE/build
