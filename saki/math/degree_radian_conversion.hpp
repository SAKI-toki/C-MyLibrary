/**
* @file degree_radian_conversion.hpp
* @brief Degree‚©‚çRadianARadian‚©‚çDegree‚Ö‚Ì•ÏŠ·
* @author ÎR —I
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
	* @brief Degree‚©‚çRadian‚É•ÏŠ·
	* @param deg Radian‚É•ÏŠ·‚·‚éDegree
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T to_radian(T deg)
{
	if (saki::isnan(deg) || saki::isinf(deg) || deg == 0)
		return deg;
	return static_cast<T>(deg * 0.0174532925199389);
}
/**
	* @brief ˆø”‚ªintŒ^‚Ìê‡‚ÉA–ß‚è’l‚ğdoubleŒ^‚É‚·‚é‚½‚ß‚Ì‚à‚Ì
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double to_radian(T deg)
{
	return saki::to_radian(static_cast<double>(deg));
}
/**
	* @brief Radian‚©‚çDegree‚É•ÏŠ·
	* @param rad Degree‚É•ÏŠ·‚·‚éRadian
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T to_degree(T rad)
{
	if (saki::isnan(rad) || saki::isinf(rad) || rad == 0)
		return rad;
	return static_cast<T>(rad * 57.29577951309679);
}
/**
	* @brief ˆø”‚ªintŒ^‚Ìê‡‚ÉA–ß‚è’l‚ğdoubleŒ^‚É‚·‚é‚½‚ß‚Ì‚à‚Ì
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double to_degree(T rad)
{
	return saki::to_degree(static_cast<double>(rad));
}
} // namespace saki
#endif //SAKI_MATH_DEGREE_RADIAN_CONVERSION_HPP