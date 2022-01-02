#include "../incs/Vector.hpp"

int main(void) {
	ft::Vector<float> vs1({0., 0., 0.});
    vs1.print("vs1");
	std::cout << "norm_1:   " << vs1.norm_1() << std::endl;
	std::cout << "norm_e:   " << vs1.norm() << std::endl;
	std::cout << "norm_inf: " << vs1.norm_inf() << std::endl << std::endl;
	// 0, 0, 0

	vs1 = ft::Vector<float> ({1., 2., 3.});
    vs1.print("vs1");
	std::cout << "norm_1:   " << vs1.norm_1() << std::endl;
	std::cout << "norm_e:   " << vs1.norm() << std::endl;
	std::cout << "norm_inf: " << vs1.norm_inf() << std::endl << std::endl;
	// 6., 3.16227766, 3.

	vs1 = ft::Vector<float> ({-1., -2.});
    vs1.print("vs1");
	std::cout << "norm_1:   " << vs1.norm_1() << std::endl;
	std::cout << "norm_e:   " << vs1.norm() << std::endl;
	std::cout << "norm_inf: " << vs1.norm_inf() << std::endl;
	// 3., 2.236067977, 2.

    return (0);
}