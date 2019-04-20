/**
* @file return_param.hpp
* @brief そのまま引数の値を返す関数オブジェクト
* @author 石山 悠
* @date 2018/12/10
*/
#ifndef SAKI_FUNCTION_OBJECT_RETURN_PARAM_HPP
#define SAKI_FUNCTION_OBJECT_RETURN_PARAM_HPP

namespace saki
{
/**
	* @brief そのまま引数を返す関数オブジェクト
	*/
struct return_param
{
	template <typename T>
	constexpr T operator()(const T &t) const
	{
		return t;
	}
};
} // namespace saki
#endif //SAKI_FUNCTION_OBJECT_RETURN_PARAM_HPP