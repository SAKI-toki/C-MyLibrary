/**
* @file enable_if_nullptr.hpp
* @brief nullptr_t��Ԃ�enabled_if
* @author �ΎR �I
* @date 2019/01/19
*/
#ifndef SAKI_TYPE_TRAITS_ENABLE_IF_NULLPTR_HPP
#define SAKI_TYPE_TRAITS_ENABLE_IF_NULLPTR_HPP
#include <cstddef>

namespace saki
{
/**
	* @brief enalbe_if��false
	*/
template <bool>
struct enable_if_nullptr
{
};
/**
	* @brief enable_if��true
	*/
template <>
struct enable_if_nullptr<true>
{
	using type = std::nullptr_t;
};
/**
	* @brief enable_if_nullptr���ȒP�ɌĂяo����ϐ�
	*/
template <bool Con>
using enable_if_nullptr_t = typename saki::enable_if_nullptr<Con>::type;
} // namespace saki
#endif //SAKI_TYPE_TRAITS_ENABLE_IF_NULLPTR_HPP