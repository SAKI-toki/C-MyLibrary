/**
* @file expm1.h
* @brief �R���p�C����expm1
* @author �ΎR �I
* @date 2019/01/10
*/
#pragma once
#ifndef SAKI_EXPM1_2019_01_10
#define SAKI_EXPM1_2019_01_10
#include <limits>
#include <type_traits>
#include <saki/math/isnan.h>
#include <saki/math/exp.h>

namespace saki
{
	/**
	* @brief �R���p�C����expm1
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T expm1(T x)
	{
		if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())return x;
		if (x == -std::numeric_limits<T>::infinity())return 0;
		if (x == 0)return static_cast<T>(1);

		return saki::exp(x) - 1;
	}
	/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double expm1(T x)
	{
		return saki::expm1(static_cast<double>(x));
	}
}
#endif //SAKI_EXPM1_2019_01_10