/**
* @file accumulate.h
* @brief ������accumulate�֐��̊ȗ���
* @author �ΎR �I
* @date 2018/12/06
*/
/*
�S�Ă̗v�f�����v�i���͎w�肵�����Z�q�j���R���e�i�N���X�Ə����l��n�������ŉ\�ɂ���
�W�����C�u�����ł�Iterator��n���̂ŁA�S�ĂȂ炱�������g�����ق����ǂ�
*/
#pragma once
#ifndef SAKI_ACCUMULATE_2018_12_06
#define SAKI_ACCUMULATE_2018_12_06
#include <type_traits>
#include <saki/meta/can_range_based_for.h>
#include <saki/meta/remove_reference_const.h>
#include <saki/binary_operator/addition.h>
namespace saki
{
	/**
	* @brief ������2�̊֐����w�肵�A��������ׂĂ̗v�f�ŉ�
	* @param con �R���e�i�N���X
	* @param init �����l
	* @param binary_op ������2�̊֐�
	* @return �S�Ă̗v�f���񂵂�����
	*/
	template<typename Container, typename BinaryOperation = saki::addition,
		typename std::enable_if_t<saki::can_range_based_for_v<Container>, std::nullptr_t> = nullptr,
		typename T = saki::remove_reference_const_t<typename Container::value_type>,
		typename std::enable_if_t<std::is_invocable_r_v<T, BinaryOperation, T, T>, std::nullptr_t> = nullptr>
		constexpr auto accumulate(const Container& con, T init = 0, BinaryOperation&& binary_op = saki::addition())
	{
		for (const auto& n : con)
		{
			init = binary_op(init, n);
		}
		return init;
	}

}
#endif //SAKI_ACCUMULATE_2018_12_06