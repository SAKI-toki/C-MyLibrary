/**
* @file floor.hpp
* @brief �R���p�C����floor
* @author �ΎR �I
* @date 2019/01/15
*/
#ifndef SAKI_MATH_FLOOR_HPP
#define SAKI_MATH_FLOOR_HPP
#include <cstddef>
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/fmod.hpp>
#include <saki/math/log.hpp>
#include <saki/math/copysign.hpp>
#include <saki/math/details/pow_n.hpp>

namespace saki
{
/**
	* @brief �R���p�C����floor
	* @details |x|>uint64_t_max�̏ꍇ�͉������������Ԃ�
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
inline constexpr T floor(T x)
{
	if (saki::isnan(x) || saki::isinf(x) || x == 0)
		return x;
	if (saki::abs(x) > static_cast<T>(std::numeric_limits<int64_t>::max()))
	{
		return x;
	}
	T ans = x - saki::fmod(x, 1);
	if (x < 0 && ans != x)
		ans -= 1;
	return ans;
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
inline constexpr double floor(T x)
{
	return saki::floor(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_FLOOR_HPP