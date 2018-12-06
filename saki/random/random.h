/**
* @file random.h
* @brief 決められた範囲でランダムな値を取得する
* @author 石山 悠
* @date 2018/11/26
*/
/*
決められた範囲でランダムな値を取得する関数です
*/
#pragma once
#ifndef SAKI_RANDOM_2018_11_26
#define SAKI_RANDOM_2018_11_26
#include <random>
#include <cassert> //for assert
namespace saki
{
	/**
	* @brief 最小値と最大値を引数にとり、その間からランダムな値を返す
	* @param min 最小値
	* @param max 最大値
	* @details 最大値を含むランダムな値を返す
	*/
	template<typename T>
	T random(const T random_min, const T random_max)
	{
		assert(random_min <= random_max);
		static std::random_device rd;
		static std::mt19937 mt(rd());
		if constexpr (std::is_integral_v<T>)
		{
			std::uniform_int_distribution<int> rnd(random_min, random_max);
			return rnd(mt);
		}
		else
		{
			std::uniform_real_distribution<T> rnd(random_min, random_max);
			return rnd(mt);
		}
	}
}
#endif //SAKI_RANDOM_2018_11_26