/**
* @file type_traits_test.h
* @brief コンパイル時type_traitsのテスト
* @author 石山 悠
* @date 2019/02/19
*/
#pragma once
#ifndef SAKI_TYPE_TRAITS_TEST_2019_02_19
#define SAKI_TYPE_TRAITS_TEST_2019_02_19
#include <type_traits>
#include <saki/type_traits.h>
#include <vector>
#include <queue>

struct HasX
{
	int x;
};
struct NotHasX
{
	int y;
};
static_assert(saki::has_x_v<HasX>);
static_assert(saki::has_x_v<NotHasX> == false);
static_assert(saki::float_constant_v<10, 11, 2> == 10.0011f);
static_assert(saki::can_range_based_for_v<std::vector<int>>);
static_assert(saki::can_range_based_for_v<std::queue<int>> == false);
static_assert(saki::can_equal_equal_v<double>);
static_assert(std::is_same_v<saki::remove_reference_const_t<const int&>, int>);


#endif //SAKI_TYPE_TRAITS_TEST_2019_02_19