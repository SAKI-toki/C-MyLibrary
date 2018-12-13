/**
* @file matrix.h
* @brief �s��
* @author �ΎR �I
* @date 2018/12/13
*/
#pragma once
#ifndef SAKI_MATRIX_2018_12_13
#define SAKI_MATRIX_2018_12_13
#include <saki/matrix/details/matrix_operator.h>
#include <saki/macro/type_macro.h>

namespace saki
{
	/**
	* @brief �s��
	*/
	template<typename T>
	class Matrix
	{
		T m[4][4];
	public:
		SAKI_TYPE_MACRO(T)
		/**
		* @brief �����Ȃ��R���X�g���N�^
		* @details �S��0�ŏ�����
		*/
		constexpr Matrix() :
			m{}
		{}
		/**
		* @brief ��������R���X�g���N�^
		*/
		constexpr Matrix(
			const T& m00, const T& m01, const T& m02, const T& m03,
			const T& m10, const T& m11, const T& m12, const T& m13,
			const T& m20, const T& m21, const T& m22, const T& m23,
			const T& m30, const T& m31, const T& m32, const T& m33) :
			m{ {m00,m01,m02,m03},
				{m10,m11,m12,m13},
				{m20,m21,m22,m23},
				{m30,m31,m32,m33} }
		{}
		/**
		* @brief ���z�񂩂�̏�����
		* @param arr 4*4�̔z��
		*/
		constexpr Matrix(const T arr[4][4]) :
			m{ {arr[0][0],arr[0][1],arr[0][2],arr[0][3]},
			{arr[1][0],arr[1][1],arr[1][2],arr[1][3]},
			{arr[2][0],arr[2][1],arr[2][2],arr[2][3]},
			{arr[3][0],arr[3][1],arr[3][2],arr[3][3]} }
		{}
		//�f�t�H���g���g�p
		//�f�t�H���g�ł̓����o�ϐ��̃R�s�[�A���[�u���s��
		Matrix(const Matrix<T>&) = default;
		Matrix<T>& operator=(const Matrix<T>&) = default;
		Matrix(Matrix<T>&&)noexcept = default;
		Matrix& operator=(Matrix<T>&&)noexcept = default;
		/**
		* @brief +=���Z�q
		*/
		template<typename U = T>
		auto operator+=(const Matrix<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -=���Z�q
		*/
		template<typename U = T>
		auto operator-=(const Matrix<U>& other)
		{
			*this = *this - other;
			return *this;
		}
		/**
		* @brief *=���Z�q(�X�J��)
		*/
		template<typename U = T>
		auto operator*=(const U& scalar)
		{
			*this = *this * scalar;
			return *this;
		}
		/**
		* @brief *=���Z�q(�s��)
		*/
		template<typename U = T>
		auto operator*=(const Matrix<U>& other)
		{
			*this = *this * other;
			return *this;
		}
		/**
		* @brief /=���Z�q(�X�J��)
		*/
		template<typename U = T>
		auto operator/=(const U& scalar)
		{
			*this = *this / scalar;
			return *this;
		}
		/**
		* @brief []���Z�q
		*/
		T* operator[](const unsigned int index)
		{
			return m[index];
		}
		/**
		* @brief []���Z�q�ł͕\���ł��Ȃ����߁A���ʂ̊֐��ɂ���
		* @param row,col �s�A��
		* @details ����array�N���X���쐬����΂ł��邪�A�Ƃ肠�������͂��̂܂܂�
		*/
		constexpr T at_constexpr(const unsigned int row, const unsigned int col)const
		{
			return m[row][col];
		}

		/**
		* @brief �P�ʍs��ɕϊ�
		*/
		void identity()
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					m[i][j] = (i == j) ? 1 : 0;
				}
			}
		}
	};

	/**
	* @brief �P�ʍs��
	*/
	template<typename T>
	static constexpr Matrix<T> matrix_identity{
		static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0) ,
		static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0) ,
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0) ,
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
	};
}
#endif //SAKI_MATRIX_2018_12_13