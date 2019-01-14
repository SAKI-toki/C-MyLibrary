/**
* @file copy.h
* @brief 既存のcopy関数の簡略化
* @author 石山 悠
* @date 2018/12/09
*/
#pragma once
#ifndef SAKI_COPY_2018_12_09
#define SAKI_COPY_2018_12_09
#include <iterator>
#include <saki/meta/can_range_based_for.h>

namespace saki
{
	/**
	* @brief コンテナとコンテナを渡すcopy
	* @param con1 コピーするコンテナクラス
	* @param con2 ペーストするコンテナクラス
	*/
	template <typename Container1, typename Container2,
		typename std::enable_if_t<
		saki::can_range_based_for_v<Container1>&&saki::can_range_based_for_v<Container2>, std::nullptr_t> = nullptr>
		constexpr auto copy(const Container1& con1, Container2& con2)
	{
		auto con1itr = std::begin(con1);
		auto con1end = std::end(con1);
		auto con2itr = std::begin(con2);
		auto con2end = std::end(con2);
		while (con1itr != con1end && con2itr != con2end)
		{
			*(con2itr++) = *(con1itr++);
		}
		return con2itr;
	}
}
#endif //SAKI_COPY_2018_12_09