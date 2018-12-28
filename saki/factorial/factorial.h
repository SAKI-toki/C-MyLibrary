/**
* @file factorial.h
* @brief 階乗
* @author 石山 悠
* @date 2018/11/22
*/
#pragma once
#ifndef SAKI_FACTORIAL_2018_11_22
#define SAKI_FACTORIAL_2018_11_22
#include <cstdint>
#include <cstddef>

namespace saki
{
	/**
	* @brief 階乗(引数バージョン)
	* @param N 1からNまでの階乗を求める
	* @details 引数に値を入れるため、実行時の値でも使用できる
	*/
	template<typename T = uint64_t>
	constexpr T factorial(size_t N)
	{
		return N * ((N > 1) ? saki::factorial<T>(N - 1) : 1);
	}
	/**
	* @brief 階乗(仮引数バージョン)
	* @details 仮引数に値を入れるため、実行時の値は使用できない
	*/
	template<size_t N, typename T = uint64_t>
	constexpr T factorial()
	{
		if constexpr (N > 1)
		{
			return N * saki::factorial<N - 1, T>();
		}
		else
		{
			return N;
		}
	}
}
#endif //SAKI_FACTORIAL_2018_11_22