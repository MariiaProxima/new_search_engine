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
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.2/include.zip
)
FetchContent_MakeAvailable(nlohmann_json)

include_directories(${nlohmann_json_SOURCE_DIR})



add_subdirectory(src)
