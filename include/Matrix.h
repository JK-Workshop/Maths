#pragma once

#include <Vector.h>

namespace jk::math {
	template<class T, size_t R, size_t C,
		T(*ADD)(const T& self, const T& other), T(*NEG)(const T& self),
		T(*MUL)(const T& self, const T& other), T(*INV)(const T& self)>
	class Matrix {
	private:
		T m_entry[C][R];
	public:
		Matrix() {
		}

		~Matrix() {
		}

		constexpr size_t Row() const { return R; }

		constexpr size_t Col() const { return C; }

		Matrix operator+(const Matrix& other) const {
			Matrix tmpMat;
			for (size_t c = 0; c < Col(); c++)
				for (size_t r = 0; r < Row(); r++)
					tmpMat[c][r] = ADD(m_entry[c][r], other.m_entry[c][r]);
		}

		Matrix operator-(const Matrix& other) const {
			Matrix tmpMat;
			for (size_t c = 0; c < Col(); c++)
				for (size_t r = 0; r < Row(); r++)
					tmpMat[c][r] = ADD(m_entry[c][r], NEG(other.m_entry[c][r]));
		}

		Vector<T, R, ADD, NEG, MUL, INV> operator*(const Vector<T, C, ADD, NEG, MUL, INV>& other) const {
			//Vector<T, R, ADD, NEG, MUL, INV> tmpVec;
			//for(size_t r=0;r<Row)
		}
	};
}