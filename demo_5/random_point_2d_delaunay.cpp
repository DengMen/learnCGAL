//https://doc.cgal.org/latest/Generator/index.html#GeneratorExample_1
//https://doc.cgal.org/latest/Triangulation_2/index.html#Chapter_2D_Triangulations

#include<vector>
#include<algorithm>
#include<CGAL/point_generators_2.h>
#include<CGAL/algorithm.h>
#include<CGAL/random_selection.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include<CGAL/Delaunay_triangulation_2.h>

#define CGAL_USE_BASIC_VIEWER
#include <CGAL/draw_triangulation_2.h>


using namespace CGAL;

typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point;
typedef Creator_uniform_2<double, Point> Creator;
typedef std::vector<Point> Vector;
typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay;
typedef Delaunay::Vertex_handle Vertex_handle;

int main() {
	Vector points;
	points.reserve(10);

	Random_points_in_disc_2<Point, Creator> g(150.0);
	CGAL::cpp11::copy_n(g, 10, std::back_inserter(points));

	Delaunay dt;

	dt.insert(points.begin(), points.end());
	CGAL::draw(dt);
	
	return EXIT_SUCCESS;
}