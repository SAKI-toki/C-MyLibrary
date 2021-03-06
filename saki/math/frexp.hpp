/**
* @file frexp.hpp
* @brief コンパイル時frexp
* @author 石山 悠
* @date 2019/01/15
*/
#ifndef SAKI_MATH_FREXP_HPP
#define SAKI_MATH_FREXP_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/log2.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/details/pow_n.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief コンパイル時frexp
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T frexp(T value, int *exp)
{
	if (saki::isnan(value) || saki::isinf(value))
	{
		*exp = -1;
		return value;
	}
	if (value == 0)
	{
		*exp = 0;
		return value;
	}

	*exp = static_cast<int>(saki::log2(saki::abs(value)) + ((saki::abs(value) > 0.5) ? 1 : 0));
	return value / saki::details::pow_n(static_cast<T>(2), *exp);
}
/**
* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double frexp(T value, int *exp)
{
	return saki::frexp(static_cast<double>(value), exp);
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_FREXP_HPP