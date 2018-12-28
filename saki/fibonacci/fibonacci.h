/**
* @file fibonacci.h
* @brief �t�B�{�i�b�`������o���֐�
* @author �ΎR �I
* @date 2018/12/28
*/
#pragma once
#ifndef SAKI_FIBONACCI_2018_12_28
#define SAKI_FIBONACCI_2018_12_28
#include <cstdint>
#include <cstddef>

namespace saki
{
	/**
	* @brief �t�B�{�i�b�`������R���p�C�����ɋ��߂�֐�
	* @details �������ɋ��߂����ԍ�������(94�ȍ~�͌v�Z�ł��܂���)
	*/
	template<size_t N, typename T = uint64_t>
	constexpr T fibonacci()
	{
		if constexpr (N > 2)
		{
			return fibonacci<N - 1, T>() + fibonacci<N - 2, T>();
		}
		else
		{
			return static_cast<T>(1);
		}
	}

	/**
	* @brief �t�B�{�i�b�`����������������ɋ��߂�֐�
	* @param N ���߂����ԍ�
	* @details 94�ȍ~�͌v�Z�ł��܂���
	*/
	template<typename T = uint64_t>
	T fibonacci(size_t N)
	{
		return N > 2 ? fibonacci<T>(N - 1) + fibonacci<T>(N - 2) : 1;
	}
}
#endif //SAKI_FIBONACCI_2018_12_28