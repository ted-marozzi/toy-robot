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


set(TEST_EXE toy-robot-test)

add_executable(${TEST_EXE} MainTest.cpp)

target_include_directories(${TEST_EXE} PUBLIC ToyRobot Commands Parser Table)

target_link_directories(${TEST_EXE} PUBLIC ToyRobot Commands Parser Table)

target_link_libraries(${TEST_EXE} PUBLIC gtest_main ToyRobot Commands Parser Table)
