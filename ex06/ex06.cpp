#include "../incs/Vector.hpp"

int main(void)
{
	ft::Vector<float> vs1({0., 0., 1.});
	ft::Vector<float> vs2({1., 0., 0.});
    vs1.print("vs1");
    vs2.print("vs2");
	cross_product(vs1,vs2).print("cross_product");
    std::cout << std::endl;
	// [0., 1., 0.]

	vs1 = ft::Vector<float> ({1., 2., 3.});
	vs2 = ft::Vector<float> ({4., 5., 6.});
    vs1.print("vs1");
    vs2.print("vs2");
	cross_product(vs1,vs2).print("cross_product");
    std::cout << std::endl;
	// [-3., 6., -3.]

	vs1 = ft::Vector<float> ({4., 2., -3.});
	vs2 = ft::Vector<float> ({-2., -5., 16.});
    vs1.print("vs1");
    vs2.print("vs2");
	cross_product(vs1,vs2).print("cross_product");
	// [17., -58., -16.]
}
