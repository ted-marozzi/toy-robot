cmake_minimum_required(VERSION 3.8)

set(TEST_EXE toy-robot-test)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(${TEST_EXE} MainTest.cpp)

target_link_libraries(${TEST_EXE} PUBLIC gtest_main ToyRobot)
