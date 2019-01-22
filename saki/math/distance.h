/**
* @file distance.h
* @brief 2�_�Ԃ̋����𑪂�
* @author �ΎR �I
* @date 2018/12/06
*/
#pragma once
#ifndef SAKI_MATH_DISTANCE_2018_12_06
#define SAKI_MATH_DISTANCE_2018_12_06
#include <saki/math/hypot.h>

namespace saki
{
	/**
	* @brief ��_�Ԃ̋���(XY)
	*/
	template<typename T1, typename T2>
	constexpr auto distanceXY(const T1& v1, const T2& v2)
	{
		return saki::hypot(
			(v1.x - v2.x),
			(v1.y - v2.y));
	}
	/**
	* @brief ��_�Ԃ̋���(XZ)
	*/
	template<typename T1, typename T2>
	constexpr auto distanceXZ(const T1& v1, const T2& v2)
	{
		return saki::hypot(
			(v1.x - v2.x),
			(v1.z - v2.z));
	}
	/**
	* @brief ��_�Ԃ̋���(YZ)
	*/
	template<typename T1, typename T2>
	constexpr auto distanceYZ(const T1& v1, const T2& v2)
	{
		return saki::hypot(
			(v1.y - v2.y),
			(v1.z - v2.z));
	}
	/**
	* @brief ��_�Ԃ̋���(XYZ)
	*/
	template<typename T1, typename T2>
	constexpr auto distanceXYZ(const T1& v1, const T2& v2)
	{
		return saki::hypot(
			(v1.x - v2.x),
			(v1.y - v2.y),
			(v1.z - v2.z));
	}
}
#endif //SAKI_MATH_DISTANCE_2018_12_06