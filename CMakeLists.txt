cmake_minimum_required(VERSION 3.10)
project(DungeonExplorer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect source files
file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(DungeonExplorer ${SRC_FILES})