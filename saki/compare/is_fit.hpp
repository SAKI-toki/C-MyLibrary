/**
* @file is_fit.hpp
* @brief �͈͓����ǂ����̔�����s��
* @author �ΎR �I
* @date 2019/01/21
*/
#ifndef SAKI_COMPARE_IS_FIT_HPP
#define SAKI_COMPARE_IS_FIT_HPP
#include <type_traits>
#include <saki/type_traits/can_compare/can_less_or_equal.hpp>
#include <saki/type_traits/enable_if_nullptr.hpp>

namespace saki
{
/**
	* @brief �͈͓����ǂ����̔�����s��
	* @details if(a <= x && x <= b)��is_fit(x,a,b)�Ə�����
	*/
template <typename T,
		  saki::enable_if_nullptr_t<
			  saki::can_less_or_equal_v<T> //<=���Z�q���L�����ǂ���
			  > = nullptr>
constexpr bool is_fit(const T &x, const T &min_n, const T &max_n)
{
	return (min_n <= x && x <= max_n);
}
/**
	* @brief �^�����낦��
	*/
template <typename First, typename MinType, typename MaxType,
		  saki::enable_if_nullptr_t<
			  std::is_convertible_v<MinType, First> && //MinType����First�ɕϊ��\��
			  std::is_convertible_v<MaxType, First> && //MaxType����First�ɕϊ��\��
			  saki::can_less_or_equal_v<First>		   //<=���Z�q���L�����ǂ���
			  > = nullptr>
constexpr bool is_fit(First x, MinType min_n, MaxType max_n)
{
	return is_fit(x, static_cast<First>(min_n), static_cast<First>(max_n));
}
} // namespace saki
#endif //SAKI_COMPARE_IS_FIT_HPP