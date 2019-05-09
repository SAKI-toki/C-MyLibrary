/**
* @file is_min.hpp
* @brief 複数の比較を一度に行う(<=)
* @author 石山 悠
* @date 2019/01/21
*/
#ifndef SAKI_COMPARE_IS_MIN_HPP
#define SAKI_COMPARE_IS_MIN_HPP
#include <type_traits>
#include <saki/type_traits/can_compare/can_greater.hpp>
#include <saki/type_traits/enable_if_nullptr.hpp>

namespace saki
{
namespace impl
{
/**
		* @brief 比較するものがない(なくなった)場合、trueを返す
		*/
template <typename T>
constexpr bool is_min_impl(const T &)
{
	return true;
}
/**
		* @brief is_minの実装部
		* @details 毎回isnanを判定する必要がないため、実装部を分けた
		*/
template <typename First, typename Second, typename... Args>
constexpr bool is_min_impl(const First &first, Second second, const Args &... args)
{
	return (first > static_cast<First>(second)) ? false : saki::impl::is_min_impl(first, (args)...);
}
} // namespace impl
/**
	* @brief 複数の比較を一度に行える(<=)
	* @details if(x <= a && x <= b && x <= c)をis_min(x,a,b,c)と書ける
	*/
template <typename First, typename... Args,
		  saki::enable_if_nullptr_t<
			  std::conjunction_v<std::is_convertible<First, Args>...> && //最初以外の型がFirstに変換可能か
			  std::conjunction_v<saki::can_greater<First>>				 //Firstが>演算子が有効かどうか
			  > = nullptr>
constexpr bool is_min(const First &first, const Args &... args)
{
	return saki::impl::is_min_impl(first, (args)...);
}
} // namespace saki
#endif //SAKI_COMPARE_IS_MIN_HPP