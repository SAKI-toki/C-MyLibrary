/**
* @file singleton.hpp
* @brief �V���O���g���N���X
* @author �ΎR �I
* @date 2018/10/17
*/
/*
�N���X���V���O���g���ɂ���Ƃ��A���̃N���X���p�����邾���ŃV���O���g���ɂȂ�
���g����
class A:public saki::singleton<A>{}
*/
#ifndef SAKI_SINGLETON_SINGLETON_HPP
#define SAKI_SINGLETON_SINGLETON_HPP
#include <memory> //for unique_ptr
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief �p������ƃV���O���g���N���X�ɂȂ�
*/
template <typename T>
class singleton
{
public:
	/**
	* @brief �C���X�^���X���擾
	* @return std::unique_ptr<T> �C���X�^���X��Ԃ�
	*/
	static std::unique_ptr<T> &getinstance()
	{
		static auto instance = std::make_unique<T>();
		return instance;
	}

	virtual ~singleton() {}

protected:
	singleton() {}

private:
	singleton(const singleton &) = delete;
	singleton &operator=(const singleton &) = delete;
	singleton(singleton &&) = delete;
	singleton &operator=(singleton &&) = delete;
};
SAKI_NAMESPACE_END
#endif //SAKI_SINGLETON_SINGLETON_HPP