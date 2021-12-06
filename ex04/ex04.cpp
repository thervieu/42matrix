#include "../incs/VectorSpace.hpp"

int main(void) {
	ft::VectorSpace<float> vs1({0.0, 0.0, 0.0});
    vs1.print("vs1");
	std::cout << "norm_1:   " << vs1.norm_1() << std::endl;
	std::cout << "norm_e:   " << vs1.norm() << std::endl;
	std::cout << "norm_inf: " << vs1.norm_inf() << std::endl << std::endl;
	// 0, 0, 0

	vs1 = ft::VectorSpace<float> ({1.0, 2.0, 3.0});
    vs1.print("vs1");
	std::cout << "norm_1:   " << vs1.norm_1() << std::endl;
	std::cout << "norm_e:   " << vs1.norm() << std::endl;
	std::cout << "norm_inf: " << vs1.norm_inf() << std::endl << std::endl;
	// 6.0, 3.16227766, 3.0

	vs1 = ft::VectorSpace<float> ({-1.0, -2.0});
    vs1.print("vs1");
	std::cout << "norm_1:   " << vs1.norm_1() << std::endl;
	std::cout << "norm_e:   " << vs1.norm() << std::endl;
	std::cout << "norm_inf: " << vs1.norm_inf() << std::endl;
	// 3.0, 2.236067977, 2.0

    return (0);
}