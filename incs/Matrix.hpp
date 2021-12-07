#include "VectorSpace.hpp"
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

			void add(Matrix<T> & rhs) {
				if (this->myMatrix.size() != rhs.myMatrix.size()
					|| (this->myMatrix.size() != 0 && this->myMatrix[0].size() != rhs.myMatrix[0].size())) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->myMatrix.size(); i++) {
					for (int j = 0; j < this->myMatrix[0].size(); j++) {
						this->myMatrix[i][j] += rhs.myMatrix[i][j];
					}
				}
			};
			void sub(Matrix<T> & rhs) {
				if (this->myMatrix.size() != rhs.myMatrix.size()
					|| (this->myMatrix.size() != 0 && this->myMatrix[0].size() != rhs.myMatrix[0].size())) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->myMatrix.size(); i++) {
					for (int j = 0; j < this->myMatrix[0].size(); j++) {
						this->myMatrix[i][j] -= rhs.myMatrix[i][j];
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
			VectorSpace<T> mul_vec(VectorSpace<T> & rhs) {
				VectorSpace<T> rtn_vec(this->myMatrix[0].size());

				for (int j = 0; j < this->myMatrix[0].size(); j++) {
					for (int i = 0; i < this->myMatrix.size(); i++) {
						rtn_vec.myVec[j] += rhs.myVec[i] * this->myMatrix[i][j];
					}
				}
				return rtn_vec;
			};
			Matrix<T> mul_mat(Matrix<T> & rhs) {
				if (this->myMatrix[0].size() != rhs.myMatrix.size()) {
					printf("error: mul_mat: matrixes size not compatible\n");
					return Matrix<T>(0,0);
				}
				Matrix<T> rtn_mat(this->myMatrix.size(), rhs.myMatrix[0].size());

				for (int i = 0; i < rtn_mat.myMatrix.size(); i++) {
					for (int j = 0; j < rtn_mat.myMatrix[0].size(); j++) {
						for (int k = 0; k < rhs.myMatrix.size(); k++) {
							rtn_mat.myMatrix[i][j] += this->myMatrix[i][k] * rhs.myMatrix[k][j];
						}
					}
				}
				return rtn_mat;
			};
			T trace(void) {
				T trace = 0;
				if (this->myMatrix.size() != this->myMatrix[0].size()) {
					printf("error: trace: matrix not square\n");
					return trace;
				}
				for (int i = 0; i < this->myMatrix.size(); i++) {
					trace += this->myMatrix[i][i];
				}
				return (trace);
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
				std::cout << "]" << std::endl << std::endl;
			};
	};
	template <class T>
	Matrix<T> lerp(Matrix<T> &lhs, Matrix<T> &rhs, float t) {
		Matrix<T> lerp_matrix(lhs.myMatrix.size(), lhs.myMatrix[0].size());
		for (int i = 0; i < lhs.myMatrix.size(); i++) {
			for (int j = 0; j < lhs.myMatrix[0].size(); j++) {
				lerp_matrix.myMatrix[i][j] = ((1 - t) * lhs.myMatrix[i][j]) + (t * rhs.myMatrix[i][j]);
			}
		}
		return lerp_matrix;
	}
}
