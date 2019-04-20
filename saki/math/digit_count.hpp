/**
* @file digit_count.hpp
* @brief �������̌����𐔂���
* @author �ΎR �I
* @date 2019/01/15
*/
#ifndef SAKI_MATH_DIGIT_COUNT_HPP
#define SAKI_MATH_DIGIT_COUNT_HPP
#include <cstddef>
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>

namespace saki
{
/**
	* @brief �������̌����𐔂���֐�
	* @details log10�ł��\�����A�����������Ȃ炱������g�����ق����ǂ�
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
constexpr size_t digit_count(T x)
{
	if constexpr (std::is_floating_point_v<T>)
	{
		if (saki::isnan(x) || saki::isinf(x))
			return 0;
	}
	if (std::is_signed_v<T>)
	{
		x = saki::abs(x);
	}
	if (x < 1)
	{
		return 1;
	}
	size_t count = 0;
	while (x >= 1)
	{
		++count;
		x /= 10;
	}
	return count;
}
} // namespace saki
#endif //SAKI_MATH_DIGIT_COUNT_HPP