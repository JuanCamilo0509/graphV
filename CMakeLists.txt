cmake_minimum_required(VERSION 3.10)
project(graphV VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

#std::filesystem requires C++ standard 17+, 20 has lots of other
#nice things, I would consider C++23 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(graphV ${SRC_FILES})

target_include_directories(graphV PRIVATE include)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(graphV ${CURSES_LIBRARIES})
