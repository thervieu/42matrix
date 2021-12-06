#include <iostream>
#include <vector>

namespace ft {
	template <class T>
	class Matrix {
		private:
			std::vector<std::vector<T>> myMatrix;
		public:
			Matrix(const Matrix<T> & rhs) {
				this->myMatrix = rhs.getMatrix();
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
			std::vector<std::vector<T>> getMatrix(void) {
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
				std::cout << str << ": [";
				for (int i = 0; i < this->myMatrix.size(); i++) {
				    std::cout << "[";
				    for (int j = 0; j < this->myMatrix[0].size(); j++) {
					    std::cout << this->myMatrix[i][j] << (j != this->myMatrix[0].size() - 1 ? ", " : "");
                    }
				    std::cout << (i != this->myMatrix.size() - 1 ? "], " : "]");
				}
				std::cout << "]" << std::endl;
			}

	};
}
