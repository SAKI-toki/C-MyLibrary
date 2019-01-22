/**
* @file is_fit.h
* @brief 範囲内かどうかの判定を行う
* @author 石山 悠
* @date 2019/01/21
*/
#pragma once
#ifndef SAKI_COMPARE_IS_FIT_2019_01_21
#define SAKI_COMPARE_IS_FIT_2019_01_21
#include <type_traits>
#include <limits>
#include <saki/type_traits/enabled_if_nullptr.h>
#include <saki/math/isnan.h>
#include <saki/math/isinf.h>

namespace saki
{
	/**
	* @brief 範囲内かどうかの判定を行う
	* @details if(a <= x && x <= b)をis_fit(x,a,b)と書ける
	*/
	template<typename T,
		typename saki::enabled_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
	constexpr bool is_fit(const T& x, const T& min_n, const T& max_n)
	{
		if (saki::isnan(x) ||
			saki::isnan(min_n) ||
			saki::isnan(max_n) ||
			min_n > max_n)return false;
		return (min_n <= x && x <= max_n);
	}
	/**
	* @brief 型をそろえる
	*/
	template<typename T1,typename T2,typename T3,
		typename saki::enabled_if_nullptr_t<
		std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2> && std::is_arithmetic_v<T3>
	> = nullptr>
	constexpr bool is_fit(const T1& x, const T2& min_n, const T3& max_n)
	{
		using type = decltype(x * min_n * max_n);
		return is_fit(static_cast<type>(x), static_cast<type>(min_n), static_cast<type>(max_n));
	}
}
#endif //SAKI_COMPARE_IS_MAX_2019_01_21