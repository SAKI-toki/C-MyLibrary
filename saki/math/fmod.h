/**
* @file fmod.h
* @brief コンパイル時float,double剰余
* @author 石山 悠
* @date 2019/01/02
*/
#pragma once
#ifndef SAKI_FMOD_2019_01_02
#define SAKI_FMOD_2019_01_02
#include <limits>
#include <saki/math/isnan.h>
#include <saki/math/signbit.h>

namespace saki
{
	/**
	* @brief コンパイル時float,double剰余
	* @param x 割られる数
	* @param y 割る数
	* @return 剰余
	*/
	template<typename T = double, typename T1, typename T2>
	constexpr T fmod(T1 x, T2 y)
	{
		if (saki::isnan(x))
		{
			if (saki::isnan(y))
			{
				return saki::signbit(x) && saki::signbit(y) ?
					-std::numeric_limits<T>::quiet_NaN() :
					std::numeric_limits<T>::quiet_NaN();
			}
		}
		if (saki::isnan(y))return static_cast<T>(y);
		if (x == std::numeric_limits<T>::infinity() ||
			x == -std::numeric_limits<T>::infinity() ||
			y == 0)
		{
			return -std::numeric_limits<T>::quiet_NaN();
		}
		if (x == 0)return static_cast<T>(x);
		if (y == std::numeric_limits<T>::infinity() ||
			y == -std::numeric_limits<T>::infinity())
		{
			return static_cast<T>(x);
		}
		return static_cast<T>(x - static_cast<int>(x / y)*y);
	}
}
#endif //SAKI_FMOD_2019_01_02