/**
* @file cbrt.hpp
* @brief コンパイル時cbrt
* @author 石山 悠
* @date 2019/01/08
*/
#ifndef SAKI_MATH_CBRT_HPP
#define SAKI_MATH_CBRT_HPP
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/pow.hpp>

namespace saki
{
/**
	* @brief コンパイル時cbrt
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T cbrt(T x)
{
	if (saki::isnan(x) || saki::isinf(x) || x == 0)
		return x;

	return static_cast<T>((x < 0) ? -saki::pow(-x, 1.0 / 3.0) : saki::pow(x, 1.0 / 3.0));
}
/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double cbrt(T x)
{
	return saki::cbrt(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_CBRT_HPP