/**
* @file constexpr_aqrt.h
* @brief コンパイル時平方根
* @author 石山 悠
* @date 2018/11/21
*/
#pragma once
#ifndef SAKI_CONSTEXPR_SQRT_2018_11_21
#define SAKI_CONSTEXPR_SQRT_2018_11_21

namespace saki
{
	/**
	* @brief コンパイル時平方根
	* @param n 平方根を求める値
	* @details アルゴリズムはバビロニアの平方根を利用
	*/
	template<typename T1 = double, typename T2 = double>
	constexpr T1 sqrt(T2 n)
	{
		//0除算をしないようにする
		if (n == 0)return 0;
		//負の場合
		if (n < 0)return -nan("ind");
		T1 prev = n / 2;
		T1 next = (prev + n / prev) * 0.5;
		while (prev != next)
		{
			prev = next;
			next = (prev + n / prev) * 0.5;
		}
		return prev;
	}
}
#endif //SAKI_CONSTEXPR_SQRT_2018_11_21