cmake_minimum_required (VERSION 3.2)

project(helloworld VERSION 0.0.1)

add_executable (helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

set_target_properties(helloworld_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  #COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(helloworld_cli helloworld)


