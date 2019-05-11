/**
* @file isinf.hpp
* @brief コンパイル時isinf
* @author 石山 悠
* @date 2019/01/08
*/
#ifndef SAKI_MATH_ISINF_HPP
#define SAKI_MATH_ISINF_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>

namespace saki
{
/**
	* @brief コンパイル時isinf
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr bool isinf(T x)
{
	return x == std::numeric_limits<T>::infinity() ||
		   x == -std::numeric_limits<T>::infinity();
}
/**
	* @brief コンパイル時isinf
	* @details floating_point以外はfalse
	*/
template <typename T,
		  saki::enable_if_nullptr_t<!std::is_floating_point_v<T>> = nullptr>
inline constexpr bool isinf(T)
{
	return false;
}
} // namespace saki
#endif //SAKI_MATH_ISINF_HPP