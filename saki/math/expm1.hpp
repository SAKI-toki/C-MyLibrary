/**
* @file expm1.hpp
* @brief コンパイル時expm1
* @author 石山 悠
* @date 2019/01/10
*/
#ifndef SAKI_MATH_EXPM1_HPP
#define SAKI_MATH_EXPM1_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/exp.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief コンパイル時expm1
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T expm1(T x)
{
	if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())
		return x;
	if (x == -std::numeric_limits<T>::infinity())
		return 0;
	if (x == 0)
		return static_cast<T>(1);

	return saki::exp(x) - 1;
}
/**
* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double expm1(T x)
{
	return saki::expm1(static_cast<double>(x));
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_EXPM1_HPP