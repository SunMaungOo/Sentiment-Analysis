cmake_minimum_required(VERSION 3.14)

set(LIB_NAME "NLP")

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../include/${LIB_NAME}" 
"${CMAKE_CURRENT_SOURCE_DIR}/../extern/gsl")

set(LIB_SRC "${LIB_NAME}/NLP.cpp"
"${LIB_NAME}/StringUtils.cpp")

add_library(nlp SHARED "${LIB_SRC}")

target_include_directories(nlp PUBLIC "${INCLUDE_DIR}")

set_property(TARGET nlp PROPERTY CXX_STANDARD 17)

