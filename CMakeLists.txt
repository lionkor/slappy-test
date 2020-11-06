cmake_minimum_required(VERSION 3.1)

project(slappy-lion-test-project)

if(WIN32) 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /permissive- /W3")
elseif(UNIX) 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_executable(test main.cpp)
