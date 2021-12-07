#include "../incs/Matrix.hpp"

int main(void) {
	ft::Matrix<float> m1({
		{1, -1},
		{-1, 1}
		});
	m1.print("m1");
	std::cout << "determinant: " << m1.determinant() << std::endl << std::endl;
	std::cout << std::endl;
	// 0

	m1 = ft::Matrix<float>({
		{2., 0., 0.},
		{0., 2., 0.},
		{0., 0., 2.}
		});
	m1.print("m1");
	std::cout << "determinant: " << m1.determinant() << std::endl << std::endl;
	std::cout << std::endl;
	// 8

	m1 = ft::Matrix<float>({
		{8., 5., -2.},
		{4., 7., 20.},
		{7., 6.,  1.}
		});
	m1.print("m1");
	std::cout << "determinant: " << m1.determinant() << std::endl << std::endl;
	// -174


	m1 = ft::Matrix<float>({
		{8., 5., -2.,  4.},
		{4., 2.5, 20., 4.},
		{8., 5.,  1.,  4.},
		{28., -4, 17., 1.},
		});
	m1.print("m1");
	std::cout << "determinant: " << m1.determinant() << std::endl;
	// 1032
}
