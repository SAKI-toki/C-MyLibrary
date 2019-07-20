/**
* @file sigma.hpp
* @brief 数学のシグマ(Σ)
* @author 石山 悠
* @date 2019/01/18
*/
#ifndef SAKI_MATH_SIGMA_HPP
#define SAKI_MATH_SIGMA_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/function_object/return_param.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief 数学のシグマを簡単に実装
* @param start 初期値
* @param end 繰り返しの終わり(この値を使用したら終了)
* @param f 関数
* @return 計算結果
* @details start>endの場合、0が返る、算術型のみ対応
*/
template <typename T = int, typename Func = saki::return_param,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T> &&
									std::is_invocable_v<Func, T>> = nullptr>
constexpr T sigma(T start, const T &end, Func &&f = Func())
{
	T sum = 0;
	for (; start <= end; ++start)
	{
		sum += static_cast<T>(f(start));
	}
	return sum;
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_SIGMA_HPP