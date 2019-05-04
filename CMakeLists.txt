cmake_minimum_required(VERSION 2.8)

project(learnCGAL)

find_package(CGAL)

include(${CGAL_USE_FILE})

add_subdirectory(demo_1)