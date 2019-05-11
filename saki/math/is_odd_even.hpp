/**
* @file is_odd_even.hpp
* @brief ����ǂ����A�������ǂ������肷��֐�
* @author �ΎR �I
* @date 2019/01/07
*/
#ifndef SAKI_MATH_IS_ODD_EVEN_HPP
#define SAKI_MATH_IS_ODD_EVEN_HPP
#include <limits>
#include <saki/math/fmod.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/isnan.hpp>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>

namespace saki
{
/**
	* @brief ����ǂ������肷��֐�
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
inline constexpr bool is_odd(T x)
{
	if (saki::isnan(x))
		return false;
	return saki::isinf(x) ||
		   saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(1);
}
/**
	* @brief �������ǂ������肷��֐�
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
inline constexpr bool is_even(T x)
{
	if (saki::isnan(x))
		return false;
	return saki::isinf(x) ||
		   saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(0);
}
} // namespace saki
#endif //SAKI_MATH_IS_ODD_EVEN_HPP