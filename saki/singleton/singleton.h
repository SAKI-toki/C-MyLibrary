/**
* @file singleton.h
* @brief �V���O���g���N���X
* @author �ΎR �I
* @date 2018/10/17
*/
/*
�N���X���V���O���g���ɂ���Ƃ��A���̃N���X���p�����邾���ŃV���O���g���ɂȂ�N���X
���g����
class A:public saki::singleton<A>{}
*/
#ifndef SAKI_SINGLETON_2018_10_17
#define SAKI_SINGLETON_2018_10_17
#include <memory> //for unique_ptr
namespace saki
{
	/**
	* @brief �p������ƃV���O���g���N���X�ɂȂ�
	* @details �g�����Fclass A : public singleton<A>{}
	*/
	template<typename T>
	class singleton
	{
		using type = std::unique_ptr<T>;
		static type instance;
	public:
		/**
		* @brief �C���X�^���X���擾
		* @return std::unique_ptr<T> �C���X�^���X��Ԃ�
		*/
		static type& getinstance()
		{			
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