add_executable(demo_12 demo_12.cpp)

target_link_libraries(demo_12 PRIVATE
    CGAL::CGAL CGAL::CGAL_Qt5 Qt5::Gui)


