/**
* @file logb.hpp
* @brief �R���p�C����logb
* @author �ΎR �I
* @date 2019/01/15
*/
#ifndef SAKI_MATH_LOGB_HPP
#define SAKI_MATH_LOGB_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/log2.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/floor.hpp>

namespace saki
{
/**
	* @brief �R���p�C����logb
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T logb(T x)
{
	return saki::floor(saki::log2(saki::abs(x)));
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double logb(T x)
{
	return saki::logb(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_LOGB_HPP