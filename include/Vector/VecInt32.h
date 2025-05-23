#pragma once

#include "../Vector.h"

namespace jk::math {

	template<size_t R> requires (R >= 2) class Vector<int32_t, R> {
	private:
		alignas(32) int32_t entry[LEAST_POWER_OF_TWO_ABOVE(this->Size())];
	public:
		constexpr size_t Size() { return R; }

		Vector<int32_t, R> operator+(Vector<int32_t, R>& other) {
			Vector<int32_t, R> sumVec;
			if constexpr (this->Size() <= 4) {
				__m128i a = _mm_load_si128(this->entry);
				__m128i b = _mm_load_si128(other.entry);
				__m128i sum = _mm_add_epi32(a, b);
				_mm_store_si128(sumVec.entry, sum);
			}
			else if constexpr (this->Size() <= 8) {
				__m256i a = _mm256_load_si256(this->entry);
				__m256i b = _mm256_load_si256(other.entry);
				__m256i sum = _mm256_add_epi32(a, b);
				_mm256_store_si256(sumVec.entry, sum);
			}
			else {
				// TODO: implement CUDA submission
			}
			return sumVec;
		}
	};
}