/**
* @file floor.hpp
* @brief コンパイル時floor
* @author 石山 悠
* @date 2019/01/15
*/
#ifndef SAKI_MATH_FLOOR_HPP
#define SAKI_MATH_FLOOR_HPP
#include <cstddef>
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/fmod.hpp>
#include <saki/math/log.hpp>
#include <saki/math/copysign.hpp>
#include <saki/math/details/pow_n.hpp>

namespace saki
{
/**
	* @brief コンパイル時floor
	* @details |x|>uint64_t_maxの場合は何も処理せず返す
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T floor(T x)
{
	if (saki::isnan(x) || saki::isinf(x) || x == 0)
		return x;
	if (saki::abs(x) > static_cast<T>(std::numeric_limits<int64_t>::max()))
	{
		return x;
	}
	T ans = x - saki::fmod(x, 1);
	if (x < 0 && ans != x)
		ans -= 1;
	return ans;
}
/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double floor(T x)
{
	return saki::floor(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_FLOOR_HPP