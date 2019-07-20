/**
* @file can_begin_method.hpp
* @brief 指定した型がstd::beginできるかどうか判定するメタ関数
* @author 石山 悠
* @date 2018/12/13
*/
#ifndef SAKI_TYPE_TRAITS_BEGIN_METHOD_HPP
#define SAKI_TYPE_TRAITS_BEGIN_METHOD_HPP
#include <type_traits>
#include <utility>
#include <iterator>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief beginできるかどうかを判定する構造体
*/
template <typename T>
struct can_begin
{
private:
	template <typename U>
	static constexpr std::true_type begin_check(decltype(std::begin(std::declval<U>())) *u);
	template <typename U>
	static constexpr std::false_type begin_check(...);

public:
	static constexpr auto value = decltype(begin_check<T>(nullptr))::value;
};
/**
* @brief can_beginを簡単に呼び出せる変数
*/
template <typename T>
inline constexpr auto can_begin_v = saki::can_begin<T>::value;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_CAN_BEGIN_METHOD_HPP