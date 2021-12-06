#include "../incs/VectorSpace.hpp"

int main(void) {
	ft::VectorSpace<float> vs1({1.0, 1.0});
	ft::VectorSpace<float> vs2({0.0, 0.0});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "dot: " << ft::dot(vs1, vs2) << std::endl << std::endl;
	// 0

	vs1 = ft::VectorSpace<float>({1, 1});
	vs2 = ft::VectorSpace<float>({1, 1});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "dot: " << ft::dot(vs1, vs2) << std::endl << std::endl;
    // 2

	vs1 = ft::VectorSpace<float>({-1.0, 6.0});
	vs2 = ft::VectorSpace<float>({3.0, 2.0});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "dot: " << ft::dot(vs1, vs2) << std::endl;
    // 9

	return (0);
}
