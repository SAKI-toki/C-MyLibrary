/**
* @file constexpr_copysign.h
* @brief �R���p�C���������R�s�[
* @author �ΎR �I
* @date 2018/12/09
*/
#pragma once
#ifndef SAKI_CONSTEXPR_COPYSIGN_2018_12_09
#define SAKI_CONSTEXPR_COPYSIGN_2018_12_09
#include <saki/constexpr/constexpr_abs.h>

namespace saki
{
	/**
	* @brief �R���p�C���������R�s�[
	* @param t ��Βl
	* @param st ����
	*/
	template<typename T,typename SignType>
	constexpr T copysign(const T& t, const SignType& st)
	{
		T abs = saki::abs(t);
		return (st > 0) ? abs : -abs;
	}
}
#endif //SAKI_CONSTEXPR_COPYSIGN_2018_12_09