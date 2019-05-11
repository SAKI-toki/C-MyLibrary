/**
* @file log2.hpp
* @brief �R���p�C����log2
* @author �ΎR �I
* @date 2019/01/13
*/
#ifndef SAKI_MATH_LOG2_HPP
#define SAKI_MATH_LOG2_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/log.hpp>

namespace saki
{
/**
	* @brief �R���p�C����log2
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T log2(T x)
{
	if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())
		return x;
	if (x == -std::numeric_limits<T>::infinity() || x < 0)
		return -std::numeric_limits<T>::quiet_NaN();
	if (x == 0)
		return -std::numeric_limits<T>::infinity();
	if (x == 1)
		return 0;

	return saki::log(x) / saki::log(2);
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double log2(T x)
{
	return saki::log2(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_LOG2_HPP