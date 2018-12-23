/**
* @file split.h
* @brief •¶š—ñ‚Ì•ªŠ„
* @author ÎR —I
* @date 2018/12/23
*/
#pragma once
#ifndef SAKI_SPLIT_2018_12_23
#define SAKI_SPLIT_2018_12_23
#include <string>
#include <vector>
#include <type_traits>
#include <saki/split/details/multiple_separation.h>
#include <saki/meta/has_check_method.h>

namespace saki
{
	/**
	* @brief stringŒ^‚ğw’è‚³‚ê‚½•¶š‚Å‹æØ‚Á‚½‚à‚Ì‚ğvector‚Å•Ô‚·
	* @param str ‹æØ‚é‘ÎÛ‚Ì•¶š—ñ
	* @param split_separation ‹æØ‚è‚ğ•¡”‘I‘ğ‚Å‚«‚éƒNƒ‰ƒX
	* @return ‹æØ‚Á‚½•¶š—ñ‚ğŠi”[‚·‚évectorƒNƒ‰ƒX
	* @details bool check(char)‚ÌŠÖ”‚ğ‚Á‚Ä‚¢‚éƒNƒ‰ƒX‚È‚ç‚È‚ñ‚Å‚àó‚¯æ‚êAfalse‚ÌŠÔ•¶š‚ğŠi”[‚µ‘±‚¯‚Ü‚·
	*/
	template<typename T, typename std::enable_if_t<has_check_v<T>, std::nullptr_t> = nullptr>
	std::vector<std::string> split(std::string str, T&& split_separation)
	{
		//‹æØ‚Á‚½•¶š—ñ‚ğ’Ç‰Á
		std::vector<std::string> str_list;

		size_t index = 0;
		while (index < str.size())
		{
			std::string buffer = "";
			while (index < str.size() && !split_separation.check(str[index]))
			{
				buffer += str[index++];
			}
			str_list.push_back(buffer);
			++index;
		}

		return str_list;
	}

	/**
	* @brief stringŒ^‚ğw’è‚³‚ê‚½•¶š‚Å‹æØ‚Á‚½‚à‚Ì‚ğvector‚Å•Ô‚·
	* @param str ‹æØ‚é‘ÎÛ‚Ì•¶š—ñ
	* @param first_separation 1‚Â–Ú‚Ì‹æØ‚è•¶š
	* @param t 2‚Â–ÚˆÈ~‚Ì‹æØ‚è•¶š
	* @return ‹æØ‚Á‚½•¶š—ñ‚ğŠi”[‚·‚évectorƒNƒ‰ƒX
	*/
	template<typename First,typename ...T>
	std::vector<std::string> split(std::string str, First first_separation, T ...t)
	{
		//‹æØ‚Á‚½•¶š—ñ‚ğ’Ç‰Á
		std::vector<std::string> str_list;
		//•¡”‹æØ‚è•¶š‚Ì¶¬
		MultipleSeparation separation(first_separation, t...);
		size_t index = 0;
		while (index < str.size())
		{
			std::string buffer = "";
			while (index < str.size() && !separation.check(str[index]))
			{
				buffer += str[index++];
			}
			str_list.push_back(buffer);
			++index;
		}

		return str_list;
	}
}
#endif //SAKI_SPLIT_2018_12_23