add_executable(demo_11 demo_11.cpp)

target_link_libraries(demo_11 PRIVATE
    CGAL::CGAL CGAL::CGAL_Qt5 Qt5::Gui)

add_executable(demo_11_2 demo_11_2.cpp)

target_link_libraries(demo_11_2 PRIVATE
    CGAL::CGAL CGAL::CGAL_Qt5 Qt5::Gui)

