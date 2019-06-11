add_executable(demo_8 main_8.cpp)

target_link_libraries(demo_8 PRIVATE
    CGAL::CGAL CGAL::CGAL_Qt5 Qt5::Gui)

