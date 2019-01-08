/**
* @file cbrt.h
* @brief �R���p�C����cbrt
* @author �ΎR �I
* @date 2019/01/08
*/
#pragma once
#ifndef SAKI_CBRT_2019_01_08
#define SAKI_CBRT_2019_01_08
#include <type_traits>
#include <limits>
#include <saki/math/isnan.h>
#include <saki/math/isinf.h>
#include <saki/math/pow.h>

namespace saki
{
	/**
	* @brief �R���p�C����cbrt
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T cbrt(T x)
	{
		if (saki::isnan(x) || saki::isinf(x) || x == 0)return x;

		return static_cast<T>(saki::pow(x, 1.0 / 3.0));
	}
	/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double cbrt(T x)
	{
		return saki::cbrt(static_cast<double>(x));
	}

	/**
	* @brief �W���Ɋ񂹂邽�ߎ���
	*/
	constexpr float cbrtf(float x)
	{
		return saki::cbrt(x);
	}
	/**
	* @brief �W���Ɋ񂹂邽�ߎ���
	*/
	constexpr long double cbrtl(long double x)
	{
		return saki::cbrt(x);
	}
}
#endif //SAKI_CBRT_2019_01_08