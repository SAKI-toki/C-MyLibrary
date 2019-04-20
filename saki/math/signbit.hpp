/**
* @file signbit.hpp
* @brief �������ǂ������肷��֐�
* @author �ΎR �I
* @date 2019/01/03
*/
#ifndef SAKI_MATH_SIGNBIT_HPP
#define SAKI_MATH_SIGNBIT_HPP
#include <saki/math/copysign.hpp>
#include <saki/math/isnan.hpp>

namespace saki
{
/**
	* @brief �������ǂ������肷��
	* @param x ���肷��l
	* @return �������ǂ���
	*/
template <typename T>
constexpr bool signbit(T x)
{
	return x < static_cast<T>(0);
}
} // namespace saki
#endif //SAKI_MATH_SIGNBIT_HPP