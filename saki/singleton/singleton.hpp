/**
* @file singleton.hpp
* @brief シングルトンクラス
* @author 石山 悠
* @date 2018/10/17
*/
/*
クラスをシングルトンにするとき、このクラスを継承するだけでシングルトンになる
※使い方
class A:public saki::singleton<A>{}
*/
#ifndef SAKI_SINGLETON_SINGLETON_HPP
#define SAKI_SINGLETON_SINGLETON_HPP
#include <memory> //for unique_ptr
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief 継承するとシングルトンクラスになる
*/
template <typename T>
class singleton
{
public:
	/**
	* @brief インスタンスを取得
	* @return std::unique_ptr<T> インスタンスを返す
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