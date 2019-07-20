/**
* @file remove_reference_const.hpp
* @brief �Q�Ƃ�const�C�����폜�����^��Ԃ�
* @author �ΎR �I
* @date 2019/01/12
*/
#ifndef SAKI_TYPE_TRAITS_REMOVE_REFERENCE_CONST_HPP
#define SAKI_TYPE_TRAITS_REMOVE_REFERENCE_CONST_HPP
#include <type_traits>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief �Q�Ƃ�const�C�����폜
*/
template <typename T>
struct remove_reference_const
{
	using type = typename std::remove_const_t<std::remove_reference_t<T>>;
};
/**
* @brief remove_reference_const���ȒP�ɌĂяo����悤�ɂ��� 
*/
template <typename T>
using remove_reference_const_t = typename saki::remove_reference_const<T>::type;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_REMOVE_REFERENCE_CONST_HPP