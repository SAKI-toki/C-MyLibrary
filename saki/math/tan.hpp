/**
* @file tan.hpp
* @brief コンパイル時tan
* @author 石山 悠
* @date 2019/01/05
*/
#ifndef SAKI_MATH_TAN_HPP
#define SAKI_MATH_TAN_HPP
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/sin.hpp>
#include <saki/math/cos.hpp>
#include <saki/math/isinf.hpp>

namespace saki
{
/**
	* @brief コンパイル時tan
	* @param x ラジアン角
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T tan(T x)
{
	//NaN
	if (saki::isnan(x))
		return x;
	//inf
	if (saki::isinf(x))
	{
		return -std::numeric_limits<T>::quiet_NaN();
	}
	return saki::sin(x) / saki::cos(x);
}

/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	* @param x int型のラジアン角
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double tan(T x)
{
	return saki::tan(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_TAN_HPP