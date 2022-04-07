cmake_minimum_required(VERSION 3.8)
project(ted-toy-robot VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CXX_STANDARD 17)

enable_testing()

# Sets the output dir of the exe to this level, build/ted-toy-robot.exe
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_BUILD_TYPE Debug)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Local directories list here
add_subdirectory(src)
add_subdirectory(lib/googletest)

