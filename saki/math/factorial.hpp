/**
* @file factorial.hpp
* @brief �K��
* @author �ΎR �I
* @date 2019/01/06
*/
#ifndef SAKI_MATH_FACTORIAL_HPP
#define SAKI_MATH_FACTORIAL_HPP
#include <cstdint>
#include <cstddef>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief �K��(�����o�[�W����)
* @param N 1����N�܂ł̊K������߂�
*/
template <typename T = double,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
constexpr T factorial(size_t N)
{
	T sum = 1;
	for (size_t i = 2; i <= N; ++i)
	{
		sum *= static_cast<T>(i);
	}
	return sum;
}
/**
* @brief �K��(�������o�[�W����)
*/
template <size_t N, typename T = double,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
constexpr T factorial()
{
	return factorial<T>(N);
}

/**
* @brief �^���Ƃ̍ő�K�搔
*/
template <typename T>
struct factorial_limits
{
};
template <>
struct factorial_limits<float>
{
	static constexpr std::size_t limit = 34;
};
template <>
struct factorial_limits<double>
{
	static constexpr std::size_t limit = 170;
};
template <>
struct factorial_limits<long double>
{
	static constexpr std::size_t limit = 170;
};
template <>
struct factorial_limits<std::int8_t>
{
	static constexpr std::size_t limit = 5;
};
template <>
struct factorial_limits<std::uint8_t>
{
	static constexpr std::size_t limit = 6;
};
template <>
struct factorial_limits<wchar_t>
{
	static constexpr std::size_t limit = 8;
};
template <>
struct factorial_limits<char16_t>
{
	static constexpr std::size_t limit = 8;
};
template <>
struct factorial_limits<char32_t>
{
	static constexpr std::size_t limit = 13;
};
template <>
struct factorial_limits<std::int16_t>
{
	static constexpr std::size_t limit = 7;
};
template <>
struct factorial_limits<std::uint16_t>
{
	static constexpr std::size_t limit = 8;
};
template <>
struct factorial_limits<std::int32_t>
{
	static constexpr std::size_t limit = 13;
};
template <>
struct factorial_limits<std::uint32_t>
{
	static constexpr std::size_t limit = 13;
};
template <>
struct factorial_limits<std::int64_t>
{
	static constexpr std::size_t limit = 20;
};
template <>
struct factorial_limits<std::uint64_t>
{
	static constexpr std::size_t limit = 22;
};
SAKI_NAMESPACE_END
#endif //SAKI_MATH_FACTORIAL_HPP