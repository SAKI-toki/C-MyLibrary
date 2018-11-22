/**
* @file vector_2d.h
* @brief 2次元でのベクトル
* @author 石山 悠
* @date 2018/11/18
*/
#pragma once
#ifndef SAKI_VECTOR_2D_2018_11_18
#define SAKI_VECTOR_2D_2018_11_18
#include <type_traits> //for meta method
#include "../constexpr/constexpr_sqrt.h"

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
			x(T()), y(T())
		{}
		/**
		* @brief 引数ありコンストラクタ
		* @param _x xの初期値
		* @param _y yの初期値
		*/
		constexpr Vector2(const T& _x, const T& _y) :
			x(_x), y(_y)
		{}
		/**
		* @brief 引数あり型変換コンストラクタ
		* @param _x xの初期値
		* @param _y yの初期値
		*/
		template<typename U1, typename U2>
		constexpr Vector2(const U1& _x, const U2& _y) :
			x(static_cast<T>(_x)), y(static_cast<T>(_y))
		{}
		/**
		* @brief コピーコンストラクタ
		* @param other コピーする対象（型が一致）
		*/
		Vector2(const Vector2<T>& other)
		{
			this->x = other.x;
			this->y = other.y;
		}
		/**
		* @brief 型変換コピーコンストラクタ
		* @param other コピーする対象（型が不一致）
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector2(const Vector2<U>& other)
		{
			this->x = static_cast<T>(other.x);
			this->y = static_cast<T>(other.y);
		}
		/**
		* @brief コピー代入演算子
		* @param other コピーする対象（型が一致）
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
		* @brief 型変換コピー代入演算子
		* @param other コピーする対象（型が不一致）
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
		* @brief ムーブコンストラクタ
		* @param other ムーブする対象（型が一致）
		*/
		Vector2(Vector2<T>&& other)noexcept
		{
			this->x = std::move(other.x);
			this->y = std::move(other.y);
		}
		/**
		* @brief 型変換ムーブコンストラクタ
		* @param other ムーブする対象（型が不一致）
		*/
		template<typename U,
			std::enable_if_t<std::is_convertible_v<U, T>, std::nullptr_t> = nullptr>
			Vector2(Vector2<U>&& other)noexcept
		{
			this->x = std::move(static_cast<T>(other.x));
			this->y = std::move(static_cast<T>(other.y));
		}
		/**
		* @brief ムーブ代入演算子
		* @param other ムーブする対象（型が一致）
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
		* @brief 型変換ムーブ代入演算子
		* @param other ムーブする対象（型が不一致）
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
		* @brief +演算子
		*/
		template<typename U>
		constexpr auto operator+(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() + std::declval<U>())>
			{ this->x + other.x, this->y + other.y };
		}
		/**
		* @brief +=演算子
		*/
		template<typename U>
		constexpr auto operator+=(const Vector2<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -演算子
		*/
		template<typename U>
		constexpr auto operator-(const Vector2<U>& other)const
		{
			return Vector2<decltype(std::declval<T>() - std::declval<U>())>
			{ this->x - other.x, this->y - other.y };
		}
		/**
		* @brief -=演算子
		*/
		template<typename U>
		constexpr auto operator-=(const Vector2<U>& other)
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
			return Vector2<decltype(std::declval<T>() * std::declval<U>())>
			{ this->x * scalar, this->y * scalar };
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
			return Vector2<decltype(std::declval<T>() / std::declval<U>())>
			{ this->x / scalar, this->y / scalar };
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
	};

	/**
	* @brief 二点間の距離
	* @details std::sqrtとstd::powがconstexprじゃないので実行時処理のみで有効
	*/
	template<typename T1, typename T2>
	constexpr auto distance(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return static_cast<decltype(std::declval<T1>() - std::declval<T2>())>(
			saki::sqrt(
			(v1.x - v2.x) * (v1.x - v2.x) +
				(v1.y - v2.y) * (v1.y - v2.y)));
	}
}

#endif //SAKI_VECTOR_2D_2018_11_18