/**
* @file int_to_string.hpp
* @brief intå^Ç©ÇÁstringå^Ç…ïœä∑
* @author êŒéR óI
* @date 2019/01/26
*/
#ifndef SAKI_STRING_TO_STRING_INT_TO_STRING_HPP
#define SAKI_STRING_TO_STRING_INT_TO_STRING_HPP
#include <cstddef>
#include <limits>
#include <type_traits>
#include <saki/math/details/pow_n.hpp>
#include <saki/math/digit_count.hpp>
#include <saki/math/abs.hpp>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/string/base/string_base.hpp>

namespace saki
{
/**
	* @brief intå^Ç©ÇÁstringå^Ç…ïœä∑
	* @details å≈íËí∑ÇÃÇΩÇﬂÉTÉCÉYéwíËÇµÇ»ÇØÇÍÇŒÇ»ÇÁÇ»Ç¢
	*/
template <typename T, typename Integer,
		  size_t N = saki::digit_count(std::numeric_limits<Integer>::max()) + 1,
		  typename StringType = saki::string_base<T, N>,
		  typename saki::enable_if_nullptr_t<std::is_integral_v<Integer>> = nullptr>
constexpr StringType int_to_string(Integer x)
{
	if (x == 0)
	{
		return StringType{"0"};
	}
	StringType str;
	size_t index = 0;
	if constexpr (std::is_signed_v<Integer>)
	{
		if (x < 0)
		{
			str[index++] = '-';
			x = saki::abs(x);
		}
	}
	size_t digit = saki::digit_count(x);
	for (size_t i = digit; i > 0; --i)
	{
		auto pow10 = saki::details::pow_n(Integer(10), i - 1);
		auto digit_n = x / pow10;
		str[index++] = static_cast<T>('0' + digit_n);
		x -= digit_n * pow10;
	}
	return str;
}

} // namespace saki

#endif //SAKI_STRING_TO_STRING_INT_TO_STRING_HPP