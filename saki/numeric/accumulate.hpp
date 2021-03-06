/**
* @file accumulate.hpp
* @brief 既存のaccumulate関数の簡略化
* @author 石山 悠
* @date 2019/01/15
*/
/*
全ての要素を合計（又は指定した演算子）をコンテナクラスと初期値を渡すだけで可能にした
標準ライブラリではIteratorを渡すので、全てならこっちを使ったほうが良い
*/
#ifndef SAKI_NUMERIC_ACCUMULATE_HPP
#define SAKI_NUMERIC_ACCUMULATE_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/type_traits/can_range_based_for.hpp>
#include <saki/type_traits/remove_reference_const.hpp>
#include <saki/function_object/addition.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief 引数が2つの関数を指定し、それをすべての要素で回す
* @param con コンテナクラス
* @param init 初期値
* @param binary_op 引数が2つの関数
* @return 全ての要素を回した結果
*/
template <typename Container, typename BinaryOperation = saki::addition,
		  typename T = saki::remove_reference_const_t<typename Container::value_type>,
		  saki::enable_if_nullptr_t<
			  saki::can_range_based_for_v<Container> &&		  //コンテナがbegin,end有効かどうか
			  std::is_invocable_r_v<T, BinaryOperation, T, T> //BinaryOperation(T,T)の返り値がTかどうか
			  > = nullptr>
constexpr T accumulate(const Container &con, T init = 0, BinaryOperation &&binary_op = saki::addition())
{
	for (const auto &n : con)
	{
		init = static_cast<T>(binary_op(init, n));
	}
	return init;
}
SAKI_NAMESPACE_END
#endif //SAKI_NUMERIC_ACCUMULATE_HPP