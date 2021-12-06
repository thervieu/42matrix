#include "../incs/VectorSpace.hpp"

int main(void) {
	std::cout << "Linear combination\n";
	std::cout << "Example1\n";
	std::cout << "Vector Spaces:\n[1, 0, 0],\n[0, 1, 0],\n[0, 0, 1]\n\n";
	std::cout << "Scalar vector is\n[10,\n-2 ,\n0.5]\n\n";
	
	std::vector<float> v1{10.0, -2.0, 0.5};
	std::vector<ft::VectorSpace<float>> vecOfVS1({
			ft::VectorSpace<float>({1.0, 0.0, 0.0}),
			ft::VectorSpace<float>({0.0, 1.0, 0.0}),
			ft::VectorSpace<float>({0.0, 0.0, 1.0})
		});

	linear_combination(vecOfVS1, v1).print("linear_combination");
	// [10.]
	// [-2.]
	// [0.5]

	std::cout << "\nVector Spaces:\n[1,  2,   3],\n[0, 10, -100]\n\n";
	std::cout << "Scalar vector:\n[10,\n-2]\n\n";
	std::vector<float> v2{10.0, -2.0};
	std::vector<ft::VectorSpace<float>> vecOfVS2({
			ft::VectorSpace<float>({1.0, 2.0, 3.0}),
			ft::VectorSpace<float>({0.0, 10.0, -100.0})
		});
	linear_combination(vecOfVS2, v2).print("linear_combination");
	return (0);
}
