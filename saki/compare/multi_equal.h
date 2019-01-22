/**
* @file multi_equal.h
* @brief �����̔�r����x�ɍs��(==)
* @author �ΎR �I
* @date 2019/01/18
*/
#pragma once
#ifndef SAKI_COMPARE_MULTI_EQUAL_2019_01_18
#define SAKI_COMPARE_MULTI_EQUAL_2019_01_18
#include <saki/math/isnan.h>

namespace saki
{
	namespace impl
	{
		/**
		* @brief ��r������̂��Ȃ�(�Ȃ��Ȃ���)�ꍇ�Afalse��Ԃ�
		*/
		template<typename T>
		constexpr bool multi_equal_impl(const T&)
		{
			return false;
		}
		/**
		* @brief multi_equal�̎�����
		* @details ����isnan�𔻒肷��K�v���Ȃ����߁A�������𕪂���
		*/
		template<typename First, typename Second, typename ...Args>
		constexpr bool multi_equal_impl(const First& first, const Second& second, const Args& ...args)
		{
			return (first == static_cast<First>(second)) ? true : saki::impl::multi_equal_impl(first, (args)...);
		}
	}
	/**
	* @brief �����̔�r����x�ɍs����
	* @details if(x == 1 || x == 2 || x == 3)��multi_equal(x,1,2,3)�Ə�����
	*/
	template<typename First, typename ...Args>
	constexpr bool multi_equal(const First& first, const Args& ...args)
	{
		if (saki::isnan(first))return false;
		return saki::impl::multi_equal_impl(first, (args)...);
	}
}
#endif //SAKI_COMPARE_MULTI_EQUAL_2019_01_18