cmake_minimum_required(VERSION 3.0.0)
project(tiny_json_parser VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF) # 禁用编译器的拓展

include(CTest)
enable_testing()

# 静态库
add_library(json_object src/json_object.cpp)
# add_library(scanner src/scanner.cpp)
# add_library(parser src/parser.cpp)

# main 最终的可执行文件
add_executable(tiny_json_parser src/main.cpp)
target_link_libraries(tiny_json_parser json_object)
# target_link_libraries(tiny_json_parser scanner)
# target_link_libraries(tiny_json_parser parser)

# test 测试json_object.cpp
add_executable(test_jobject test/json_object_test.cpp)
target_link_libraries(test_jobject json_object)




set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
