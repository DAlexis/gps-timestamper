cmake_minimum_required(VERSION 2.8)

project(gps-timestamper-unit-tests)

find_package (GTest REQUIRED)

include_directories (
    ${GTEST_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/../gps-timestamper/high-level/include
)

set(EXE_SOURCES
    nmea-parser-tests.cpp
    ${PROJECT_SOURCE_DIR}/../gps-timestamper/high-level/src/nmea-parser.cpp
    ${PROJECT_SOURCE_DIR}/../gps-timestamper/high-level/src/gps-data.cpp
)

add_executable(${PROJECT_NAME} ${EXE_SOURCES})

target_link_libraries (${PROJECT_NAME}
    gtest
    gtest_main
)

add_test(NAME Library_testing
         COMMAND ${PROJECT_NAME})

run_test(${PROJECT_NAME})