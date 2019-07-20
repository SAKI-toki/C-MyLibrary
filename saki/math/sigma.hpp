/**
* @file sigma.hpp
* @brief ���w�̃V�O�}(��)
* @author �ΎR �I
* @date 2019/01/18
*/
#ifndef SAKI_MATH_SIGMA_HPP
#define SAKI_MATH_SIGMA_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/function_object/return_param.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief ���w�̃V�O�}���ȒP�Ɏ���
* @param start �����l
* @param end �J��Ԃ��̏I���(���̒l���g�p������I��)
* @param f �֐�
* @return �v�Z����
* @details start>end�̏ꍇ�A0���Ԃ�A�Z�p�^�̂ݑΉ�
*/
template <typename T = int, typename Func = saki::return_param,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T> &&
									std::is_invocable_v<Func, T>> = nullptr>
constexpr T sigma(T start, const T &end, Func &&f = Func())
{
	T sum = 0;
	for (; start <= end; ++start)
	{
		sum += static_cast<T>(f(start));
	}
	return sum;
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_SIGMA_HPP