#include "../incs/Matrix.hpp"

int main(void) {
	ft::Matrix<float> m1({
		{1.0, 0.0},
		{0.0, 1.0}
		});
	ft::VectorSpace<float> v1({4.0, 2.0});
	m1.print("m1"); v1.print("v1");
	m1.mul_vec(v1).print("mul_vec");
	std::cout << std::endl;
	// [4.0, 2.0]
	
	m1 = ft::Matrix<float>({
		{2.0, 0.0},
		{0.0, 2.0}
		});
	v1 = ft::VectorSpace<float>({4.0, 2.0});
	m1.print("m1"); v1.print("v1");
	m1.mul_vec(v1).print("mul_vec");
	std::cout << std::endl;
	// [8.0, 4.0]

	m1 = ft::Matrix<float>({
		{2.0, -2.0},
		{-2.0, 2.0}
		});
	v1 = ft::VectorSpace<float>({4.0, 2.0});
	m1.print("m1"); v1.print("v1");
	m1.mul_vec(v1).print("mul_vec");
	std::cout << std::endl;
	// [4.0, -4.0]

	m1 = ft::Matrix<float>({
		{1.0, 0.0},
		{0.0, 1.0}
		});
	ft::Matrix<float> m2({
		{1.0, 0.0},
		{0.0, 1.0}
		});
	m1.print("m1"); m2.print("m2");
	m1.mul_mat(m2).print("mult_mat");
	std::cout << std::endl;
	// [[1.0, 0.0],
	//  [0.0, 1.0]]

	m1 = ft::Matrix<float>({
		{1.0, 0.0},
		{0.0, 1.0}
		});
	m2 = ft::Matrix<float>({
		{2.0, 1.0},
		{4.0, 2.0}
		});
	m1.print("m1"); m2.print("m2");
	m1.mul_mat(m2).print("mult_mat");
	std::cout << std::endl;
	// [[2.0, 1.0],
	//  [4.0, 2.0]]

	m1 = ft::Matrix<float>({
		{3.0, -5.0},
		{6.0, 8.0}
		});
	m2 = ft::Matrix<float>({
		{2.0, 1.0},
		{4.0, 2.0}
		});
	m1.print("m1"); m2.print("m2");
	m1.mul_mat(m2).print("mult_mat");
	std::cout << std::endl;
	// [[-14.0, -7.0],
	//  [44.0,  22.0]]
	return (0);
}
