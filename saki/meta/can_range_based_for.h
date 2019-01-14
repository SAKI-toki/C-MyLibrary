/**
* @file can_range_based_for.h
* @brief 範囲ベースfor文に利用できる型がどうか判定するメタ関数
* @author 石山 悠
* @date 2019/01/12
*/
#pragma once
#ifndef SAKI_CAN_RANGE_BASED_FOR_2019_01_12
#define SAKI_CAN_RANGE_BASED_FOR_2019_01_12
#include <type_traits>
#include <saki/meta/can_begin_method.h>
#include <saki/meta/can_end_method.h>

namespace saki
{
	template<typename T>
	class can_range_based_for
	{
		template<typename U,
			typename std::enable_if_t<saki::can_begin_v<U> && saki::can_end_v<U>, std::nullptr_t> = nullptr>
			static constexpr std::true_type check_range_based_for(std::nullptr_t* u);
		template<typename U,
			typename std::enable_if_t<!saki::can_begin_v<U> || !saki::can_end_v<U>, std::nullptr_t> = nullptr>
			static constexpr std::false_type check_range_based_for(std::nullptr_t* u);
	public:
		static constexpr auto value = decltype(check_range_based_for<T>(nullptr))::value;
	};
	template<typename T>
	static constexpr auto can_range_based_for_v = can_range_based_for<T>::value;
}
#endif //SAKI_CAN_RANGE_BASED_FOR_2019_01_12