/**
* @file compile_time_fizzbuzz.hpp
* @brief コンパイル時fizzbuzzのテスト
* @author 石山 悠
* @date 2019/02/12
*/
#ifndef SAKI_TEST_FIZZBUZZ_HPP
#define SAKI_TEST_FIZZBUZZ_HPP
#include <cstddef>
#include <limits>
#include <saki/string.hpp>
#include <saki/math/digit_count.hpp>
/**
* @brief コンパイル時にfizzbuzzを求める関数
*/
template <std::size_t N, typename StringType = saki::string<saki::digit_count(std::numeric_limits<std::size_t>::max()) + 1>>
constexpr StringType fizzbuzz()
{
	if constexpr (N % 15 == 0)
	{
		return StringType("FizzBuzz");
	}
	if constexpr (N % 3 == 0)
	{
		return StringType("Fizz");
	}
	if constexpr (N % 5 == 0)
	{
		return StringType("Buzz");
	}
	return StringType(saki::int_to_string<char>(N));
}

static_assert(fizzbuzz<1>() == "1");
static_assert(fizzbuzz<2>() == "2");
static_assert(fizzbuzz<3>() == "Fizz");
static_assert(fizzbuzz<4>() == "4");
static_assert(fizzbuzz<5>() == "Buzz");
static_assert(fizzbuzz<6>() == "Fizz");
static_assert(fizzbuzz<7>() == "7");
static_assert(fizzbuzz<8>() == "8");
static_assert(fizzbuzz<9>() == "Fizz");
static_assert(fizzbuzz<10>() == "Buzz");
static_assert(fizzbuzz<11>() == "11");
static_assert(fizzbuzz<12>() == "Fizz");
static_assert(fizzbuzz<13>() == "13");
static_assert(fizzbuzz<14>() == "14");
static_assert(fizzbuzz<15>() == "FizzBuzz");
#endif //SAKI_TEST_FIZZBUZZ_HPP