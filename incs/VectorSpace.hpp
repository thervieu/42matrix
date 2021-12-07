#include <iostream>
#include <vector>
#include <cmath>

namespace ft {
	template <class T>
	class VectorSpace {
		public:
			std::vector<T> myVec;

			VectorSpace(size_t n) {
				this->myVec = std::vector<T>(n, 0);
			};
			VectorSpace(const VectorSpace<T> & rhs) {
				this->myVec = rhs.myVec;
			};
			VectorSpace(const std::vector<T> & rhs) {
				this->myVec = rhs;
			};
			void add(VectorSpace<T> & rhs) {
				if (this->myVec.size() != rhs.myVec.size()) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->myVec.size(); i++) {
					this->myVec[i] += rhs.myVec[i];
				}
			};
			void sub(VectorSpace<T> & rhs) {
				if (this->myVec.size() != rhs.myVec.size()) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->myVec.size(); i++) {
					this->myVec[i] -= rhs.myVec[i];
				}
			};
			void scl(T scalar) {
				for (int i = 0; i < this->myVec.size(); i++) {
					this->myVec[i] *= scalar;
				}
			};
			float norm_1(void) {
				float n1 = 0;
				for (int i = 0; i < this->myVec.size(); i++) {
					n1 += (this->myVec[i] > 0 ? this->myVec[i] : -1 * this->myVec[i]);
				}
				return (n1);
			};
			float norm(void) {
				float n_euclidean = 0;
				for (int i = 0; i < this->myVec.size(); i++) {
					n_euclidean += powf(this->myVec[i], 2);
				}
				return (powf(n_euclidean, 0.5));
			};
			float norm_inf(void) {
				T n_inf = (this->myVec[0] > 0 ? this->myVec[0] : -1 * this->myVec[0]);
				for (int i = 1; i < this->myVec.size(); i++) {
					n_inf = std::max(n_inf, (this->myVec[i] > 0 ? this->myVec[i] : -1 * this->myVec[i]));
				}
				return (n_inf);
			};

			void print(std::string str) {
				std::cout << str << ": [";
				for (int i = 0; i < this->myVec.size(); i++) {
					std::cout << this->myVec[i] << (i != this->myVec.size() - 1 ? ", " : "");
				}
				std::cout << "]" << std::endl << std::endl;
			}

	};
	template <class T>
	VectorSpace<T> linear_combination(std::vector<VectorSpace<T>> &lhs, std::vector<T> rhs) {
		VectorSpace<T> lin_comb_vs(lhs[0].myVec.size());
		for (int i = 0; i < lhs[0].myVec.size(); i++) {
			for (int j = 0; j < lhs.size(); j++) {
				lin_comb_vs.myVec[i] += rhs[j] * lhs[j].myVec[i];
			}
		}
		return lin_comb_vs;
	}
	template <class T>
	VectorSpace<T> lerp(VectorSpace<T> &lhs, VectorSpace<T> &rhs, float t) {
		VectorSpace<T> lerp_VS(lhs.myVec.size());
		for (int i = 0; i < lhs.myVec.size(); i++) {
			lerp_VS.myVec[i] += ((1 - t) * lhs.myVec[i]) + (t * rhs.myVec[i]);
		}
		return lerp_VS;
	}
	template <class T>
	float angle_cosine(VectorSpace<T> &lhs, VectorSpace<T> &rhs) {
		return dot(lhs, rhs) / (lhs.norm() * rhs.norm());
	}
	template <class T>
	T dot(VectorSpace<T> &lhs, VectorSpace<T> &rhs) {
		T rtn_me = 0;
		for (int i = 0; i < lhs.myVec.size(); i++) {
			rtn_me += lhs.myVec[i] * rhs.myVec[i];
		}
		return rtn_me;
	}
	template <class T>
	VectorSpace<T> cross_product(VectorSpace<T> &lhs, VectorSpace<T> &rhs) {
		if (lhs.myVec.size() != 3 || lhs.myVec.size() != rhs.myVec.size())
			std::cout << "error: cross_product: vector space size != 3 OR vector spaces sizedifferent\n";
		VectorSpace<T> cross_VS(lhs.myVec.size());
		cross_VS.myVec[0] = lhs.myVec[1] * rhs.myVec[2] - lhs.myVec[2] * rhs.myVec[1];
		cross_VS.myVec[1] = lhs.myVec[2] * rhs.myVec[0] - lhs.myVec[0] * rhs.myVec[2];
		cross_VS.myVec[2] = lhs.myVec[0] * rhs.myVec[1] - lhs.myVec[1] * rhs.myVec[0];
		return cross_VS;
	}
}
