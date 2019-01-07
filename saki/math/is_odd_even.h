/**
* @file is_odd_even.h
* @brief Šï”‚ª‚Ç‚¤‚©A‹ô”‚©‚Ç‚¤‚©”»’è‚·‚éŠÖ”
* @author ÎR —I
* @date 2019/01/07
*/
#pragma once
#ifndef SAKI_IS_ODD_EVEN_2019_01_07
#define SAKI_IS_ODD_EVEN_2019_01_07
#include <limits>
#include <saki/math/fmod.h>

namespace saki
{
	/**
	* @brief Šï”‚ª‚Ç‚¤‚©”»’è‚·‚éŠÖ”
	*/
	template<typename T>
	constexpr bool is_odd(T x)
	{
		return x == std::numeric_limits<T>::infinity() ||
			x == -std::numeric_limits<T>::infinity() ||
			saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(1);
	}
	/**
	* @brief ‹ô”‚ª‚Ç‚¤‚©”»’è‚·‚éŠÖ”
	*/
	template<typename T>
	constexpr bool is_even(T x)
	{
		return x == std::numeric_limits<T>::infinity() ||
			x == -std::numeric_limits<T>::infinity() ||
			saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(0);
	}
}
#endif //SAKI_IS_ODD_EVEN_2019_01_07