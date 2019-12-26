cmake_minimum_required(VERSION 2.9)

message("PROJECT_NAME=${PROJECT_NAME}")
message("ENGINE_PATH=${ENGINE_PATH}")
project (${PROJECT_NAME})


# Set the linker flags
SET(LINK_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

include_directories(include config "${ENGINE_PATH}/include")
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE ENGINE_SRC "${ENGINE_PATH}/src/*.cpp")

SET(SOURCES "${SOURCES};${ENGINE_SRC}")

message("SOURCES=${SOURCES}")
add_executable(${PROJECT_NAME} ${SOURCES})