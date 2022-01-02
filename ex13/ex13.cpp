#include "../incs/Matrix.hpp"

int main(void) {
	ft::Matrix<float> m1({
		{1., 0., 0.},
		{0., 1., 0.},
		{0., 0., 1.}
		});
	m1.print("m1");
	std::cout << "rank: " << m1.rank() << std::endl << std::endl;
    // 3

	m1 = ft::Matrix<float>({
		{1.,  2., 0., 0.},
		{2.,  4., 0., 0.},
		{-1., 2., 0., 0.}
		});
	m1.print("m2");
	std::cout << "rank: " << m1.rank() << std::endl << std::endl;
    // 2

	m1 = ft::Matrix<float>({
		{8.,   5., -2.},
		{4.,   7., 20.},
		{7.,   6.,  1.},
		{21., 18.,  7.}
		});
	m1.print("m3");
	std::cout << "rank: " << m1.rank() << std::endl << std::endl;
    // 3
}
