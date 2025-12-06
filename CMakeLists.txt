cmake_minimum_required(VERSION 3.10)
project(graphV VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(graphV ${SRC_FILES})

target_include_directories(graphV PRIVATE include)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(graphV ${CURSES_LIBRARIES})
