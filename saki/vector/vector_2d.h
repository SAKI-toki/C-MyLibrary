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
#include "../constexpr/constexpr_sqrt.h"

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
			x(T()), y(T())
		{}
		/**
		* @brief ��������R���X�g���N�^
		* @param _x x�̏����l
		* @param _y y�̏����l
		*/
		constexpr Vector2(const T& _x, const T& _y) :
			x(_x), y(_y)
		{}
		/**
		* @brief ��������^�ϊ��R���X�g���N�^
		* @param _x x�̏����l
		* @param _y y�̏����l
		*/
		template<typename U1, typename U2>
		constexpr Vector2(const U1& _x, const U2& _y) :
			x(static_cast<T>(_x)), y(static_cast<T>(_y))
		{}
		/**
		* @brief �R�s�[�R���X�g���N�^
		* @param other �R�s�[����Ώہi�^����v�j
		*/
		Vector2(const Vector2<T>& other)
		{
			this->x = other.x;
			this->y = other.y;
		}
		/**
		* @brief �^�ϊ��R�s�[�R���X�g���N�^
		* @param other �R�s�[����Ώہi�^���s��v�j
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector2(const Vector2<U>& other)
		{
			this->x = static_cast<T>(other.x);
			this->y = static_cast<T>(other.y);
		}
		/**
		* @brief �R�s�[������Z�q
		* @param other �R�s�[����Ώہi�^����v�j
		*/
		Vector2<T>& operator=(const Vector2<T>& other)
		{
			if (this != &other)
			{
				this->x = other.x;
				this->y = other.y;
			}
			return *this;
		}
		/**
		* @brief �^�ϊ��R�s�[������Z�q
		* @param other �R�s�[����Ώہi�^���s��v�j
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector2<T>& operator=(const Vector2<U>& other)
		{
			this->x = static_cast<T>(other.x);
			this->y = static_cast<T>(other.y);

			return *this;
		}
		/**
		* @brief ���[�u�R���X�g���N�^
		* @param other ���[�u����Ώہi�^����v�j
		*/
		Vector2(Vector2<T>&& other)noexcept
		{
			this->x = std::move(other.x);
			this->y = std::move(other.y);
		}
		/**
		* @brief �^�ϊ����[�u�R���X�g���N�^
		* @param other ���[�u����Ώہi�^���s��v�j
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector2(Vector2<U>&& other)noexcept
		{
			this->x = std::move(static_cast<T>(other.x));
			this->y = std::move(static_cast<T>(other.y));
		}
		/**
		* @brief ���[�u������Z�q
		* @param other ���[�u����Ώہi�^����v�j
		*/
		Vector2<T>& operator=(Vector2<T>&& other)noexcept
		{
			if (this != &other)
			{
				this->x = std::move(other.x);
				this->y = std::move(other.y);
			}
			return *this;
		}
		/**
		* @brief �^�ϊ����[�u������Z�q
		* @param other ���[�u����Ώہi�^���s��v�j
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector2<T>& operator=(Vector2<U>&& other)noexcept
		{
			this->x = std::move(static_cast<T>(other.x));
			this->y = std::move(static_cast<T>(other.y));

			return *this;
		}
		/**
		* @brief +���Z�q
		*/
		template<typename U>
		constexpr auto operator+(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() + std::declval<U>())>
			{ this->x + other.x, this->y + other.y };
		}
		/**
		* @brief +=���Z�q
		*/
		template<typename U>
		auto operator+=(const Vector2<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -���Z�q
		*/
		template<typename U>
		constexpr auto operator-(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() - std::declval<U>())>
			{ this->x - other.x, this->y - other.y };
		}
		/**
		* @brief -=���Z�q
		*/
		template<typename U>
		auto operator-=(const Vector2<U>& other)
		{
			*this = *this - other;
			return *this;
		}
		/**
		* @brief *���Z�q
		*/
		template<typename U>
		constexpr auto operator*(const U& scalar)const
		{
			return Vector2<decltype(std::declval<T>() * std::declval<U>())>
			{ this->x * scalar, this->y * scalar };
		}
		/**
		* @brief *=���Z�q
		*/
		template<typename U>
		auto operator*=(const U& other)
		{
			*this = *this * other;
			return *this;
		}
		/**
		* @brief /���Z�q
		*/
		template<typename U>
		constexpr auto operator/(const T& scalar)const
		{
			return Vector2<decltype(std::declval<T>() / std::declval<U>())>
			{ this->x / scalar, this->y / scalar };
		}
		/**
		* @brief /=���Z�q
		*/
		template<typename U>
		auto operator/=(const U& other)
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
	};

	/**
	* @brief ��_�Ԃ̋���
	* @details C++17���݁Astd::sqrt��constexpr�ł͂Ȃ��̂ŁA����sqrt�𗘗p��constexpr�ɑΉ�
	*/
	template<typename T1, typename T2>
	constexpr auto distance(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return static_cast<decltype(std::declval<T1>() - std::declval<T2>())>(
			saki::sqrt(
			(v1.x - v2.x) * (v1.x - v2.x) +
				(v1.y - v2.y) * (v1.y - v2.y)));
	}
	/**
	* @brief ����
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U dot(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return static_cast<U>(v1.x*v2.x + v1.y*v2.y);
	}
}

#endif //SAKI_VECTOR_2D_2018_12_02