/**
* @file fibonacci.h
* @brief フィボナッチ数列を出す関数
* @author 石山 悠
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
	* @brief フィボナッチ数列をコンパイル時に求める関数
	* @details 仮引数に求めたい番号を入れる(94以降は計算できません)
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
	* @brief フィボナッチ数列をじっこう時に求める関数
	* @param N 求めたい番号
	* @details 94以降は計算できません
	*/
	template<typename T = uint64_t>
	T fibonacci(size_t N)
	{
		return N > 2 ? fibonacci<T>(N - 1) + fibonacci<T>(N - 2) : 1;
	}
}
#endif //SAKI_FIBONACCI_2018_12_28