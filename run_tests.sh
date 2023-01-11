#!/bin/bash

BASE=$(dirname $BASE_SOURCE[0])
cwd=$(pwd)

./build.sh

cd $BASE/build/test/ && ctest --output-on-failure -vv ; cd $cwd
