#include "../incs/Matrix.hpp"

int main(void) {
	std::cout << "Vector Spaces are [2, 1] and [4, 2]\n\n";
	ft::VectorSpace<float> vs1({2.0, 1.0});
	ft::VectorSpace<float> vs2({4.0, 2.0});
	lerp(vs1, vs2, 0.3).print("linear interpolation");
	// [2.6]
	// [1.3]

	ft::Matrix<float> m1({
        {2.0, 1.0},
        {3.0, 4.0}
        });
	ft::Matrix<float> m2({
        {20.0, 10.0},
        {30.0, 40.0}
        });

    m1.print("m1"); m2.print("m2");

	lerp(m1, m2, 0.5).print("linear interpolation");
	// [2.6]
	// [1.3]

	return (0);
}
