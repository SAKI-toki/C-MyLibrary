/**
* @file is_odd_even.hpp
* @brief 奇数がどうか、偶数かどうか判定する関数
* @author 石山 悠
* @date 2019/01/07
*/
#ifndef SAKI_MATH_IS_ODD_EVEN_HPP
#define SAKI_MATH_IS_ODD_EVEN_HPP
#include <limits>
#include <saki/math/fmod.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/isnan.hpp>

namespace saki
{
/**
	* @brief 奇数がどうか判定する関数
	*/
template <typename T>
constexpr bool is_odd(T x)
{
	if (saki::isnan(x))
		return false;
	return saki::isinf(x) ||
		   saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(1);
}
/**
	* @brief 偶数がどうか判定する関数
	*/
template <typename T>
constexpr bool is_even(T x)
{
	if (saki::isnan(x))
		return false;
	return saki::isinf(x) ||
		   saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(0);
}
} // namespace saki
#endif //SAKI_MATH_IS_ODD_EVEN_HPP