/**
* @file asin.hpp
* @brief コンパイル時asin
* @author 石山 悠
* @date 2019/01/06
*/
#ifndef SAKI_MATH_ASIN_HPP
#define SAKI_MATH_ASIN_HPP
#include <cstddef>
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/factorial.hpp>
#include <saki/math/sqrt.hpp>
#include <saki/math/pow.hpp>
#include <saki/math/copysign.hpp>
#include <saki/math/pi.hpp>
#include <saki/math/isnan.hpp>

namespace saki
{
/**
	* @brief コンパイル時asin
	* @param x 辺の比
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T asin(T x)
{
	if (saki::isnan(x) || x == 0)
		return x;
	if (saki::abs(x) > 1)
		return -std::numeric_limits<T>::quiet_NaN();

	//精度向上のため値によって処理を分ける
	//0≦|x|≦1/√2
	if (saki::abs(x) <= (1.0 / saki::sqrt<T>(2)))
	{
		T sum = 0;
		size_t n = 0;
		while (n * 2 + 1 <= saki::factorial_limits<T>::limit)
		{
			sum += static_cast<T>(saki::factorial<T>(2 * n) *
								  saki::pow(x, 2 * n + 1) /
								  (saki::pow(4, n) *
								   saki::pow(saki::factorial<T>(n), 2) *
								   (2 * n + 1)));

			++n;
		}
		return sum;
	}
	//1/√2≦x<1
	else
	{
		return saki::copysign(saki::PI_HALF<T> - saki::asin<T>(saki::sqrt<T>(1 - x * x)), x);
	}
}
/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	* @param x int型の比
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double asin(T x)
{
	return saki::asin(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_ASIN_HPP