/**
* @file vector_2d.h
* @brief 2次元でのベクトル
* @author 石山 悠
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
	* @brief 2次元でのベクトル
	*/
	template<typename T>
	class Vector2
	{
	public:
		T x, y;
		/**
		* @brief 引数なしコンストラクタ
		*/
		constexpr Vector2() :
			x(static_cast<T>(0)), y(static_cast<T>(0))
		{}
		/**
		* @brief 引数ありコンストラクタ
		* @param _x xの初期値
		* @param _y yの初期値
		*/
		constexpr Vector2(const T& _x, const T& _y) :
			x(_x), y(_y)
		{}
		//デフォルトを使用
		Vector2(const Vector2<T>&) = default;
		Vector2<T>& operator=(const Vector2<T>&) = default;
		Vector2(Vector2<T>&&) = default;
		Vector2& operator=(Vector2<T>&&) = default;
		/**
		* @brief +演算子
		*/
		template<typename U = T>
		constexpr auto operator+(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() + std::declval<U>())>
			{ this->x + other.x, this->y + other.y };
		}
		/**
		* @brief +=演算子
		*/
		template<typename U = T>
		auto operator+=(const Vector2<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -演算子
		*/
		template<typename U = T>
		constexpr auto operator-(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() - std::declval<U>())>
			{ this->x - other.x, this->y - other.y };
		}
		/**
		* @brief -=演算子
		*/
		template<typename U = T>
		auto operator-=(const Vector2<U>& other)
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
			return Vector2<decltype(std::declval<T>() * std::declval<U>())>
			{ this->x * scalar, this->y * scalar };
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
		constexpr auto operator*(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() * std::declval<U>())>
			{ this->x * other.x, this->y * other.y };
		}
		/**
		* @brief *=演算子(ベクトル)
		*/
		template<typename U = T>
		auto operator*=(const Vector2<U>& other)
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
			return Vector2<decltype(std::declval<T>() / std::declval<U>())>
			{ this->x / scalar, this->y / scalar };
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
		constexpr auto operator/(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() / std::declval<U>())>
			{ this->x / other.x, this->y / other.y };
		}
		/**
		* @brief /=演算子(ベクトル)
		*/
		template<typename U = T>
		auto operator/=(const Vector2<U>& other)
		{
			*this = *this / other;
			return *this;
		}
		/**
		* @brief ==演算子
		*/
		constexpr bool operator==(const Vector2<T>& other)const
		{
			return this->x == other.x && this->y == other.y;
		}
		/**
		* @brief !=演算子
		*/
		constexpr bool operator!=(const Vector2<T>& other)const
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
		* @brief 正規化
		* @return 正規化したもの
		* @details thisは正規化しない
		*/
		template<typename U = double>
		constexpr Vector2<U> return_normalize()const
		{
			//分母
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
	* @brief 二点間の距離
	* @details C++17現在、std::sqrtがconstexprではないので、自作sqrtを利用しconstexprに対応
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U distance(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return saki::sqrt<U>(
			(v1.x - v2.x) * (v1.x - v2.x) +
			(v1.y - v2.y) * (v1.y - v2.y));
	}
	/**
	* @brief 内積
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U dot(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return static_cast<U>(v1.x*v2.x + v1.y*v2.y);
	}
	/**
	* @brief 外積
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U cross(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return static_cast<U>(v1.x * v2.y - v1.y * v2.x);
	}
}
#endif //SAKI_VECTOR_2D_2018_12_02