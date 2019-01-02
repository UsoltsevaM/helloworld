cmake_minimum_required (VERSION 3.2)

project(helloworld VERSION 0.0.1)

find_package(GTest REQUIRED)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

#add_executable(test_main_cli test_main.cpp)

set_target_properties(helloworld_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(helloworld_cli helloworld)

#target_link_libraries(test_main_cli helloworld)