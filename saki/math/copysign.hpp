/**
* @file copysign.hpp
* @brief コンパイル時符号コピー
* @author 石山 悠
* @date 2018/12/09
*/
#ifndef SAKI_MATH_COPYSIGN_HPP
#define SAKI_MATH_COPYSIGN_HPP
#include <limits>
#include <saki/math/abs.hpp>
#include <saki/math/isnan.hpp>

namespace saki
{
/**
	* @brief コンパイル時符号コピー
	* @param x 絶対値
	* @param y 符号
	*/
template <typename T, typename SignType>
constexpr T copysign(const T &x, const SignType &y)
{
	T abs_n = (saki::isnan(x)) ? std::numeric_limits<T>::quiet_NaN() : saki::abs(x);
	return (y >= 0) ? abs_n : -abs_n;
}
} // namespace saki
#endif //SAKI_MATH_COPYSIGN_HPP