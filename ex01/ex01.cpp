#include "../incs/Vector.hpp"

int main(void) {
	std::cout << "Linear combination\n";
	std::vector<float> v1{10., -2., 0.5};
	std::vector<ft::Vector<float>> vecOfVS1({
			ft::Vector<float>({1., 0., 0.}),
			ft::Vector<float>({0., 1., 0.}),
			ft::Vector<float>({0., 0., 1.})
		});
	
	vecOfVS1[0].print("v1");
	vecOfVS1[1].print("v2");
	vecOfVS1[2].print("v3");
	std::cout << "Scalar vector:\n[10,\n-2 ,\n0.5]\n\n";
	linear_combination(vecOfVS1, v1).print("linear_combination");
	// [10.]
	// [-2.]
	// [0.5]

	std::vector<float> v2{10., -2.};
	std::vector<ft::Vector<float>> vecOfVS2({
			ft::Vector<float>({1., 2., 3.}),
			ft::Vector<float>({0., 10., -100.})
		});

	vecOfVS2[0].print("v1");
	vecOfVS2[1].print("v2");
	std::cout << "Scalar vector:\n[10,\n-2]\n\n";	
	linear_combination(vecOfVS2, v2).print("linear_combination");
	return (0);
}
