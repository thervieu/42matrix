#include "../incs/VectorSpace.hpp"

int main(void)
{
	ft::VectorSpace<float> vs1({0.0, 0.0, 1.0});
	ft::VectorSpace<float> vs2({1.0, 0.0, 0.0});
    vs1.print("vs1");
    vs2.print("vs2");
	cross_product(vs1,vs2).print("cross_product");
    std::cout << std::endl;
	// [0.0, 1.0, 0.0]

	vs1 = ft::VectorSpace<float> ({1.0, 2.0, 3.0});
	vs2 = ft::VectorSpace<float> ({4.0, 5.0, 6.0});
    vs1.print("vs1");
    vs2.print("vs2");
	cross_product(vs1,vs2).print("cross_product");
    std::cout << std::endl;
	// [-3.0, 6.0, -3.0]

	vs1 = ft::VectorSpace<float> ({4.0, 2.0, -3.0});
	vs2 = ft::VectorSpace<float> ({-2.0, -5.0, 16.0});
    vs1.print("vs1");
    vs2.print("vs2");
	cross_product(vs1,vs2).print("cross_product");
	// [17.0, -58.0, -16.0]
}
