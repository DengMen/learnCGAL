//https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Point__2.html
//https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Triangle__2.html
//https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Triangle__2.html#a80edbf8b7a35ea8de4d4970dd00cfd07


#include <iostream>
#include <vector>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Triangle_2.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point_2;
typedef CGAL::Triangle_2<Kernel> Triangle_2;


int main()
{

	Point_2 p(0, 1);
	Point_2 A(0, 0), B(10, 0), C(0, 10);
	Triangle_2 T(A,B,C);
	if(T.bounded_side(p)== CGAL::ON_UNBOUNDED_SIDE)
		std::cout << "点在三角形外部 " << std::endl;
	else if(T.bounded_side(p) == CGAL::ON_BOUNDARY)
		std::cout << "点在三角形边上 " << std::endl;
	else if (T.bounded_side(p) == CGAL::ON_BOUNDED_SIDE)
		std::cout << "点在三角形内部 " << std::endl;

	system("pause");
	return 0;
}
