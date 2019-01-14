/**
* @file accumulate.h
* @brief 既存のaccumulate関数の簡略化
* @author 石山 悠
* @date 2018/12/06
*/
/*
全ての要素を合計（又は指定した演算子）をコンテナクラスと初期値を渡すだけで可能にした
標準ライブラリではIteratorを渡すので、全てならこっちを使ったほうが良い
*/
#pragma once
#ifndef SAKI_ACCUMULATE_2018_12_06
#define SAKI_ACCUMULATE_2018_12_06
#include <type_traits>
#include <saki/meta/can_range_based_for.h>
#include <saki/meta/remove_reference_const.h>
#include <saki/binary_operator/addition.h>
namespace saki
{
	/**
	* @brief 引数が2つの関数を指定し、それをすべての要素で回す
	* @param con コンテナクラス
	* @param init 初期値
	* @param binary_op 引数が2つの関数
	* @return 全ての要素を回した結果
	*/
	template<typename Container, typename BinaryOperation = saki::addition,
		typename std::enable_if_t<saki::can_range_based_for_v<Container>, std::nullptr_t> = nullptr,
		typename T = saki::remove_reference_const_t<typename Container::value_type>,
		typename std::enable_if_t<std::is_invocable_r_v<T, BinaryOperation, T, T>, std::nullptr_t> = nullptr>
		constexpr auto accumulate(const Container& con, T init = 0, BinaryOperation&& binary_op = saki::addition())
	{
		for (const auto& n : con)
		{
			init = binary_op(init, n);
		}
		return init;
	}

}
#endif //SAKI_ACCUMULATE_2018_12_06