/**
* @file muptiple_separation.h
* @brief ��؂蕶������ł������ł��I���ł���悤�ɂ���
* @author �ΎR �I
* @date 2018/12/23
*/
#pragma once
#ifndef SAKI_MULTIPLE_SEPARATION_2018_12_23
#define SAKI_MULTIPLE_SEPARATION_2018_12_23
#include <vector>

namespace saki
{
	class MultipleSeparation
	{
		std::vector<char> separation_list;
	public:
		template<typename ...T>
		explicit MultipleSeparation(const T& ...t) :
			separation_list({ t... })
		{}

		bool check(const char c)
		{
			for (auto separation : separation_list)
			{
				if (separation == c)return true;
			}
			return false;
		}
	};
}
#endif //SAKI_MULTIPLE_SEPARATION_2018_12_23