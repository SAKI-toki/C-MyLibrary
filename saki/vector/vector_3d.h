/**
* @file vector_3d.h
* @brief 3�����ł̃x�N�g��
* @author �ΎR �I
* @date 2018/12/06
*/
#pragma once
#ifndef SAKI_VECTOR_3D_2018_12_06
#define SAKI_VECTOR_3D_2018_12_06
#include <type_traits> //for meta method
#include <limits> //for numeric_limits
#include <saki/constexpr/constexpr_sqrt.h> //for constexpr_sqrt

namespace saki
{
	/**
	* @brief 3�����ł̃x�N�g��
	*/
	template<typename T>
	class Vector3
	{
	public:
		T x, y, z;
		/**
		* @brief �����Ȃ��R���X�g���N�^
		* @details �S��0�ŏ�����
		*/
		constexpr Vector3() :
			x(T()), y(T()), z(T())
		{}
		/**
		* @brief ��������R���X�g���N�^
		* @param _x x�̏����l
		* @param _y y�̏����l
		* @param _z z�̏����l
		*/
		constexpr Vector3(const T& _x, const T& _y, const T& _z) :
			x(_x), y(_y), z(_z)
		{}
		/**
		* @brief ���z�񂩂�̏�����
		* @param pointer �z��̃|�C���^
		*/
		constexpr Vector3(const T* const pointer) :
			x(*pointer), y(*(pointer + 1)), z(*(pointer + 2))
		{}
		//�f�t�H���g���g�p
		//�f�t�H���g�ł̓����o�ϐ��̃R�s�[�A���[�u���s��
		Vector3(const Vector3<T>&) = default;
		Vector3<T>& operator=(const Vector3<T>&) = default;
		Vector3(Vector3<T>&&)noexcept = default;
		Vector3& operator=(Vector3<T>&&)noexcept = default;
		/**
		* @brief +=���Z�q
		*/
		template<typename U = T>
		auto operator+=(const Vector3<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -=���Z�q
		*/
		template<typename U = T>
		auto operator-=(const Vector3<U>& other)
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
		* @brief *=���Z�q(�x�N�g��)
		*/
		template<typename U = T>
		auto operator*=(const Vector3<U>& other)
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
		* @brief /=���Z�q(�x�N�g��)
		*/
		template<typename U = T>
		auto operator/=(const Vector3<U>& other)
		{
			*this = *this / other;
			return *this;
		}
		/**
		* @brief �P��+���Z�q
		*/
		constexpr Vector3<T> operator+()const
		{
			return *this;
		}
		/**
		* @brief �P��-���Z�q
		*/
		constexpr Vector3<T> operator-()const
		{
			return Vector3<T>(this->x * (-1), this->y * (-1), this->z * (-1));
		}
		/**
		* @brief []���Z�q
		*/
		T& operator[](const unsigned int index)
		{
			return (index == 0) ? this->x : (index == 1) ? this->y : this->z;
		}
		/**
		* @brief []���Z�q(constexpr)
		*/
		constexpr T operator[](const unsigned int index)const
		{
			return (index == 0) ? this->x : (index == 1) ? this->y : this->z;
		}
		/**
		* @brief ++���Z�q(�O�u)
		*/
		Vector3<T>& operator++()
		{
			this->x += 1; this->y += 1; this->z += 1;
			return *this;
		}
		/**
		* @brief ++���Z�q(��u)
		*/
		Vector3<T> operator++(int)
		{
			Vector3<T> temp = *this;
			this->x += 1; this->y += 1; this->z += 1;
			return temp;
		}
		/**
		* @brief --���Z�q(�O�u)
		*/
		Vector3<T>& operator--()
		{
			this->x -= 1; this->y -= 1; this->z -= 1;
			return *this;
		}
		/**
		* @brief --���Z�q(��u)
		*/
		Vector3<T> operator--(int)
		{
			Vector3<T> temp = *this;
			this->x -= 1; this->y -= 1; this->z -= 1;
			return temp;
		}
		/**
		* @brief ���K��
		* @details int�^�̏ꍇ�A���ׂĂ̗v�f��0�ŕԂ�܂�
		*/
		void normalize()
		{
			//����
			auto den = saki::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
			if (den == 0)
			{
				this->x = 0;
				this->y = 0;
				this->z = 0;
			}
			else
			{
				this->x /= den;
				this->y /= den;
				this->z /= den;
			}
		}
		/**
		* @brief ���K��
		* @return ���K����������
		* @details this�͐��K�����Ȃ��Aint�^�̏ꍇ�A���ׂĂ̗v�f��0�ŋA��܂�
		*/
		template<typename U = double>
		constexpr Vector2<U> return_normalize()const
		{
			//����
			auto den = saki::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
			if (den == 0)
			{
				return Vector2<U>
					(static_cast<U>(0),//x
						static_cast<U>(0),//y
						static_cast<U>(0));//z
			}
			else
			{
				return Vector2<U>
					(static_cast<U>(this->x / den),//x
						static_cast<U>(this->y / den),//y
						static_cast<U>(this->z / den));//z
			}
		}
	};
	/**
	* @brief Vector3�̃I�[���[��
	*/
	template<typename T>
	static constexpr Vector3<T> vector3_zero{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(0) };
	/**
	* @brief Vector3�̃I�[������
	*/
	template<typename T>
	static constexpr Vector2<T> vector3_one{ static_cast<T>(1), static_cast<T>(1), static_cast<T>(1) };
	/**
	* @brief Vector3�̍ŏ��l
	*/
	template<typename T>
	static constexpr Vector3<T> vector3_min{ std::numeric_limits<T>::min(), std::numeric_limits<T>::min(), std::numeric_limits<T>::min() };
	/**
	* @brief Vector3�̍ő�l
	*/
	template<typename T>
	static constexpr Vector3<T> vector3_max{ std::numeric_limits<T>::max(), std::numeric_limits<T>::max(), std::numeric_limits<T>::max() };
	/**
	* @brief ����
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U dot(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return static_cast<U>(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	}
	/**
	* @brief �O��
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr Vector3<U> cross(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return Vector3<U>(
			v1.y * v2.z - v1.z * v1.y, //x
			v1.z * v2.x - v1.x * v1.z, //y
			v1.x * v2.y - v1.y * v1.x);//z
	}
	/**
	* @brief ���`���
	*/
	template<typename U = double, typename T1, typename T2, typename T = double>
	constexpr Vector3<U> lerp(const Vector3<T1>& v1, const Vector3<T2>& v2, const T& t, const T& base = 1)
	{
		return Vector3<U>(
			v1.x + (v2.x - v1.x) * t / base,
			v1.y + (v2.y - v1.y) * t / base,
			v1.z + (v2.z - v1.z) * t / base);
	}
	/**
	* @brief +���Z�q
	*/
	template<typename T1, typename T2>
	constexpr auto operator+(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return Vector3<decltype(std::declval<T1>() + std::declval<T2>())>
		{ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
	}
	/**
	* @brief -���Z�q
	*/
	template<typename T1, typename T2>
	constexpr auto operator-(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return Vector3<decltype(std::declval<T1>() - std::declval<T2>())>
		{ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
	}
	/**
	* @brief *���Z�q(�X�J��)
	*/
	template<typename T1, typename T2>
	constexpr auto operator*(const Vector3<T1>& v, const T2& scalar)
	{
		return Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
		{ v.x * scalar, v.y * scalar, v.z * scalar };
	}
	/**
	* @brief *���Z�q(�x�N�g��)
	*/
	template<typename T1, typename T2>
	constexpr auto operator*(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
		{ v1.x * v2.x, v1.y * v2.y, v1.z * v2.z };
	}
	/**
	* @brief /���Z�q(�X�J��)
	*/
	template<typename T1, typename T2>
	constexpr auto operator/(const Vector3<T1>& v, const T2& scalar)
	{
		return Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
		{ v.x / scalar, v.y / scalar, v.z / scalar };
	}
	/**
	* @brief /���Z�q(�x�N�g��)
	*/
	template<typename T1, typename T2>
	constexpr auto operator/(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
		{ v1.x / v2.x, v1.y / v2.y, v1.z / v2.z };
	}
	/**
	* @brief ==���Z�q
	*/
	template<typename T>
	constexpr bool operator==(const Vector3<T>& v1, const Vector3<T>& v2)
	{
		return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
	}
	/**
	* @brief !=���Z�q
	*/
	template<typename T>
	constexpr bool operator!=(const Vector3<T>& v1, const Vector3<T>& v2)
	{
		return !(v1 == v2);
	}
	/**
	* @brief ==���Z�q(�^�s��v)
	* @details ���̊֐��̎g�p�͐������Ȃ�
	*/
	template<typename T1, typename T2>[[deprecated("type_mismatch")]]
		constexpr bool operator==(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
	}
	/**
	* @brief !=���Z�q(�^�s��v)
	* @details ���̊֐��̎g�p�͐������Ȃ�
	*/
	template<typename T1, typename T2>[[deprecated("type_mismatch")]]
		constexpr bool operator!=(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return !(v1 == v2);
	}
}

#endif //SAKI_VECTOR_3D_2018_12_06