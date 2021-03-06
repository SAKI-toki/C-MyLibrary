/**
* @file abs.hpp
* @brief コンパイル時絶対値
* @author 石山 悠
* @date 2019/01/19
*/
#ifndef SAKI_MATH_ABS_HPP
#define SAKI_MATH_ABS_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief コンパイル時絶対値
* @param x 絶対値を求める値
* @details 符号あり
*/
template <typename T,
		  saki::enable_if_nullptr_t<!std::is_unsigned_v<T>> = nullptr>
constexpr T abs(T x)
{
	if (saki::isnan(x))
		return x;
	return x < 0 ? -x : x;
}
/**
* @brief コンパイル時絶対値
* @param x 絶対値を求める値
* @details 符号なし
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_unsigned_v<T>> = nullptr>
constexpr T abs(T x)
{
	return x;
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_ABS_HPP