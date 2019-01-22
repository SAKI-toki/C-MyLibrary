/**
* @file enabled_if_nullptr.h
* @brief nullptr_t‚ğ•Ô‚·enabled_if
* @author ÎR —I
* @date 2019/01/19
*/
#pragma once
#ifndef SAKI_TYPE_TRAITS_ENABLED_IF_NULLPTR_2019_01_19
#define SAKI_TYPE_TRAITS_ENABLED_IF_NULLPTR_2019_01_19

namespace saki
{
	/**
	* @brief enalbed_if‚Ìfalse
	*/
	template<bool>
	struct enabled_if_nullptr
	{
	};
	/**
	* @brief enabled_if‚Ìtrue
	*/
	template<>
	struct enabled_if_nullptr<true>
	{
		using type = std::nullptr_t;
	};
	/**
	* @brief enabled_if_nullptr‚ğŠÈ’P‚ÉŒÄ‚Ño‚¹‚é•Ï”
	*/
	template<bool Con>
	using enabled_if_nullptr_t = typename enabled_if_nullptr<Con>::type;
}
#endif //SAKI_TYPE_TRAITS_ENABLED_IF_NULLPTR_2019_01_19