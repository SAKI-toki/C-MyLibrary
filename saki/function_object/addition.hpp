/**
* @file addition.hpp
* @brief 足し算のオペレーターを呼び出すconstexpr関数オブジェクト
* @author 石山 悠
* @date 2018/12/08
*/
#ifndef SAKI_FUNCTION_OBJECT_ADDITION_HPP
#define SAKI_FUNCTION_OBJECT_ADDITION_HPP
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief 足し算のconstexpr対応した関数オブジェクト
*/
struct addition
{
	template <typename T1, typename T2>
	constexpr auto operator()(const T1 &t1, const T2 &t2) const
		-> decltype(t1 + t2)
	{
		return t1 + t2;
	}
};
SAKI_NAMESPACE_END
#endif //SAKI_FUNCTION_OBJECT_ADDITION_HPP