cmake_minimum_required(VERSION 3.1)

project(SentAnalysis DESCRIPTION "C++ Simple Sentiment Analysis" LANGUAGES CXX)

option(BUILD_DEMO_PROJECT "Build the demo project" ON)

option(BUILD_TESTS "Build the tests" ON)

add_subdirectory("src")


if(BUILD_DEMO_PROJECT)
    add_subdirectory("app")
endif()

if(BUILD_TESTS)
    enable_testing()

    add_subdirectory("tests")
    
endif()