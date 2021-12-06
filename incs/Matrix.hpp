#include <iostream>
#include <vector>

namespace ft {
	template <class T>
	class Matrix {
		private:
			std::vector<std::vector<T>> myMatrix;
		public:
			Matrix(size_t n, size_t m) {
				this->myMatrix = std::vector<std::vector<T>>(n, std::vector<T>(m, 0));
			};
			Matrix(const Matrix<T> & rhs) {
				this->myMatrix = rhs.myMatrix;
			};
			Matrix(const std::vector<std::vector<T>> & rhs) {
				for (int i = 0; i < rhs.size() - 1; i++) {
					if (rhs[i].size() != rhs[i + 1].size())
					{
						std::cout << "wrong size in init matrix\n";
						return ;
					}
				}
				this->myMatrix = rhs;
			};
			std::vector<std::vector<T>> &getMatrix(void) {
				return (this->myMatrix);
			};

			void add(Matrix<T> & rhs) {
				if (this->myMatrix.size() != rhs.getMatrix().size()
					|| (this->myMatrix.size() != 0 && this->myMatrix[0].size() != rhs.getMatrix()[0].size())) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->myMatrix.size(); i++) {
					for (int j = 0; j < this->myMatrix[0].size(); j++) {
						this->myMatrix[i][j] += rhs.getMatrix()[i][j];
					}
				}
			};
			void sub(Matrix<T> & rhs) {
				if (this->myMatrix.size() != rhs.getMatrix().size()
					|| (this->myMatrix.size() != 0 && this->myMatrix[0].size() != rhs.getMatrix()[0].size())) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->myMatrix.size(); i++) {
					for (int j = 0; j < this->myMatrix[0].size(); j++) {
						this->myMatrix[i][j] -= rhs.getMatrix()[i][j];
					}
				}
			};
			void scl(T scalar) {
				for (int i = 0; i < this->myMatrix.size(); i++) {
					for (int j = 0; j < this->myMatrix[0].size(); j++) {
						this->myMatrix[i][j] *= scalar;
					}
				}
			};

			void print(std::string str) {
				std::cout << str << ":\n[";
				for (int i = 0; i < this->myMatrix.size(); i++) {
					std::cout << "[";
					for (int j = 0; j < this->myMatrix[0].size(); j++) {
						std::cout << this->myMatrix[i][j] << (j != this->myMatrix[0].size() - 1 ? ", " : "");
					}
					std::cout << (i != this->myMatrix.size() - 1 ? "],\n" : "]");
				}
				std::cout << "]" << std::endl;
			};
	};
	template <class T>
	Matrix<T> lerp(Matrix<T> &lhs, Matrix<T> &rhs, float t) {
		Matrix<T> lerp_matrix(lhs.getMatrix().size(), lhs.getMatrix()[0].size());
		for (int i = 0; i < lhs.getMatrix().size(); i++) {
			for (int j = 0; j < lhs.getMatrix()[0].size(); j++) {
				lerp_matrix.getMatrix()[i][j] = ((1 - t) * lhs.getMatrix()[i][j]) + (t * rhs.getMatrix()[i][j]);
			}
		}
		return lerp_matrix;
	}
}
