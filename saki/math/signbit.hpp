/**
* @file signbit.hpp
* @brief •‰”‚©‚Ç‚¤‚©”»’è‚·‚éŠÖ”
* @author ÎR —I
* @date 2019/01/03
*/
#ifndef SAKI_MATH_SIGNBIT_HPP
#define SAKI_MATH_SIGNBIT_HPP
#include <saki/math/copysign.hpp>
#include <saki/math/isnan.hpp>

namespace saki
{
/**
	* @brief •‰”‚©‚Ç‚¤‚©”»’è‚·‚é
	* @param x ”»’è‚·‚é’l
	* @return •‰”‚©‚Ç‚¤‚©
	*/
template <typename T>
constexpr bool signbit(T x)
{
	return x < static_cast<T>(0);
}
} // namespace saki
#endif //SAKI_MATH_SIGNBIT_HPP