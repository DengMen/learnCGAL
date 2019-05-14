// https://doc.cgal.org/latest/Triangulation_3/index.html#Chapter_3D_Triangulations
// https://github.com/Will-S/MeshSimplification/blob/8b2d67f1cc82281a4de4a37f6a21ba804b03a305/CGAL/IO/Complex_2_in_triangulation_3_file_writer.h

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_3.h>

#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_3<K>      Triangulation;
typedef Triangulation::Finite_facets_iterator Finite_facets_iterator;
typedef K::Point_3 Point_3;
typedef K::Line_3 Line_3;
typedef K::Triangle_3 Triangle_3;
typedef K::Intersect_3 Intersect_3;

int main()
{

  Point_3 linea_b(0,0,0);
  Point_3 linea_e(1,1,1);

  Line_3 lina(linea_b,linea_e);


  std::list<Point_3> L;
  L.push_front(Point_3(0,0,0));
  L.push_front(Point_3(1,0,0));
  L.push_front(Point_3(0,1,0));
  L.push_front(Point_3(0,0,1));

  Triangulation T(L.begin(), L.end());

  std::vector<Point_3> intersect_points;
  for(Finite_facets_iterator fit = T.finite_facets_begin();fit!=T.finite_facets_end();fit++)
  {
      
      Point_3 one = fit->first->vertex(T.vertex_triple_index(fit->second,0))->point();
      Point_3 two = fit->first->vertex(T.vertex_triple_index(fit->second,1))->point();
      Point_3 thr = fit->first->vertex(T.vertex_triple_index(fit->second,2))->point();

      Triangle_3 tri(one,two,thr);

      CGAL::cpp11::result_of<Intersect_3(Line_3, Triangle_3)>::type result = intersection(lina, tri);
      if (result) 
      {
        const Point_3* p = boost::get<Point_3 >(&*result);

        bool similiar = false;
        for(size_t i=0;i<intersect_points.size();i++)
        {
            Point_3 &point = intersect_points[i];
            double distance = sqrt( pow(point.x()-p->x(),2) +
                                    pow(point.y()-p->y(),2) +
                                    pow(point.z()-p->z(),2) );

            if(distance<0.000001)
                similiar = true;
        }
        if(!similiar)
            intersect_points.push_back(*p);
      }
  }

  std::cout<<"Intersect Point Number: "<<intersect_points.size()<<std::endl;
  for(size_t i=0;i<intersect_points.size();i++)
  {
      std::cout<<intersect_points[i]<<std::endl;
  }

  return 0;
}