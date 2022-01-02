#include "../incs/Matrix.hpp"

int main(void) {
	ft::Vector<float> vs1({2., 1.});
	ft::Vector<float> vs2({4., 2.});
	vs1.print("vs1"); vs2.print("vs2");
	lerp(vs1, vs2, 0.3).print("linear interpolation (0.3)");
	// [2.6]
	// [1.3]

	ft::Matrix<float> m1({
        {2., 1.},
        {3., 4.}
        });
	ft::Matrix<float> m2({
        {20., 10.},
        {30., 40.}
        });

    m1.print("m1"); m2.print("m2");

	lerp(m1, m2, 0.5).print("linear interpolation (0.5)");
	// [2.6]
	// [1.3]

	return (0);
}
