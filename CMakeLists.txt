CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(LIDAR-filter)

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
SET(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
SET(TEST_DIR "${PROJECT_SOURCE_DIR}/test")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

INCLUDE_DIRECTORIES({INCLUDE_DIR})

ADD_EXECUTABLE(
    median-filter-manual-test.out
    ${TEST_DIR}/median-filter-manual-test.cpp
    ${SOURCE_DIR}/median-fiter.cpp
)

ADD_EXECUTABLE(
    range-filter-manual-test.out
    ${TEST_DIR}/range-filter-manual-test.cpp
    ${SOURCE_DIR}/range-filter.cpp
)