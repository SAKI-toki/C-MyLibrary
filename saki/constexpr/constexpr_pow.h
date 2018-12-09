/**
* @file constexpr_pow.h
* @brief �R���p�C�����ݏ�(�ׂ���)
* @author �ΎR �I
* @date 2018/12/09
*/
#pragma once
#ifndef SAKI_CONSTEXPR_POW_2018_12_09
#define SAKI_CONSTEXPR_POW_2018_12_09
#include <type_traits>

namespace saki
{
	/**
	* @brief �R���p�C����2��
	* @param base �ꐔ
	*/
	template<typename T = double, typename T1>
	constexpr T square(const T1& base)
	{
		return base * base;
	}

	/**
	* @brief �R���p�C�����ݏ�(�ׂ���)
	* @param base �ꐔ
	* @param index �w��
	*/
	template<typename T = double, typename T1, typename T2>
	constexpr T pow(const T1& base, const T2& index)
	{
		//�[����
		if (index == 0 || base == 1)return 1;
		if constexpr (std::is_integral_v<T2>)
		{
			T1 sum = 1;
			for (int i = 0; i < index; ++i)
			{
				sum *= base;
			}
			return sum;
		}
		else
		{

		}
	}
}
#endif //SAKI_CONSTEXPR_POW_2018_12_09