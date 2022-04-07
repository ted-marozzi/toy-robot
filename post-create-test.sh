#!/bin/bash

ls -la
source ./post-create-dev.sh

printf "\n\nRunning Tests\n\n"
./build/toy-robot-test
