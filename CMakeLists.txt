cmake_minimum_required(VERSION 3.0.0)
project(ted-toy-robot VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Sets the output dir of the exe to this level, build/ted-toy-robot.exe
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(CPack)

include(CTest)
enable_testing()

# Local directories list here
add_subdirectory(src)

set(CMAKE_BUILD_TYPE Debug)
