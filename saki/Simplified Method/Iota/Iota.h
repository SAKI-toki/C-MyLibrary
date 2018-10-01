/*!
* @file Iota.h
* @brief 既存のiota関数の簡略化＋拡張
* @author 石山　悠
* @date 2018/09/30
*/
/*
配列の中身全てに連番をつける場合はイテレーターを渡さず、コンテナクラスをそのまま渡すだけでよい
さらに最初の値の設定や、いくつおきに値を格納するかを決めることができる

有効な標準ライブラリのコンテナクラス
vector,list,forward_list,array

有効な型
operator+とoperator=があるもの
*/
#ifndef SAKI_SIMPLIFIED_METHOD_IOTA
#define SAKI_SIMPLIFIED_METHOD_IOTA
namespace saki
{
	/**
	* @param con		コンテナクラス
	* @param val		最初の値
	* @param interval	いくつおきに値を格納させるか
	* @details	全ての要素に対して行う場合はこっちを使う
	*/
	template<typename Container>
	void iota(Container& con, typename Container::value_type val = 0, typename Container::value_type interval = 1)
	{
		for (auto&& n : con)
		{
			n = val;
			val = val + interval;
		}
	}

	/**
	* @param start		スタートのイテレーター
	* @param end		終わりのイテレーター
	* @param val		最初の値
	* @param interval	いくつおきに値を格納させるか
	* @details	決められた範囲の要素に対して行う場合はこっちを使う
	*/
	template<typename Iterator>
	void iota(Iterator start, const Iterator& end, typename Iterator::value_type val = 0, typename Iterator::value_type interval = 1)
	{
		for (; start != end; ++start)
		{
			*start = val;
			val = val + interval;
		}
	}
}
#endif //SAKI_SIMPLIFIED_METHOD_IOTA