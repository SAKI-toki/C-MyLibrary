/**
* @file abs.hpp
* @brief �R���p�C������Βl
* @author �ΎR �I
* @date 2019/01/19
*/
#ifndef SAKI_MATH_ABS_HPP
#define SAKI_MATH_ABS_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>

namespace saki
{
/**
	* @brief �R���p�C������Βl
	* @param x ��Βl�����߂�l
	* @details ��������
	*/
template <typename T,
		  saki::enable_if_nullptr_t<!std::is_unsigned_v<T>> = nullptr>
inline constexpr T abs(T x)
{
	if (saki::isnan(x))
		return x;
	return x < 0 ? -x : x;
}
/**
	* @brief �R���p�C������Βl
	* @param x ��Βl�����߂�l
	* @details �����Ȃ�
	*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_unsigned_v<T>> = nullptr>
inline constexpr T abs(T x)
{
	return x;
}
} // namespace saki
#endif //SAKI_MATH_ABS_HPP