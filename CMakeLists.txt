cmake_minimum_required(VERSION 3.16)
project(CubeSolver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HDR CONFIGURE_DEPENDS include/*.h include/*.hpp)
file(GLOB_RECURSE UI  CONFIGURE_DEPENDS include/*.ui src/*.ui)

add_executable(cube_solver ${SRC} ${HDR} ${UI}
    src/View/qt/viewerqt.cpp
    src/CubeUtility.cpp)
set_target_properties(cube_solver PROPERTIES
    AUTOUIC_SEARCH_PATHS "${CMAKE_SOURCE_DIR}/include/View/qt")
target_include_directories(cube_solver PRIVATE include)
target_link_libraries(cube_solver PRIVATE Qt6::Widgets)
target_compile_options(cube_solver PRIVATE -Wall -Wextra)
