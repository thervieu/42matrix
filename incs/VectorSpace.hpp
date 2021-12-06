#include <iostream>
#include <vector>

namespace ft {
	template <class T>
	class VectorSpace {
		private:
			std::vector<T> myVec;
		public:
			VectorSpace(size_t n) {
				this->myVec = std::vector<T>(n, 0);
			};
			VectorSpace(const VectorSpace<T> & rhs) {
				this->myVec = rhs.myVec;
			};
			VectorSpace(const std::vector<T> & rhs) {
				this->myVec = rhs;
			};
			std::vector<T> &getVec(void) {
				return (this->myVec);
			};
			void add(VectorSpace<T> & rhs) {
				if (this->myVec.size() != rhs.getVec().size()) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->myVec.size(); i++) {
					this->myVec[i] += rhs.getVec()[i];
				}
			};
			void sub(VectorSpace<T> & rhs) {
				if (this->myVec.size() != rhs.getVec().size()) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->myVec.size(); i++) {
					this->myVec[i] -= rhs.getVec()[i];
				}
			};
			void scl(T scalar) {
				for (int i = 0; i < this->myVec.size(); i++) {
					this->myVec[i] *= scalar;
				}
			};

			void print(std::string str) {
				std::cout << str << ": [";
				for (int i = 0; i < this->myVec.size(); i++) {
					std::cout << this->myVec[i] << (i != this->myVec.size() - 1 ? ", " : "");
				}
				std::cout << "]" << std::endl;
			}

	};
	template <class T>
	VectorSpace<T> linear_combination(std::vector<VectorSpace<T>> &lhs, std::vector<T> rhs) {
		VectorSpace<T> lin_comb_vs(lhs[0].getVec().size());
		for (int i = 0; i < lhs[0].getVec().size(); i++) {
			for (int j = 0; j < lhs.size(); j++) {
				lin_comb_vs.getVec()[i] += rhs[j] * lhs[j].getVec()[i];
			}
		}
		return lin_comb_vs;
	}
	template <class T>
	VectorSpace<T> lerp(VectorSpace<T> &lhs, VectorSpace<T> &rhs, float t) {
		VectorSpace<T> lerp_VS(lhs.getVec().size());
		for (int i = 0; i < lhs.getVec().size(); i++) {
			lerp_VS.getVec()[i] += ((1 - t) * lhs.getVec()[i]) + (t * rhs.getVec()[i]);
		}
		return lerp_VS;
	}
}
