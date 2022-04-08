#!/bin/bash
set -euo pipefail

mkdir lib && cd lib/ && git clone https://github.com/google/googletest.git && cd ../
cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/clang++ -S/app -B/app/build -G Ninja

cmake --build build --config Debug --target toy-robot
cmake --build build --config Debug --target toy-robot-test
