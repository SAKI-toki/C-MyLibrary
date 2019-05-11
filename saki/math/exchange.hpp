/**
* @file exchange.hpp
* @brief コンパイル時exchange
* @author 石山 悠
* @date 2018/11/21
*/
#ifndef SAKI_MATH_EXCHANGE_HPP
#define SAKI_MATH_EXCHANGE_HPP
#include <type_traits>
#include <utility>

namespace saki
{
/**
	* @brief コンパイル時exchange
	* @param obj 値を入れられる値
	* @param new_val 値に入れる値
	*/
template <typename T, typename U = T>
inline constexpr T exchange(T &obj, U &&new_val)
{
	T t1 = std::move(obj);
	obj = std::forward<U>(new_val);
	return t1;
}
} // namespace saki
#endif //SAKI_MATH_EXCHANGE_HPP