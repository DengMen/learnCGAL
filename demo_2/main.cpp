// https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Line__2.html
// https://doc.cgal.org/latest/Kernel_23/classKernel_1_1Intersect__2.html
// https://doc.cgal.org/latest/Kernel_23/group__intersection__linear__grp.html
// https://doc.cgal.org/latest/Kernel_23/group__intersection__linear__grp.html#gab77f3cd98c4c4ff7acff59c98ab88ff0
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/intersections.h>
#include <CGAL/Triangle_2.h>
typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef K::Line_2 Line_2;
typedef K::Intersect_2 Intersect_2;
typedef K::Triangle_2 Triangle_2;
typedef K::Segment_2 Segment_2;
int main()
{
  Line_2 line(0,-1,1);
  
  Triangle_2 triangle(Point_2(0,0), Point_2(2, 0), Point_2(1, 1.732));

  CGAL::cpp11::result_of<Intersect_2(Line_2, Triangle_2)>::type
	  result = intersection(line, triangle);
  if (result) {
	  /* not empty */
	  if (const Point_2 *p = boost::get<Point_2>(&*result)) {
		  std::cout <<"Points intersect:" << std::endl;
		  std::cout << *p << std::endl;
	  }
	  else {
		  std::cout << "Segment intersect:" << std::endl;
		  const Segment_2 *s = boost::get<Segment_2>(&*result);
		  std::cout << *s << std::endl;
	  }
  }
  else {
	  /* empty intersection */
	  std::cout << "None intersection!" << std::endl;
  }

  system("pause");
  return 0;
}