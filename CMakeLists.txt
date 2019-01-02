cmake_minimum_required (VERSION 3.2)

project(helloworld VERSION 0.0.1)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

set_target_properties(helloworld_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  #COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(helloworld_cli helloworld)

# for windows
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(./googletest)

add_executable(test_main_cli test_main.cpp)

set_target_properties(test_main_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  INCLUDE_DIRECTORIES ${gtest_SOURCE_DIR}/include
  INCLUDE_DIRECTORIES ${gtest_SOURCE_DIR}
  #COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(test_main_cli gtest gtest_main)

target_link_libraries(test_main_cli helloworld)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT m.a.usoltseva@gmail.com)

include (CPack)

enable_testing()

add_test(test_version_valid test_main_cli)
