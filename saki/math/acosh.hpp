/**
* @file acosh.hpp
* @brief �R���p�C����acosh
* @author �ΎR �I
* @date 2019/01/08
*/
#ifndef SAKI_MATH_ACOSH_HPP
#define SAKI_MATH_ACOSH_HPP
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/log.hpp>
#include <saki/math/sqrt.hpp>

namespace saki
{
/**
	* @brief �R���p�C����sinh
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T acosh(T x)
{
	if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())
		return x;
	if (x < 1)
		return std::numeric_limits<T>::quiet_NaN();
	if (x == 1)
		return 0;

	return saki::log(x + saki::sqrt(x * x - 1));
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double acosh(T x)
{
	return saki::acosh(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_ACOSH_HPP