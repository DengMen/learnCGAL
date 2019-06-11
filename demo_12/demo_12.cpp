//https://doc.cgal.org/latest/Generator/index.html#GeneratorExample_1
//https://doc.cgal.org/latest/Triangulation_2/index.html#Chapter_2D_Triangulations
//https://doc.cgal.org/latest/Surface_mesh/index.html#Chapter_3D_Surface_mesh

#include <map>
#include <vector>
#include <algorithm>

#define CGAL_USE_BASIC_VIEWER
#include<CGAL/point_generators_2.h>
#include<CGAL/algorithm.h>
#include<CGAL/random_selection.h>
#include <CGAL/Simple_cartesian.h>
#include<CGAL/Delaunay_triangulation_2.h>
// #include <CGAL/draw_triangulation_2.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/draw_surface_mesh.h>


using namespace CGAL;

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point;
typedef std::vector<Point> Vector;
typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay;
typedef Delaunay::Vertex_iterator Vertex_iterator;
typedef Delaunay::Vertex_handle Vertex_handle;
typedef Delaunay::Edge_iterator Edge_iterator;
typedef Delaunay::Face_iterator Face_iterator;


typedef CGAL::Surface_mesh<Kernel::Point_3> Mesh;
typedef Mesh::Vertex_index vertex_descriptor;
typedef Mesh::Face_index face_descriptor;

int main() 
{
	Vector points;
	points.reserve(10);
	points.push_back(Point(10,10));
	points.push_back(Point(0,0));
	points.push_back(Point(1,10));
	points.push_back(Point(10,1));
	points.push_back(Point(20,15));
	points.push_back(Point(25,35));

	Delaunay dt;
	dt.insert(points.begin(), points.end());
	std::cout<<"Delaunay Info:"<<std::endl;
    std::cout<<"Face   Number:"<<dt.number_of_faces()<<std::endl;
    std::cout<<"Vertex Number:"<<dt.number_of_vertices()<<std::endl;


    Mesh m;
	
	std::map<Point,vertex_descriptor> point_in_mesh;
	for (Vertex_iterator vc = dt.finite_vertices_begin(); vc != dt.finite_vertices_end(); vc++) 
	{
		Point p = vc->point();	
		vertex_descriptor p_des = m.add_vertex(Kernel::Point_3(p.x(),p.y(),0));
		point_in_mesh.insert({p,p_des});
	}

	for (Face_iterator fa = dt.finite_faces_begin(); fa != dt.finite_faces_end(); fa++) 
    {
        Point p1 = fa->vertex(0)->point();
        Point p2 = fa->vertex(1)->point();
        Point p3 = fa->vertex(2)->point();
	
		// Only one side
        m.add_face(point_in_mesh[p1],point_in_mesh[p2],point_in_mesh[p3]);
	}

	std::cout<<"Mesh Info:"<<std::endl;
    std::cout<<"Face   Number:"<<m.number_of_faces()<<std::endl;
    std::cout<<"Vertex Number:"<<m.number_of_vertices()<<std::endl;

    // Show
	CGAL::draw(m,"mesh");

	return EXIT_SUCCESS;
}