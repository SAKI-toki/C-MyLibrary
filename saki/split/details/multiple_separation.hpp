/**
* @file multiple_separation.hpp
* @brief 区切り文字を一つでも複数でも選択できるようにする
* @author 石山 悠
* @date 2018/12/23
*/
#ifndef SAKI_SPLIT_DETAILS_MULTIPLE_SEPARATION_HPP
#define SAKI_SPLIT_DETAILS_MULTIPLE_SEPARATION_HPP
#include <vector>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief split関数で利用する、区切り文字を複数指定できるクラス
*/
class MultipleSeparation
{
	//区切り文字を格納
	std::vector<char> separation_list;

public:
	/**
	* @brief コンストラクタ
	* @param t 区切り文字
	*/
	template <typename... T>
	explicit MultipleSeparation(const T &... t) : separation_list({t...})
	{
	}

	/**
	* @brief 渡された引数が区切り文字かチェックする
	* @param c 判定する文字
	* @details bool check(char)という形にしなけらばならない
	*/
	bool check(const char c)
	{
		for (auto separation : separation_list)
		{
			if (separation == c)
				return true;
		}
		return false;
	}
};
SAKI_NAMESPACE_END
#endif //SAKI_SPLIT_DETAILS_MULTIPLE_SEPARATION_HPP