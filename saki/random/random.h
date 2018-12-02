/**
* @file random.h
* @brief ���߂�ꂽ�͈͂Ń����_���Ȓl���擾����
* @author �ΎR �I
* @date 2018/11/26
*/
/*
���߂�ꂽ�͈͂Ń����_���Ȓl���擾����֐��ł�
*/
#pragma once
#ifndef SAKI_RANDOM_2018_11_26
#define SAKI_RANDOM_2018_11_26
#include <random>
#include <assert.h>	//for assert
namespace saki
{
	/**
	* @brief �ŏ��l�ƍő�l�������ɂƂ�A���̊Ԃ��烉���_���Ȓl��Ԃ�
	* @param min �ŏ��l
	* @param max �ő�l
	* @details �ő�l���܂ރ����_���Ȓl��Ԃ�
	*/
	template<typename T>
	T random(const T min, const T max)
	{
		assert(min <= max);
		static std::random_device rd;
		static std::mt19937 mt(rd());
		if constexpr (std::is_integral_v<T>)
		{
			static std::uniform_int_distribution<int> rnd(min, max);
			return rnd(mt);
		}
		else
		{
			static std::uniform_real_distribution<T> rnd(min, max);
			return rnd(mt);
		}
	}
}
#endif //SAKI_RANDOM_2018_11_26