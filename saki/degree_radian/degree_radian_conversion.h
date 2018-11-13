/**
* @file degree_radian_conversion.h
* @brief Degree����Radian�ARadian����Degree�ւ̕ϊ�
* @author �ΎR �I
* @date 2018/11/13
*/
#ifndef SAKI_DEGREE_RADIAN_CONVERSION_2018_11_13
#define SAKI_DEGREE_RADIAN_CONVERSION_2018_11_13
#include "../pi.h"
namespace saki
{
	/**
	* @brief Degree����Radian�ɕϊ�
	* @param deg Radian�ɕϊ�����Degree
	*/
	template<typename Rad, typename Deg>
	inline constexpr Rad to_radian(const Deg& deg)
	{
		return static_cast<Rad>(deg * 0.0174532925199389);
	}
	/**
	* @brief Radian����Degree�ɕϊ�
	* @param rad Degree�ɕϊ�����Radian
	*/
	template<typename Deg, typename Rad>
	inline constexpr Deg to_degree(const Rad& rad)
	{
		return static_cast<Deg>(rad * 57.29577951309679);
	}
}
#endif //SAKI_DEGREE_RADIAN_CONVERSION_2018_11_13