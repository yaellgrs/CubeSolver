cmake_minimum_required(VERSION 3.16)
project(CubeSolver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS src/*.cpp)

add_executable(cube_solver ${SRC})
target_include_directories(cube_solver PRIVATE include)
target_link_libraries(cube_solver PRIVATE Qt6::Widgets)
target_compile_options(cube_solver PRIVATE -Wall -Wextra