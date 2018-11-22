/**
* @file singleton.h
* @brief �V���O���g���N���X
* @author �ΎR �I
* @date 2018/10/17
*/
/*
�N���X���V���O���g���ɂ���Ƃ��A���̃N���X���p�����邾���ŃV���O���g���ɂȂ�
���g����
class A:public saki::singleton<A>{}
*/
#pragma once
#ifndef SAKI_SINGLETON_2018_10_17
#define SAKI_SINGLETON_2018_10_17
#include "../smart_ptr/immobile/immobile_ptr.h"
namespace saki
{
	/**
	* @brief �p������ƃV���O���g���N���X�ɂȂ�
	*/
	template<typename T>
	class singleton
	{
	public:
		/**
		* @brief �C���X�^���X���擾
		* @return std::unique_ptr<T> �C���X�^���X��Ԃ�
		*/
		static immobile_ptr<T>& getinstance()
		{
			static auto instance = immobile_ptr<T>();
			return instance;
		}

		virtual ~singleton() {}

	protected:
		singleton() {}
	private:
		singleton(const singleton&) = delete;
		singleton& operator=(const singleton&) = delete;
		singleton(singleton&&) = delete;
		singleton& operator=(singleton&&) = delete;
	};
}
#endif //SAKI_SINGLETON_2018_10_17