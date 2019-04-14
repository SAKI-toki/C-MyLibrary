/**
* @file is_odd_even.hpp
* @brief Šï”‚ª‚Ç‚¤‚©A‹ô”‚©‚Ç‚¤‚©”»’è‚·‚éŠÖ”
* @author ÎR —I
* @date 2019/01/07
*/
#ifndef SAKI_MATH_IS_ODD_EVEN_2019_01_07
#define SAKI_MATH_IS_ODD_EVEN_2019_01_07
#include <limits>
#include <saki/math/fmod.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/isnan.hpp>

namespace saki
{
/**
	* @brief Šï”‚ª‚Ç‚¤‚©”»’è‚·‚éŠÖ”
	*/
template <typename T>
constexpr bool is_odd(T x)
{
	if (saki::isnan(x))
		return false;
	return saki::isinf(x) ||
		   saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(1);
}
/**
	* @brief ‹ô”‚ª‚Ç‚¤‚©”»’è‚·‚éŠÖ”
	*/
template <typename T>
constexpr bool is_even(T x)
{
	if (saki::isnan(x))
		return false;
	return saki::isinf(x) ||
		   saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(0);
}
} // namespace saki
#endif //SAKI_MATH_IS_ODD_EVEN_2019_01_07