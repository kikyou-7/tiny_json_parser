cmake_minimum_required(VERSION 3.0.0)
project(tiny_json_parser VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF) # 禁用编译器的拓展

include(CTest)
enable_testing()

add_executable(tiny_json_parser src/main.cpp)
add_executable(tiny_test src/tiny_test.cpp)

# add_library(value_type src/value_type.cpp)
# add_library(parser src/parser.cpp)
# target_link_libraries(tiny_json_parser parser)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
