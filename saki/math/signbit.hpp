/**
* @file signbit.hpp
* @brief 負数かどうか判定する関数
* @author 石山 悠
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
* @brief 負数かどうか判定する
* @param x 判定する値
* @return 負数かどうか
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