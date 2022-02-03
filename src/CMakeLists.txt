
# Main executable
add_executable(${PROJECT_NAME} main.cpp)

# Local directories list here
add_subdirectory(ToyRobot)

# Include the above list in this call
target_include_directories(${PROJECT_NAME} PUBLIC ToyRobot)

# Link the above list here
target_link_directories(${PROJECT_NAME} PUBLIC ToyRobot)

# Link the libs here
target_link_libraries(${PROJECT_NAME} ToyRobot)
