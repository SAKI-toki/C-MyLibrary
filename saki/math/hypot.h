/**
* @file hypot.h
* @brief コンパイル時hypot
* @author 石山 悠
* @date 2019/01/08
*/
#pragma once
#ifndef SAKI_MATH_HYPOT_2019_01_08
#define SAKI_MATH_HYPOT_2019_01_08
#include <limits>
#include <type_traits>
#include <saki/type_traits/enabled_if_nullptr.h>
#include <saki/math/isnan.h>
#include <saki/math/sqrt.h>
#include <saki/math/abs.h>
#include <saki/math/isinf.h>

namespace saki
{
	///------2引数--------
	/**
	* @brief コンパイル時累乗
	*/
	template<typename T,
		typename saki::enabled_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
		constexpr T hypot(T x, T y)
	{
		if (saki::isinf(x) || saki::isinf(y))return std::numeric_limits<T>::infinity();
		if (saki::isnan(x))return x;
		if (saki::isnan(y))return y;

		if (x == 0)
		{
			if (y == 0)
			{
				//x==0&&y==0
				return 0;
			}
			else
			{
				//y==0
				return saki::abs(y);
			}
		}
		else if (y == 0)
		{
			//x==0
			return saki::abs(x);
		}
		return saki::sqrt(x * x + y * y);
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
	template<typename T,
		typename saki::enabled_if_nullptr_t<std::is_integral_v<T>> = nullptr>
		constexpr double hypot(T x, T y)
	{
		return saki::hypot(static_cast<double>(x), static_cast<double>(y));
	}
	/**
	* @brief 型が違う場合はそろえる
	*/
	template<typename T1, typename T2>
	constexpr auto hypot(T1 x, T2 y)
	{
		return saki::hypot(static_cast<decltype(x * y)>(x), static_cast<decltype(x * y)>(y));
	}

	///------3引数--------

	/**
	* @brief コンパイル時累乗
	*/
	template<typename T,
		typename saki::enabled_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
		constexpr T hypot(T x, T y, T z)
	{
		if (saki::isinf(x) || saki::isinf(y) || saki::isinf(z))return std::numeric_limits<T>::infinity();
		if (saki::isnan(x))return x;
		if (saki::isnan(y))return y;
		if (saki::isnan(z))return z;


		if (x == 0)
		{
			if (y == 0)
			{
				if (z == 0)
				{
					//x==0&&y==0&&z==0
					return 0;
				}
			}
			else if (z == 0)
			{
				//x==0&&z==0
				return saki::abs(y);
			}
			else
			{
				//x==0
				return saki::sqrt(y * y + z * z);
			}
		}
		else if (y == 0)
		{
			if (z == 0)
			{
				//y==0&&z==0
				return saki::abs(x);
			}
			else
			{
				//y==0
				return saki::sqrt(x * x + z * z);
			}
		}
		else if (z == 0)
		{
			//z==0
			return saki::sqrt(x * x + y * y);
		}
		return saki::sqrt(x * x + y * y + z * z);
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
	template<typename T,
		typename saki::enabled_if_nullptr_t<std::is_integral_v<T>> = nullptr>
		constexpr double hypot(T x, T y, T z)
	{
		return saki::hypot(static_cast<double>(x), static_cast<double>(y), static_cast<double>(z));
	}
	/**
	*@brief 型が違う場合はそろえる
	*/
	template<typename T1, typename T2, typename T3>
	constexpr auto hypot(T1 x, T2 y, T3 z)
	{
		return saki::hypot(static_cast<decltype(x * y * z)>(x), 
			static_cast<decltype(x * y * z)>(y), 
			static_cast<decltype(x * y * z)>(z));
	}
}
#endif //SAKI_MATH_HYPOT_2019_01_08