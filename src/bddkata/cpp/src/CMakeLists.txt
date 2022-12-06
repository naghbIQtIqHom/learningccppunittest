add_library(BowlingGame SHARED
  BowlingGame.cpp)
set_target_properties(BowlingGame PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  COMPILE_FLAGS -fPIC
)

add_executable(run_BowlingGame
  main.cpp)
target_link_libraries(run_BowlingGame BowlingGame)
set_target_properties(run_BowlingGame PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  COMPILE_FLAGS -fPIC
)
