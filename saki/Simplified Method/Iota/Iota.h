#pragma once
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

namespace saki
{
	template<typename Container>
	void iota(Container& con, typename Container::value_type val = 0, typename Container::value_type separated = 1)
	{
		for (auto&& n : con)
		{
			n = val;
			val = val + separated;
		}
	}

	template<typename Container>

}