/**
* @file acos.hpp
* @brief �R���p�C����acos
* @author �ΎR �I
* @date 2019/01/06
*/
#ifndef SAKI_MATH_ACOS_HPP
#define SAKI_MATH_ACOS_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/pi.hpp>
#include <saki/math/asin.hpp>

namespace saki
{
/**
	* @brief �R���p�C����acos
	* @param x �ӂ̔�
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T acos(T x)
{
	if (saki::isnan(x))
		return x;
	if (saki::abs(x) > 1)
		return -std::numeric_limits<T>::quiet_NaN();

	return saki::PI_HALF<T> - saki::asin(x);
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	* @param x int�^�̔�
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double acos(T x)
{
	return saki::acos(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_ACOS_HPP