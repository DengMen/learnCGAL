// https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Line__3.html
// https://doc.cgal.org/latest/Kernel_23/classKernel_1_1Intersect__3.html
// https://doc.cgal.org/latest/Kernel_23/group__intersection__linear__grp.html

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/intersections.h>
typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Point_3 Point_3;
typedef K::Line_3 Line_3;
typedef K::Intersect_3 Intersect_3;

int main()
{
  Point_3 linea_b(0,0,0);
  Point_3 linea_e(1,1,1);

  Point_3 lineb_b(0,1,0);
  Point_3 lineb_e(1,0,1);

  Line_3 lina(linea_b,linea_e);
  Line_3 linb(lineb_b,lineb_e);

  CGAL::cpp11::result_of<Intersect_3(Line_3, Line_3)>::type
    result = intersection(lina, linb);
  if (result) 
  {
    const Point_3* p = boost::get<Point_3 >(&*result);
    std::cout << *p << std::endl;
  }
  return 0;
}