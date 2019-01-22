/**
* @file digit_count.h
* @brief �������̌����𐔂���
* @author �ΎR �I
* @date 2019/01/15
*/
#pragma once
#ifndef SAKI_MATH_DIGIT_COUNT_2019_01_15
#define SAKI_MATH_DIGIT_COUNT_2019_01_15
#include <cstddef>
#include <type_traits>
#include <limits>
#include <saki/type_traits/enabled_if_nullptr.h>
#include <saki/math/abs.h>
#include <saki/math/isnan.h>
#include <saki/math/isinf.h>

namespace saki
{
	/**
	* @brief �������̌����𐔂���֐�
	* @details log10�ł��\�����A�����������Ȃ炱������g�����ق����ǂ�
	*/
	template<typename T,
		typename saki::enabled_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
		constexpr size_t digit_count(T x)
	{
		if (saki::isnan(x) || saki::isinf(x))return 0;
		if (saki::abs(x) < 1)return 1;
		size_t count = 0;
		x = saki::abs(x);
		while (x >= 1)
		{
			++count;
			x /= 10;
		}
		return count;
	}
}
#endif //SAKI_MATH_DIGIT_COUNT_2019_01_15