//https://doc.cgal.org/latest/Triangulation_3/classCGAL_1_1Triangulation__3.html#aa100228164b0cf78d5c2b1009c2df258

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_3.h>
#include <CGAL/point_generators_3.h>
#define CGAL_USE_BASIC_VIEWER
#include <CGAL/draw_triangulation_3.h>
#include <CGAL/intersections.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_3<K>                   DT3;
typedef CGAL::Creator_uniform_3<double, K::Point_3>          Creator;
typedef K::Point_3 Point;
typedef std::vector<Point> Vector;
typedef K::Line_3 Line;
typedef K::Intersect_3 Intersect_3;
typedef DT3::Facet_iterator Facets_iterator;
typedef K::Triangle_3 Triangle;

int main()
{
	std::vector<K::Point_3> t_points;
	CGAL::Random_points_in_sphere_3<K::Point_3, Creator> g(1.0);
	CGAL::cpp11::copy_n(g, 10, std::back_inserter(t_points));

	DT3 dt3(t_points.begin(), t_points.end());

	Vector lpoints;
	lpoints.reserve(2);
	CGAL::Random_points_in_sphere_3<K::Point_3, Creator> gl(1.0);
	CGAL::cpp11::copy_n(gl, 2, std::back_inserter(lpoints));

	std::cout << "Line is:" << std::endl;
	std::cout << "(" << lpoints[0].x() << "," << lpoints[0].y() << "," << lpoints[0].z() << ")" << "(" << lpoints[1].x() << "," << lpoints[1].y()  << "," << lpoints[0].z()<< ")" << std::endl;
	Line l(lpoints[0], lpoints[1]);

	std::cout << "intersection points are:" << std::endl;
	int intersection_number = 0;
	for (Facets_iterator face_iter = dt3.facets_begin(); face_iter != dt3.facets_end(); face_iter++) {
		Triangle t = dt3.triangle(*face_iter);
		CGAL::cpp11::result_of<Intersect_3(Line, Triangle)>::type
			result = intersection(l, t);
		if (result)
		{
			const Point* p = boost::get<Point>(&*result);
			std::cout << *p << std::endl;
			intersection_number++;
		}
	}
	std::cout << "intersection points number is:" << intersection_number << std::endl;
	CGAL::draw(dt3);

	return EXIT_SUCCESS;
}
