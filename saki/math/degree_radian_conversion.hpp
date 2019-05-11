/**
* @file degree_radian_conversion.hpp
* @brief Degree����Radian�ARadian����Degree�ւ̕ϊ�
* @author �ΎR �I
* @date 2019/01/19
*/
#ifndef SAKI_MATH_DEGREE_RADIAN_CONVERSION_HPP
#define SAKI_MATH_DEGREE_RADIAN_CONVERSION_HPP
#include <type_traits>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/pi.hpp>
#include <saki/type_traits/enable_if_nullptr.hpp>

namespace saki
{
/**
	* @brief Degree����Radian�ɕϊ�
	* @param deg Radian�ɕϊ�����Degree
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T to_radian(T deg)
{
	if (saki::isnan(deg) || saki::isinf(deg) || deg == 0)
		return deg;
	return static_cast<T>(deg * 0.0174532925199389);
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double to_radian(T deg)
{
	return saki::to_radian(static_cast<double>(deg));
}
/**
	* @brief Radian����Degree�ɕϊ�
	* @param rad Degree�ɕϊ�����Radian
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T to_degree(T rad)
{
	if (saki::isnan(rad) || saki::isinf(rad) || rad == 0)
		return rad;
	return static_cast<T>(rad * 57.29577951309679);
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double to_degree(T rad)
{
	return saki::to_degree(static_cast<double>(rad));
}
} // namespace saki
#endif //SAKI_MATH_DEGREE_RADIAN_CONVERSION_HPP