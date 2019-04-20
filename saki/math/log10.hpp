/**
* @file log10.hpp
* @brief �R���p�C����log10
* @author �ΎR �I
* @date 2019/01/12
*/
#ifndef SAKI_MATH_LOG10_HPP
#define SAKI_MATH_LOG10_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/log.hpp>

namespace saki
{
/**
	* @brief �R���p�C����log10
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T log10(T x)
{
	if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())
		return x;
	if (x == -std::numeric_limits<T>::infinity() || x < 0)
		return -std::numeric_limits<T>::quiet_NaN();
	if (x == 0)
		return -std::numeric_limits<T>::infinity();
	if (x == 1)
		return 0;

	return saki::log(x) / saki::log(10);
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double log10(T x)
{
	return saki::log10(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_LOG10_HPP