cmake_minimum_required(VERSION 3.5)  
  
project(testboost LANGUAGES CXX)  
  
set(CMAKE_CXX_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
  
# 使用 find_package 而不是硬编码路径  
find_package(Boost REQUIRED COMPONENTS unit_test_framework system)  
  
if(NOT Boost_FOUND)  
    message(FATAL_ERROR "Could not find Boost")  
endif()  
  
include_directories(${Boost_INCLUDE_DIRS})  
link_directories(${Boost_LIBRARY_DIRS})  
  
add_executable(testboost main.cpp)  
  
# 使用 Boost_LIBRARIES 而不是手动指定库名  
target_link_libraries(testboost ${Boost_LIBRARIES})  
  
enable_testing()  
  
add_test(  
    NAME boost_test  
    COMMAND $<TARGET_FILE:testboost>  
)
