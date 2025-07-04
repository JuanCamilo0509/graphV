cmake_minimum_required(VERSION 3.10)
project(graphV VERSION 0.1)

aux_source_directory(src SRC_FILES)

add_executable(graphV ${SRC_FILES})

target_include_directories(graphV PRIVATE include)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(graphV ${CURSES_LIBRARIES})
