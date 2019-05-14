cmake_minimum_required(VERSION 2.8)

project(learnCGAL)

find_package(CGAL)

include(${CGAL_USE_FILE})

add_subdirectory(demo_1)

add_subdirectory(demo_2)

add_subdirectory(demo_3)

add_subdirectory(demo_4)

add_subdirectory(demo_5)

add_subdirectory(demo_7)