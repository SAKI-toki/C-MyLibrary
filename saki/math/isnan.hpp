/**
* @file isnan.hpp
* @brief Not a Number���ǂ������肷��֐�
* @author �ΎR �I
* @date 2019/01/02
*/
#ifndef SAKI_MATH_ISNAN_HPP
#define SAKI_MATH_ISNAN_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief Not a Number���ǂ�������
* @param x ���肷��l
* @return NaN���ǂ���
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr bool isnan(T x)
{
	return !(x == x);
}
/**
* @brief Not a Number���ǂ�������
* @details floating_point�ȊO��false
*/
template <typename T,
		  saki::enable_if_nullptr_t<!std::is_floating_point_v<T>> = nullptr>
constexpr bool isnan(T)
{
	return false;
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_ISNAN_HPP