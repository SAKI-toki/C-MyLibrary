/**
* @file isinf.hpp
* @brief �R���p�C����isinf
* @author �ΎR �I
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
	* @brief �R���p�C����isinf
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr bool isinf(T x)
{
	return x == std::numeric_limits<T>::infinity() ||
		   x == -std::numeric_limits<T>::infinity();
}
/**
	* @brief �R���p�C����isinf
	* @details floating_point�ȊO��false
	*/
template <typename T,
		  saki::enable_if_nullptr_t<!std::is_floating_point_v<T>> = nullptr>
inline constexpr bool isinf(T)
{
	return false;
}
} // namespace saki
#endif //SAKI_MATH_ISINF_HPP