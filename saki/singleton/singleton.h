/**
* @file singleton.h
* @brief シングルトンクラス
* @author 石山 悠
* @date 2018/10/17
*/
/*
クラスをシングルトンにするとき、このクラスを継承するだけでシングルトンになる
※使い方
class A:public saki::singleton<A>{}
*/
#pragma once
#ifndef SAKI_SINGLETON_2018_10_17
#define SAKI_SINGLETON_2018_10_17
#include "../smart_ptr/immobile/immobile_ptr.h"
namespace saki
{
	/**
	* @brief 継承するとシングルトンクラスになる
	*/
	template<typename T>
	class singleton
	{
	public:
		/**
		* @brief インスタンスを取得
		* @return std::unique_ptr<T> インスタンスを返す
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