//https://doc.cgal.org/latest/Poisson_surface_reconstruction_3/index.html#Chapter_Poisson_Surface_Reconstruction
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/poisson_surface_reconstruction.h>
#include <CGAL/IO/read_xyz_points.h>

#include <vector>
#include <fstream>

// Types
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_3 Point;
typedef Kernel::Vector_3 Vector;
typedef std::pair<Point, Vector> Pwn;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;

int main(void)
{
	std::vector<Pwn> points;
	//std::ifstream stream("F:/CGAL/cgal/examples/Poisson_surface_reconstruction_3/data/kitten.xyz");
	std::ifstream stream("E:\\refine_test\\test\\useP8\\output\\experient0\\2.ply");
	if (!stream ||
		!CGAL::read_xyz_points(
			stream,
			std::back_inserter(points),
			CGAL::parameters::point_map(CGAL::First_of_pair_property_map<Pwn>()).
			normal_map(CGAL::Second_of_pair_property_map<Pwn>())))
	{
		std::cerr << "Error: cannot read file data/kitten.xyz" << std::endl;
		return EXIT_FAILURE;
	}

	Polyhedron output_mesh;

	double average_spacing = CGAL::compute_average_spacing<CGAL::Sequential_tag>
		(points, 6, CGAL::parameters::point_map(CGAL::First_of_pair_property_map<Pwn>()));

	if (CGAL::poisson_surface_reconstruction_delaunay
	(points.begin(), points.end(),
		CGAL::First_of_pair_property_map<Pwn>(),
		CGAL::Second_of_pair_property_map<Pwn>(),
		output_mesh, average_spacing))
	{
		std::ofstream out("E:\\refine_test\\test\\useP8\\output\\experient0\\P8_poisson_by_VS_2.off");
		out << output_mesh;
	}
	else
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}