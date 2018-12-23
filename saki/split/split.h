/**
* @file split.h
* @brief ������̕���
* @author �ΎR �I
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
	* @brief string�^���w�肳�ꂽ�����ŋ�؂������̂�vector�ŕԂ�
	* @param str ��؂�Ώۂ̕�����
	* @param split_separation ��؂�𕡐��I���ł���N���X
	* @return ��؂�����������i�[����vector�N���X
	* @details bool check(char)�̊֐��������Ă���N���X�Ȃ�Ȃ�ł��󂯎��Afalse�̊ԕ������i�[�������܂�
	*/
	template<typename T, typename std::enable_if_t<has_check_v<T>, std::nullptr_t> = nullptr>
	std::vector<std::string> split(std::string str, T&& split_separation)
	{
		//��؂����������ǉ�
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
	* @brief string�^���w�肳�ꂽ�����ŋ�؂������̂�vector�ŕԂ�
	* @param str ��؂�Ώۂ̕�����
	* @param first_separation 1�ڂ̋�؂蕶��
	* @param t 2�ڈȍ~�̋�؂蕶��
	* @return ��؂�����������i�[����vector�N���X
	*/
	template<typename First,typename ...T>
	std::vector<std::string> split(std::string str, First first_separation, T ...t)
	{
		//��؂����������ǉ�
		std::vector<std::string> str_list;
		//������؂蕶���̐���
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