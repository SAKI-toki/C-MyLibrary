/**
* @file equal_define.h
* @brief bool型のoperatorを自動で定義するマクロ
* @author 石山 悠
* @date 2018/10/30
*/
/*
operator==とoperator<を定義していれば
operator!=とoperator>とoperator<=とoperator>=が上の二つのoperatorをもとに定義される
※使用例
class A
{
public:
	int n = 0;
	bool operator==(const A& a)
	{
		return this->n == a.n;
	}
	bool operator<(const A& a)
	{
		return this->n < a.n;
	}
	SAKI_EQUAL_DEFINE(A)
};
*/

#ifndef SAKI_EQUAL_DEFINE_2018_10_30
#define SAKI_EQUAL_DEFINE_2018_10_30

/**
* @brief operatorを自動定義するマクロ
* @param name 定義するクラスの名前
* @details ==と<が定義されていれば!=と>と<=と>=が自動定義される
*/
#define SAKI_EQUAL_DEFINE(name)						\
\
/*ノットイコール									*/\
bool operator!=(const name& other)const				\
{													\
	return !(*this == other);						\
}													\
													\
/*大なり											*/\
bool operator>(const name& other)const				\
{													\
	return other < *this;							\
}													\
													\
/*小なりイコール									*/\
bool operator<=(const name& other)const				\
{													\
	return !(other < *this);						\
}													\
													\
/*大なりイコール									*/\
bool operator>=(const name& other)const				\
{													\
	return !(*this < other);						\
}													\
\


#endif //SAKI_EQUAL_DEFINE_2018_10_30