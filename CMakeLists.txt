cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 26)

project(advent-of-code-c++ LANGUAGES CXX)

find_package(OpenSSL CONFIG REQUIRED)

add_library(lib STATIC lib/lib.hh)
set_target_properties(lib PROPERTIES LINKER_LANGUAGE CXX)

foreach(AOC_YEAR RANGE 2015 2015)
foreach(DAY RANGE 1 4)
string(LENGTH "${DAY}" _strlen)
if(_strlen EQUAL 1)
string(PREPEND DAY "0")
endif()
add_executable(aoc${AOC_YEAR}_day${DAY} aoc${AOC_YEAR}/day${DAY}/main.cc)
target_include_directories(aoc${AOC_YEAR}_day${DAY} PRIVATE lib)
target_link_libraries(aoc${AOC_YEAR}_day${DAY} PRIVATE lib)

if (WIN32)
  add_custom_command(TARGET aoc${AOC_YEAR}_day${DAY} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "c:/mingw64/bin/libstdc++-6.dll"
    $<TARGET_FILE_DIR:aoc${AOC_YEAR}_day${DAY}>)
endif()
endforeach()
endforeach()

target_link_libraries(aoc2015_day04 PRIVATE OpenSSL::Crypto)
if (WIN32)
target_link_options(aoc2015_day04 PRIVATE "-Xlinker" "/debug:dwarf")
endif()
