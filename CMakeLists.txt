# Project configure
cmake_minimum_required(VERSION 3.0)
project(Akashi VERSION 0.1 LANGUAGES CXX)

# Set variables
set(AKASHI_SRC_DIR "${Akashi_SOURCE_DIR}/src")
set(AKASHI_TEST_DIR "${Akashi_SOURCE_DIR}/test")
set(AKASHI_SRC_THIRDPATRY_DIR "${AKASHI_SRC_DIR}/thirdparty")
set(AKASHI_TEST_THIRDPARTY_DIR "${AKASHI_TEST_DIR}/thirdparty")
set(AKASHI_TESTCASE_DIR "${AKASHI_TEST_DIR}/testcase")

include_directories(${AKASHI_SRC_THIRDPATRY_DIR})
include_directories(${AKASHI_SRC_DIR})

add_subdirectory(src)
add_subdirectory(test/testcase)
