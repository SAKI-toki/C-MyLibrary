/**
* @file cos.h
* @brief �R���p�C����cos
* @author �ΎR �I
* @date 2019/01/05
*/
#pragma once
#ifndef SAKI_COS_2019_01_05
#define SAKI_COS_2019_01_05
#include <type_traits>
#include <limits>
#include <saki/math/factorial.h>
#include <saki/math/pi.h>
#include <saki/math/pow.h>
#include <saki/math/isnan.h>

namespace saki
{
	/**
	* @brief �R���p�C����cos
	* @param x ���W�A���p
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T cos(T x)
	{
		//NaN
		if (saki::isnan(x))return x;
		//inf
		if (x == std::numeric_limits<T>::infinity() ||
			x == -std::numeric_limits<T>::infinity())
		{
			return -std::numeric_limits<T>::quiet_NaN();
		}
		//-PI��x��PI�͈̔͂Ɏ��߂�
		while (x > saki::PI<T>)x -= saki::PI<T> * 2;
		while (x < -saki::PI<T>)x += saki::PI<T> * 2;

		T sum = 0;
		int n = 0;
		while (n < saki::factorial_limits<T>::limit)
		{
			sum += saki::pow<T>(-1, n) *
				saki::pow<T>(x, 2 * n) /
				saki::factorial<T>(2 * n);
			++n;
		}
		return sum;
	}
	/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	* @param x int�^�̃��W�A���p
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double cos(T x)
	{
		return saki::cos(static_cast<double>(x));
	}

	/**
	* @brief �W���Ɋ񂹂邽�ߎ���
	*/
	float cosf(float x)
	{
		return saki::cos(x);
	}
	/**
	* @brief �W���Ɋ񂹂邽�ߎ���
	*/
	long double cosl(long double x)
	{
		return saki::cos(x);
	}
}
#endif //SAKI_COS_2019_01_05