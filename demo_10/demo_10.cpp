//https://doc.cgal.org/latest/Generator/index.html#GeneratorExample_1
//https://doc.cgal.org/latest/Triangulation_2/index.html#Chapter_2D_Triangulations

#include<vector>
#include<algorithm>
#include<CGAL/point_generators_2.h>
#include<CGAL/algorithm.h>
#include<CGAL/random_selection.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include<CGAL/Delaunay_triangulation_2.h>
#include <CGAL/intersections.h>

#ifdef CGAL_USE_BASIC_VIEWER	
#include <CGAL/draw_triangulation_2.h>
#endif

using namespace CGAL;

typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point;
typedef Kernel::Line_2 Line;
typedef Kernel::Segment_2 Segment;
typedef Kernel::Intersect_2 Intersect_2;
typedef Creator_uniform_2<double, Point> Creator;
typedef std::vector<Point> Vector;
typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay;
typedef Delaunay::Vertex_iterator Vertex_iterator;
typedef Delaunay::Vertex_handle Vertex_handle;
typedef Delaunay::Edge_iterator Edge_iterator;
typedef Delaunay::Face_iterator Face_iterator;


int main() {
	Vector points;
	points.reserve(10);

	Random_points_in_disc_2<Point, Creator> g(150.0);
	CGAL::cpp11::copy_n(g, 10, std::back_inserter(points));

	Delaunay dt;

	dt.insert(points.begin(), points.end());
	

	//�������ɶ�άƽ�������㹹��һ��ֱ��
	Vector lpoints;
	lpoints.reserve(2);

	Random_points_in_disc_2<Point, Creator> g1(150.0);
	CGAL::cpp11::copy_n(g1, 2, std::back_inserter(lpoints));

	std::cout << "Line is:" << std::endl;
	std::cout << "(" << lpoints[0].x() << "," << lpoints[0].y() << ")"<< "(" << lpoints[1].x() << "," << lpoints[1].y() << ")" << std::endl;
	Line l(lpoints[0], lpoints[1]);

	std::vector<Segment> tri_edges;


	//�����ߣ��߹����߶�
	std::cout << "Edges are:" << std::endl;
	for (Edge_iterator eg = dt.edges_begin(); eg != dt.edges_end(); eg++) {
		Vertex_handle f_v1 = eg->first->vertex(dt.cw(eg->second));
		Vertex_handle f_v2 = eg->first->vertex(dt.ccw(eg->second));
		Point p1 = f_v1->point();
		Point p2 = f_v2->point();
		std::cout << "(" << p1.x() << "," << p1.y() << ")" << "(" << p2.x() << "," << p2.y() << ")" << std::endl;
		Segment temp_l(p1, p2);
		tri_edges.push_back(temp_l);
	}
	
	//��ֱ����ÿ�����߶εĽ���
	std::cout << "intersection points are:" << std::endl;
	int intersection_number = 0;
	for (int i = 0; i < tri_edges.size(); i++) {
		CGAL::cpp11::result_of<Intersect_2(Line, Segment)>::type
			result = intersection(l, tri_edges[i]);
		if (result)
		{
			const Point* p = boost::get<Point>(&*result);
			std::cout << *p << std::endl;
			intersection_number++;
		}
	}
	std::cout << "intersection points number is:" << intersection_number << std::endl;


	return EXIT_SUCCESS;
}