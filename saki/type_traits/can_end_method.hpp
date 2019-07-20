/**
* @file can_end_method.hpp
* @brief �w�肵���^��std::end�ł��邩�ǂ������肷�郁�^�֐�
* @author �ΎR �I
* @date 2019/01/12
*/
#ifndef SAKI_TYPE_TRAITS_CAN_END_METHOD_HPP
#define SAKI_TYPE_TRAITS_CAN_END_METHOD_HPP
#include <type_traits>
#include <utility>
#include <iterator>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief end�ł��邩�ǂ����𔻒肷��\����
*/
template <typename T>
struct can_end
{
private:
	template <typename U>
	static constexpr std::true_type end_check(decltype(std::begin(std::declval<U>())) *u);
	template <typename U>
	static constexpr std::false_type end_check(...);

public:
	static constexpr auto value = decltype(end_check<T>(nullptr))::value;
};
/**
* @brief can_end���ȒP�ɌĂяo����ϐ�
*/
template <typename T>
inline constexpr auto can_end_v = saki::can_end<T>::value;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_CAN_END_METHOD_HPP