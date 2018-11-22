cmake_minimum_required(VERSION 2.8)

project(gps-timestamper-unit-tests)

include_directories (
    ${GTEST_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/../gps-timestamper/high-level/include
)

set(EXE_SOURCES
    nmea-parser-tests.cpp
    string-utils-tests.cpp
    pos-date-time-tests.cpp
    ${PROJECT_SOURCE_DIR}/../gps-timestamper/high-level/src/nmea-parser.cpp
    ${PROJECT_SOURCE_DIR}/../gps-timestamper/high-level/src/gps-data.cpp
    ${PROJECT_SOURCE_DIR}/../gps-timestamper/high-level/src/time-location-types.cpp
    ${PROJECT_SOURCE_DIR}/../gps-timestamper/high-level/src/string-utils.cpp
)

add_executable(${PROJECT_NAME} ${EXE_SOURCES})

target_link_libraries (${PROJECT_NAME}
    gtest
    gtest_main
)

add_test(NAME Library_testing
         COMMAND ${PROJECT_NAME})

run_test(${PROJECT_NAME})
