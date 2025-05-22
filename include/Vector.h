#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include <immintrin.h>

namespace jk::math {
	template<class T, size_t R,
		T(*ADD)(const T& self, const T& other), T(*NEG)(const T& self),
		T(*MUL)(const T& self, const T& other), T(*INV)(const T& self)>
	class Vector {
	private:
		T* entry;
		std::vector<void*> operantChain;
		std::vector<uint8_t> operatorChain;
	public:
		Vector(const T& x, const T& y, const T& z)
			: entry(new T[R]) {
			this->entry[0] = x;
			this->entry[1] = y;
			this->entry[2] = z;
		}

		~Vector() {
			delete[] this->entry;
		}

		constexpr size_t Size() const { return R; }

		Vector operator+(const Vector& other) const {
			Vector<T, R, ADD, NEG, MUL, INV> tmpVec(0.0, 0.0, 0.0);
			for (size_t i = 0; i < Size(); i++)
				tmpVec.entry[i] = ADD(this->entry[i], other.entry[i]);
			return tmpVec;
		}

		Vector operator-(const Vector& other) const {
			Vector<T, R, ADD, NEG, MUL, INV> tmpVec(0.0, 0.0, 0.0);
			for (size_t i = 0; i < Size(); i++)
				tmpVec.entry[i] = ADD(this->entry[i], NEG(other.entry[i]));
			return tmpVec;
		}

		T Dot(const Vector& other) {
			T tmpScalar = MUL(this->entry[0], other.entry[0]);
			for (size_t i = 1; i < Size(); i++)
				tmpScalar = ADD(tmpScalar, MUL(this->entry[i], other.entry[i]));
			return tmpScalar;
		}

		void Print() {
			printf("(%lf", this->entry[0]);
			for (size_t i = 1; i < Size(); i++)
				printf(", %lf", this->entry[i]);
			printf(")\n");
		}
	};

	using Vec2f32_t = Vector <float, 2, nullptr, nullptr, nullptr, nullptr>;
	using Vec3f32_t = Vector <float, 3, nullptr, nullptr, nullptr, nullptr>;
	using Vec4f32_t = Vector <float, 4, nullptr, nullptr, nullptr, nullptr>;
	using Vec5f32_t = Vector <float, 5, nullptr, nullptr, nullptr, nullptr>;
	using Vec6f32_t = Vector <float, 6, nullptr, nullptr, nullptr, nullptr>;
	using Vec7f32_t = Vector <float, 7, nullptr, nullptr, nullptr, nullptr>;
	using Vec8f32_t = Vector <float, 8, nullptr, nullptr, nullptr, nullptr>;

	using Vec2f64_t = Vector <double, 2, nullptr, nullptr, nullptr, nullptr>;
	using Vec3f64_t = Vector <double, 3, nullptr, nullptr, nullptr, nullptr>;
	using Vec4f64_t = Vector <double, 4, nullptr, nullptr, nullptr, nullptr>;

	using Vec2i8_t  = Vector <int8_t, 2,  nullptr, nullptr, nullptr, nullptr>;
	using Vec3i8_t  = Vector <int8_t, 3,  nullptr, nullptr, nullptr, nullptr>;
	using Vec4i8_t  = Vector <int8_t, 4,  nullptr, nullptr, nullptr, nullptr>;
	using Vec5i8_t  = Vector <int8_t, 5,  nullptr, nullptr, nullptr, nullptr>;
	using Vec6i8_t  = Vector <int8_t, 6,  nullptr, nullptr, nullptr, nullptr>;
	using Vec7i8_t  = Vector <int8_t, 7,  nullptr, nullptr, nullptr, nullptr>;
	using Vec8i8_t  = Vector <int8_t, 8,  nullptr, nullptr, nullptr, nullptr>;
	using Vec9i8_t  = Vector <int8_t, 9,  nullptr, nullptr, nullptr, nullptr>;
	using Vec10i8_t = Vector <int8_t, 10, nullptr, nullptr, nullptr, nullptr>;
	using Vec11i8_t = Vector <int8_t, 11, nullptr, nullptr, nullptr, nullptr>;
	using Vec12i8_t = Vector <int8_t, 12, nullptr, nullptr, nullptr, nullptr>;
	using Vec13i8_t = Vector <int8_t, 13, nullptr, nullptr, nullptr, nullptr>;
	using Vec14i8_t = Vector <int8_t, 14, nullptr, nullptr, nullptr, nullptr>;
	using Vec15i8_t = Vector <int8_t, 15, nullptr, nullptr, nullptr, nullptr>;
	using Vec16i8_t = Vector <int8_t, 16, nullptr, nullptr, nullptr, nullptr>;
	using Vec17i8_t = Vector <int8_t, 17, nullptr, nullptr, nullptr, nullptr>;
	using Vec18i8_t = Vector <int8_t, 18, nullptr, nullptr, nullptr, nullptr>;
	using Vec19i8_t = Vector <int8_t, 19, nullptr, nullptr, nullptr, nullptr>;
	using Vec20i8_t = Vector <int8_t, 20, nullptr, nullptr, nullptr, nullptr>;
	using Vec21i8_t = Vector <int8_t, 21, nullptr, nullptr, nullptr, nullptr>;
	using Vec22i8_t = Vector <int8_t, 22, nullptr, nullptr, nullptr, nullptr>;
	using Vec23i8_t = Vector <int8_t, 23, nullptr, nullptr, nullptr, nullptr>;
	using Vec24i8_t = Vector <int8_t, 24, nullptr, nullptr, nullptr, nullptr>;
	using Vec25i8_t = Vector <int8_t, 25, nullptr, nullptr, nullptr, nullptr>;
	using Vec26i8_t = Vector <int8_t, 26, nullptr, nullptr, nullptr, nullptr>;
	using Vec27i8_t = Vector <int8_t, 27, nullptr, nullptr, nullptr, nullptr>;
	using Vec28i8_t = Vector <int8_t, 28, nullptr, nullptr, nullptr, nullptr>;
	using Vec29i8_t = Vector <int8_t, 29, nullptr, nullptr, nullptr, nullptr>;
	using Vec30i8_t = Vector <int8_t, 30, nullptr, nullptr, nullptr, nullptr>;
	using Vec31i8_t = Vector <int8_t, 31, nullptr, nullptr, nullptr, nullptr>;
	using Vec32i8_t = Vector <int8_t, 32, nullptr, nullptr, nullptr, nullptr>;

	using Vec2i16_t  = Vector <int16_t, 2,  nullptr, nullptr, nullptr, nullptr>;
	using Vec3i16_t  = Vector <int16_t, 3,  nullptr, nullptr, nullptr, nullptr>;
	using Vec4i16_t  = Vector <int16_t, 4,  nullptr, nullptr, nullptr, nullptr>;
	using Vec5i16_t  = Vector <int16_t, 5,  nullptr, nullptr, nullptr, nullptr>;
	using Vec6i16_t  = Vector <int16_t, 6,  nullptr, nullptr, nullptr, nullptr>;
	using Vec7i16_t  = Vector <int16_t, 7,  nullptr, nullptr, nullptr, nullptr>;
	using Vec8i16_t  = Vector <int16_t, 8,  nullptr, nullptr, nullptr, nullptr>;
	using Vec9i16_t  = Vector <int16_t, 9,  nullptr, nullptr, nullptr, nullptr>;
	using Vec10i16_t = Vector <int16_t, 10, nullptr, nullptr, nullptr, nullptr>;
	using Vec11i16_t = Vector <int16_t, 11, nullptr, nullptr, nullptr, nullptr>;
	using Vec12i16_t = Vector <int16_t, 12, nullptr, nullptr, nullptr, nullptr>;
	using Vec13i16_t = Vector <int16_t, 13, nullptr, nullptr, nullptr, nullptr>;
	using Vec14i16_t = Vector <int16_t, 14, nullptr, nullptr, nullptr, nullptr>;
	using Vec15i16_t = Vector <int16_t, 15, nullptr, nullptr, nullptr, nullptr>;
	using Vec16i16_t = Vector <int16_t, 16, nullptr, nullptr, nullptr, nullptr>;

	using Vec2i32_t = Vector <int32_t, 2, nullptr, nullptr, nullptr, nullptr>;
	using Vec3i32_t = Vector <int32_t, 3, nullptr, nullptr, nullptr, nullptr>;
	using Vec4i32_t = Vector <int32_t, 4, nullptr, nullptr, nullptr, nullptr>;
	using Vec5i32_t = Vector <int32_t, 5, nullptr, nullptr, nullptr, nullptr>;
	using Vec6i32_t = Vector <int32_t, 6, nullptr, nullptr, nullptr, nullptr>;
	using Vec7i32_t = Vector <int32_t, 7, nullptr, nullptr, nullptr, nullptr>;
	using Vec8i32_t = Vector <int32_t, 8, nullptr, nullptr, nullptr, nullptr>;

	using Vec2i64_t = Vector <int64_t, 2, nullptr, nullptr, nullptr, nullptr>;
	using Vec3i64_t = Vector <int64_t, 3, nullptr, nullptr, nullptr, nullptr>;
	using Vec4i64_t = Vector <int64_t, 4, nullptr, nullptr, nullptr, nullptr>;

	using Vec2u8_t  = Vector <uint8_t, 2,  nullptr, nullptr, nullptr, nullptr>;
	using Vec3u8_t  = Vector <uint8_t, 3,  nullptr, nullptr, nullptr, nullptr>;
	using Vec4u8_t  = Vector <uint8_t, 4,  nullptr, nullptr, nullptr, nullptr>;
	using Vec5u8_t  = Vector <uint8_t, 5,  nullptr, nullptr, nullptr, nullptr>;
	using Vec6u8_t  = Vector <uint8_t, 6,  nullptr, nullptr, nullptr, nullptr>;
	using Vec7u8_t  = Vector <uint8_t, 7,  nullptr, nullptr, nullptr, nullptr>;
	using Vec8u8_t  = Vector <uint8_t, 8,  nullptr, nullptr, nullptr, nullptr>;
	using Vec9u8_t  = Vector <uint8_t, 9,  nullptr, nullptr, nullptr, nullptr>;
	using Vec10u8_t = Vector <uint8_t, 10, nullptr, nullptr, nullptr, nullptr>;
	using Vec11u8_t = Vector <uint8_t, 11, nullptr, nullptr, nullptr, nullptr>;
	using Vec12u8_t = Vector <uint8_t, 12, nullptr, nullptr, nullptr, nullptr>;
	using Vec13u8_t = Vector <uint8_t, 13, nullptr, nullptr, nullptr, nullptr>;
	using Vec14u8_t = Vector <uint8_t, 14, nullptr, nullptr, nullptr, nullptr>;
	using Vec15u8_t = Vector <uint8_t, 15, nullptr, nullptr, nullptr, nullptr>;
	using Vec16u8_t = Vector <uint8_t, 16, nullptr, nullptr, nullptr, nullptr>;
	using Vec17u8_t = Vector <uint8_t, 17, nullptr, nullptr, nullptr, nullptr>;
	using Vec18u8_t = Vector <uint8_t, 18, nullptr, nullptr, nullptr, nullptr>;
	using Vec19u8_t = Vector <uint8_t, 19, nullptr, nullptr, nullptr, nullptr>;
	using Vec20u8_t = Vector <uint8_t, 20, nullptr, nullptr, nullptr, nullptr>;
	using Vec21u8_t = Vector <uint8_t, 21, nullptr, nullptr, nullptr, nullptr>;
	using Vec22u8_t = Vector <uint8_t, 22, nullptr, nullptr, nullptr, nullptr>;
	using Vec23u8_t = Vector <uint8_t, 23, nullptr, nullptr, nullptr, nullptr>;
	using Vec24u8_t = Vector <uint8_t, 24, nullptr, nullptr, nullptr, nullptr>;
	using Vec25u8_t = Vector <uint8_t, 25, nullptr, nullptr, nullptr, nullptr>;
	using Vec26u8_t = Vector <uint8_t, 26, nullptr, nullptr, nullptr, nullptr>;
	using Vec27u8_t = Vector <uint8_t, 27, nullptr, nullptr, nullptr, nullptr>;
	using Vec28u8_t = Vector <uint8_t, 28, nullptr, nullptr, nullptr, nullptr>;
	using Vec29u8_t = Vector <uint8_t, 29, nullptr, nullptr, nullptr, nullptr>;
	using Vec30u8_t = Vector <uint8_t, 30, nullptr, nullptr, nullptr, nullptr>;
	using Vec31u8_t = Vector <uint8_t, 31, nullptr, nullptr, nullptr, nullptr>;
	using Vec32u8_t = Vector <uint8_t, 32, nullptr, nullptr, nullptr, nullptr>;

	using Vec2u16_t  = Vector <uint16_t, 2,  nullptr, nullptr, nullptr, nullptr>;
	using Vec3u16_t  = Vector <uint16_t, 3,  nullptr, nullptr, nullptr, nullptr>;
	using Vec4u16_t  = Vector <uint16_t, 4,  nullptr, nullptr, nullptr, nullptr>;
	using Vec5u16_t  = Vector <uint16_t, 5,  nullptr, nullptr, nullptr, nullptr>;
	using Vec6u16_t  = Vector <uint16_t, 6,  nullptr, nullptr, nullptr, nullptr>;
	using Vec7u16_t  = Vector <uint16_t, 7,  nullptr, nullptr, nullptr, nullptr>;
	using Vec8u16_t  = Vector <uint16_t, 8,  nullptr, nullptr, nullptr, nullptr>;
	using Vec9u16_t  = Vector <uint16_t, 9,  nullptr, nullptr, nullptr, nullptr>;
	using Vec10u16_t = Vector <uint16_t, 10, nullptr, nullptr, nullptr, nullptr>;
	using Vec11u16_t = Vector <uint16_t, 11, nullptr, nullptr, nullptr, nullptr>;
	using Vec12u16_t = Vector <uint16_t, 12, nullptr, nullptr, nullptr, nullptr>;
	using Vec13u16_t = Vector <uint16_t, 13, nullptr, nullptr, nullptr, nullptr>;
	using Vec14u16_t = Vector <uint16_t, 14, nullptr, nullptr, nullptr, nullptr>;
	using Vec15u16_t = Vector <uint16_t, 15, nullptr, nullptr, nullptr, nullptr>;
	using Vec16u16_t = Vector <uint16_t, 16, nullptr, nullptr, nullptr, nullptr>;

	using Vec2u32_t = Vector <uint32_t, 2, nullptr, nullptr, nullptr, nullptr>;
	using Vec3u32_t = Vector <uint32_t, 3, nullptr, nullptr, nullptr, nullptr>;
	using Vec4u32_t = Vector <uint32_t, 4, nullptr, nullptr, nullptr, nullptr>;
	using Vec5u32_t = Vector <uint32_t, 5, nullptr, nullptr, nullptr, nullptr>;
	using Vec6u32_t = Vector <uint32_t, 6, nullptr, nullptr, nullptr, nullptr>;
	using Vec7u32_t = Vector <uint32_t, 7, nullptr, nullptr, nullptr, nullptr>;
	using Vec8u32_t = Vector <uint32_t, 8, nullptr, nullptr, nullptr, nullptr>;

	using Vec2u64_t = Vector <uint64_t, 2, nullptr, nullptr, nullptr, nullptr>;
	using Vec3u64_t = Vector <uint64_t, 3, nullptr, nullptr, nullptr, nullptr>;
	using Vec4u64_t = Vector <uint64_t, 4, nullptr, nullptr, nullptr, nullptr>;
}