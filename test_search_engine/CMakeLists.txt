cmake_minimum_required (VERSION 3.8)
project("test_search_engine")

set(CMAKE_CXX_STANDARD 20)

add_executable(test_search_engine test_search_engine.cpp)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(test_search_engine PRIVATE gtest_main)

include(GoogleTest)

gtest_discover_tests(test_search_engine)