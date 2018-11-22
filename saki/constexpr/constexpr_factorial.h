/**
* @file constexpr_factorial.h
* @brief コンパイル時階乗
* @author 石山 悠
* @date 2018/11/22
*/
#pragma once
#ifndef SAKI_CONSTEXPR_FACTORIAL_2018_11_22
#define SAKI_CONSTEXPR_FACTORIAL_2018_11_22

namespace saki
{
	/**
	* @brief コンパイル時階乗
	* @param N 1からNまでの階乗を求める
	* @details 引数に値を入れるため、実行時の値でも使用できる
	*/
	template<typename T = unsigned long long>
	constexpr T factorial(unsigned int N)
	{
		return N * ((N > 1) ? factorial<T>(N - 1) : 1);
	}
	/**
	* @brief コンパイル時階乗
	* @details 仮引数に値を入れるため、実行時の値は使用できない
	*/
	template<unsigned int N, typename T = unsigned long long>
	constexpr T factorial()
	{
		if constexpr (N > 1)
		{
			return N * factorial<N - 1, T>();
		}
		else
		{
			return N;
		}
	}
}
#endif //SAKI_CONSTEXPR_FACTORIAL_2018_11_22