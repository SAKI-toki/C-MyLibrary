/**
* @file fibonacci.hpp
* @brief �t�B�{�i�b�`������o���֐�
* @author �ΎR �I
* @date 2018/12/28
*/
#ifndef SAKI_MATH_FIBONACCI_HPP
#define SAKI_MATH_FIBONACCI_HPP
#include <cstdint>
#include <cstddef>
#include <saki/math/exchange.hpp>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief �t�B�{�i�b�`���񋁂߂�֐�
* @param N ���߂����ԍ�
*/
template <typename T = double,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
constexpr T fibonacci(size_t N)
{
	T prev1 = 1;
	T prev2 = 1;
	for (size_t i = 3; i <= N; ++i)
	{
		prev2 = saki::exchange(prev1, prev1 + prev2);
	}
	return prev1;
}

/**
* @brief �t�B�{�i�b�`��������߂�֐�
*/
template <size_t N, typename T = double,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
constexpr T fibonacci()
{
	return saki::fibonacci<T>(N);
}

/**
* @brief �^���Ƃ̃t�B�{�i�b�`��
*/
template <typename T>
struct fibonacci_limits
{
};
template <>
struct fibonacci_limits<float>
{
	static constexpr std::size_t limit = 186;
};
template <>
struct fibonacci_limits<double>
{
	static constexpr std::size_t limit = 1476;
};
template <>
struct fibonacci_limits<long double>
{
	static constexpr std::size_t limit = 1476;
};
template <>
struct fibonacci_limits<std::int8_t>
{
	static constexpr std::size_t limit = 11;
};
template <>
struct fibonacci_limits<std::uint8_t>
{
	static constexpr std::size_t limit = 13;
};
template <>
struct fibonacci_limits<wchar_t>
{
	static constexpr std::size_t limit = 24;
};
template <>
struct fibonacci_limits<char16_t>
{
	static constexpr std::size_t limit = 24;
};
template <>
struct fibonacci_limits<char32_t>
{
	static constexpr std::size_t limit = 47;
};
template <>
struct fibonacci_limits<std::int16_t>
{
	static constexpr std::size_t limit = 23;
};
template <>
struct fibonacci_limits<std::uint16_t>
{
	static constexpr std::size_t limit = 24;
};
template <>
struct fibonacci_limits<std::int32_t>
{
	static constexpr std::size_t limit = 46;
};
template <>
struct fibonacci_limits<std::uint32_t>
{
	static constexpr std::size_t limit = 47;
};
template <>
struct fibonacci_limits<std::int64_t>
{
	static constexpr std::size_t limit = 92;
};
template <>
struct fibonacci_limits<std::uint64_t>
{
	static constexpr std::size_t limit = 93;
};
SAKI_NAMESPACE_END
#endif //SAKI_MATH_FIBONACCI_HPP