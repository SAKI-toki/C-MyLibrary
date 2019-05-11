/**
* @file exp2.h
* @brief �R���p�C����exp2
* @author �ΎR �I
* @date 2019/01/10
*/
#ifndef SAKI_MATH_EXP2_HPP
#define SAKI_MATH_EXP2_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/exp.hpp>
#include <saki/math/log.hpp>

namespace saki
{
/**
	* @brief �R���p�C����exp2
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T exp2(T x)
{
	if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())
		return x;
	if (x == -std::numeric_limits<T>::infinity())
		return 0;
	if (x == 0)
		return static_cast<T>(1);

	return saki::exp(x * saki::log(2));
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double exp2(T x)
{
	return saki::exp2(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_EXP2_HPP