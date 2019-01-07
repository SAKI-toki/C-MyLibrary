/**
* @file sqrt.h
* @brief �R���p�C����������
* @author �ΎR �I
* @date 2018/11/21
*/
#pragma once
#ifndef SAKI_SQRT_2018_11_21
#define SAKI_SQRT_2018_11_21
#include <limits>
#include <saki/math/isnan.h>

namespace saki
{
	/**
	* @brief �R���p�C����������
	* @param x �����������߂�l
	* @details �A���S���Y���̓o�r���j�A�̕������𗘗p
	*/
	template<typename T1 = double, typename T2>
	constexpr T1 sqrt(T2 x)
	{
		if (saki::isnan(x) ||
			x == std::numeric_limits<T2>::infinity() ||
			x == 0)return static_cast<T1>(x);
		if (x < 0)return -std::numeric_limits<T1>::quiet_NaN();

		T1 prev = static_cast<T1>(x / 2.0);
		T1 next = static_cast<T1>((prev + x / prev) * 0.5);
		while (prev != next)
		{
			prev = next;
			next = static_cast<T1>((prev + x / prev) * 0.5);
		}
		return prev;
	}
}
#endif //SAKI_SQRT_2018_11_21