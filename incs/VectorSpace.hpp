#include <iostream>
#include <vector>
#include <cmath>

namespace ft {
	template <class T>
	class VectorSpace {
		public:
			std::vector<T> vec;

			VectorSpace(size_t n) {
				this->vec = std::vector<T>(n, 0);
			};
			VectorSpace(const VectorSpace<T> & rhs) {
				this->vec = rhs.vec;
			};
			VectorSpace(const std::vector<T> & rhs) {
				this->vec = rhs;
			};
			void add(VectorSpace<T> & rhs) {
				if (this->vec.size() != rhs.vec.size()) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->vec.size(); i++) {
					this->vec[i] += rhs.vec[i];
				}
			};
			void sub(VectorSpace<T> & rhs) {
				if (this->vec.size() != rhs.vec.size()) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->vec.size(); i++) {
					this->vec[i] -= rhs.vec[i];
				}
			};
			void scl(T scalar) {
				for (int i = 0; i < this->vec.size(); i++) {
					this->vec[i] *= scalar;
				}
			};
			float norm_1(void) {
				float n1 = 0;
				for (int i = 0; i < this->vec.size(); i++) {
					n1 += (this->vec[i] > 0 ? this->vec[i] : -1 * this->vec[i]);
				}
				return (n1);
			};
			float norm(void) {
				float n_euclidean = 0;
				for (int i = 0; i < this->vec.size(); i++) {
					n_euclidean += powf(this->vec[i], 2);
				}
				return (powf(n_euclidean, 0.5));
			};
			float norm_inf(void) {
				T n_inf = (this->vec[0] > 0 ? this->vec[0] : -1 * this->vec[0]);
				for (int i = 1; i < this->vec.size(); i++) {
					n_inf = std::max(n_inf, (this->vec[i] > 0 ? this->vec[i] : -1 * this->vec[i]));
				}
				return (n_inf);
			};

			void print(std::string str) {
				std::cout << str << ": [";
				for (int i = 0; i < this->vec.size(); i++) {
					std::cout << this->vec[i] << (i != this->vec.size() - 1 ? ", " : "");
				}
				std::cout << "]" << std::endl << std::endl;
			}

	};
	template <class T>
	VectorSpace<T> linear_combination(std::vector<VectorSpace<T>> &lhs, std::vector<T> rhs) {
		VectorSpace<T> lin_comb_vs(lhs[0].vec.size());
		for (int i = 0; i < lhs[0].vec.size(); i++) {
			for (int j = 0; j < lhs.size(); j++) {
				lin_comb_vs.vec[i] += rhs[j] * lhs[j].vec[i];
			}
		}
		return lin_comb_vs;
	}
	template <class T>
	VectorSpace<T> lerp(VectorSpace<T> &lhs, VectorSpace<T> &rhs, float t) {
		VectorSpace<T> lerp_VS(lhs.vec.size());
		for (int i = 0; i < lhs.vec.size(); i++) {
			lerp_VS.vec[i] += ((1 - t) * lhs.vec[i]) + (t * rhs.vec[i]);
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
		for (int i = 0; i < lhs.vec.size(); i++) {
			rtn_me += lhs.vec[i] * rhs.vec[i];
		}
		return rtn_me;
	}
	template <class T>
	VectorSpace<T> cross_product(VectorSpace<T> &lhs, VectorSpace<T> &rhs) {
		if (lhs.vec.size() != 3 || lhs.vec.size() != rhs.vec.size())
			std::cout << "error: cross_product: vector space size != 3 OR vector spaces sizedifferent\n";
		VectorSpace<T> cross_VS(lhs.vec.size());
		cross_VS.vec[0] = lhs.vec[1] * rhs.vec[2] - lhs.vec[2] * rhs.vec[1];
		cross_VS.vec[1] = lhs.vec[2] * rhs.vec[0] - lhs.vec[0] * rhs.vec[2];
		cross_VS.vec[2] = lhs.vec[0] * rhs.vec[1] - lhs.vec[1] * rhs.vec[0];
		return cross_VS;
	}
}
