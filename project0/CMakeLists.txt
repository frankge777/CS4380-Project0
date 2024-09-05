cmake_minimum_required(VERSION 3.10)
project(myproject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp myUFls.cpp)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL
    https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(MyTests mytest.cpp myUFls.cpp)
target_link_libraries(MyTests gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(MyTests)
