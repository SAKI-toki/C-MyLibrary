/**
* @file matrix_math.h
* @brief �s��֌W�̌v�Z�֐�
* @author �ΎR �I
* @date 2018/12/29
*/
#pragma once
#ifndef SAKI_MATRIX_MATH_2018_12_29
#define SAKI_MATRIX_MATH_2018_12_29
#include <saki/vector/vector_2d.h>
#include <saki/vector/vector_3d.h>
#include <saki/vector/vector_4d.h>

namespace saki
{
	template<typename T>
	class Matrix;
	namespace math
	{
		/**
		* @brief ���s�ړ�
		* @param vec �ړ���(Vector2)
		*/
		template<typename T>
		constexpr Matrix<T> translate(const Vector2<T>& vec)
		{
			return Matrix<T>
			{
				1, 0, 0, vec.x,
					0, 1, 0, vec.y,
					0, 0, 1, 0,
					0, 0, 0, 1
			};
		}
		/**
		* @brief ���s�ړ�
		* @param vec �ړ���(Vector3)
		*/
		template<typename T>
		constexpr Matrix<T> translate(const Vector3<T>& vec)
		{
			return Matrix<T>
			{
				1, 0, 0, vec.x,
					0, 1, 0, vec.y,
					0, 0, 1, vec.z,
					0, 0, 0, 1
			};
		}
		/**
		* @brief ���s�ړ�
		* @param vec �ړ���(Vector4)
		*/
		template<typename T>
		constexpr Matrix<T> translate(const Vector4<T>& vec)
		{
			return Matrix<T>
			{
				1, 0, 0, vec.x,
					0, 1, 0, vec.y,
					0, 0, 1, vec.z,
					0, 0, 0, 1
			};
		}

		/**
		* @brief �g�k
		* @param vec �g�k��(Vector2)
		*/
		template<typename T>
		constexpr Matrix<T> scaling(const Vector2<T>& vec)
		{
			return Matrix<T>
			{
				vec.x, 0, 0, 0,
					0, vec.y, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1
			};
		}
		/**
		* @brief �g�k
		* @param vec �g�k��(Vector3)
		*/
		template<typename T>
		constexpr Matrix<T> scaling(const Vector3<T>& vec)
		{
			return Matrix<T>
			{
				vec.x, 0, 0, 0,
					0, vec.y, 0, 0,
					0, 0, vec.z, 0,
					0, 0, 0, 1
			};
		}
		/**
		* @brief �g�k
		* @param vec �g�k��(Vector4)
		*/
		template<typename T>
		constexpr Matrix<T> scaling(const Vector4<T>& vec)
		{
			return Matrix<T>
			{
				vec.x, 0, 0, 0,
					0, vec.y, 0, 0,
					0, 0, vec.z, 0,
					0, 0, 0, 1
			};
		}

	}
}
#endif //SAKI_MATRIX_MATH_2018_12_29