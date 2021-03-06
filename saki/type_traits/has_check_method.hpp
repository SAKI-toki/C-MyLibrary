/**
* @file has_check_method.hpp
* @brief 指定した型がcheck関数を持っているかどうか判定するメタ関数
* @author 石山 悠
* @date 2018/12/23
*/
#ifndef SAKI_TYPE_TRAITS_HAS_CHECK_METHOD_HPP
#define SAKI_TYPE_TRAITS_HAS_CHECK_METHOD_HPP
#include <type_traits>
#include <utility>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief check関数を持っているかどうかを判定する構造体
*/
template <typename T>
struct has_check
{
private:
	template <typename U>
	static constexpr std::true_type check_check(decltype(std::declval<U>().check(char())) *u);
	template <typename U>
	static constexpr std::false_type check_check(...);

public:
	static constexpr auto value = decltype(check_check<T>(nullptr))::value;
};
/**
* @brief has_checkを簡単に呼び出せる変数
*/
template <typename T>
inline constexpr auto has_check_v = saki::has_check<T>::value;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_HAS_CHECK_METHOD_HPP