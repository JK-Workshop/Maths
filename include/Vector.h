#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>

#include <emmintrin.h>
#include <immintrin.h>

namespace jk::math {

	consteval size_t LEAST_POWER_OF_TWO_ABOVE(size_t N) {
		size_t mostSignificantBit = 0;
		while (N >>= 1)  mostSignificantBit++;
		return mostSignificantBit + 1;
	}

	template<class T, size_t R> class Vector {
	private:
		T* entry;

		auto add, neg, mul, inv;
		
		std::vector<void*> operantChain;
		std::vector<uint8_t> operatorChain;
	public:
		Vector(auto add, auto neg, auto mul, auto inv)
			: entry(new T[R]), add(add), neg(neg), mul(mul), inv(inv) {
		}

		~Vector() {
			delete[] this->entry;
		}

		constexpr size_t Size() const { return R; }

		Vector operator+(const Vector& other) const {
			Vector<T, R> tmpVec(add, neg, mul, inv);
			for (size_t i = 0; i < Size(); i++)
				tmpVec.entry[i] = add(this->entry[i], other.entry[i]);
			return tmpVec;
		}

		Vector operator-(const Vector& other) const {
			Vector<T, R> tmpVec(add, neg, mul, inv);
			for (size_t i = 0; i < Size(); i++)
				tmpVec.entry[i] = add(this->entry[i], neg(other.entry[i]));
			return tmpVec;
		}

		T Dot(const Vector& other) {
			T tmpScalar = mul(this->entry[0], other.entry[0]);
			for (size_t i = 1; i < Size(); i++)
				tmpScalar = add(tmpScalar, mul(this->entry[i], other.entry[i]));
			return tmpScalar;
		}

		void Print() {
			printf("(%lf", this->entry[0]);
			for (size_t i = 1; i < Size(); i++)
				printf(", %lf", this->entry[i]);
			printf(")\n");
		}
	};

	using Vec2f32_t = Vector <float, 2>;
	using Vec3f32_t = Vector <float, 3>;
	using Vec4f32_t = Vector <float, 4>;
	using Vec5f32_t = Vector <float, 5>;
	using Vec6f32_t = Vector <float, 6>;
	using Vec7f32_t = Vector <float, 7>;
	using Vec8f32_t = Vector <float, 8>;

	using Vec2f64_t = Vector <double, 2>;
	using Vec3f64_t = Vector <double, 3>;
	using Vec4f64_t = Vector <double, 4>;

	using Vec2i16_t  = Vector <int16_t,  2>;
	using Vec3i16_t  = Vector <int16_t,  3>;
	using Vec4i16_t  = Vector <int16_t,  4>;
	using Vec5i16_t  = Vector <int16_t,  5>;
	using Vec6i16_t  = Vector <int16_t,  6>;
	using Vec7i16_t  = Vector <int16_t,  7>;
	using Vec8i16_t  = Vector <int16_t,  8>;
	using Vec9i16_t  = Vector <int16_t,  9>;
	using Vec10i16_t = Vector <int16_t, 10>;
	using Vec11i16_t = Vector <int16_t, 11>;
	using Vec12i16_t = Vector <int16_t, 12>;
	using Vec13i16_t = Vector <int16_t, 13>;
	using Vec14i16_t = Vector <int16_t, 14>;
	using Vec15i16_t = Vector <int16_t, 15>;
	using Vec16i16_t = Vector <int16_t, 16>;

	using Vec2i32_t = Vector <int32_t, 2>;
	using Vec3i32_t = Vector <int32_t, 3>;
	using Vec4i32_t = Vector <int32_t, 4>;
	using Vec5i32_t = Vector <int32_t, 5>;
	using Vec6i32_t = Vector <int32_t, 6>;
	using Vec7i32_t = Vector <int32_t, 7>;
	using Vec8i32_t = Vector <int32_t, 8>;

	using Vec2i64_t = Vector <int64_t, 2>;
	using Vec3i64_t = Vector <int64_t, 3>;
	using Vec4i64_t = Vector <int64_t, 4>;

	using Vec2u8_t  = Vector <uint8_t,  2>;
	using Vec3u8_t  = Vector <uint8_t,  3>;
	using Vec4u8_t  = Vector <uint8_t,  4>;
	using Vec5u8_t  = Vector <uint8_t,  5>;
	using Vec6u8_t  = Vector <uint8_t,  6>;
	using Vec7u8_t  = Vector <uint8_t,  7>;
	using Vec8u8_t  = Vector <uint8_t,  8>;
	using Vec9u8_t  = Vector <uint8_t,  9>;
	using Vec10u8_t = Vector <uint8_t, 10>;
	using Vec11u8_t = Vector <uint8_t, 11>;
	using Vec12u8_t = Vector <uint8_t, 12>;
	using Vec13u8_t = Vector <uint8_t, 13>;
	using Vec14u8_t = Vector <uint8_t, 14>;
	using Vec15u8_t = Vector <uint8_t, 15>;
	using Vec16u8_t = Vector <uint8_t, 16>;
	using Vec17u8_t = Vector <uint8_t, 17>;
	using Vec18u8_t = Vector <uint8_t, 18>;
	using Vec19u8_t = Vector <uint8_t, 19>;
	using Vec20u8_t = Vector <uint8_t, 20>;
	using Vec21u8_t = Vector <uint8_t, 21>;
	using Vec22u8_t = Vector <uint8_t, 22>;
	using Vec23u8_t = Vector <uint8_t, 23>;
	using Vec24u8_t = Vector <uint8_t, 24>;
	using Vec25u8_t = Vector <uint8_t, 25>;
	using Vec26u8_t = Vector <uint8_t, 26>;
	using Vec27u8_t = Vector <uint8_t, 27>;
	using Vec28u8_t = Vector <uint8_t, 28>;
	using Vec29u8_t = Vector <uint8_t, 29>;
	using Vec30u8_t = Vector <uint8_t, 30>;
	using Vec31u8_t = Vector <uint8_t, 31>;
	using Vec32u8_t = Vector <uint8_t, 32>;

	using Vec2u16_t  = Vector <uint16_t,  2>;
	using Vec3u16_t  = Vector <uint16_t,  3>;
	using Vec4u16_t  = Vector <uint16_t,  4>;
	using Vec5u16_t  = Vector <uint16_t,  5>;
	using Vec6u16_t  = Vector <uint16_t,  6>;
	using Vec7u16_t  = Vector <uint16_t,  7>;
	using Vec8u16_t  = Vector <uint16_t,  8>;
	using Vec9u16_t  = Vector <uint16_t,  9>;
	using Vec10u16_t = Vector <uint16_t, 10>;
	using Vec11u16_t = Vector <uint16_t, 11>;
	using Vec12u16_t = Vector <uint16_t, 12>;
	using Vec13u16_t = Vector <uint16_t, 13>;
	using Vec14u16_t = Vector <uint16_t, 14>;
	using Vec15u16_t = Vector <uint16_t, 15>;
	using Vec16u16_t = Vector <uint16_t, 16>;

	using Vec2u32_t = Vector <uint32_t, 2>;
	using Vec3u32_t = Vector <uint32_t, 3>;
	using Vec4u32_t = Vector <uint32_t, 4>;
	using Vec5u32_t = Vector <uint32_t, 5>;
	using Vec6u32_t = Vector <uint32_t, 6>;
	using Vec7u32_t = Vector <uint32_t, 7>;
	using Vec8u32_t = Vector <uint32_t, 8>;

	using Vec2u64_t = Vector <uint64_t, 2>;
	using Vec3u64_t = Vector <uint64_t, 3>;
	using Vec4u64_t = Vector <uint64_t, 4>;
}