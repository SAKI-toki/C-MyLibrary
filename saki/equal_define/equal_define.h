/**
* @file equal_define.h
* @brief bool�^��operator�������Œ�`����}�N��
* @author �ΎR �I
* @date 2018/10/30
*/
/*
operator==��operator<���`���Ă����
operator!=��operator>��operator<=��operator>=����̓��operator�����Ƃɒ�`�����
���g�p��
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
* @brief operator��������`����}�N��
* @param name ��`����N���X�̖��O
* @details ==��<����`����Ă����!=��>��<=��>=��������`�����
*/
#define SAKI_EQUAL_DEFINE(name)						\
\
/*�m�b�g�C�R�[��									*/\
bool operator!=(const name& other)const				\
{													\
	return !(*this == other);						\
}													\
													\
/*��Ȃ�											*/\
bool operator>(const name& other)const				\
{													\
	return other < *this;							\
}													\
													\
/*���Ȃ�C�R�[��									*/\
bool operator<=(const name& other)const				\
{													\
	return !(other < *this);						\
}													\
													\
/*��Ȃ�C�R�[��									*/\
bool operator>=(const name& other)const				\
{													\
	return !(*this < other);						\
}													\
\


#endif //SAKI_EQUAL_DEFINE_2018_10_30