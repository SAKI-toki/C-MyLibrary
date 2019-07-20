/**
* @file has_check_method.hpp
* @brief �w�肵���^��check�֐��������Ă��邩�ǂ������肷�郁�^�֐�
* @author �ΎR �I
* @date 2018/12/23
*/
#ifndef SAKI_TYPE_TRAITS_HAS_CHECK_METHOD_HPP
#define SAKI_TYPE_TRAITS_HAS_CHECK_METHOD_HPP
#include <type_traits>
#include <utility>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief check�֐��������Ă��邩�ǂ����𔻒肷��\����
*/
template <typename T>
struct has_check
{
private:
	template <typename U>
	static constexpr std::true_type check_check(decltype(std::declval<U>().check(char())) *u);
	template <typename U>
	static constexpr std::false_type check_check(...);

public:
	static constexpr auto value = decltype(check_check<T>(nullptr))::value;
};
/**
* @brief has_check���ȒP�ɌĂяo����ϐ�
*/
template <typename T>
inline constexpr auto has_check_v = saki::has_check<T>::value;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_HAS_CHECK_METHOD_HPP