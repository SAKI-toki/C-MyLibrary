/**
* @file compound_assignment_operator_define.h
* @brief ����������Z�q�������Œ�`����}�N��
* @author �ΎR �I
* @date 2018/11/13
*/
/*
operator+,-,*,/���`���Ă����
operator+=,-=,*=,/=�����operator�����Ƃɒ�`�����
*/
#pragma once
#ifndef SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE_2018_11_13
#define SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE_2018_11_13

/**
* @brief ����������Z�q��������`����}�N��
* @param return_name �ԋp����l
* @param name �^��
* @param scalar �|���Z�Ɗ���Z�ł̌^��
* @details operator+,-,*,/���`���Ă����operator+=,-=,*=,/=��������`�����
*/
#ifndef SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE
#define SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE(return_name,name,scalar)	\
/*���Z																		*/\
return_name operator+=(const name& other)									\
{																			\
	*this = *this + other;													\
	return *this;															\
}																			\
/*���Z																		*/\
return_name operator-=(const name& other)									\
{																			\
	*this = *this - other;													\
	return *this;															\
}																			\
/*��Z																		*/\
return_name operator*=(const scalar& other)									\
{																			\
	*this = *this * other;													\
	return *this;															\
}																			\
/*���Z																		*/\
return_name operator/=(const scalar& other)									\
{																			\
	*this = *this / other;													\
	return *this;															\
}																			\

#endif	//SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE
#endif	//SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE_2018_11_13