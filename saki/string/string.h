/**
* @file string.h
* @brief �R���p�C�����Œ蒷string�N���X
* @author �ΎR �I
* @date 2019/01/09
*/
#pragma once
#ifndef SAKI_STRING_STRING_2019_01_09
#define SAKI_STRING_STRING_2019_01_09
#include <cstddef>
#include <saki/array/array.h>

namespace saki
{
	/**
	* @brief �R���p�C�����Œ蒷string_base�N���X
	*/
	template<typename T, size_t N>
	class string_base
	{
		saki::array<T, N> str;
	public:
		constexpr string_base() :str() {}
		constexpr string_base(const saki::array<T, N>& arr) :str(arr) {}
		constexpr T& operator[](size_t index)
		{
			return str[index];
		}
		constexpr const T& operator[](size_t index)const
		{
			return str[index];
		}
	};
}
#endif //SAKI_STRING_STRING_2019_01_09