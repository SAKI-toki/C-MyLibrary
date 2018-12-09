/**
* @file constexpr_pow.h
* @brief コンパイル時累乗(べき乗)
* @author 石山 悠
* @date 2018/12/09
*/
#pragma once
#ifndef SAKI_CONSTEXPR_POW_2018_12_09
#define SAKI_CONSTEXPR_POW_2018_12_09
#include <type_traits>

namespace saki
{
	/**
	* @brief コンパイル時2乗
	* @param base 底数
	*/
	template<typename T = double, typename T1>
	constexpr T square(const T1& base)
	{
		return base * base;
	}

	/**
	* @brief コンパイル時累乗(べき乗)
	* @param base 底数
	* @param index 指数
	*/
	template<typename T = double, typename T1, typename T2>
	constexpr T pow(const T1& base, const T2& index)
	{
		//ゼロ乗
		if (index == 0 || base == 1)return 1;
		if constexpr (std::is_integral_v<T2>)
		{
			T1 sum = 1;
			for (int i = 0; i < index; ++i)
			{
				sum *= base;
			}
			return sum;
		}
		else
		{

		}
	}
}
#endif //SAKI_CONSTEXPR_POW_2018_12_09