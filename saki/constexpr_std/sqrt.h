/**
* @file sqrt.h
* @brief �R���p�C����������
* @author �ΎR �I
* @date 2018/11/21
*/
#pragma once
#ifndef SAKI_SQRT_2018_11_21
#define SAKI_SQRT_2018_11_21
#include <cmath>
#include <limits>

namespace saki
{
	/**
	* @brief �R���p�C����������
	* @param n �����������߂�l
	* @details �A���S���Y���̓o�r���j�A�̕������𗘗p
	*/
	template<typename T1 = double, typename T2 = double>
	constexpr T1 sqrt(const T2& n)
	{
		//NaN��infinity��0�Ȃ炻�̂܂ܕԂ�
		if (!(n == n) ||
			n == std::numeric_limits<T2>::infinity() ||
			n == 0)return n;
		//0�ȉ��Ȃ�-NaN��Ԃ�
		if (n < 0)return -std::numeric_limits<T2>::quiet_NaN();

		T1 prev = n / 2.0;
		T1 next = (prev + n / prev) * 0.5;
		while (prev != next)
		{
			prev = next;
			next = (prev + n / prev) * 0.5;
		}
		return prev;
	}
}
#endif //SAKI_SQRT_2018_11_21