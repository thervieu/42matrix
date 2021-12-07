#include "../incs/Matrix.hpp"

int main(void) {
	ft::Matrix<float> m1({
		{1.0, 0.0},
		{0.0, 1.0}
		});
	m1.print("m1");
	m1.transpose().print("transpose");
	std::cout << std::endl;
	// [[1, 0],
    //  [0, 1]]

	m1 = ft::Matrix<float>({
		{1.0, 0.0, 0.0},
		{2.0, 4.0, 0.0},
		{3.0, 5.0, 6.0}
		});
	m1.print("m1");
	m1.transpose().print("transpose");
	std::cout << std::endl;
	// 9.0

	m1 = ft::Matrix<float>({
		{1.0, 2.0, 3.0},
		{4.0, 5.0, 6.0},
		{7.0, 8.0, 9.0},
		{10.0, 11.0, 12.0},
		{13.0, 14.0, 15.0}
		});
	m1.print("m1");
	m1.transpose().print("transpose");
	std::cout << std::endl;
	// 21.0
}