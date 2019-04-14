/**
* @file tanh.hpp
* @brief �R���p�C����tanh
* @author �ΎR �I
* @date 2019/01/08
*/
#ifndef SAKI_MATH_TANH_2019_01_08
#define SAKI_MATH_TANH_2019_01_08
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/copysign.hpp>
#include <saki/math/sinh.hpp>
#include <saki/math/cosh.hpp>

namespace saki
{
/**
	* @brief �R���p�C����tanh
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T tanh(T x)
{
	if (saki::isnan(x) || x == 0)
		return x;
	if (saki::isinf(x))
		return static_cast<T>(saki::copysign(1, x));

	return saki::sinh(x) / saki::cosh(x);
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double tanh(T x)
{
	return saki::tanh(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_TANH_2019_01_08