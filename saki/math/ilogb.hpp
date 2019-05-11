/**
* @file ilogb.hpp
* @brief �R���p�C����ilogb
* @author �ΎR �I
* @date 2019/01/15
*/
#ifndef SAKI_MATH_ILOGB_HPP
#define SAKI_MATH_ILOGB_HPP
#include <type_traits>
#include <cmath>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/logb.hpp>

namespace saki
{
/**
	* @brief �R���p�C����ilogb
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr int ilogb(T x)
{
	if (saki::isnan(x))
		return FP_ILOGBNAN;
	if (saki::isinf(x))
		return INT_MAX;
	if (x == 0)
		return FP_ILOGB0;
	return static_cast<int>(saki::logb(x));
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr int ilogb(T x)
{
	return saki::ilogb(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_ILOGB_HPP