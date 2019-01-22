/**
* @file is_max.h
* @brief �����̔�r����x�ɍs��(>=)
* @author �ΎR �I
* @date 2019/01/21
*/
#pragma once
#ifndef SAKI_COMPARE_IS_MAX_2019_01_21
#define SAKI_COMPARE_IS_MAX_2019_01_21
#include <type_traits>
#include <saki/math/isnan.h>
#include <saki/math/isinf.h>

namespace saki
{
	namespace impl
	{
		/**
		* @brief ��r������̂��Ȃ�(�Ȃ��Ȃ���)�ꍇ�Atrue��Ԃ�
		*/
		template<typename T>
		constexpr bool is_max_impl(const T&)
		{
			return true;
		}
		/**
		* @brief is_max�̎�����
		* @details ����isnan�𔻒肷��K�v���Ȃ����߁A�������𕪂���
		*/
		template<typename First, typename Second, typename ...Args>
		constexpr bool is_max_impl(const First& first, const Second& second, const Args& ...args)
		{
			return (first < static_cast<First>(second)) ? false : saki::impl::is_max_impl(first, (args)...);
		}
	}
	/**
	* @brief �����̔�r����x�ɍs����(>=)
	* @details if(x >= a && x >= b && x >= c)��is_max(x,a,b,c)�Ə�����
	*/
	template<typename First, typename ...Args>
	constexpr auto is_max(const First& first, const Args& ...args)
		->decltype(std::enable_if_t<std::conjunction_v<std::is_convertible<First, Args>...>>(), bool())
	{
		if (saki::isnan(first))return false;
		if (saki::isinf(first))return true;
		return saki::impl::is_max_impl(first, (args)...);
	}
}
#endif //SAKI_COMPARE_IS_MAX_2019_01_21