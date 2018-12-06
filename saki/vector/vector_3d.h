/**
* @file vector_3d.h
* @brief 3次元でのベクトル
* @author 石山 悠
* @date 2018/12/02
*/
#pragma once
#ifndef SAKI_VECTOR_3D_2018_12_02
#define SAKI_VECTOR_3D_2018_12_02
#include <type_traits> //for meta method
#include <limits> //for numeric_limits
#include <saki/constexpr/constexpr_sqrt.h>

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
		//デフォルトを使用
		Vector3(const Vector3<T>&) = default;
		Vector3<T>& operator=(const Vector3<T>&) = default;
		Vector3(Vector3<T>&&) = default;
		Vector3& operator=(Vector3<T>&&) = default;
		/**
		* @brief +演算子
		*/
		template<typename U = T>
		constexpr auto operator+(const Vector3<U>& other)const
		{
			return Vector3<decltype(std::declval<T>() + std::declval<U>())>
			{ this->x + other.x, this->y + other.y, this->z + other.z };
		}
		/**
		* @brief +=演算子
		*/
		template<typename U = T>
		auto operator+=(const Vector3<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -演算子
		*/
		template<typename U = T>
		constexpr auto operator-(const Vector3<U>& other)const
		{
			return Vector3<decltype(std::declval<T>() - std::declval<U>())>
			{ this->x - other.x, this->y - other.y, this->z - other.z };
		}
		/**
		* @brief -=演算子
		*/
		template<typename U = T>
		auto operator-=(const Vector3<U>& other)
		{
			*this = *this - other;
			return *this;
		}
		/**
		* @brief *演算子(スカラ)
		*/
		template<typename U = T>
		constexpr auto operator*(const U& scalar)const
		{
			return Vector3<decltype(std::declval<T>() * std::declval<U>())>
			{ this->x * scalar, this->y * scalar, this->z * scalar };
		}
		/**
		* @brief *=演算子(スカラ)
		*/
		template<typename U = T>
		auto operator*=(const U& scalar)
		{
			*this = *this * scalar;
			return *this;
		}
		/**
		* @brief *演算子(ベクトル)
		*/
		template<typename U = T>
		constexpr auto operator*(const Vector3<U>& other)const
		{
			return Vector3<decltype(std::declval<T>() * std::declval<U>())>
			{ this->x * other.x, this->y * other.y, this->z * other.z };
		}
		/**
		* @brief *=演算子(ベクトル)
		*/
		template<typename U = T>
		auto operator*=(const Vector3<U>& other)
		{
			*this = *this * other;
			return *this;
		}
		/**
		* @brief /演算子(スカラ)
		*/
		template<typename U = T>
		constexpr auto operator/(const U& scalar)const
		{
			return Vector3<decltype(std::declval<T>() / std::declval<U>())>
			{ this->x / scalar, this->y / scalar, this->z / scalar };
		}
		/**
		* @brief /=演算子(スカラ)
		*/
		template<typename U = T>
		auto operator/=(const U& scalar)
		{
			*this = *this / scalar;
			return *this;
		}
		/**
		* @brief /演算子(ベクトル)
		*/
		template<typename U = T>
		constexpr auto operator/(const Vector3<U>& other)const
		{
			return Vector3<decltype(std::declval<T>() / std::declval<U>())>
			{ this->x / other.x, this->y / other.y, this->z / other.x };
		}
		/**
		* @brief /=演算子(ベクトル)
		*/
		template<typename U = T>
		auto operator/=(const Vector3<U>& other)
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
		/**
		* @brief 正規化
		* @return int型の場合は必ず0になるので注意してください
		*/
		void normalize()
		{
			//分母
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
		* @brief 正規化
		* @return 正規化したもの
		* @details thisは正規化しない
		*/
		template<typename U = double>
		constexpr Vector2<U> return_normalize()const
		{
			//分母
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
	* @brief 二点間の距離
	* @details C++17現在、標準ライブラリのsqrtがconstexprではないので、自作sqrtを利用しconstexprに対応
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U distance(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return saki::sqrt<U>(
			(v1.x - v2.x) * (v1.x - v2.x) +
			(v1.y - v2.y) * (v1.y - v2.y) +
			(v1.z - v2.z) * (v1.z - v2.z));
	}
	/**
	* @brief 内積
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U dot(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return static_cast<U>(v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
	}
	/**
	* @brief 外積
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr Vector3<U> cross(const Vector3<T1>& v1, const Vector3<T2>& v2)
	{
		return Vector3<U>(
			v1.y*v2.z - v1.z*v1.y, //x
			v1.z*v2.x - v1.x*v1.z, //y
			v1.x*v2.y - v1.y*v1.x);//z
	}
}

#endif //SAKI_VECTOR_3D_2018_12_02