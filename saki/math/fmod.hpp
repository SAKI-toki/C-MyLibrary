/**
* @file fmod.hpp
* @brief コンパイル時float,double剰余
* @author 石山 悠
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
* @brief コンパイル時float,double剰余
* @param x 割られる数
* @param y 割る数
* @return 剰余
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

	//処理
	return static_cast<T>(x - static_cast<int64_t>(x / y) * y);
}

/**
* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr T fmod(T x, T y)
{
	return (x % y);
}

/**
* @brief 型が違う場合はそろえる
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