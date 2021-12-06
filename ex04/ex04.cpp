#include "../incs/VectorSpace.hpp"

int main(void) {
	ft::VectorSpace<float> vs1({1.0, 0.0});
	ft::VectorSpace<float> vs2({1.0, 0.0});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "cosine: " << ft::angle_cosine(vs1, vs2) << std::endl << std::endl;
	// 1.0

	vs1 = ft::VectorSpace<float> ({1.0, 0.0});
	vs2 = ft::VectorSpace<float> ({0.0, 1.0});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "cosine: " << ft::angle_cosine(vs1, vs2) << std::endl << std::endl;
	// 0.0

	vs1 = ft::VectorSpace<float> ({2.0, 1.0});
	vs2 = ft::VectorSpace<float> ({4.0, 2.0});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "cosine: " << ft::angle_cosine(vs1, vs2) << std::endl << std::endl;
	// 1.0

	vs1 = ft::VectorSpace<float> ({1.0, 2.0, 3.0});
	vs2 = ft::VectorSpace<float> ({4.0, 5.0, 6.0});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "cosine: " << ft::angle_cosine(vs1, vs2) << std::endl << std::endl;
	// 0.974631846

    return (0);
}