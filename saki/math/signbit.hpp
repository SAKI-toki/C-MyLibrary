/**
* @file signbit.hpp
* @brief 負数かどうか判定する関数
* @author 石山 悠
* @date 2019/01/03
*/
#ifndef SAKI_MATH_SIGNBIT_HPP
#define SAKI_MATH_SIGNBIT_HPP
#include <saki/math/copysign.hpp>
#include <saki/math/isnan.hpp>

namespace saki
{
/**
	* @brief 負数かどうか判定する
	* @param x 判定する値
	* @return 負数かどうか
	*/
template <typename T>
constexpr bool signbit(T x)
{
	return x < static_cast<T>(0);
}
} // namespace saki
#endif //SAKI_MATH_SIGNBIT_HPP