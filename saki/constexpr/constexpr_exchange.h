/**
* @file constexpr_exchange.h
* @brief �R���p�C����exchange
* @author �ΎR �I
* @date 2018/11/21
*/
#pragma once
#ifndef SAKI_CONSTEXPR_EXCHANGE_2018_11_21
#define SAKI_CONSTEXPR_EXCHANGE_2018_11_21

namespace saki
{
	/**
	* @brief �R���p�C����exchange
	* @param t �l��������l
	* @param next �l�ɓ����l
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