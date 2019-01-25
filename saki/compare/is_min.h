/**
* @file is_min.h
* @brief �����̔�r����x�ɍs��(<=)
* @author �ΎR �I
* @date 2019/01/21
*/
#pragma once
#ifndef SAKI_COMPARE_IS_MIN_2019_01_21
#define SAKI_COMPARE_IS_MIN_2019_01_21
#include <type_traits>
#include <saki/type_traits/can_compare/can_greater.h>

namespace saki
{
	namespace impl
	{
		/**
		* @brief ��r������̂��Ȃ�(�Ȃ��Ȃ���)�ꍇ�Atrue��Ԃ�
		*/
		template<typename T>
		constexpr bool is_min_impl(const T&)
		{
			return true;
		}
		/**
		* @brief is_min�̎�����
		* @details ����isnan�𔻒肷��K�v���Ȃ����߁A�������𕪂���
		*/
		template<typename First, typename Second, typename ...Args>
		constexpr bool is_min_impl(const First& first, Second second, const Args& ...args)
		{
			return (first > static_cast<First>(second)) ? false : saki::impl::is_min_impl(first, (args)...);
		}
	}
	/**
	* @brief �����̔�r����x�ɍs����(<=)
	* @details if(x <= a && x <= b && x <= c)��is_min(x,a,b,c)�Ə�����
	*/
	template<typename First, typename ...Args>
	constexpr auto is_min(const First& first, const Args& ...args)
		->decltype(std::enable_if_t<
			std::conjunction_v<std::is_convertible<First, Args>...>&&
			std::conjunction_v<saki::can_greater<First>>
			, bool>())
	{
		return saki::impl::is_min_impl(first, (args)...);
	}
}
#endif //SAKI_COMPARE_IS_MIN_2019_01_21