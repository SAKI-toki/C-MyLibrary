/**
* @file enabled_if_nullptr.h
* @brief nullptr_tを返すenabled_if
* @author 石山 悠
* @date 2019/01/19
*/
#pragma once
#ifndef SAKI_TYPE_TRAITS_ENABLED_IF_NULLPTR_2019_01_19
#define SAKI_TYPE_TRAITS_ENABLED_IF_NULLPTR_2019_01_19

namespace saki
{
	/**
	* @brief enalbed_ifのfalse
	*/
	template<bool>
	struct enabled_if_nullptr
	{
	};
	/**
	* @brief enabled_ifのtrue
	*/
	template<>
	struct enabled_if_nullptr<true>
	{
		using type = std::nullptr_t;
	};
	/**
	* @brief enabled_if_nullptrを簡単に呼び出せる変数
	*/
	template<bool Con>
	using enabled_if_nullptr_t = typename enabled_if_nullptr<Con>::type;
}
#endif //SAKI_TYPE_TRAITS_ENABLED_IF_NULLPTR_2019_01_19