#pragma once

#include "../Vector.h"

namespace jk::math {

	template<size_t R> class Vector<int8_t, R> {
	private:
		alignas(8) int8_t entry[this->Size()];
	public:
		constexpr size_t Size() { return R; }

		Vector<int8_t, R> operator+(Vector<int8_t, R>& other) {
			if constexpr (this->Size() <= 32) {
				
			}
			else if constexpr (this->Size() <= 64) {

			}
			else;
		}
	};
}