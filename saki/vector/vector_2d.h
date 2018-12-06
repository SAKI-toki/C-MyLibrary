/**
* @file vector_2d.h
* @brief 2�����ł̃x�N�g��
* @author �ΎR �I
* @date 2018/12/02
*/
#pragma once
#ifndef SAKI_VECTOR_2D_2018_12_02
#define SAKI_VECTOR_2D_2018_12_02
#include <type_traits> //for meta method
#include <limits> //for numeric_limits
#include <saki/constexpr/constexpr_sqrt.h>

namespace saki
{
	/**
	* @brief 2�����ł̃x�N�g��
	*/
	template<typename T>
	class Vector2
	{
	public:
		T x, y;
		/**
		* @brief �����Ȃ��R���X�g���N�^
		*/
		constexpr Vector2() :
			x(static_cast<T>(0)), y(static_cast<T>(0))
		{}
		/**
		* @brief ��������R���X�g���N�^
		* @param _x x�̏����l
		* @param _y y�̏����l
		*/
		constexpr Vector2(const T& _x, const T& _y) :
			x(_x), y(_y)
		{}
		//�f�t�H���g���g�p
		Vector2(const Vector2<T>&) = default;
		Vector2<T>& operator=(const Vector2<T>&) = default;
		Vector2(Vector2<T>&&) = default;
		Vector2& operator=(Vector2<T>&&) = default;
		/**
		* @brief +���Z�q
		*/
		template<typename U = T>
		constexpr auto operator+(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() + std::declval<U>())>
			{ this->x + other.x, this->y + other.y };
		}
		/**
		* @brief +=���Z�q
		*/
		template<typename U = T>
		auto operator+=(const Vector2<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -���Z�q
		*/
		template<typename U = T>
		constexpr auto operator-(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() - std::declval<U>())>
			{ this->x - other.x, this->y - other.y };
		}
		/**
		* @brief -=���Z�q
		*/
		template<typename U = T>
		auto operator-=(const Vector2<U>& other)
		{
			*this = *this - other;
			return *this;
		}
		/**
		* @brief *���Z�q(�X�J��)
		*/
		template<typename U = T>
		constexpr auto operator*(const U& scalar)const
		{
			return Vector2<decltype(std::declval<T>() * std::declval<U>())>
			{ this->x * scalar, this->y * scalar };
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
		* @brief *���Z�q(�x�N�g��)
		*/
		template<typename U = T>
		constexpr auto operator*(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() * std::declval<U>())>
			{ this->x * other.x, this->y * other.y };
		}
		/**
		* @brief *=���Z�q(�x�N�g��)
		*/
		template<typename U = T>
		auto operator*=(const Vector2<U>& other)
		{
			*this = *this * other;
			return *this;
		}
		/**
		* @brief /���Z�q(�X�J��)
		*/
		template<typename U = T>
		constexpr auto operator/(const U& scalar)const
		{
			return Vector2<decltype(std::declval<T>() / std::declval<U>())>
			{ this->x / scalar, this->y / scalar };
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
		* @brief /���Z�q(�x�N�g��)
		*/
		template<typename U = T>
		constexpr auto operator/(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() / std::declval<U>())>
			{ this->x / other.x, this->y / other.y };
		}
		/**
		* @brief /=���Z�q(�x�N�g��)
		*/
		template<typename U = T>
		auto operator/=(const Vector2<U>& other)
		{
			*this = *this / other;
			return *this;
		}
		/**
		* @brief ==���Z�q
		*/
		constexpr bool operator==(const Vector2<T>& other)const
		{
			return this->x == other.x && this->y == other.y;
		}
		/**
		* @brief !=���Z�q
		*/
		constexpr bool operator!=(const Vector2<T>& other)const
		{
			return !(this == other);
		}

		/**
		* @brief ���K��
		* @return int�^�̏ꍇ�͕K��0�ɂȂ�̂Œ��ӂ��Ă�������
		*/
		void normalize()
		{
			//����
			auto den = saki::sqrt(this->x * this->x + this->y * this->y);
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
		/**
		* @brief ���K��
		* @return ���K����������
		* @details this�͐��K�����Ȃ�
		*/
		template<typename U = double>
		constexpr Vector2<U> return_normalize()const
		{
			//����
			auto den = saki::sqrt(this->x * this->x + this->y * this->y);
			if (den == 0)
			{
				return Vector2<U>
					(static_cast<U>(0),//x
						static_cast<U>(0));//y
			}
			else
			{
				return Vector2<U>
					(static_cast<U>(this->x / den),//x
						static_cast<U>(this->y / den));//y
			}
		}
		static constexpr Vector2<T> zero()
		{
			return Vector2<T>(static_cast<T>(0), static_cast<T>(0));
		}
		static constexpr Vector2<T> min()
		{
			return Vector2<T>(std::numeric_limits<T>::min(), std::numeric_limits<T>::min());
		}
		static constexpr Vector2<T> max()
		{
			return Vector2<T>(std::numeric_limits<T>::max(), std::numeric_limits<T>::max());
		}
	};
	/**
	* @brief ��_�Ԃ̋���
	* @details C++17���݁Astd::sqrt��constexpr�ł͂Ȃ��̂ŁA����sqrt�𗘗p��constexpr�ɑΉ�
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U distance(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return saki::sqrt<U>(
			(v1.x - v2.x) * (v1.x - v2.x) +
			(v1.y - v2.y) * (v1.y - v2.y));
	}
	/**
	* @brief ����
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U dot(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return static_cast<U>(v1.x*v2.x + v1.y*v2.y);
	}
	/**
	* @brief �O��
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U cross(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return static_cast<U>(v1.x * v2.y - v1.y * v2.x);
	}
}
#endif //SAKI_VECTOR_2D_2018_12_02