/**
* @file isinf.hpp
* @brief コンパイル時isinf
* @author 石山 悠
* @date 2019/01/08
*/
#ifndef SAKI_MATH_ISINF_HPP
#define SAKI_MATH_ISINF_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief コンパイル時isinf
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr bool isinf(T x)
{
	return x == std::numeric_limits<T>::infinity() ||
		   x == -std::numeric_limits<T>::infinity();
}
/**
* @brief コンパイル時isinf
* @details floating_point以外はfalse
*/
template <typename T,
		  saki::enable_if_nullptr_t<!std::is_floating_point_v<T>> = nullptr>
constexpr bool isinf(T)
{
	return false;
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_ISINF_HPP