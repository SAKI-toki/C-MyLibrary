/**
* @file return_param.hpp
* @brief ���̂܂܈����̒l��Ԃ��֐��I�u�W�F�N�g
* @author �ΎR �I
* @date 2018/12/10
*/
#ifndef SAKI_FUNCTION_OBJECT_RETURN_PARAM_HPP
#define SAKI_FUNCTION_OBJECT_RETURN_PARAM_HPP

namespace saki
{
/**
	* @brief ���̂܂܈�����Ԃ��֐��I�u�W�F�N�g
	*/
struct return_param
{
	template <typename T>
	constexpr T operator()(const T &t) const
	{
		return t;
	}
};
} // namespace saki
#endif //SAKI_FUNCTION_OBJECT_RETURN_PARAM_HPP