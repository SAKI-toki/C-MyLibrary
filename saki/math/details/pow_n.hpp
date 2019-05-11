/**
* @file pow_n.hpp
* @brief ‘æ“ñˆø”‚ªintŒ^‚Ìpow
* @author ÎR —I
* @date 2019/01/19
*/
#ifndef SAKI_MATH_DETAILS_POW_N_HPP
#define SAKI_MATH_DETAILS_POW_N_HPP
#include <cstddef>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>

namespace saki
{
namespace details
{
/**
		* @brief pow‚©‚ç”h¶
		*/
template <typename T1, typename T2,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T1> && std::is_integral_v<T2>> = nullptr>
inline constexpr T1 pow_n(T1 x, T2 y)
{
	T1 sum = static_cast<T1>(1);
	if (y > 0)
	{
		while (y)
		{
			sum *= (y & 1) ? x : 1;
			x *= x;
			y >>= 1;
		}
	}
	if constexpr (std::is_signed_v<T2>)
	{
		if (y < 0)
		{
			y = -y;
			while (y)
			{
				sum /= (y & 1) ? x : 1;
				x *= x;
				y >>= 1;
			}
		}
	}
	return sum;
}
} // namespace details
} // namespace saki
#endif //SAKI_MATH_DETAILS_POW_N_HPP