#include "../incs/Matrix.hpp"

int main(void) {
	ft::Matrix<float> m1({
		{1., 0.},
		{0., 1.}
		});
	m1.print("m1");
	m1.transpose().print("transpose");
	std::cout << std::endl;
	// [[1, 0],
    //  [0, 1]]

	m1 = ft::Matrix<float>({
		{1., 0., 0.},
		{2., 4., 0.},
		{3., 5., 6.}
		});
	m1.print("m1");
	m1.transpose().print("transpose");
	std::cout << std::endl;
	// [[1, 2, 3],
	// [0, 4, 5],
	// [0, 0, 6]]

	m1 = ft::Matrix<float>({
		{1., 2., 3.},
		{4., 5., 6.},
		{7., 8., 9.},
		{10., 11., 12.},
		{13., 14., 15.}
		});
	m1.print("m1");
	m1.transpose().print("transpose");
	// [[1, 4, 7, 10, 13],
	// [2, 5, 8, 11, 14],
	// [3, 6, 9, 12, 15]]
}