/**
* @file cbrt.h
* @brief コンパイル時cbrt
* @author 石山 悠
* @date 2019/01/08
*/
#pragma once
#ifndef SAKI_CBRT_2019_01_08
#define SAKI_CBRT_2019_01_08
#include <type_traits>
#include <limits>
#include <saki/math/isnan.h>
#include <saki/math/isinf.h>
#include <saki/math/pow.h>

namespace saki
{
	/**
	* @brief コンパイル時cbrt
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T cbrt(T x)
	{
		if (saki::isnan(x) || saki::isinf(x) || x == 0)return x;

		return static_cast<T>(saki::pow(x, 1.0 / 3.0));
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double cbrt(T x)
	{
		return saki::cbrt(static_cast<double>(x));
	}

	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr float cbrtf(float x)
	{
		return saki::cbrt(x);
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr long double cbrtl(long double x)
	{
		return saki::cbrt(x);
	}
}
#endif //SAKI_CBRT_2019_01_08