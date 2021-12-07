#include "../incs/Matrix.hpp"

int main(void) {
	ft::Matrix<float> m1({
		{1.0, 0.0},
		{0.0, 1.0}
		});
	m1.print("m1");
	std::cout << "trace: " << m1.trace();
	std::cout << std::endl;
	// 2.0

	m1 = ft::Matrix<float>({
		{2.0, -5.0, 0.0},
		{4.0, 3.0, 7.0},
		{-2.0, 3.0, 4.0}
		});
	m1.print("m2");
	std::cout << "trace: " << m1.trace();
	std::cout << std::endl;
	// 9.0

	m1 = ft::Matrix<float>({
		{-2.0, 8.0, 4.0},
		{1.0, -23.0, 4.0},
		{0.0, 6.0, 4.0}
		});
	m1.print("m2");
	std::cout << "trace: " << m1.trace();
	std::cout << std::endl;
	// 21.0
}