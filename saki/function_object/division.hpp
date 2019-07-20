/**
* @file division.hpp
* @brief ����Z�̃I�y���[�^�[���Ăяo��constexpr�֐��I�u�W�F�N�g
* @author �ΎR �I
* @date 2018/12/08
*/
#ifndef SAKI_FUNCTION_OBJECT_DIVISION_HPP
#define SAKI_FUNCTION_OBJECT_DIVISION_HPP
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief ����Z��constexpr�Ή������֐��I�u�W�F�N�g
*/
struct division
{
	template <typename T1, typename T2>
	constexpr auto operator()(const T1 &t1, const T2 &t2) const
		-> decltype(t1 / t2)
	{
		return t1 / t2;
	}
};
SAKI_NAMESPACE_END
#endif //SAKI_FUNCTION_OBJECT_DIVISION_HPP