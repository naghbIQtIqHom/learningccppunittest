find_package(cgreen)

add_library(test_LifeGame SHARED
  check_LifeGame.cpp)
target_link_libraries(test_LifeGame
  cgreen
  LifeGame
)
add_test(NAME test_cgreen
 COMMAND cgreen-runner $<TARGET_FILE:test_LifeGame> --verbose
)


