/**
* @file fmod.hpp
* @brief �R���p�C����float,double��]
* @author �ΎR �I
* @date 2019/01/02
*/
#ifndef SAKI_MATH_FMOD_HPP
#define SAKI_MATH_FMOD_HPP
#include <cstddef>
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/signbit.hpp>
#include <saki/math/isinf.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief �R���p�C����float,double��]
* @param x �����鐔
* @param y ���鐔
* @return ��]
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T fmod(T x, T y)
{
	if (saki::isnan(x))
	{
		if (saki::isnan(y))
		{
			return saki::signbit(x) && saki::signbit(y) ? -std::numeric_limits<T>::quiet_NaN() : std::numeric_limits<T>::quiet_NaN();
		}
		else
		{
			return x;
		}
	}
	if (saki::isnan(y))
		return static_cast<T>(y);
	if (saki::isinf(x) || y == 0)
	{
		return -std::numeric_limits<T>::quiet_NaN();
	}
	if (x == 0)
		return static_cast<T>(x);
	if (saki::isinf(y))
	{
		return static_cast<T>(x);
	}

	//����
	return static_cast<T>(x - static_cast<int64_t>(x / y) * y);
}

/**
* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr T fmod(T x, T y)
{
	return (x % y);
}

/**
* @brief �^���Ⴄ�ꍇ�͂��낦��
*/
template <typename T1, typename T2,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<std::common_type_t<T1, T2>>> = nullptr>
constexpr auto fmod(T1 x, T2 y)
{
	using type = std::common_type_t<T1, T2>;
	return saki::fmod(static_cast<type>(x), static_cast<type>(y));
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_FMOD_HPP