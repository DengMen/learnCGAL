#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/point_generators_2.h>
#include <CGAL/random_polygon_2.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Boolean_set_operations_2.h>
#include <list>




typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2                                   Point_2;
typedef CGAL::Polygon_2<Kernel>                           Polygon_2;
typedef CGAL::Polygon_with_holes_2<Kernel>                Polygon_with_holes_2;
typedef std::list<Polygon_with_holes_2>                   Pwh_list_2;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
//typedef K::Point_2                                 Point_2;
typedef std::list<Point_2>                         Container;
//typedef CGAL::Polygon_2<K, Container>              Polygon_2;
typedef CGAL::Random_points_in_square_2< Point_2 > Point_generator;

#include "print_utils.h"

int main() {
	Polygon_2 triangle1;
	Polygon_2 triangle2;

	// create 50-gon and write it into a window:
	CGAL::random_polygon_2(3, std::back_inserter(triangle1),
		Point_generator(2));
	CGAL::random_polygon_2(3, std::back_inserter(triangle2),
		Point_generator(2));


	std::cout << triangle1 << std::endl;
	std::cout << triangle2 << std::endl;

	// Compute the intersection of P and Q.
	Pwh_list_2                  intR;
	Pwh_list_2::const_iterator  it;

	CGAL::intersection(triangle1, triangle2, std::back_inserter(intR));

	std::cout << "The intersection:" << std::endl;
	for (it = intR.begin(); it != intR.end(); ++it) {
		std::cout << "--> ";
		print_polygon_with_holes(*it);
	}


	return 0;
}