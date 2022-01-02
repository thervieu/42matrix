#include "../incs/Matrix.hpp"

int main(void) {
	ft::Vector<float> v1({2., 3.});
	ft::Vector<float> v2({5., 7.});
	v1.print("v1");
	v2.print("v2");
	v1.add(v2);
	v1.print("add");
	// [7.]
	// [10.]

	v1 = ft::Vector<float>({2., 3.});
	v1.sub(v2);
	v1.print("sub");
	// [-3.]
	// [-4.]

	v1 = ft::Vector<float>({2., 3.});
	v1.scl(2.);
	v1.print("scl (*2)");
	// [4.]
	// [6.]

	ft::Matrix<float> m1({{1., 2.}, {3., 4.}});
	ft::Matrix<float> m2({{7., 4.}, {-2., 2.}});
	m1.print("m1");
	m2.print("m2");
	m1.add(m2);
	m1.print("add");
	// [8., 6.]
	// [1., 6.]

	m1 = ft::Matrix<float>({{1., 2.}, {3., 4.}});
	m1.sub(m2);
	m1.print("sub");
	// [-6., -2.]
	// [5., 2.]

	m1 = ft::Matrix<float>({{1.0, 2.0}, {3.0, 4.0}});
	m1.scl(2.0);
	m1.print("scl (*2)");
	// [2.0, 4.0]
	// [6.0, 8.0]

	return (0);
}
