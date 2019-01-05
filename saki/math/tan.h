/**
* @file tan.h
* @brief �R���p�C����tan
* @author �ΎR �I
* @date 2019/01/05
*/
#pragma once
#ifndef SAKI_TAN_2019_01_05
#define SAKI_TAN_2019_01_05
#include <type_traits>
#include <limits>
#include <saki/math/isnan.h>
#include <saki/math/sin.h>
#include <saki/math/cos.h>

namespace saki
{
	/**
	* @brief �R���p�C����tan
	* @param x ���W�A���p
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T tan(T x)
	{
		//NaN
		if (saki::isnan(x))return x;
		//inf
		if (x == std::numeric_limits<T>::infinity() ||
			x == -std::numeric_limits<T>::infinity())
		{
			return -std::numeric_limits<T>::quiet_NaN();
		}
		return saki::sin(x) / saki::cos(x);
	}
}
#endif //SAKI_TAN_2019_01_05