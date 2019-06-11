cmake_minimum_required(VERSION 2.8)

project(learnCGAL)

find_package(CGAL COMPONENTS Qt5 Core)
find_package(Qt5 QUIET COMPONENTS Xml Script OpenGL Svg)

include(${CGAL_USE_FILE})

add_subdirectory(demo_1)
add_subdirectory(demo_2)
add_subdirectory(demo_3)
add_subdirectory(demo_5)
add_subdirectory(demo_6)
add_subdirectory(demo_7)
add_subdirectory(demo_8)
add_subdirectory(demo_10)
add_subdirectory(demo_11)
add_subdirectory(demo_12)
