/**
* @file exp.h
* @brief コンパイル時exp
* @author 石山 悠
* @date 2019/01/06
*/
#pragma once
#ifndef SAKI_EXP_2019_01_06
#define SAKI_EXP_2019_01_06
#include <limits>
#include <type_traits>
#include <saki/math/factorial.h>
#include <saki/math/isnan.h>
#include <saki/math/pow.h>

namespace saki
{
	/**
	* @brief コンパイル時exp
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T exp(T x)
	{
		if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())return x;
		if (x == -std::numeric_limits<T>::infinity())return 0;
		if (x == 0)return static_cast<T>(1);

		T sum = 0;
		int n = 0;
		while (n <= saki::factorial_limits<T>::limit)
		{
			sum += saki::details::pow_n<T>(x, n) / saki::factorial<T>(n);
			++n;
		}
		return sum;
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double exp(T x)
	{
		return saki::exp(static_cast<double>(x));
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr float expf(float x)
	{
		return saki::exp(x);
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr long double expl(long double x)
	{
		return saki::exp(x);
	}
}
#endif //SAKI_EXP_2019_01_06