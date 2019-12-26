cmake_minimum_required(VERSION 2.9)

message("PROJECT_NAME=${PROJECT_NAME}")
project (${PROJECT_NAME})

# Set the linker flags
SET(LINK_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

include_directories(include config)
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
