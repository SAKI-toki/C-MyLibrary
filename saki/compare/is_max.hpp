/**
* @file is_max.hpp
* @brief �����̔�r����x�ɍs��(>=)
* @author �ΎR �I
* @date 2019/01/21
*/
#ifndef SAKI_COMPARE_IS_MAX_HPP
#define SAKI_COMPARE_IS_MAX_HPP
#include <type_traits>
#include <saki/type_traits/can_compare/can_less.hpp>
#include <saki/type_traits/enable_if_nullptr.hpp>

namespace saki
{
namespace impl
{
/**
		* @brief ��r������̂��Ȃ�(�Ȃ��Ȃ���)�ꍇ�Atrue��Ԃ�
		*/
template <typename T>
constexpr bool is_max_impl(const T &)
{
	return true;
}
/**
		* @brief is_max�̎�����
		* @details ����isnan�𔻒肷��K�v���Ȃ����߁A�������𕪂���
		*/
template <typename First, typename Second, typename... Args>
constexpr bool is_max_impl(const First &first, Second second, const Args &... args)
{
	return (first < static_cast<First>(second)) ? false : saki::impl::is_max_impl(first, (args)...);
}
} // namespace impl
/**
	* @brief �����̔�r����x�ɍs����(>=)
	* @details if(x >= a && x >= b && x >= c)��is_max(x,a,b,c)�Ə�����
	*/
template <typename First, typename... Args,
		  saki::enable_if_nullptr_t<
			  std::conjunction_v<std::is_convertible<Args, First>...> && //�ŏ��ȊO�̌^��First�ɕϊ��\��
			  std::conjunction_v<saki::can_less<First>>					 //First��<���Z�q���L�����ǂ���
			  > = nullptr>
constexpr bool is_max(const First &first, const Args &... args)
{
	return saki::impl::is_max_impl(first, (args)...);
}
} // namespace saki
#endif //SAKI_COMPARE_IS_MAX_HPP