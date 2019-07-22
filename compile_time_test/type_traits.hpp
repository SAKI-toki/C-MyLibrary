/**
* @file type_traits.hpp
* @brief �R���p�C����type_traits�̃e�X�g
* @author �ΎR �I
* @date 2019/02/19
*/
#ifndef SAKI_COMPILE_TIME_TEST_TYPE_TRAITS_HPP
#define SAKI_COMPILE_TIME_TEST_TYPE_TRAITS_HPP
#include <type_traits>
#include <saki/type_traits.hpp>
#include <vector>
#include <queue>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN

namespace compile_time_test
{
/**
* @brief X��public�ɕϐ��Ɏ��\����
*/
struct HasX
{
	int x;
};
/**
* @brief X��public�ɕϐ��Ɏ����Ȃ��\����
*/
struct NotHasX
{
	int y;
};
static_assert(saki::has_x_v<saki::compile_time_test::HasX>);
static_assert(saki::has_x_v<saki::compile_time_test::NotHasX> == false);
static_assert(saki::float_constant_v<10, 11, 2> == 10.0011f);
static_assert(saki::can_range_based_for_v<std::vector<int>>);
static_assert(saki::can_range_based_for_v<std::queue<int>> == false);
static_assert(saki::can_equal_equal_v<double>);
static_assert(std::is_same_v<saki::remove_reference_const_t<const int &>, int>);

} // namespace compile_time_test

SAKI_NAMESPACE_END

#endif //SAKI_COMPILE_TIME_TEST_TYPE_TRAITS_HPP