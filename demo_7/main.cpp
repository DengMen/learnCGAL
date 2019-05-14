// https://github.com/CGAL/releases/blob/891fcc2ba4d79637e31ee32bb0a3827851fb666d/examples/Boolean_set_operations_2/print_utils.h
// https://doc.cgal.org/latest/Boolean_set_operations_2/index.html

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Boolean_set_operations_2.h>
typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2                                   Point_2;
typedef CGAL::Polygon_2<Kernel>                           Polygon_2;
typedef CGAL::Polygon_with_holes_2<Kernel>                Polygon_with_holes_2;
typedef std::list<Polygon_with_holes_2>                   Pwh_list_2;

template<class Kernel, class Container>
void print_polygon (const CGAL::Polygon_2<Kernel, Container>& P)
{
  typename CGAL::Polygon_2<Kernel, Container>::Vertex_const_iterator  vit;

  std::cout << "[ " << P.size() << " vertices:";
  for (vit = P.vertices_begin(); vit != P.vertices_end(); ++vit)
    std::cout << " (" << *vit << ')';
  std::cout << " ]" << std::endl;

  return;
}

//-----------------------------------------------------------------------------
// Pretty-print a polygon with holes.
//
template<class Kernel, class Container>
void print_polygon_with_holes
    (const CGAL::Polygon_with_holes_2<Kernel, Container>& pwh)
{
  if (! pwh.is_unbounded())
  {
    std::cout << "{ Outer boundary = ";
    print_polygon (pwh.outer_boundary());
  }
  else
    std::cout << "{ Unbounded polygon." << std::endl;

  typename CGAL::Polygon_with_holes_2<Kernel,Container>::
                                             Hole_const_iterator  hit;
  unsigned int                                                     k = 1;

  std::cout << "  " << pwh.number_of_holes() << " holes:" << std::endl;
  for (hit = pwh.holes_begin(); hit != pwh.holes_end(); ++hit, ++k)
  {
    std::cout << "    Hole #" << k << " = ";
    print_polygon (*hit);
  }
  std::cout << " }" << std::endl;

  return;
}

int main ()
{
  Polygon_2 P;
  P.push_back (Point_2 (0,0));
  P.push_back (Point_2 (1000,0));
  P.push_back (Point_2 (1000,1000));
  P.push_back (Point_2 (0,1000));


  Polygon_2 Q;
  Q.push_back(Point_2 (500,500));
  Q.push_back(Point_2 (1500,500));
  Q.push_back(Point_2 (1500,1500));
  Q.push_back(Point_2 (500,1500));


    // Compute the union of P and Q.
  Polygon_with_holes_2 unionR;
  if (CGAL::join (P, Q, unionR)) {
    std::cout << "The union: ";
    print_polygon_with_holes (unionR);
  } else
    std::cout << "P and Q are disjoint and their union is trivial."
              << std::endl;
  std::cout << std::endl;

  // Compute the intersection of P and Q.
  Pwh_list_2                  intR;
  Pwh_list_2::const_iterator  it;
  CGAL::intersection (P, Q, std::back_inserter(intR));
  std::cout << "The intersection:" << std::endl;
  for (it = intR.begin(); it != intR.end(); ++it) {
    std::cout << "--> ";
    print_polygon_with_holes (*it);
  }
}