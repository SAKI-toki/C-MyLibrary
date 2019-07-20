/**
* @file iterator_operator.hpp
* @brief iterator�N���X�̉��Z�q
* @author �ΎR �I
* @date 2019/01/09
*/
#ifndef SAKI_ITERATOR_DETAILS_ITERATOR_OPERATOR_HPP
#define SAKI_ITERATOR_DETAILS_ITERATOR_OPERATOR_HPP
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
namespace details
{
//�v���g�^�C�v�錾
template <typename T>
class iterator_base;
/**
* @brief ==���Z�q
*/
template <typename T>
constexpr bool operator==(const iterator_base<T> &itr1, const iterator_base<T> &itr2)
{
	return itr1.itr == itr2.itr;
}
/**
* @brief !=���Z�q
*/
template <typename T>
constexpr bool operator!=(const iterator_base<T> &itr1, const iterator_base<T> &itr2)
{
	return !(itr1 == itr2);
}
} // namespace details
SAKI_NAMESPACE_END
#endif //SAKI_ITERATOR_DETAILS_ITERATOR_OPERATOR_HPP