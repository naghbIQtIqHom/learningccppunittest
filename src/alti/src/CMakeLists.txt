
add_library(${CMAKE_PROJECT_NAME} STATIC
  fizzbuzz.c
  write_console.c
)
# set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PUBLIC_HEADER ../include/fizzbuzz.h)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PUBLIC_HEADER fizzbuzz.h)
# target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
# #  ${CMAKE_CURRENT_SOURCE_DIR}/../include)
# # target_include_directories(${CMAKE_PROJECT_NAME}
#   ${FIZZBUZZ_INCLUDE_DIRS}
# #  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/mylib>
# #  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
# #   $<INSTALL_PUBLIC:include/fizzbuzz>  # <prefix>/include/mylib
# )
target_compile_options(${CMAKE_PROJECT_NAME}
  PRIVATE -g -w -Wall -fPIC
)
#add_compile_definitions(BUILD_TEST)
#target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC BUILD_TEST)

add_executable(print_${CMAKE_PROJECT_NAME}
  main.c
)
target_link_libraries(print_${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_PROJECT_NAME}
)
target_compile_options(print_${CMAKE_PROJECT_NAME}
  PRIVATE -Wall
)
# target_include_directories(print_${CMAKE_PROJECT_NAME}
#   PRIVATE ${FIZZBUZZ_INCLUDE_DIRS}
#)

install(TARGETS ${CMAKE_PROJECT_NAME}
  #PUBLIC_HEADER DESTINATION include/fizzbuzz
  PUBLIC_HEADER DESTINATION include/fizzbuzz
  LIBRARY       DESTINATION lib
)

install(TARGETS print_${CMAKE_PROJECT_NAME}
  RUNTIME DESTINATION bin
)
