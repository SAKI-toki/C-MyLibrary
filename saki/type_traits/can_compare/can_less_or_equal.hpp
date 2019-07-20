/**
* @file can_less_or_equal.hpp
* @brief �w�肵���^��(<=)���Z�q���g�p�ł��邩�ǂ������肷�郁�^�֐�
* @author �ΎR �I
* @date 2019/01/22
*/
#ifndef SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_LESS_OR_EQUAL_HPP
#define SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_LESS_OR_EQUAL_HPP
#include <type_traits>
#include <utility>
#include <saki/type_traits/remove_reference_const.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief �ȉ���r�ł��邩�ǂ����𔻒肷��\����(<=)
*/
template <typename T>
struct can_less_or_equal
{
private:
	template <typename U>
	static constexpr std::true_type less_or_equal_check(
		saki::remove_reference_const_t<decltype(std::declval<U>() <= std::declval<U>())> *);
	template <typename U>
	static constexpr std::false_type less_or_equal_check(...);

public:
	static constexpr auto value = decltype(less_or_equal_check<T>(nullptr))::value;
};
/**
* @brief can_less_or_equal���ȒP�ɌĂяo����ϐ�
*/
template <typename T>
inline constexpr auto can_less_or_equal_v = saki::can_less_or_equal<T>::value;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_LESS_OR_EQUAL_HPP