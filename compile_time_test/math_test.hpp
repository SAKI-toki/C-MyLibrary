/**
* @file math_test.hpp
* @brief コンパイル時mathのテスト
* @author 石山 悠
* @date 2019/02/19
*/
#ifndef SAKI_TEST_MATH_TEST_HPP
#define SAKI_TEST_MATH_TEST_HPP
#include <limits>
#include <saki/math.hpp>

static_assert(saki::abs(-10) == 10);
static_assert(saki::sqrt(4) == 2);
static_assert(saki::copysign(5, -10) == -5);
static_assert(saki::digit_count(123456789) == 9);
static_assert(saki::fibonacci(10) == 55);
static_assert(saki::isinf(std::numeric_limits<double>::infinity()));
static_assert(saki::isnan(std::numeric_limits<float>::quiet_NaN()));
static_assert(saki::isnan(std::numeric_limits<double>::quiet_NaN()));
static_assert(saki::is_odd(1001));
static_assert(saki::is_even(1000));
static_assert(saki::pow(10, 4) == 10000);
static_assert(saki::factorial(4) == 24);
static_assert(saki::sigma(0, 5, [](int x) { return x * x; }) == 55);
static_assert(saki::signbit(-10));

#endif //SAKI_TEST_MATH_TEST_HPP