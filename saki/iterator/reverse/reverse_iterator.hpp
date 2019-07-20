/**
* @file reverse_iterator.hpp
* @brief �t�����ɐi�ރC�e���[�^�[
* @author �ΎR �I
* @date 2019/01/13
*/
#ifndef SAKI_ITERATOR_REVERSE_REVERSE_ITERATOR_HPP
#define SAKI_ITERATOR_REVERSE_REVERSE_ITERATOR_HPP
#include <saki/iterator/reverse/details/reverse_iterator_base.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief �m�[�}���ȃ��o�[�X�C�e���[�^�[
*/
template <typename T>
class reverse_iterator : public saki::details::reverse_iterator_base<T>
{
public:
	explicit constexpr reverse_iterator(T pointer) : saki::details::reverse_iterator_base<T>(pointer) {}
};
/**
* @brief const�ȃ��o�[�X�C�e���[�^�[
*/
template <typename T>
class const_reverse_iterator : public saki::details::reverse_iterator_base<const T>
{
public:
	explicit constexpr const_reverse_iterator(const T pointer) : saki::details::reverse_iterator_base<const T>(pointer) {}
};
SAKI_NAMESPACE_END
#endif //SAKI_ITERATOR_REVERSE_REVERSE_ITERATOR_HPP