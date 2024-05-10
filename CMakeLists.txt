cmake_minimum_required(VERSION 3.5)

project(testboost LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(testboost main.cpp)

target_link_libraries(testboost boost_unit_test_framework)
target_link_libraries(testboost boost_system)

enable_testing()

add_test(
        NAME boost_test
        COMMAND $<TARGET_FILE:testboost>
        )
