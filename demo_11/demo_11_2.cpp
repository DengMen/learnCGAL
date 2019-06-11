//https://doc.cgal.org/latest/Surface_mesh/index.html#Chapter_3D_Surface_mesh

#define CGAL_USE_BASIC_VIEWER
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/draw_surface_mesh.h>

typedef CGAL::Simple_cartesian<double> K;
typedef CGAL::Surface_mesh<K::Point_3> Mesh;
typedef Mesh::Vertex_index vertex_descriptor;
typedef Mesh::Face_index face_descriptor;

int main() 
{
    Mesh m;

    vertex_descriptor a = m.add_vertex(K::Point_3(0,0,0));
    vertex_descriptor b = m.add_vertex(K::Point_3(1,0,0));
    vertex_descriptor c = m.add_vertex(K::Point_3(1,1,0));
    vertex_descriptor d = m.add_vertex(K::Point_3(0,1,0));
    vertex_descriptor e = m.add_vertex(K::Point_3(0,0,1));
    vertex_descriptor f = m.add_vertex(K::Point_3(1,0,1));
    vertex_descriptor g = m.add_vertex(K::Point_3(1,1,1));
    vertex_descriptor h = m.add_vertex(K::Point_3(0,1,1));

    // Be careful for the direction
    m.add_face(a,b,c,d);
    m.add_face(e,f,b,a);
    m.add_face(c,b,f,g);
    m.add_face(c,g,h,d);
    m.add_face(e,a,d,h);
    m.add_face(e,h,g,f);

	CGAL::draw(m);

    return 0;


}