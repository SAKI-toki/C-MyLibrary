/**
* @file is_fit.h
* @brief ”ÍˆÍ“à‚©‚Ç‚¤‚©‚Ì”»’è‚ğs‚¤
* @author ÎR —I
* @date 2019/01/21
*/
#pragma once
#ifndef SAKI_COMPARE_IS_FIT_2019_01_21
#define SAKI_COMPARE_IS_FIT_2019_01_21
#include <type_traits>
#include <saki/type_traits/can_compare/can_less_or_equal.h>
#include <saki/type_traits/enable_if_nullptr.h>

namespace saki
{
	/**
	* @brief ”ÍˆÍ“à‚©‚Ç‚¤‚©‚Ì”»’è‚ğs‚¤
	* @details if(a <= x && x <= b)‚ğis_fit(x,a,b)‚Æ‘‚¯‚é
	*/
	template<typename T,
		typename saki::enable_if_nullptr_t<saki::can_less_or_equal_v<T>> = nullptr>
	constexpr bool is_fit(const T& x, const T& min_n, const T& max_n)
	{
		return (min_n <= x && x <= max_n);
	}
	/**
	* @brief Œ^‚ğ‚»‚ë‚¦‚é
	*/
	template<typename First, typename MinType, typename MaxType,
		typename saki::enable_if_nullptr_t <
		std::is_convertible_v<MinType, First>&&std::is_convertible_v<MaxType, First>&&
		saki::can_less_or_equal_v<First>
	> = nullptr>
	constexpr bool is_fit(First x, MinType min_n, MaxType max_n)
	{
		return is_fit(x, static_cast<First>(min_n), static_cast<First>(max_n));
	}
}
#endif //SAKI_COMPARE_IS_MAX_2019_01_21