find_package(cgreen)

add_library(test_BowlingGame SHARED
  check_BowlingGame.cpp)
target_link_libraries(test_BowlingGame
  cgreen
  BowlingGame
)
add_test(NAME test_cgreen
 COMMAND cgreen-runner $<TARGET_FILE:test_BowlingGame> --verbose
)

