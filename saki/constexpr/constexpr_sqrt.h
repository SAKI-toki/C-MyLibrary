/**
* @file constexpr_aqrt.h
* @brief �R���p�C����������
* @author �ΎR �I
* @date 2018/11/21
*/
#pragma once
#ifndef SAKI_CONSTEXPR_SQRT_2018_11_21
#define SAKI_CONSTEXPR_SQRT_2018_11_21

namespace saki
{
	/**
	* @brief �R���p�C����������
	* @param n �����������߂�l
	* @details �A���S���Y���̓o�r���j�A�̕������𗘗p
	*/
	template<typename T1 = double, typename T2 = double>
	constexpr T1 sqrt(T2 n)
	{
		//0���Z�����Ȃ��悤�ɂ���
		if (n == 0)return 0;
		T1 prev_x = n;
		T1 next_x = (prev_x + n / prev_x) * 0.5;
		while (prev_x != next_x)
		{
			prev_x = next_x;
			next_x = (prev_x + n / prev_x) * 0.5;
		}
		return prev_x;
	}
}
#endif //SAKI_CONSTEXPR_SQRT_2018_11_21