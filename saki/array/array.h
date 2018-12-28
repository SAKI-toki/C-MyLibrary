/**
* @file array.h
* @brief コンパイル時固定長配列クラス
* @author 石山 悠
* @date 2018/12/24
*/
#pragma once
#ifndef SAKI_ARRAY_2018_12_24
#define SAKI_ARRAY_2018_12_24
#include <saki/macro/type_macro.h>
#include <saki/array/details/array_operator.h>

namespace saki
{
	/**
	* @brief コンパイル時固定長配列クラス
	*/
	template<typename T, size_t Size>
	class Array
	{
	public:
		SAKI_TYPE_MACRO(T)
	private:
		value_type arr[Size];
	public:
		/**
		* @brief 引数なしコンストラクタ
		* @details 全て0で初期化
		*/
		constexpr Array() :
			arr{}
		{}
		/**
		* @brief 引数ありコンストラクタ
		* @param u 配列の初期化値
		*/
		template<typename ...U>
		constexpr Array(const U& ...u) :
			arr{ u... }
		{}
		//デフォルトを使用
		//デフォルトではメンバ変数のコピー、ムーブを行う
		Array(const Array<T, Size>&) = default;
		Array<T, Size>& operator=(const Array<T, Size>&) = default;
		Array(Array<T, Size>&&)noexcept = default;
		Array<T, Size>& operator=(Array<T, Size>&&)noexcept = default;
		/**
		* @brief []演算子
		*/
		reference operator[](unsigned int index)
		{
			return arr[index];
		}
		/**
		* @brief []演算子(constexpr)
		*/
		constexpr const_reference operator[](unsigned int index)const
		{
			return arr[index];
		}
		/**
		* @brief 配列の大きさを取得
		* @return 配列の大きさ
		*/
		constexpr size_type size()const
		{
			return Size;
		}
	};
}
#endif //SAKI_ARRAY_2018_12_24