/**
* @file split.hpp
* @brief 文字列の分割
* @author 石山 悠
* @date 2018/12/23
*/
#ifndef SAKI_SPLIT_SPLIT_HPP
#define SAKI_SPLIT_SPLIT_HPP
#include <string>
#include <vector>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/split/details/multiple_separation.hpp>
#include <saki/split/details/not_equal_separation.hpp>
#include <saki/type_traits/has_check_method.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief string型を指定された文字で区切ったものをvectorで返す
* @param str 区切る対象の文字列
* @param split_separation 区切りを複数選択できるクラス
* @return 区切った文字列を格納するvectorクラス
* @details bool check(char)の関数を持っているクラスならなんでも受け取れ、falseの間文字を格納し続けます
*/
template <template <typename, typename> typename Container = std::vector, typename T,
		  saki::enable_if_nullptr_t<saki::has_check_v<T>> = nullptr>
Container<std::string, std::allocator<std::string>> split(const std::string &str, T &&split_separation)
{
	//区切った文字列を追加
	std::vector<std::string> str_list;
	size_t index = 0;
	auto begin = std::begin(str);
	while (index < str.size())
	{
		size_t start_index = index;
		while (index < str.size() && !split_separation.check(str[index]))
		{
			++index;
		}
		str_list.push_back(std::string(begin + start_index, begin + index));
		++index;
	}
	//型がstd::vectorならそのままstr_listを返す
	if constexpr (std::is_same_v<Container<std::string, std::allocator<std::string>>,
								 std::vector<std::string, std::allocator<std::string>>>)
	{
		return std::move(str_list);
	}
	//型がstd::listのように別の型ならそれに変換してから返す
	else
	{
		Container<std::string, std::allocator<std::string>> return_str_list(std::begin(str_list), std::end(str_list));
		return std::move(return_str_list);
	}
}

/**
* @brief string型を指定された文字で区切ったものをvectorで返す
* @param str 区切る対象の文字列
* @param first_separation 1つ目の区切り文字
* @param t 2つ目以降の区切り文字
* @return 区切った文字列を格納するvectorクラス
*/
template <template <typename, typename> typename Container = std::vector,
		  typename First, typename... T>
Container<std::string, std::allocator<std::string>> split(const std::string &str, First first_separation, T... t)
{
	return saki::split<Container>(str, saki::MultipleSeparation(first_separation, t...));
}
SAKI_NAMESPACE_END
#endif //SAKI_SPLIT_SPLIT_HPP