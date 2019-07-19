/**
* @file ldexp.hpp
* @brief �R���p�C����ldexp
* @author �ΎR �I
* @date 2019/01/15
*/
#ifndef SAKI_MATH_LDEXP_HPP
#define SAKI_MATH_LDEXP_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/details/pow_n.hpp>

namespace saki
{
/**
	* @brief �R���p�C����ldexp
	*/
template <typename T, typename IntegerT,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T> && std::is_integral_v<IntegerT>> = nullptr>
constexpr T ldexp(T x, IntegerT exp)
{
	if (saki::isnan(x) || saki::isinf(x) || x == 0 || exp == 0)
		return x;

	return x * saki::details::pow_n(static_cast<T>(2), exp);
}

/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T, typename IntegerT,
		  saki::enable_if_nullptr_t<std::is_integral_v<T> && std::is_integral_v<IntegerT>> = nullptr>
constexpr double ldexp(T x, IntegerT exp)
{
	return saki::ldexp(static_cast<double>(x), exp);
}
} // namespace saki
#endif //SAKI_MATH_LDEXP_HPP