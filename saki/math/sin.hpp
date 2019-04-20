/**
* @file sin.hpp
* @brief コンパイル時sin
* @author 石山 悠
* @date 2019/01/03
*/
#ifndef SAKI_MATH_SIN_HPP
#define SAKI_MATH_SIN_HPP
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/factorial.hpp>
#include <saki/math/pi.hpp>
#include <saki/math/pow.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/cos.hpp>
#include <saki/math/isinf.hpp>

namespace saki
{
/**
	* @brief コンパイル時sin
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T sin(T x)
{
	//NaN
	if (saki::isnan(x) || x == 0)
		return x;
	//inf
	if (saki::isinf(x))
	{
		return -std::numeric_limits<T>::quiet_NaN();
	}

	return -saki::cos(x + saki::PI_HALF<T>);
}
/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double sin(T x)
{
	return saki::sin(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_SIN_HPP