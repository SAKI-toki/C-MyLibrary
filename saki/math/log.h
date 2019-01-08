/**
* @file log.h
* @brief コンパイル時log
* @author 石山 悠
* @date 2019/01/06
*/
#pragma once
#ifndef SAKI_LOG_2019_01_06
#define SAKI_LOG_2019_01_06
#include <limits>
#include <type_traits>
#include <saki/math/isnan.h>

namespace saki
{
	/**
	* @brief コンパイル時log
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T log(T x)
	{
		if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())return x;
		if (x == -std::numeric_limits<T>::infinity() || x < 0)return -std::numeric_limits<T>::quiet_NaN();
		if (x == 0)return -std::numeric_limits<T>::infinity();
		if (x == 1)return 0;

		int ad = 1;
		if (x < 1)
		{
			ad = -1;
			x = 1 / x;
		}
		while (x > saki::details::sqrt_v<2, T>)
		{
			ad *= 2;
			x = saki::sqrt<T>(x);
		}
		--x;
		T sum = 0;
		int n = 1;
		T _sum = -1;
		while (sum != _sum)
		{
			_sum = sum;
			sum += (((n + 1) % 2 == 0) ? 1 : -1) *
				saki::details::pow_n<T>(x, n) /
				n;
			++n;
		}
		return sum * ad;
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double log(T x)
	{
		return saki::log(static_cast<double>(x));
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr float logf(float x)
	{
		return saki::log(x);
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr long double logl(long double x)
	{
		return saki::log(x);
	}
}
#endif //SAKI_LOG_2019_01_06