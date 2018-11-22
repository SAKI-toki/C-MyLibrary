/**
* @file constexpr_exchange.h
* @brief コンパイル時exchange
* @author 石山 悠
* @date 2018/11/21
*/
#pragma once
#ifndef SAKI_CONSTEXPR_EXCHANGE_2018_11_21
#define SAKI_CONSTEXPR_EXCHANGE_2018_11_21

namespace saki
{
	/**
	* @brief コンパイル時exchange
	* @param t 値を入れられる値
	* @param next 値に入れる値
	*/
	template<typename T, typename U = T>
	constexpr T exchange(T& t, U next)
	{
		auto t1 = t;
		t = next;
		return t1;
	}
}
#endif //SAKI_CONSTEXPR_EXCHANGE_2018_11_21