/**
* @file pow.h
* @brief —İæ‚ğ‹‚ß‚éŠÖ”
* @author ÎR —I
* @date 2019/01/03
*/
#pragma once
#ifndef SAKI_POW_2019_01_03
#define SAKI_POW_2019_01_03
#include <type_traits>

namespace saki
{
	template<typename T = double, typename T1>
	constexpr T pow(T1 x, int y)
	{
		T sum = 1;
		for (int i = 0; i < y; ++i)
		{
			sum *= x;
		}
		for (int i = 0; i > y; --i)
		{
			sum /= x;
		}
		return sum;
	}
}
#endif //SAKI_POW_2019_01_03