#include "../incs/Vector.hpp"

int main(void) {
	ft::Vector<float> vs1({1., 1.});
	ft::Vector<float> vs2({0., 0.});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "dot: " << ft::dot(vs1, vs2) << std::endl << std::endl;
	// 0

	vs1 = ft::Vector<float>({1, 1});
	vs2 = ft::Vector<float>({1, 1});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "dot: " << ft::dot(vs1, vs2) << std::endl << std::endl;
    // 2

	vs1 = ft::Vector<float>({-1., 6.});
	vs2 = ft::Vector<float>({3., 2.});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "dot: " << ft::dot(vs1, vs2) << std::endl;
    // 9

	return (0);
}
