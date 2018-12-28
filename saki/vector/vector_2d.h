/**
* @file vector_2d.h
* @brief 2�����ł̃x�N�g��
* @author �ΎR �I
* @date 2018/12/13
*/
#pragma once
#ifndef SAKI_VECTOR_2D_2018_12_13
#define SAKI_VECTOR_2D_2018_12_13
#include <limits> //for numeric_limits
#include <saki/constexpr_std/sqrt.h> //for constexpr_sqrt
#include <saki/vector/details/2d/vector_2d_operator.h>
#include <saki/macro/type_macro.h>
#include <cmath>


namespace saki
{
	/**
	* @brief 2�����ł̃x�N�g��
	*/
	template<typename T>
	class Vector2
	{
	public:
		SAKI_TYPE_MACRO(T)
	public:
		value_type x, y;
		/**
		* @brief �����Ȃ��R���X�g���N�^
		* @details �S��0�ŏ�����
		*/
		constexpr Vector2() :
			x(static_cast<value_type>(0)), y(static_cast<value_type>(0))
		{}
		/**
		* @brief ��������R���X�g���N�^
		* @param _x x�̏����l
		* @param _y y�̏����l
		*/
		constexpr Vector2(const_reference _x, const_reference _y) :
			x(_x), y(_y)
		{}
		/**
		* @brief ���z�񂩂�̏�����
		* @param pointer �z��̃|�C���^
		*/
		explicit constexpr Vector2(const_pointer const pointer) :
			x(*pointer), y(*(pointer + 1))
		{}
		//�f�t�H���g���g�p
		//�f�t�H���g�ł̓����o�ϐ��̃R�s�[�A���[�u���s��
		Vector2(const Vector2<value_type>&) = default;
		Vector2<value_type>& operator=(const Vector2<value_type>&) = default;
		Vector2(Vector2<value_type>&&)noexcept = default;
		Vector2<value_type>& operator=(Vector2<value_type>&&)noexcept = default;
		/**
		* @brief +=���Z�q
		*/
		template<typename U = value_type>
		auto operator+=(const saki::Vector2<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -=���Z�q
		*/
		template<typename U = value_type>
		auto operator-=(const saki::Vector2<U>& other)
		{
			*this = *this - other;
			return *this;
		}
		/**
		* @brief *=���Z�q(�X�J��)
		*/
		template<typename U = value_type>
		auto operator*=(const U& scalar)
		{
			*this = *this * scalar;
			return *this;
		}
		/**
		* @brief *=���Z�q(�x�N�g��)
		*/
		template<typename U = value_type>
		auto operator*=(const saki::Vector2<U>& other)
		{
			*this = *this * other;
			return *this;
		}
		/**
		* @brief /=���Z�q(�X�J��)
		*/
		template<typename U = value_type>
		auto operator/=(const U& scalar)
		{
			*this = *this / scalar;
			return *this;
		}
		/**
		* @brief /=���Z�q(�x�N�g��)
		*/
		template<typename U = value_type>
		auto operator/=(const saki::Vector2<U>& other)
		{
			*this = *this / other;
			return *this;
		}
		/**
		* @brief �P��+���Z�q
		*/
		constexpr saki::Vector2<value_type> operator+()const
		{
			return *this;
		}
		/**
		* @brief �P��-���Z�q
		*/
		constexpr saki::Vector2<value_type> operator-()const
		{
			return saki::Vector2<value_type>(this->x * (-1), this->y * (-1));
		}
		/**
		* @brief []���Z�q
		*/
		reference operator[](const size_type index)
		{
			return (index == 0) ? this->x : this->y;
		}
		/**
		* @brief []���Z�q(constexpr)
		*/
		constexpr const_reference operator[](const size_type index)const
		{
			return (index == 0) ? this->x : this->y;
		}
		/**
		* @brief ++���Z�q(�O�u)
		*/
		saki::Vector2<value_type>& operator++()
		{
			this->x += 1; this->y += 1;
			return *this;
		}
		/**
		* @brief ++���Z�q(��u)
		*/
		saki::Vector2<value_type> operator++(int)
		{
			saki::Vector2<value_type> temp = *this;
			this->x += 1; this->y += 1;
			return temp;
		}
		/**
		* @brief --���Z�q(�O�u)
		*/
		saki::Vector2<value_type>& operator--()
		{
			this->x -= 1; this->y -= 1;
			return *this;
		}
		/**
		* @brief --���Z�q(��u)
		*/
		saki::Vector2<value_type> operator--(int)
		{
			saki::Vector2<value_type> temp = *this;
			this->x -= 1; this->y -= 1;
			return temp;
		}
		/**
		* @brief ���K��
		* @details int�^�̏ꍇ�A���ׂĂ̗v�f��0�ŋA��܂�
		*/
		void normalize()
		{
			//����
			auto den = std::sqrt(this->x * this->x + this->y * this->y);
			if (den == 0)
			{
				this->x = 0;
				this->y = 0;
			}
			else
			{
				this->x /= den;
				this->y /= den;
			}
		}

	};
	/**
	* @brief Vector2�̃I�[���[��
	*/
	template<typename T>
	static constexpr saki::Vector2<T> vector2_zero{ static_cast<T>(0), static_cast<T>(0) };
	/**
	* @brief Vector2�̃I�[������
	*/
	template<typename T>
	static constexpr saki::Vector2<T> vector2_one{ static_cast<T>(1), static_cast<T>(1) };
	/**
	* @brief Vector2�̍ŏ��l
	*/
	template<typename T>
	static constexpr saki::Vector2<T> vector2_min{ std::numeric_limits<T>::min(), std::numeric_limits<T>::min() };
	/**
	* @brief Vector2�̍ő�l
	*/
	template<typename T>
	static constexpr saki::Vector2<T> vector2_max{ std::numeric_limits<T>::max(), std::numeric_limits<T>::max() };
	/**
	* @brief ���K��
	* @return ���K����������
	*/
	template<typename U = double, typename T>
	constexpr saki::Vector2<U> normalize(const saki::Vector2<T>& v)
	{
		//����
		auto den = saki::sqrt(v.x * v.x + v.y * v.y);
		if (den == 0)
		{
			return saki::Vector2<U>
				(static_cast<U>(0),//x
					static_cast<U>(0));//y
		}
		else
		{
			return saki::Vector2<U>
				(static_cast<U>(v.x / den),//x
					static_cast<U>(v.y / den));//y
		}
	}
	/**
	* @brief ����
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U dot(const saki::Vector2<T1>& v1, const saki::Vector2<T2>& v2)
	{
		return static_cast<U>(v1.x*v2.x + v1.y*v2.y);
	}
	/**
	* @brief �O��
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U cross(const saki::Vector2<T1>& v1, const saki::Vector2<T2>& v2)
	{
		return static_cast<U>(v1.x * v2.y - v1.y * v2.x);
	}

	/**
	* @brief ���`���
	* @details Quaternion�͎g�p���Ă��܂���
	*/
	template<typename U = double, typename T1, typename T2, typename T = double>
	constexpr Vector2<U> lerp(const saki::Vector2<T1>& v1, const saki::Vector2<T2>& v2, const T& t, const T& base = 1)
	{
		auto ratio = t / base;
		return saki::Vector2<U>(
			v1.x + (v2.x - v1.x) * ratio,
			v1.y + (v2.y - v1.y) * ratio);
	}
}
#endif //SAKI_VECTOR_2D_2018_12_13