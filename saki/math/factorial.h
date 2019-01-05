/**
* @file factorial.h
* @brief Kę
* @author ĪR I
* @date 2018/11/22
*/
#pragma once
#ifndef SAKI_FACTORIAL_2018_11_22
#define SAKI_FACTORIAL_2018_11_22
#include <cstdint>
#include <cstddef>

namespace saki
{
	/**
	* @brief Kę(ųo[W)
	* @param N 1©ēNÜÅĢKęšßé
	*/
	template<typename T = uint64_t>
	constexpr T factorial(int N)
	{
		T sum = 1;
		for (int i = 2; i <= N; ++i)
		{
			sum *= static_cast<T>(i);
		}
		return sum;
	}
	/**
	* @brief Kę(¼ųo[W)
	*/
	template<int N, typename T = uint64_t>
	constexpr T factorial()
	{
		return factorial<T>(N);
	}



	template<typename T>
	struct factorial_limits
	{
		static constexpr size_t limit = 0;
	};
	template<>
	struct factorial_limits<float>
	{
		static constexpr size_t limit = 34;
	};
	template<>
	struct factorial_limits<double>
	{
		static constexpr size_t limit = 49;
	};
	template<>
	struct factorial_limits<long double>
	{
		static constexpr size_t limit = 49;
	};
	template<>
	struct factorial_limits<char>
	{
		static constexpr size_t limit = 5;
	};
	template<>
	struct factorial_limits<unsigned char>
	{
		static constexpr size_t limit = 6;
	};
	template<>
	struct factorial_limits<wchar_t>
	{
		static constexpr size_t limit = 8;
	};
	template<>
	struct factorial_limits<char16_t>
	{
		static constexpr size_t limit = 8;
	};
	template<>
	struct factorial_limits<char32_t>
	{
		static constexpr size_t limit = 13;
	};
	template<>
	struct factorial_limits<short>
	{
		static constexpr size_t limit = 7;
	};
	template<>
	struct factorial_limits<unsigned short>
	{
		static constexpr size_t limit = 8;
	};
	template<>
	struct factorial_limits<int>
	{
		static constexpr size_t limit = 13;
	};
	template<>
	struct factorial_limits<unsigned int>
	{
		static constexpr size_t limit = 13;
	};
	template<>
	struct factorial_limits<long>
	{
		static constexpr size_t limit = 13;
	};
	template<>
	struct factorial_limits<unsigned long>
	{
		static constexpr size_t limit = 13;
	};
	template<>
	struct factorial_limits<long long>
	{
		static constexpr size_t limit = 20;
	};
	template<>
	struct factorial_limits<unsigned long long>
	{
		static constexpr size_t limit = 22;
	};
	/*template<>
	struct factorial_limits<>
	{
		static constexpr size_t limit = 49;
	};*/
}
#endif //SAKI_FACTORIAL_2018_11_22