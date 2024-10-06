cmake_minimum_required(VERSION 3.0)

project(LibSetTesing LANGUAGES C VERSION 0.1)

add_library(CoreLib ./testing/sets_tests_core.c ./testing/sets_tests_core.h)
add_library(LibSets ./src/libsets.c ./src/libsets.h)

add_executable(TestProg ./testing/sets_tests.c)
target_link_libraries(TestProg LibSets CoreLib)