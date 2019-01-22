/**
* @file addition.h
* @brief �����Z�̃I�y���[�^�[���Ăяo��constexpr�֐��I�u�W�F�N�g
* @author �ΎR �I
* @date 2018/12/08
*/
#pragma once
#ifndef SAKI_FUNCTION_OBJECT_ADDITION_2018_12_08
#define SAKI_FUNCTION_OBJECT_ADDITION_2018_12_08

namespace saki
{
	/**
	* @brief �����Z��constexpr�Ή������֐��I�u�W�F�N�g
	*/
	struct addition
	{
		template<typename T1, typename T2>
		constexpr auto operator()(const T1& t1, const T2& t2)const
		{
			return t1 + t2;
		}
	};
}
#endif //SAKI_FUNCTION_OBJECT_ADDITION_2018_12_08