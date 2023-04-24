cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

get_filename_component(PROJECT_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_DEBUG_POSTFIX _debug)

project(${PROJECT_NAME} VERSION 0.0.1 DESCRIPTION "C++ Basic Reactive Concepts" LANGUAGES C CXX)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

add_subdirectory(src)