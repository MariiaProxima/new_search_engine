cmake_minimum_required (VERSION 3.8)
project("search_engine")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

set(MY_INCLUDE_DIR
  ${CMAKE_SOURCE_DIR}/include
)
set(MY_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

include(FetchContent)

FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest.git
   GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

include_directories(${googletest_SOURCE_DIR}/include)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)