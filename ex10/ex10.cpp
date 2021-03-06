#include "../incs/Matrix.hpp"

int main(void) {
	ft::Matrix<float> m1({
		{1., 0., 0.},
		{0., 1., 0.},
		{0., 0., 1.}
		});
	m1.print("m1");
	m1.reduced_row_echelon().print("reduced_row_echelon");
	std::cout << std::endl;
	// [[1, 0, 0],
    //  [0, 1, 0],
    //  [0, 0, 1]]

	m1 = ft::Matrix<float>({
		{1., 2.},
		{3., 4.}
		});
	m1.print("m2");
	m1.reduced_row_echelon().print("reduced_row_echelon");
	std::cout << std::endl;
	// [[1, 0],
    //  [0, 1]]

	m1 = ft::Matrix<float>({
		{1., 2.},
		{2., 4.}
		});
	m1.print("m3");
	m1.reduced_row_echelon().print("reduced_row_echelon");
	std::cout << std::endl;
	// [[1, 2],
    //  [0, 0]]

	m1 = ft::Matrix<float>({
        {8., 5., -2., 4., 28.},
        {4., 2.5, 20., 4., -4.},
        {8., 5., 1., 4., 17.}
        });
	m1.print("m4");
	m1.reduced_row_echelon().print("reduced_row_echelon");
	// [[1., 0.625,  0.,   0.,  -12.16667],
    //  [0., 0.,     1.,   0.,  -3.6667  ],
    //  [0., 0.,     0.,   1.,   29.5     ]]

}