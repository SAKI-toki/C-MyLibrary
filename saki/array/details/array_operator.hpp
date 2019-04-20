/**
* @file array_operator.hpp
* @brief 配列クラスの演算子
* @author 石山 悠
* @date 2018/12/24
*/
#ifndef SAKI_ARRAY_DETAILS_ARRAY_OPERATOR_HPP
#define SAKI_ARRAY_DETAILS_ARRAY_OPERATOR_HPP
#include <cstddef>

namespace saki
{
//プロトタイプ宣言
template <typename T, size_t Size>
class array;
/**
	* @brief ==演算子
	*/
template <typename T, size_t Size>
constexpr bool operator==(const array<T, Size> &arr1, const array<T, Size> &arr2)
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}
/**
	* @brief !=演算子
	*/
template <typename T, size_t Size>
constexpr bool operator!=(const array<T, Size> &arr1, const array<T, Size> &arr2)
{
	return !(arr1 == arr2);
}
} // namespace saki
#endif //SAKI_ARRAY_DETAILS_ARRAY_OPERATOR_HPP