/**
* @file fibonacci.hpp
* @brief フィボナッチ数列を出す関数
* @author 石山 悠
* @date 2018/12/28
*/
#ifndef SAKI_MATH_FIBONACCI_HPP
#define SAKI_MATH_FIBONACCI_HPP
#include <cstdint>
#include <cstddef>
#include <saki/math/exchange.hpp>

namespace saki
{

/**
	* @brief フィボナッチ数列求める関数
	* @param N 求めたい番号
	*/
template <typename T = double>
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
	* @brief フィボナッチ数列を求める関数
	*/
template <size_t N, typename T = double>
constexpr T fibonacci()
{
	return saki::fibonacci<T>(N);
}

/**
	* @brief 型ごとのフィボナッチ数
	*/
template <typename T>
struct fibonacci_limits
{
	static constexpr std::size_t limit = 0;
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
struct fibonacci_limits<char>
{
	static constexpr std::size_t limit = 11;
};
template <>
struct fibonacci_limits<unsigned char>
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
struct fibonacci_limits<short>
{
	static constexpr std::size_t limit = 23;
};
template <>
struct fibonacci_limits<unsigned short>
{
	static constexpr std::size_t limit = 24;
};
template <>
struct fibonacci_limits<int>
{
	static constexpr std::size_t limit = 46;
};
template <>
struct fibonacci_limits<unsigned int>
{
	static constexpr std::size_t limit = 47;
};
template <>
struct fibonacci_limits<long>
{
	static constexpr std::size_t limit = 46;
};
template <>
struct fibonacci_limits<unsigned long>
{
	static constexpr std::size_t limit = 47;
};
template <>
struct fibonacci_limits<long long>
{
	static constexpr std::size_t limit = 92;
};
template <>
struct fibonacci_limits<unsigned long long>
{
	static constexpr std::size_t limit = 93;
};
} // namespace saki
#endif //SAKI_MATH_FIBONACCI_HPP