/**
* @file vector_3d.h
* @brief 3次元でのベクトル
* @author 石山 悠
* @date 2018/11/18
*/
#pragma once
#ifndef SAKI_VECTOR_3D_2018_11_18
#define SAKI_VECTOR_3D_2018_11_18
#include <type_traits>
#include "../constexpr/constexpr_sqrt.h"

namespace saki
{
	/**
	* @brief 3次元でのベクトル
	*/
	template<typename T>
	class Vector3
	{
	public:
		T x, y, z;
		/**
		* @brief 引数なしコンストラクタ
		*/
		constexpr Vector3() :
			x(T()), y(T()), z(T())
		{}
		/**
		* @brief 引数ありコンストラクタ
		* @param _x xの初期値
		* @param _y yの初期値
		* @param _z zの初期値
		*/
		constexpr Vector3(const T& _x, const T& _y, const T& _z) :
			x(_x), y(_y), z(_z)
		{}
		/**
		* @brief 引数あり型変換コンストラクタ
		* @param _x xの初期値
		* @param _y yの初期値
		* @param _z zの初期値
		*/
		template<typename U1, typename U2, typename U3>
		constexpr Vector3(const U1& _x, const U2& _y, const U3& _z) :
			x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z))
		{}
		/**
		* @brief コピーコンストラクタ
		* @param other コピーする対象（型が一致）
		*/
		Vector3(const Vector3<T>& other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
		}
		/**
		* @brief 型変換コピーコンストラクタ
		* @param other コピーする対象（型が不一致）
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector3(const Vector3<U>& other)
		{
			this->x = static_cast<T>(other.x);
			this->y = static_cast<T>(other.y);
			this->z = static_cast<T>(other.z);
		}
		/**
		* @brief コピー代入演算子
		* @param other コピーする対象（型が一致）
		*/
		Vector3<T>& operator=(const Vector3<T>& other)
		{
			if (this != &other)
			{
				this->x = other.x;
				this->y = other.y;
				this->z = other.z;
			}
			return *this;
		}
		/**
		* @brief 型変換コピー代入演算子
		* @param other コピーする対象（型が不一致）
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector3<T>& operator=(const Vector3<U>& other)
		{
			this->x = static_cast<T>(other.x);
			this->y = static_cast<T>(other.y);
			this->z = static_cast<T>(other.z);

			return *this;
		}
		/**
		* @brief ムーブコンストラクタ
		* @param other ムーブする対象（型が一致）
		*/
		Vector3(Vector3<T>&& other)noexcept
		{
			this->x = std::move(other.x);
			this->y = std::move(other.y);
			this->z = std::move(other.z);
		}
		/**
		* @brief 型変換ムーブコンストラクタ
		* @param other ムーブする対象（型が不一致）
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector3(Vector3<U>&& other)noexcept
		{
			this->x = std::move(static_cast<T>(other.x));
			this->y = std::move(static_cast<T>(other.y));
			this->z = std::move(static_cast<T>(other.z));
		}
		/**
		* @brief ムーブ代入演算子
		* @param other ムーブする対象（型が一致）
		*/
		Vector3<T>& operator=(Vector3<T>&& other)noexcept
		{
			if (this != &other)
			{
				this->x = std::move(other.x);
				this->y = std::move(other.y);
				this->z = std::move(other.z);
			}
			return *this;
		}
		/**
		* @brief 型変換ムーブ代入演算子
		* @param other ムーブする対象（型が不一致）
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector3<T>& operator=(Vector3<U>&& other)noexcept
		{
			this->x = std::move(static_cast<T>(other.x));
			this->y = std::move(static_cast<T>(other.y));
			this->z = std::move(static_cast<T>(other.z));

			return *this;
		}
		/**
		* @brief +演算子
		*/
		template<typename U>
		constexpr auto operator+(const Vector3<U>& other)const
		{
			return Vector3<decltype(std::declval<T>() + std::declval<U>())>
			{ this->x + other.x, this->y + other.y, this->z + other.z };
		}
		/**
		* @brief +=演算子
		*/
		template<typename U>
		constexpr auto operator+=(const Vector3<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -演算子
		*/
		template<typename U>
		constexpr auto operator-(const Vector3<U>& other)const
		{
			return Vector3<decltype(std::declval<T>() - std::declval<U>())>
			{ this->x - other.x, this->y - other.y, this->z - other.z };
		}
		/**
		* @brief -=演算子
		*/
		template<typename U>
		constexpr auto operator-=(const Vector3<U>& other)
		{
			*this = *this - other;
			return *this;
		}
		/**
		* @brief *演算子
		*/
		template<typename U>
		constexpr auto operator*(const U& scalar)const
		{
			return Vector3<decltype(std::declval<T>() * std::declval<U>())>
			{ this->x * scalar, this->y * scalar, this->z * scalar };
		}
		/**
		* @brief *=演算子
		*/
		template<typename U>
		constexpr auto operator*=(const U& other)
		{
			*this = *this * other;
			return *this;
		}
		/**
		* @brief /演算子
		*/
		template<typename U>
		constexpr auto operator/(const T& scalar)const
		{
			return Vector3<decltype(std::declval<T>() / std::declval<U>())>
			{ this->x / scalar, this->y / scalar, this->z / scalar };
		}
		/**
		* @brief /=演算子
		*/
		template<typename U>
		constexpr auto operator/=(const U& other)
		{
			*this = *this / other;
			return *this;
		}

		/**
		* @brief ==演算子
		*/
		constexpr bool operator==(const Vector3<T>& other)const
		{
			return this->x == other.x && this->y == other.y && this->z == other.z;
		}
		/**
		* @brief !=演算子
		*/
		constexpr bool operator!=(const Vector3<T>& other)const
		{
			return !(this == other);
		}
	};
	/**
	* @brief 二点間の距離
	*/
	template<typename T1, typename T2>
	constexpr auto distance(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return static_cast<decltype(std::declval<T1>() - std::declval<T2>())>(
			saki::sqrt(
			(v1.x - v2.x) * (v1.x - v2.x) +
				(v1.y - v2.y) * (v1.y - v2.y) +
				(v1.z - v2.z) * (v1.z - v2.z)));
	}
}

#endif //SAKI_VECTOR_3D_2018_11_18