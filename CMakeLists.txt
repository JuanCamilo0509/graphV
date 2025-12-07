cmake_minimum_required(VERSION 3.10)
project(graphV VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(graphV ${SRC_FILES})

target_include_directories(graphV PRIVATE include)


if (WIN32)
  # Windows → PDCurses
  find_path(PDCURSES_INCLUDE_DIR NAMES curses.h pdcurses/curses.h)
  find_library(PDCURSES_LIB NAMES pdcurses REQUIRED)

  target_include_directories(graphV PRIVATE ${PDCURSES_INCLUDE_DIR})
  target_link_libraries(graphV PRIVATE ${PDCURSES_LIB})

else()
  # Linux/Unix → ncurses (CMake Curses)
  find_package(Curses REQUIRED)
  target_include_directories(graphV PRIVATE ${CURSES_INCLUDE_DIR})
  target_link_libraries(graphV PRIVATE ${CURSES_LIBRARIES})
endif()

find_package(SDL2 REQUIRED)

target_include_directories(graphV PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(graphV PRIVATE ${SDL2_LIBRARIES})
