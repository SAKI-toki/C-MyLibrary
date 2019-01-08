/**
* @file fmod.h
* @brief �R���p�C����float,double��]
* @author �ΎR �I
* @date 2019/01/02
*/
#pragma once
#ifndef SAKI_FMOD_2019_01_02
#define SAKI_FMOD_2019_01_02
#include <type_traits>
#include <limits>
#include <saki/math/isnan.h>
#include <saki/math/signbit.h>
#include <saki/math/isinf.h>

namespace saki
{
	/**
	* @brief �R���p�C����float,double��]
	* @param x �����鐔
	* @param y ���鐔
	* @return ��]
	*/
	template<typename T = double, typename T1>
	constexpr T fmod(T1 x, T1 y)
	{
		if (saki::isnan(x))
		{
			if (saki::isnan(y))
			{
				return saki::signbit(x) && saki::signbit(y) ?
					-std::numeric_limits<T>::quiet_NaN() :
					std::numeric_limits<T>::quiet_NaN();
			}
			else
			{
				return x;
			}
		}
		if (saki::isnan(y))return static_cast<T>(y);
		if (saki::isinf(x) || y == 0)
		{
			return -std::numeric_limits<T>::quiet_NaN();
		}
		if (x == 0)return static_cast<T>(x);
		if (saki::isinf(y))
		{
			return static_cast<T>(x);
		}

		//����
		return static_cast<T>(x - static_cast<int>(x / y) * y);
	}
	/**
	* @brief �^���Ⴄ�ꍇ�͂��낦��
	*/
	template<typename T = double, typename T1, typename T2>
	constexpr T fmod(T1 x, T2 y)
	{
		return saki::fmod(static_cast<T>(x), static_cast<T>(y));
	}
	/**
	* @brief �W���Ɋ񂹂邽�ߎ���
	*/
	float fmodf(float x, float y)
	{
		return saki::fmod<float>(x, y);
	}
	/**
	* @brief �W���Ɋ񂹂邽�ߎ���
	*/
	long double l(long double x, long double y)
	{
		return saki::fmod<long double>(x, y);
	}
}
#endif //SAKI_FMOD_2019_01_02