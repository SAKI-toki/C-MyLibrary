/**
* @file isnan.hpp
* @brief Not a Number‚©‚Ç‚¤‚©”»’è‚·‚éŠÖ”
* @author ÎR —I
* @date 2019/01/02
*/
#ifndef SAKI_MATH_ISNAN_HPP
#define SAKI_MATH_ISNAN_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief Not a Number‚©‚Ç‚¤‚©”»’è
* @param x ”»’è‚·‚é’l
* @return NaN‚©‚Ç‚¤‚©
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr bool isnan(T x)
{
	return !(x == x);
}
/**
* @brief Not a Number‚©‚Ç‚¤‚©”»’è
* @details floating_pointˆÈŠO‚Ífalse
*/
template <typename T,
		  saki::enable_if_nullptr_t<!std::is_floating_point_v<T>> = nullptr>
constexpr bool isnan(T)
{
	return false;
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_ISNAN_HPP