#include "../incs/Vector.hpp"

int main(void) {
	ft::Vector<float> vs1({1., 0.});
	ft::Vector<float> vs2({1., 0.});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "cosine: " << ft::angle_cosine(vs1, vs2) << std::endl << std::endl;
	// 1.

	vs1 = ft::Vector<float> ({1., 0.});
	vs2 = ft::Vector<float> ({0., 1.});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "cosine: " << ft::angle_cosine(vs1, vs2) << std::endl << std::endl;
	// 0.

	vs1 = ft::Vector<float> ({2., 1.});
	vs2 = ft::Vector<float> ({4., 2.});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "cosine: " << ft::angle_cosine(vs1, vs2) << std::endl << std::endl;
	// 1.

	vs1 = ft::Vector<float> ({1., 2., 3.});
	vs2 = ft::Vector<float> ({4., 5., 6.});
    vs1.print("vs1");
    vs2.print("vs2");
	std::cout << "cosine: " << ft::angle_cosine(vs1, vs2) << std::endl << std::endl;
	// 0.974631846

    return (0);
}