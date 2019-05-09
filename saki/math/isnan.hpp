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

namespace saki
{
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
	* @param x ���肷��l
	* @details floating_point�ȊO��false
	*/
template <typename T,
		  saki::enable_if_nullptr_t<!std::is_floating_point_v<T>> = nullptr>
constexpr bool isnan(T)
{
	return false;
}
} // namespace saki
#endif //SAKI_MATH_ISNAN_HPP