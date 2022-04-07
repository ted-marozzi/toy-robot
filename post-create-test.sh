#!/bin/bash

cd src && ls -la && cd ../
source ./post-create-dev.sh

printf "\n\nRunning Tests\n\n"
./build/toy-robot-test
