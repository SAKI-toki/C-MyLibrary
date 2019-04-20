/**
* @file copysign.hpp
* @brief �R���p�C���������R�s�[
* @author �ΎR �I
* @date 2018/12/09
*/
#ifndef SAKI_MATH_COPYSIGN_HPP
#define SAKI_MATH_COPYSIGN_HPP
#include <limits>
#include <saki/math/abs.hpp>
#include <saki/math/isnan.hpp>

namespace saki
{
/**
	* @brief �R���p�C���������R�s�[
	* @param x ��Βl
	* @param y ����
	*/
template <typename T, typename SignType>
constexpr T copysign(const T &x, const SignType &y)
{
	T abs_n = (saki::isnan(x)) ? std::numeric_limits<T>::quiet_NaN() : saki::abs(x);
	return (y >= 0) ? abs_n : -abs_n;
}
} // namespace saki
#endif //SAKI_MATH_COPYSIGN_HPP