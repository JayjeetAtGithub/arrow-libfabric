cmake_minimum_required(VERSION 3.2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(tc client.cc)
target_link_libraries(tc mercury)

add_executable(ts server.cc)
target_link_libraries(ts mercury)
