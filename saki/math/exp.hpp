/**
* @file exp.hpp
* @brief コンパイル時exp
* @author 石山 悠
* @date 2019/01/06
*/
#ifndef SAKI_MATH_EXP_HPP
#define SAKI_MATH_EXP_HPP
#include <cstddef>
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/factorial.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/details/pow_n.hpp>
#include <saki/math/is_odd_even.hpp>

namespace saki
{
/**
	* @brief コンパイル時exp
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T exp(T x)
{
	if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())
		return x;
	if (x == -std::numeric_limits<T>::infinity())
		return 0;
	if (x == 0)
		return static_cast<T>(1);

	bool minus = false;
	if (x <= -1)
	{
		minus = true;
		x *= -1;
	}
	size_t ad = 1;
	while (x > 2)
	{
		ad *= 2;
		x /= 2;
	}
	T sum = 1;
	size_t n = 1;
	while (n <= saki::factorial_limits<T>::limit)
	{
		sum += saki::details::pow_n(x, n) / saki::factorial<T>(n);
		++n;
	}
	return saki::details::pow_n(
		((minus) ? (1 / sum) : (sum)),
		ad);
}
/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double exp(T x)
{
	return saki::exp(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_EXP_HPP