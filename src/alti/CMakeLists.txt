cmake_minimum_required(VERSION 3.10)

project(fizzbuzz)
OPTION(BUILD_TEST "test for replacing printf" OFF) 
if(BUILD_TEST)
  add_compile_definitions(BUILD_TEST)
endif(BUILD_TEST)

# set(FIZZBUZZ_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
