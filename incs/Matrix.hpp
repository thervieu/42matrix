#include "VectorSpace.hpp"
#include <iostream>
#include <vector>

namespace ft {
	template <class T>
	class Matrix {
		private:
			std::vector<std::vector<T>> matrix;
		public:
			Matrix(size_t n, size_t m) {
				this->matrix = std::vector<std::vector<T>>(n, std::vector<T>(m, 0));
			};
			Matrix(const Matrix<T> & rhs) {
				this->matrix = rhs.matrix;
			};
			Matrix(const std::vector<std::vector<T>> & rhs) {
				for (int i = 0; i < rhs.size() - 1; i++) {
					if (rhs[i].size() != rhs[i + 1].size())
					{
						std::cout << "wrong size in init matrix\n";
						return ;
					}
				}
				this->matrix = rhs;
			};

			void add(Matrix<T> & rhs) {
				if (this->matrix.size() != rhs.matrix.size()
					|| (this->matrix.size() != 0 && this->matrix[0].size() != rhs.matrix[0].size())) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->matrix.size(); i++) {
					for (int j = 0; j < this->matrix[0].size(); j++) {
						this->matrix[i][j] += rhs.matrix[i][j];
					}
				}
			};
			void sub(Matrix<T> & rhs) {
				if (this->matrix.size() != rhs.matrix.size()
					|| (this->matrix.size() != 0 && this->matrix[0].size() != rhs.matrix[0].size())) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->matrix.size(); i++) {
					for (int j = 0; j < this->matrix[0].size(); j++) {
						this->matrix[i][j] -= rhs.matrix[i][j];
					}
				}
			};
			void scl(T scalar) {
				for (int i = 0; i < this->matrix.size(); i++) {
					for (int j = 0; j < this->matrix[0].size(); j++) {
						this->matrix[i][j] *= scalar;
					}
				}
			};
			VectorSpace<T> mul_vec(VectorSpace<T> & rhs) {
				VectorSpace<T> rtn_vec(this->matrix[0].size());

				for (int j = 0; j < this->matrix[0].size(); j++) {
					for (int i = 0; i < this->matrix.size(); i++) {
						rtn_vec.myVec[j] += rhs.myVec[i] * this->matrix[i][j];
					}
				}
				return rtn_vec;
			};
			Matrix<T> mul_mat(Matrix<T> & rhs) {
				if (this->matrix[0].size() != rhs.matrix.size()) {
					printf("error: mul_mat: matrixes size not compatible\n");
					return Matrix<T>(0,0);
				}
				Matrix<T> rtn_mat(this->matrix.size(), rhs.matrix[0].size());

				for (int i = 0; i < rtn_mat.matrix.size(); i++) {
					for (int j = 0; j < rtn_mat.matrix[0].size(); j++) {
						for (int k = 0; k < rhs.matrix.size(); k++) {
							rtn_mat.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
						}
					}
				}
				return rtn_mat;
			};
			T trace(void) {
				T trace = 0;
				if (this->matrix.size() != this->matrix[0].size()) {
					printf("error: trace: matrix not square\n");
					return trace;
				}
				for (int i = 0; i < this->matrix.size(); i++) {
					trace += this->matrix[i][i];
				}
				return (trace);
			};

			Matrix<T> transpose(void) {
				Matrix<T> transpose(this->matrix[0].size(), this->matrix.size());
				for (int i = 0; i < this->matrix[0].size(); i++) {
					for (int j = 0; j < this->matrix.size(); j++) {
						transpose.matrix[i][j] = this->matrix[j][i];
					}
				}
				return (transpose);
			};

			void print(std::string str) {
				std::cout << str << ":\n[";
				for (int i = 0; i < this->matrix.size(); i++) {
					std::cout << "[";
					for (int j = 0; j < this->matrix[0].size(); j++) {
						std::cout << this->matrix[i][j] << (j != this->matrix[0].size() - 1 ? ", " : "");
					}
					std::cout << (i != this->matrix.size() - 1 ? "],\n" : "]");
				}
				std::cout << "]" << std::endl << std::endl;
			};
	};
	template <class T>
	Matrix<T> lerp(Matrix<T> &lhs, Matrix<T> &rhs, float t) {
		Matrix<T> lerp_matrix(lhs.matrix.size(), lhs.matrix[0].size());
		for (int i = 0; i < lhs.matrix.size(); i++) {
			for (int j = 0; j < lhs.matrix[0].size(); j++) {
				lerp_matrix.matrix[i][j] = ((1 - t) * lhs.matrix[i][j]) + (t * rhs.matrix[i][j]);
			}
		}
		return lerp_matrix;
	}
}
