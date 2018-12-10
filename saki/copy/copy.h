/**
* @file copy.h
* @brief ������copy�֐��̊ȗ���
* @author �ΎR �I
* @date 2018/12/09
*/
#pragma once
#ifndef SAKI_COPY_2018_12_09
#define SAKI_COPY_2018_12_09
#include <xutility>
#include <saki/meta/can_begin_method.h>

namespace saki
{
	/**
	* @brief �R���e�i�ƃR���e�i��n��copy
	* @param con1 �R�s�[����R���e�i�N���X
	* @param con2 �y�[�X�g����R���e�i�N���X
	*/
	template <typename Container1, typename Container2>
	auto copy(Container1&& con1, Container2&& con2)
		->decltype(std::declval<std::enable_if_t<CanBegin::value<Container2>>>(), std::begin(con2))
	{
		auto con1itr = std::begin(con1);
		auto con1end = std::end(con1);
		auto con2itr = std::begin(con2);
		while (con1itr != con1end)
		{
			*(con2itr++) = *(con1itr++);
		}
		return con2itr;
	}
	/**
	* @brief �R���e�i�ƃR���e�i��n��copy
	* @param con �R�s�[����R���e�i�N���X
	* @param outitr �y�[�X�g����R���e�i�N���X�̍ŏ��̃C�e���[�^�[
	*/
	template <typename Container, typename OutItr>
	auto copy(Container&& con, OutItr outitr)
		->decltype(std::declval<std::enable_if_t<!CanBegin::value<OutItr>>>(), std::declval<OutItr>())
	{
		auto conitr = std::begin(con);
		auto conend = std::end(con);
		while (conitr != conend)
		{
			*(outitr++) = *(conitr++);
		}
		return outitr;
	}
}
#endif //SAKI_COPY_2018_12_09