/**
* @file degree_radian_conversion.h
* @brief DegreeからRadian、RadianからDegreeへの変換
* @author 石山 悠
* @date 2018/11/13
*/
#pragma once
#ifndef SAKI_DEGREE_RADIAN_CONVERSION_2018_11_13
#define SAKI_DEGREE_RADIAN_CONVERSION_2018_11_13
#include "../pi.h"
namespace saki
{
	/**
	* @brief DegreeからRadianに変換
	* @param deg Radianに変換するDegree
	*/
	template<typename Rad, typename Deg>
	constexpr Rad to_radian(Deg deg)
	{
		return static_cast<Rad>(deg * 0.0174532925199389);
	}
	/**
	* @brief RadianからDegreeに変換
	* @param rad Degreeに変換するRadian
	*/
	template<typename Deg, typename Rad>
	constexpr Deg to_degree(Rad rad)
	{
		return static_cast<Deg>(rad * 57.29577951309679);
	}
}
#endif //SAKI_DEGREE_RADIAN_CONVERSION_2018_11_13