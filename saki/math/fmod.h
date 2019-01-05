/**
* @file fmod.h
* @brief �R���p�C����float,double��]
* @author �ΎR �I
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
	* @brief �R���p�C����float,double��]
	* @param x �����鐔
	* @param y ���鐔
	* @return ��]
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