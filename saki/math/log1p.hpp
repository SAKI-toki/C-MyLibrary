/**
* @file log1p.hpp
* @brief �R���p�C����log1p
* @author �ΎR �I
* @date 2019/01/13
*/
#ifndef SAKI_MATH_LOG1P_HPP
#define SAKI_MATH_LOG1P_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/log.hpp>

namespace saki
{
/**
	* @brief �R���p�C����log1p
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T log1p(T x)
{
	if (saki::isnan(x) || x == std::numeric_limits<T>::infinity() || x == 0)
		return x;
	if (x == -std::numeric_limits<T>::infinity())
		return -std::numeric_limits<T>::quiet_NaN();
	if (x < -1)
		return std::numeric_limits<T>::quiet_NaN();
	if (x == -1)
		return -std::numeric_limits<T>::infinity();

	return saki::log(x + 1);
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double log1p(T x)
{
	return saki::log1p(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_LOG1P_HPP