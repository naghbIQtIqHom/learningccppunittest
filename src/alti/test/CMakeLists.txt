find_package(cgreen)

add_library(test_fizzbuzz SHARED
  check_fizzbuzz.c
  check_print_console.c
)
target_link_libraries(test_fizzbuzz fizzbuzz cgreen)
target_include_directories(test_fizzbuzz PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../src)
#   ${FIZZBUZZ_INCLUDE_DIRS})
  
target_compile_options(test_fizzbuzz
  PRIVATE -Wall
)

add_test(NAME test_fizzbuzz
  COMMAND cgreen-runner $<TARGET_FILE:test_fizzbuzz> --verbose
)
