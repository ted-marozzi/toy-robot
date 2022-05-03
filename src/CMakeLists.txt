# Local directories list here
add_subdirectory(ToyRobot)
add_subdirectory(ToyRobot/Commands)
add_subdirectory(ToyRobot/Parser)
add_subdirectory(ToyRobot/Table)


set(EXE toy-robot)

# Main executable
add_executable(${EXE} Main.cpp)

# Include the above list in this call
target_include_directories(${EXE} PUBLIC ToyRobot Commands Parser Table)

# Link the above list here
target_link_directories(${EXE} PUBLIC ToyRobot Commands Parser Table)

# Link the libs here
target_link_libraries(${EXE} PUBLIC ToyRobot Commands Parser Table)

SET(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

# Test
set(TEST_EXE toy-robot-test)

add_executable(${TEST_EXE} MainTest.cpp)

target_include_directories(${TEST_EXE} PUBLIC ToyRobot Commands Parser Table)

target_link_directories(${TEST_EXE} PUBLIC ToyRobot Commands Parser Table)

target_link_libraries(${TEST_EXE} PUBLIC gtest_main ToyRobot Commands Parser Table)
