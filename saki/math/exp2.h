/**
* @file exp2.h
* @brief �R���p�C����exp2
* @author �ΎR �I
* @date 2019/01/10
*/
#pragma once
#ifndef SAKI_EXP2_2019_01_10
#define SAKI_EXP2_2019_01_10
#include <limits>
#include <type_traits>
#include <saki/math/isnan.h>
#include <saki/math/exp.h>
#include <saki/math/log.h>

namespace saki
{
	/**
	* @brief �R���p�C����exp2
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T exp2(T x)
	{
		if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())return x;
		if (x == -std::numeric_limits<T>::infinity())return 0;
		if (x == 0)return static_cast<T>(1);

		return saki::exp(x * saki::log(2));
	}
	/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double exp2(T x)
	{
		return saki::exp2(static_cast<double>(x));
	}
}
#endif //SAKI_EXP2_2019_01_10