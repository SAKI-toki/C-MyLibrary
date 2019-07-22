/**
* @file size.hpp
* @brief コンパイル時fizzbuzzのテスト
* @author 石山 悠
* @date 2019/02/12
*/
#ifndef SAKI_COMPILE_TIME_TEST_SIZE_HPP
#define SAKI_COMPILE_TIME_TEST_SIZE_HPP
#include <cstdint>
#include <saki/size.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN

namespace compile_time_test
{

static_assert(saki::is_size_8_v<std::int8_t>);
static_assert(saki::is_size_16_v<std::int16_t>);
static_assert(saki::is_size_32_v<std::int32_t>);
static_assert(saki::is_size_64_v<std::int64_t>);

struct Size128
{
    std::int64_t n1, n2;
};

static_assert(saki::is_size_128_v<saki::compile_time_test::Size128>);

} // namespace compile_time_test

SAKI_NAMESPACE_END

#endif //SAKI_COMPILE_TIME_TEST_SIZE_HPP