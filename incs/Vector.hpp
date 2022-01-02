#include <iostream>
#include <vector>
#include <cmath>

namespace ft {
	template <class T>
	class Vector {
		public:
			std::vector<T> vec;

			Vector(void) {
				this->vec = std::vector<T>(0, 0);
			}
			Vector(size_t n) {
				this->vec = std::vector<T>(n, 0);
			};
			Vector(const Vector<T> & rhs) {
				this->vec = rhs.vec;
			};
			Vector(const std::vector<T> & rhs) {
				this->vec = rhs;
			};
			void add(Vector<T> & rhs) {
				if (this->vec.size() != rhs.vec.size()) {
					printf("vectors do not have the same size\n");
					return ;
				}
				for (int i = 0; i < this->vec.size(); i++) {
					this->vec[i] += rhs.vec[i];
				}
			};
			void sub(Vector<T> & rhs) {
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
	Vector<T> linear_combination(std::vector<Vector<T>> &lhs, std::vector<T> rhs) {
		if (lhs.size() != rhs.size()) {
			std::cout << "error: linear_combination: vectors's size different\n";
			return Vector<T>();
		}
		Vector<T> lin_comb_vs(lhs[0].vec.size());
		for (int i = 0; i < lhs[0].vec.size(); i++) {
			for (int j = 0; j < lhs.size(); j++) {
				lin_comb_vs.vec[i] += rhs[j] * lhs[j].vec[i];
			}
		}
		return lin_comb_vs;
	}
	template <class T>
	Vector<T> lerp(Vector<T> &lhs, Vector<T> &rhs, float t) {
		if (lhs.vec.size() != rhs.vec.size()) {
			std::cout << "error: linear_interpolation: vectors's size different\n";
			return Vector<T>();
		}
		Vector<T> lerp_VS(lhs.vec.size());
		for (int i = 0; i < lhs.vec.size(); i++) {
			lerp_VS.vec[i] += ((1 - t) * lhs.vec[i]) + (t * rhs.vec[i]);
		}
		return lerp_VS;
	}
	template <class T>
	T dot(Vector<T> &lhs, Vector<T> &rhs) {
		if (lhs.vec.size() != rhs.vec.size()) {
			std::cout << "error: dot_product: vectors size different\n";
			return 0;
		}
		T rtn_me = 0;
		for (int i = 0; i < lhs.vec.size(); i++) {
			rtn_me += lhs.vec[i] * rhs.vec[i];
		}
		return rtn_me;
	}
	template <class T>
	float angle_cosine(Vector<T> &lhs, Vector<T> &rhs) {
		if (!lhs.norm() || !rhs.norm()) {
			std::cout << "error: angle_cosine: one of the vectors is the null vector\n";
			return 0;
		}
		return dot(lhs, rhs) / (lhs.norm() * rhs.norm());
	}
	template <class T>
	Vector<T> cross_product(Vector<T> &lhs, Vector<T> &rhs) {
		if (lhs.vec.size() != 3 || lhs.vec.size() != rhs.vec.size()) {
			std::cout << "error: cross_product: vector size != 3 OR vector size different\n";
			return Vector<T>();
		}
		Vector<T> cross_VS(lhs.vec.size());
		cross_VS.vec[0] = lhs.vec[1] * rhs.vec[2] - lhs.vec[2] * rhs.vec[1];
		cross_VS.vec[1] = lhs.vec[2] * rhs.vec[0] - lhs.vec[0] * rhs.vec[2];
		cross_VS.vec[2] = lhs.vec[0] * rhs.vec[1] - lhs.vec[1] * rhs.vec[0];
		return cross_VS;
	}
}
