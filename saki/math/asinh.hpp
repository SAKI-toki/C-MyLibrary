/**
* @file asinh.hpp
* @brief コンパイル時asinh
* @author 石山 悠
* @date 2019/01/08
*/
#ifndef SAKI_MATH_ASINH_HPP
#define SAKI_MATH_ASINH_HPP
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/log.hpp>
#include <saki/math/sqrt.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief コンパイル時asinh
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T asinh(T x)
{
	if (saki::isnan(x) || saki::isinf(x) || x == 0)
		return x;

	return saki::log(x + saki::sqrt(x * x + 1));
}
/**
* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double asinh(T x)
{
	return saki::asinh(static_cast<double>(x));
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_ASINH_HPP