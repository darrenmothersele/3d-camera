cmake_minimum_required(VERSION 3.5)
project(cfw)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(lib/cyril)
add_subdirectory(lib/cyril)

include_directories(lib/src)

set(SOURCE_FILES main.cpp)
add_executable(cfw ${SOURCE_FILES})
target_link_libraries(cfw Cyril)
