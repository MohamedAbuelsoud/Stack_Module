cmake_minimum_required(VERSION 3.25)

project(App)

find_package(GTest REQUIRED)

include(GoogleTest)

enable_testing()

set(SRC_TEST module_test.cpp)
set(SRC_FILE module.cpp)


add_executable(
    ${PROJECT_NAME}
    ${SRC_TEST}
    ${SRC_FILE}
)

target_link_libraries(
    ${PROJECT_NAME}
    # GTest::gtest
    GTest::gtest_main
)

# gtest_discover_tests(${PROJECT_NAME})
