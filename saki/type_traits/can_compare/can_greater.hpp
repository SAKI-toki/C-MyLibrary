/**
* @file can_greater.hpp
* @brief 指定した型が(>)演算子を使用できるかどうか判定するメタ関数
* @author 石山 悠
* @date 2019/01/22
*/
#ifndef SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_GREATER_HPP
#define SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_GREATER_HPP
#include <type_traits>
#include <utility>
#include <saki/type_traits/remove_reference_const.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief より大きい比較できるかどうかを判定する構造体(>)
*/
template <typename T>
struct can_greater
{
private:
	template <typename U>
	static constexpr std::true_type greater_check(
		saki::remove_reference_const_t<decltype(std::declval<U>() > std::declval<U>())> *);
	template <typename U>
	static constexpr std::false_type greater_check(...);

public:
	static constexpr auto value = decltype(greater_check<T>(nullptr))::value;
};
/**
* @brief can_greaterを簡単に呼び出せる変数
*/
template <typename T>
inline constexpr auto can_greater_v = saki::can_greater<T>::value;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_GREATER_HPP