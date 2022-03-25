
# Main executable
add_executable(${PROJECT_NAME} main.cpp)

# Local directories list here
add_subdirectory(ToyRobot)
add_subdirectory(ToyRobot/Commands)
add_subdirectory(ToyRobot/Parser)
add_subdirectory(ToyRobot/Table)

# Include the above list in this call
target_include_directories(${PROJECT_NAME} PRIVATE ToyRobot Commands)
target_include_directories(${PROJECT_NAME} PRIVATE ToyRobot Parser)
target_include_directories(${PROJECT_NAME} PRIVATE ToyRobot Table)

# Link the above list here
target_link_directories(${PROJECT_NAME} PRIVATE ToyRobot Commands)
target_link_directories(${PROJECT_NAME} PRIVATE ToyRobot Parser)
target_link_directories(${PROJECT_NAME} PRIVATE ToyRobot Table)

# Link the libs here
target_link_libraries(${PROJECT_NAME} ToyRobot Commands)
target_link_libraries(${PROJECT_NAME} ToyRobot Parser)
target_link_libraries(${PROJECT_NAME} ToyRobot Table)
