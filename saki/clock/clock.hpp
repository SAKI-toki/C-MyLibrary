/**
* @file clock.hpp
* @brief 時間を測るクラス
* @author 石山 悠
* @date 2018/12/04
*/
#ifndef SAKI_CLOCK_CLOCK_HPP
#define SAKI_CLOCK_CLOCK_HPP
#include <chrono>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief 時間を測るクラス
*/
class clock
{
	std::chrono::system_clock::time_point start_time; //開始時間
public:
	/**
	* @brief コンストラクタ
	*/
	clock() : start_time(std::chrono::system_clock::now()) {}

public:
	enum class DURATION
	{
		HOUR,
		MINUTE,
		SECOND,
		MILLISECOND,
		MICROSECOND,
		NANOSECOND,
		NONE
	};
	/**
	* @brief 開始時間のセット
	*/
	void start()
	{
		start_time = std::chrono::system_clock::now();
	}
	/**
	* @brief 開始時間をセットしてからの時間を返す
	* @param duration どの単位で返すか
	* return 時間
	*/
	template <typename T = double,
			  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
	T end(const DURATION duration = DURATION::MILLISECOND)
	{
		auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now() - start_time).count();
		switch (duration)
		{
		case DURATION::MICROSECOND: //マイクロ秒
		{
			return static_cast<T>(elapsed_time * 0.001);
		}
		case DURATION::MILLISECOND: //ミリ秒
		{
			return static_cast<T>(elapsed_time * 0.001 * 0.001);
		}
		case DURATION::SECOND: //秒
		{
			return static_cast<T>(elapsed_time * 0.001 * 0.001 * 0.001);
		}
		case DURATION::MINUTE: //分
		{
			return static_cast<T>(elapsed_time * 0.001 * 0.001 * 0.001 / 60);
		}
		case DURATION::HOUR: //時間
		{
			return static_cast<T>(elapsed_time * 0.001 * 0.001 * 0.001 / 60 / 60);
		}
		default: //ナノ秒
		{
			return static_cast<T>(elapsed_time);
		}
		}
	}
	/**
	* @brief 開始時間をセットしてからの時間を返し、そこからまた時間をスタートする
	* @param duration どの単位で返すか
	* return 時間
	*/
	template <typename T = double,
			  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
	T end_and_start(const DURATION duration = DURATION::MILLISECOND)
	{
		auto t = end<T>(duration);
		start();
		return t;
	}
};
SAKI_NAMESPACE_END
#endif //SAKI_CLOCK_CLOCK_HPP