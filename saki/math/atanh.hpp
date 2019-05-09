/**
* @file atanh.hpp
* @brief コンパイル時atanh
* @author 石山 悠
* @date 2019/01/08
*/
#ifndef SAKI_MATH_ATANH_HPP
#define SAKI_MATH_ATANH_HPP
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/log.hpp>
#include <saki/math/sqrt.hpp>
#include <saki/math/copysign.hpp>

namespace saki
{
/**
	* @brief コンパイル時atanh
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T atanh(T x)
{
	if (saki::isnan(x) || saki::abs(x) == 0)
		return x;
	if (saki::abs(x) > 1)
		return std::numeric_limits<T>::quiet_NaN();
	if (saki::abs(x) == 1)
		return saki::copysign(std::numeric_limits<T>::infinity(), x);

	return static_cast<T>(0.5 * saki::log((1 + x) / (1 - x)));
}
/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double atanh(T x)
{
	return saki::atanh(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_ATANH_HPP