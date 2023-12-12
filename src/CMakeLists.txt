cmake_minimum_required(VERSION 3.2)

find_package(fabric REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(ts server.cc)
target_link_libraries(ts fbaric)
