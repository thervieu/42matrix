#include "../incs/Matrix.hpp"

int main(void) {
	ft::Matrix<float> m1({
		{1., 0.},
		{0., 1.}
		});
	m1.print("m1");
	std::cout << "trace: " << m1.trace();
	std::cout << std::endl << std::endl;
	// 2.

	m1 = ft::Matrix<float>({
		{2., -5., 0.},
		{4., 3., 7.},
		{-2., 3., 4.}
		});
	m1.print("m2");
	std::cout << "trace: " << m1.trace();
	std::cout << std::endl << std::endl;
	// 9.

	m1 = ft::Matrix<float>({
		{-2., 8., 4.},
		{1., -23., 4.},
		{0., 6., 4.}
		});
	m1.print("m2");
	std::cout << "trace: " << m1.trace();
	std::cout << std::endl;
	// 21.
}