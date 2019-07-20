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
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief •‰”‚©‚Ç‚¤‚©”»’è‚·‚é
* @param x ”»’è‚·‚é’l
* @return •‰”‚©‚Ç‚¤‚©
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_signed_v<T>> = nullptr>
constexpr bool signbit(T x)
{
	return x < static_cast<T>(0);
}

template <typename T,
		  saki::enable_if_nullptr_t<std::is_unsigned_v<T>> = nullptr>
constexpr bool signbit(T x)
{
	return false;
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_SIGNBIT_HPP