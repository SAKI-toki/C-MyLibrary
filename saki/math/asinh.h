/**
* @file asinh.h
* @brief コンパイル時asinh
* @author 石山 悠
* @date 2019/01/08
*/
#pragma once
#ifndef SAKI_ASINH_2019_01_08
#define SAKI_ASINH_2019_01_08
#include <type_traits>
#include <limits>
#include <saki/math/isnan.h>
#include <saki/math/isinf.h>
#include <saki/math/log.h>
#include <saki/math/sqrt.h>

namespace saki
{
	/**
	* @brief コンパイル時asinh
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T asinh(T x)
	{
		if (saki::isnan(x) || saki::isinf(x) || x == 0)return x;

		return saki::log(x + saki::sqrt(x * x + 1));
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double asinh(T x)
	{
		return saki::asinh(static_cast<double>(x));
	}
}
#endif //SAKI_ASINH_2019_01_08