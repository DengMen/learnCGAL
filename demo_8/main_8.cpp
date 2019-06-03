//https://doc.cgal.org/latest/Generator/index.html#GeneratorExample_1
//https://doc.cgal.org/latest/Triangulation_2/index.html#Chapter_2D_Triangulations

#include<vector>
#include<algorithm>
#include<CGAL/point_generators_2.h>
#include<CGAL/algorithm.h>
#include<CGAL/random_selection.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include<CGAL/Delaunay_triangulation_2.h>

#ifdef CGAL_USE_BASIC_VIEWER
#include <CGAL/draw_triangulation_2.h>
#endif

using namespace CGAL;

typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point;
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

	//��������
	std::cout << "Vertices are:" << std::endl;
	for (Vertex_iterator vc = dt.vertices_begin(); vc != dt.vertices_end(); vc++) {
		Point p = vc->point();
		std::cout << "(" << p.x() << "," << p.y() << ")" << std::endl;
	}

	//������
	std::cout << "Edges are:" << std::endl;
	for (Edge_iterator eg = dt.edges_begin(); eg != dt.edges_end(); eg++) {
		for (int i = 0; i < 2; i++) {
			Vertex_handle f_v1 = eg->first->vertex(dt.cw(eg->second));
			Vertex_handle f_v2 = eg->first->vertex(dt.ccw(eg->second));
			Point p1 = f_v1->point();
			Point p2 = f_v2->point();
			std::cout << "(" << p1.x() << "," << p1.y() << ")" << "(" << p2.x() << "," << p2.y() << ")"<< std::endl;
		}
		
	}

	//����������
	std::cout << "Faces are:" << std::endl;
	for (Face_iterator fa = dt.faces_begin(); fa != dt.faces_end(); fa++) {
		//һ��������������������xy����
		//std::cout <<dt.triangle(fa)<< std::endl;
		
		//��������������ÿ�������Ҫ��vertex()��x����Ҫ��hx(),y����Ҫ��hy()
		//std::cout << dt.triangle(fa).vertex(0).hx() << " " << dt.triangle(fa).vertex(0).hy() << std::endl;

		for (int i = 0; i < 3; i++) {
			Point p = fa->vertex(i)->point();
			std::cout << "(" << p.x() << "," << p.y() << ")";
		}
		std::cout<<std::endl;
	}

#ifdef CGAL_USE_BASIC_VIEWER	
	CGAL::draw(dt);
#endif


	return EXIT_SUCCESS;
}