add_library(LifeGame SHARED
  LifeGame.cpp)
set_target_properties(LifeGame PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  COMPILE_FLAGS "-fPIC -fpermissive" #-fpermissive
)

add_executable(run_LifeGame
  main.cpp)
target_link_libraries(run_LifeGame LifeGame)
set_target_properties(run_LifeGame PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  COMPILE_FLAGS -fPIC
)
