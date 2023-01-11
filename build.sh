#!/bin/bash


BASE=$(dirname $BASE_SOURCE[0])
cwd=$(pwd)

cmake -DBUILD_DOC=false -DBUILD_TESTS=true -S $BASE -B $BASE/build && cd $BASE/build && make ; cd $cwd
