//https://doc.cgal.org/latest/Triangulation_3/classCGAL_1_1Triangulation__3.html#aa100228164b0cf78d5c2b1009c2df258

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_3.h>
#include <CGAL/point_generators_3.h>
#define CGAL_USE_BASIC_VIEWER
// #include <CGAL/draw_triangulation_3.h>

#include <CGAL/Surface_mesh.h>
#include <CGAL/draw_surface_mesh.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_3<K>                   DT3;
typedef K::Point_3 Point;
typedef CGAL::Creator_uniform_3<double, Point>          Creator;
typedef std::vector<Point> Vector;
typedef K::Triangle_3 Triangle;

typedef CGAL::Surface_mesh<Point> Mesh;
typedef Mesh::Vertex_index vertex_descriptor;
typedef Mesh::Face_index face_descriptor;

int main()
{
	std::vector<Point> t_points;
	CGAL::Random_points_in_sphere_3<Point, Creator> g(1.0);
	CGAL::cpp11::copy_n(g, 10, std::back_inserter(t_points));

	DT3 dt3(t_points.begin(), t_points.end());
	// CGAL::draw(dt3);

	Mesh mesh;
    

    for (auto face_iter = dt3.facets_begin(); face_iter != dt3.facets_end(); face_iter++) 
	{
		Triangle t = dt3.triangle(*face_iter);
		Point p1 = t.vertex(0);
        Point p2 = t.vertex(1);
        Point p3 = t.vertex(2);

        vertex_descriptor p1_index = mesh.add_vertex(p1);
        vertex_descriptor p2_index = mesh.add_vertex(p2);
        vertex_descriptor p3_index = mesh.add_vertex(p3);

        mesh.add_face(p1_index,p2_index,p3_index);
		
	}
	CGAL::draw(mesh);

	return EXIT_SUCCESS;
}
