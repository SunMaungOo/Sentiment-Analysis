set(SRC "main.cpp")

add_executable(program "${SRC}")

set_property(TARGET program PROPERTY CXX_STANDARD 17)

target_link_libraries(program PUBLIC nlp)