/**
* @file compound_assignment_operator_define.h
* @brief 複合代入演算子を自動で定義するマクロ
* @author 石山 悠
* @date 2018/11/13
*/
/*
operator+,-,*,/を定義していれば
operator+=,-=,*=,/=が上のoperatorをもとに定義される
*/
#pragma once
#ifndef SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE_2018_11_13
#define SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE_2018_11_13

/**
* @brief 複合代入演算子を自動定義するマクロ
* @param return_name 返却する値
* @param name 型名
* @param scalar 掛け算と割り算での型名
* @details operator+,-,*,/を定義していればoperator+=,-=,*=,/=が自動定義される
*/
#ifndef SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE
#define SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE(return_name,name,scalar)	\
/*加算																		*/\
return_name operator+=(const name& other)									\
{																			\
	*this = *this + other;													\
	return *this;															\
}																			\
/*減算																		*/\
return_name operator-=(const name& other)									\
{																			\
	*this = *this - other;													\
	return *this;															\
}																			\
/*乗算																		*/\
return_name operator*=(const scalar& other)									\
{																			\
	*this = *this * other;													\
	return *this;															\
}																			\
/*除算																		*/\
return_name operator/=(const scalar& other)									\
{																			\
	*this = *this / other;													\
	return *this;															\
}																			\

#endif	//SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE
#endif	//SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE_2018_11_13