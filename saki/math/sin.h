/**
* @file sin.h
* @brief コンパイル時sin
* @author 石山 悠
* @date 2019/01/03
*/
#pragma once
#ifndef SAKI_SIN_2019_01_03
#define SAKI_SIN_2019_01_03
#include <type_traits>
#include <limits>
#include <saki/math/factorial.h>
#include <saki/math/pi.h>
#include <saki/math/pow.h>
#include <saki/math/isnan.h>
#include <saki/math/cos.h>

namespace saki
{
	/**
	* @brief コンパイル時sin
	* @param x ラジアン角
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T sin(T x)
	{
		//NaN
		if (saki::isnan(x))return x;
		//inf
		if (x == std::numeric_limits<T>::infinity() ||
			x == -std::numeric_limits<T>::infinity())
		{
			return -std::numeric_limits<T>::quiet_NaN();
		}

		return -saki::cos(x + saki::PI_HALF<T>);
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	* @param x int型のラジアン角
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double sin(T x)
	{
		return saki::sin(static_cast<double>(x));
	}

	/**
	* @brief 標準に寄せるため実装
	*/
	float sinf(float x)
	{
		return saki::sin(x);
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	long double sinl(long double x)
	{
		return saki::sin(x);
	}
}
#endif //SAKI_SIN_2019_01_03