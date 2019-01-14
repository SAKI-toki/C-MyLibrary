/**
* @file remove_reference_const.h
* @brief QÆ‚ÆconstCü‚ğíœ‚µ‚½Œ^‚ğ•Ô‚·
* @author ÎR —I
* @date 2019/01/12
*/
#pragma once
#ifndef SAKI_REMOVE_REFERENCE_CONST_2019_01_12
#define SAKI_REMOVE_REFERENCE_CONST_2019_01_12
#include <type_traits>

namespace saki
{
	/**
	* @brief QÆ‚ÆconstCü‚ğíœ
	*/
	template<typename T>
	struct remove_reference_const
	{
		using type = typename std::remove_const_t<std::remove_reference_t<T>>;
	};
	/**
	* @brief remove_reference_const‚ğŠÈ’P‚ÉŒÄ‚Ño‚¹‚é‚æ‚¤‚É‚µ‚½ 
	*/
	template<typename T>
	using remove_reference_const_t = typename saki::remove_reference_const<T>::type;
}
#endif //SAKI_REMOVE_REFERENCE_CONST_2019_01_12