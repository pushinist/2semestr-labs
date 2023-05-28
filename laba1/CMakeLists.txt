cmake_minimum_required(VERSION 3.24)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp)

target_link_libraries(lab1 sfml-graphics
        sfml-window
        sfml-system)

file(COPY "assets/bold.ttf" DESTINATION ".")