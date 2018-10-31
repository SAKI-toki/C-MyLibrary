/**
* @file singleton.h
* @brief シングルトンクラス
* @author 石山 悠
* @date 2018/10/17
*/
/*
クラスをシングルトンにするとき、このクラスを継承するだけでシングルトンになるクラス
※使い方
class A:public saki::singleton<A>{}
*/
#ifndef SAKI_SINGLETON_2018_10_17
#define SAKI_SINGLETON_2018_10_17
#include <memory> //for unique_ptr
namespace saki
{
	/**
	* @brief 継承するとシングルトンクラスになる
	* @details 使い方：class A : public singleton<A>{}
	*/
	template<typename T>
	class singleton
	{
		using type = std::unique_ptr<T>;
		static type instance;
	public:
		/**
		* @brief インスタンスを取得
		* @return std::unique_ptr<T> インスタンスを返す
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