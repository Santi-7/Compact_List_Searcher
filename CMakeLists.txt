cmake_minimum_required(VERSION 3.5)
project(CompactListSearcher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
        main.cpp)

add_executable(CompactListSearcher_run
        main.cpp)

include_directories(
        src)

add_subdirectory(src)

target_link_libraries(CompactListSearcher_run compactList)