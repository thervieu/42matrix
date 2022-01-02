#include "../incs/Matrix.hpp"

int main(void) {
	ft::Matrix<float> m1({
		{1., 0.},
		{0., 1.}
		});
	ft::Vector<float> v1({4., 2.});
	m1.print("m1"); v1.print("v1");
	m1.mul_vec(v1).print("mul_vec");
	std::cout << std::endl;
	// [4., 2.]
	
	m1 = ft::Matrix<float>({
		{2., 0.},
		{0., 2.}
		});
	v1 = ft::Vector<float>({4., 2.});
	m1.print("m1"); v1.print("v1");
	m1.mul_vec(v1).print("mul_vec");
	std::cout << std::endl;
	// [8., 4.]

	m1 = ft::Matrix<float>({
		{2., -2.},
		{-2., 2.}
		});
	v1 = ft::Vector<float>({4., 2.});
	m1.print("m1"); v1.print("v1");
	m1.mul_vec(v1).print("mul_vec");
	std::cout << std::endl;
	// [4., -4.]

	m1 = ft::Matrix<float>({
		{1., 0.},
		{0., 1.}
		});
	ft::Matrix<float> m2({
		{1., 0.},
		{0., 1.}
		});
	m1.print("m1"); m2.print("m2");
	m1.mul_mat(m2).print("mult_mat");
	std::cout << std::endl;
	// [[1., 0.],
	//  [0., 1.]]

	m1 = ft::Matrix<float>({
		{1., 0.},
		{0., 1.}
		});
	m2 = ft::Matrix<float>({
		{2., 1.},
		{4., 2.}
		});
	m1.print("m1"); m2.print("m2");
	m1.mul_mat(m2).print("mult_mat");
	std::cout << std::endl;
	// [[2., 1.],
	//  [4., 2.]]

	m1 = ft::Matrix<float>({
		{3., -5.},
		{6., 8.}
		});
	m2 = ft::Matrix<float>({
		{2., 1.},
		{4., 2.}
		});
	m1.print("m1"); m2.print("m2");
	m1.mul_mat(m2).print("mult_mat");
	std::cout << std::endl;
	// [[-14., -7.],
	//  [44.,  22.]]
	return (0);
}
