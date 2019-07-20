/**
* @file atan2.hpp
* @brief コンパイル時atan2
* @author 石山 悠
* @date 2019/01/06
*/
#ifndef SAKI_MATH_ATAN2_HPP
#define SAKI_MATH_ATAN2_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/signbit.hpp>
#include <saki/math/copysign.hpp>
#include <saki/math/atan.hpp>
#include <saki/math/pi.hpp>
#include <saki/math/isinf.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief コンパイル時atan2
* @param y,x 辺の長さ
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T atan2(T y, T x)
{
	if (saki::isnan(x))
	{
		if (saki::isnan(y))
		{
			return saki::signbit(x) && saki::signbit(y)
					   ? -std::numeric_limits<T>::quiet_NaN()
					   : std::numeric_limits<T>::quiet_NaN();
		}
		else
		{
			return x;
		}
	}
	if (saki::isnan(y))
		return static_cast<T>(y);
	if (y == 0)
	{
		return (x < 0) ? saki::PI<T> : 0;
	}
	if (x == 0)
	{
		return saki::copysign(saki::PI_HALF<T>, y);
	}
	if (saki::isinf(y))
	{
		return (x == std::numeric_limits<T>::infinity())
				   ? saki::copysign(saki::PI_QUARTER<T>, y)
				   : (x == -std::numeric_limits<T>::infinity())
						 ? saki::copysign(saki::PI_QUARTER<T> * 3, y)
						 : saki::copysign(saki::PI_HALF<T>, y);
	}
	if (x == std::numeric_limits<T>::infinity())
	{
		return saki::copysign<T>(0, y);
	}
	if (x == -std::numeric_limits<T>::infinity())
	{
		return saki::copysign(saki::PI<T>, y);
	}

	//0<x
	if (0 < x)
	{
		return saki::atan(y / x);
	}
	//x<0,0<y
	else if (0 < y)
	{
		return saki::atan(y / x) + saki::PI<T>;
	}
	//x<0,y<0
	return saki::atan(y / x) - saki::PI<T>;
}
/**
* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double atan2(T y, T x)
{
	return saki::atan2(static_cast<double>(y), static_cast<double>(x));
}
/**
* @brief 型をそろえる
*/
template <typename T1, typename T2,
		  saki::enable_if_nullptr_t<
			  std::is_arithmetic_v<std::common_type_t<T1, T2>>> = nullptr>
constexpr auto atan2(T1 y, T2 x)
{
	using type = std::common_type_t<T1, T2>;
	return saki::atan2(static_cast<type>(y), static_cast<type>(x));
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_ATAN2_HPP