/**
* @file vector.hpp
* @brief コンパイル時vectorのテスト
* @author 石山 悠
* @date 2019/02/19
*/
#ifndef SAKI_COMPILE_TIME_TEST_VECTOR_HPP
#define SAKI_COMPILE_TIME_TEST_VECTOR_HPP
#include <saki/vector.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN

namespace compile_time_test
{

static_assert(saki::vector3<float>{1, 2, 3} + saki::vector3<float>{6, 4, 2} == saki::vector3<float>{7, 6, 5});

} // namespace compile_time_test

SAKI_NAMESPACE_END

#endif //SAKI_COMPILE_TIME_TEST_VECTOR_HPP