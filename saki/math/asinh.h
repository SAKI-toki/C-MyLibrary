/**
* @file asinh.h
* @brief �R���p�C����asinh
* @author �ΎR �I
* @date 2019/01/08
*/
#pragma once
#ifndef SAKI_ASINH_2019_01_08
#define SAKI_ASINH_2019_01_08
#include <type_traits>
#include <limits>
#include <saki/math/isnan.h>
#include <saki/math/isinf.h>
#include <saki/math/log.h>
#include <saki/math/sqrt.h>

namespace saki
{
	/**
	* @brief �R���p�C����asinh
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T asinh(T x)
	{
		if (saki::isnan(x) || saki::isinf(x) || x == 0)return x;

		return saki::log(x + saki::sqrt(x * x + 1));
	}
	/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double asinh(T x)
	{
		return saki::asinh(static_cast<double>(x));
	}

	/**
	* @brief �W���Ɋ񂹂邽�ߎ���
	*/
	constexpr float asinhf(float x)
	{
		return saki::asinh(x);
	}
	/**
	* @brief �W���Ɋ񂹂邽�ߎ���
	*/
	constexpr long double asinhl(long double x)
	{
		return saki::asinh(x);
	}
}
#endif //SAKI_ASINH_2019_01_08