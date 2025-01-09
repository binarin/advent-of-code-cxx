cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 26)

project(advent-of-code-c++ LANGUAGES CXX)
add_executable(aoc2015_day01 aoc2015/day01/main.cc)

if (WIN32)
  add_custom_command(TARGET aoc2015_day01 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "c:/mingw64/bin/libstdc++-6.dll"
    $<TARGET_FILE_DIR:aoc2015_day01>)
endif()
