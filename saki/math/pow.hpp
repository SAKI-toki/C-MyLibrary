/**
* @file pow.hpp
* @brief —İæ‚ğ‹‚ß‚éŠÖ”
* @author ÎR —I
* @date 2019/01/07
*/
#ifndef SAKI_MATH_POW_HPP
#define SAKI_MATH_POW_HPP
#include <cstddef>
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/signbit.hpp>
#include <saki/math/log.hpp>
#include <saki/math/exp.hpp>
#include <saki/math/fmod.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/is_odd_even.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/details/pow_n.hpp>

namespace saki
{
/**
	* @brief ƒRƒ“ƒpƒCƒ‹—İæ
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T pow(T x, T y)
{
	if (x == 1 || y == 0)
		return static_cast<T>(1);
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
	if (x == 0)
	{
		if (y < 0)
		{
			if (saki::is_odd(y))
			{
				return saki::copysign(std::numeric_limits<T>::infinity(), x);
			}
			else
			{
				return std::numeric_limits<T>::infinity();
			}
		}
		else
		{
			if (saki::is_odd(y))
			{
				return x;
			}
			else
			{
				return static_cast<T>(0);
			}
		}
	}
	if (x == -1 &&
		(saki::isinf(y)))
		return static_cast<T>(1);
	if (y == -std::numeric_limits<T>::infinity())
	{
		if (saki::abs(x) < 1)
			return std::numeric_limits<T>::infinity();
		else
			return static_cast<T>(0);
	}
	if (y == std::numeric_limits<T>::infinity())
	{
		if (saki::abs(x) > 1)
			return std::numeric_limits<T>::infinity();
		else
			return static_cast<T>(0);
	}
	if (x == -std::numeric_limits<T>::infinity())
	{
		if (saki::is_odd(y))
		{
			return (y < 0) ? static_cast<T>(-0) : -std::numeric_limits<T>::infinity();
		}
		else
		{
			return (y < 0) ? static_cast<T>(0) : std::numeric_limits<T>::infinity();
		}
	}
	if (x == std::numeric_limits<T>::infinity())
	{
		return (y < 0) ? static_cast<T>(0) : std::numeric_limits<T>::infinity();
	}
	if (x < 0 && saki::fmod(y, 1) != 0)
		return -std::numeric_limits<T>::quiet_NaN();

	//¬”“_‚È‚µ‚Ìê‡
	if (saki::fmod(y, 1) == 0)
	{
		return saki::details::pow_n(x, static_cast<int>(y));
	}

	//ˆ—
	if (x < 0)
	{
		if (saki::is_odd(y))
		{
			return -saki::exp(y * saki::log(-x));
		}
		else
		{
			return saki::exp(y * saki::log(-x));
		}
	}
	else
	{
		return saki::exp(y * saki::log(x));
	}
}
/**
	* @brief ˆø”‚ªintŒ^‚Ìê‡‚ÉA–ß‚è’l‚ğdoubleŒ^‚É‚·‚é‚½‚ß‚Ì‚à‚Ì
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double pow(T x, T y)
{
	return saki::pow(static_cast<double>(x), static_cast<double>(y));
}
/**
	* @brief Œ^‚ğ‚»‚ë‚¦‚é
	*/
template <typename T1, typename T2,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<std::common_type_t<T1, T2>>> = nullptr>
constexpr auto pow(T1 x, T2 y)
{
	using type = std::common_type_t<T1, T2>;
	return saki::pow(static_cast<type>(x), static_cast<type>(y));
}
} // namespace saki
#endif //SAKI_MATH_POW_HPP