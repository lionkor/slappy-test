cmake_minimum_required(VERSION 3.1)

add_subdirectory(sfml)
include_directories("sfml/include")

project(slappy-lion-test-project)

if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /permissive- /W3")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

add_executable(test main.cpp
    Game.cpp Game.h
    Asteroids.cpp Asteroids.h
)

target_link_libraries(test sfml-graphics sfml-system sfml-window)

add_custom_command(TARGET test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_BINARY_DIR}/sfml/lib"
        $<TARGET_FILE_DIR:test>)
