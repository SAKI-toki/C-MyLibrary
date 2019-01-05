/**
* @file isnan.h
* @brief Not a Numberかどうか判定する関数
* @author 石山 悠
* @date 2018/01/02
*/
#pragma once
#ifndef SAKI_ISNAN_2018_01_02
#define SAKI_ISNAN_2018_01_02

namespace saki
{
	/**
	* @brief Not a Numberかどうか判定
	* @param x 判定する値
	* @return NaNかどうか
	*/
	template<typename T>
	constexpr bool isnan(T x)
	{
		return !(x == x);
	}
}
#endif //SAKI_ISNAN_2018_01_02