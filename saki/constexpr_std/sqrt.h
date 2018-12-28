/**
* @file sqrt.h
* @brief コンパイル時平方根
* @author 石山 悠
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
	* @brief コンパイル時平方根
	* @param n 平方根を求める値
	* @details アルゴリズムはバビロニアの平方根を利用
	*/
	template<typename T1 = double, typename T2 = double>
	constexpr T1 sqrt(const T2& n)
	{
		//NaNかinfinityか0ならそのまま返す
		if (!(n == n) ||
			n == std::numeric_limits<T2>::infinity() ||
			n == 0)return n;
		//0以下なら-NaNを返す
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