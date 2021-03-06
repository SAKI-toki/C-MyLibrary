/**
* @file enable_if_nullptr.hpp
* @brief nullptr_tを返すenabled_if
* @author 石山 悠
* @date 2019/01/19
*/
#ifndef SAKI_TYPE_TRAITS_ENABLE_IF_NULLPTR_HPP
#define SAKI_TYPE_TRAITS_ENABLE_IF_NULLPTR_HPP
#include <cstddef>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief enalbe_ifのfalse
*/
template <bool>
struct enable_if_nullptr
{
};
/**
* @brief enable_ifのtrue
*/
template <>
struct enable_if_nullptr<true>
{
	using type = std::nullptr_t;
};
/**
* @brief enable_if_nullptrを簡単に呼び出せる変数
*/
template <bool Con>
using enable_if_nullptr_t = typename enable_if_nullptr<Con>::type;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_ENABLE_IF_NULLPTR_HPP