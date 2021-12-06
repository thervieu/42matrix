#include "../incs/VectorSpace.hpp"
#include "../incs/Matrix.hpp"

int main(void) {
	std::cout << "Vector Spaces are [2, 3] and [5, 7]\n\n";
	ft::VectorSpace<float> vs1({2.0, 3.0});
	ft::VectorSpace<float> vs2({5.0, 7.0});
	vs1.add(vs2);
	vs1.print("add");
	// [7.0]
	// [10.0]

	vs1 = ft::VectorSpace<float>({2.0, 3.0});
	vs1.sub(vs2);
	vs1.print("sub");
	// [-3.0]
	// [-4.0]

	vs1 = ft::VectorSpace<float>({2.0, 3.0});
	vs1.scl(2.0);
	vs1.print("scl");
	// [4.0]
	// [6.0]

	std::cout << "\nMatrixes are [[1, 2], [3, 4]] and [[7, 4], [-2, 2]]\n\n";
	ft::Matrix<float> m1({{1.0, 2.0}, {3.0, 4.0}});
	ft::Matrix<float> m2({{7.0, 4.0}, {-2.0, 2.0}});
	m1.add(m2);
	m1.print("add");
	// [8.0, 6.0]
	// [1.0, 6.0]

	m1 = ft::Matrix<float>({{1.0, 2.0}, {3.0, 4.0}});
	m1.sub(m2);
	m1.print("sub");
	// [-6.0, -2.0]
	// [5.0, 2.0]

	m1 = ft::Matrix<float>({{1.0, 2.0}, {3.0, 4.0}});
	m1.scl(2.0);
	m1.print("scl");
	// [2.0, 4.0]
	// [6.0, 8.0]

	return (0);
}
