cmake_minimum_required(VERSION 3.14)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../extern/catch")

set(SRC "test.cpp")

add_executable(test-program "${SRC}")

target_include_directories(test-program PUBLIC "${INCLUDE_DIR}")

target_link_libraries(test-program PUBLIC nlp)
