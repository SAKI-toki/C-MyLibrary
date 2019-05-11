/**
* @file addition.hpp
* @brief �����Z�̃I�y���[�^�[���Ăяo��constexpr�֐��I�u�W�F�N�g
* @author �ΎR �I
* @date 2018/12/08
*/
#ifndef SAKI_FUNCTION_OBJECT_ADDITION_HPP
#define SAKI_FUNCTION_OBJECT_ADDITION_HPP

namespace saki
{
/**
	* @brief �����Z��constexpr�Ή������֐��I�u�W�F�N�g
	*/
struct addition
{
	template <typename T1, typename T2>
	constexpr auto operator()(const T1 &t1, const T2 &t2) const
		-> decltype(t1 + t2)
	{
		return t1 + t2;
	}
};
} // namespace saki
#endif //SAKI_FUNCTION_OBJECT_ADDITION_HPP