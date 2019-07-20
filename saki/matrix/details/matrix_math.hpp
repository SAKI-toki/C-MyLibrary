/**
* @file matrix_math.hpp
* @brief s—ñŠÖŒW‚ÌŒvZŠÖ”
* @author ÎR —I
* @date 2018/12/29
*/
#ifndef SAKI_MATRIX_DETAILS_MATRIX_MATH_HPP
#define SAKI_MATRIX_DETAILS_MATRIX_MATH_HPP
#include <type_traits>
#include <saki/vector/vector_2d.hpp>
#include <saki/vector/vector_3d.hpp>
#include <saki/vector/vector_4d.hpp>
#include <saki/math/sin.hpp>
#include <saki/math/cos.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
template <typename T>
class matrix;

/**
* @brief •½sˆÚ“®
* @param vec ˆÚ“®—Ê(vector2)
*/
template <typename T>
constexpr matrix<T> translate(const saki::vector2<T> &vec)
{
	return matrix<T>{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		vec.x, vec.y, 0, 1};
}

/**
* @brief •½sˆÚ“®
* @param vec ˆÚ“®—Ê(vector3)
*/
template <typename T>
constexpr matrix<T> translate(const saki::vector3<T> &vec)
{
	return matrix<T>{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		vec.x, vec.y, vec.z, 1};
}

/**
* @brief •½sˆÚ“®
* @param vec ˆÚ“®—Ê(vector4)
*/
template <typename T>
constexpr matrix<T> translate(const saki::vector4<T> &vec)
{
	return matrix<T>{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		vec.x, vec.y, vec.z, 1};
}

/**
* @brief Šgk
* @param vec Šgk—Ê(vector2)
*/
template <typename T>
constexpr matrix<T> scaling(const saki::vector2<T> &vec)
{
	return matrix<T>{
		vec.x, 0, 0, 0,
		0, vec.y, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1};
}

/**
* @brief Šgk
* @param vec Šgk—Ê(vector3)
*/
template <typename T>
constexpr matrix<T> scaling(const saki::vector3<T> &vec)
{
	return matrix<T>{
		vec.x, 0, 0, 0,
		0, vec.y, 0, 0,
		0, 0, vec.z, 0,
		0, 0, 0, 1};
}

/**
* @brief Šgk
* @param vec Šgk—Ê(vector4)
*/
template <typename T>
constexpr matrix<T> scaling(const saki::vector4<T> &vec)
{
	return matrix<T>{
		vec.x, 0, 0, 0,
		0, vec.y, 0, 0,
		0, 0, vec.z, 0,
		0, 0, 0, 1};
}

/**
* @brief X²‚Ì‰ñ“]
* @param angle ‰ñ“]—Ê
*/
template <typename T>
constexpr matrix<T> rotate_x(T angle)
{
	auto c = saki::cos(angle);
	auto s = saki::sin(angle);
	return matrix<T>{
		1, 0, 0, 0,
		0, c, s, 0,
		0, -s, c, 0,
		0, 0, 0, 1};
}

/**
* @brief Y²‚Ì‰ñ“]
* @param angle ‰ñ“]—Ê
*/
template <typename T>
constexpr matrix<T> rotate_y(T angle)
{
	auto c = saki::cos(angle);
	auto s = saki::sin(angle);
	return matrix<T>{
		c, 0, -s, 0,
		0, 1, 0, 0,
		s, 0, c, 0,
		0, 0, 0, 1};
}

/**
* @brief Z²‚Ì‰ñ“]
* @param angle ‰ñ“]—Ê
*/
template <typename T>
constexpr matrix<T> rotate_z(T angle)
{
	auto c = saki::cos(angle);
	auto s = saki::sin(angle);
	return matrix<T>{
		c, s, 0, 0,
		-s, c, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1};
}

template <typename T1, typename T2, typename T3>
constexpr auto rotate_roll_pitch_yaw(T1 roll, T2 pitch, T3 yaw)
{
	using type = std::common_type_t<T1, T2, T3>;
	return saki::rotate_z<type>(yaw) *
		   saki::rotate_x<type>(roll) *
		   saki::rotate_y<type>(pitch);
}
SAKI_NAMESPACE_END
#endif //SAKI_MATRIX_DETAILS_MATRIX_MATH_HPP