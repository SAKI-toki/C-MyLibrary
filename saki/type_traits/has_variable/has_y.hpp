/**
* @file has_y.hpp
* @brief �w�肵���^���ϐ�y�������Ă��邩�ǂ������肷�郁�^�֐�
* @author �ΎR �I
* @date 2019/01/22
*/
#ifndef SAKI_TYPE_TRAITS_HAS_VARIABLE_HAS_Y_HPP
#define SAKI_TYPE_TRAITS_HAS_VARIABLE_HAS_Y_HPP
#include <type_traits>
#include <utility>
#include <saki/type_traits/remove_reference_const.hpp>

namespace saki
{
/**
	* @brief �ϐ�y�������Ă��邩�ǂ����𔻒肷��\����
	*/
template <typename T>
struct has_y
{
private:
	template <typename U>
	static constexpr std::true_type y_check(saki::remove_reference_const_t<decltype(std::declval<U>().y)> *);
	template <typename U>
	static constexpr std::false_type y_check(...);

public:
	static constexpr auto value = decltype(y_check<T>(nullptr))::value;
};
/**
	* @brief has_y���ȒP�ɌĂяo����ϐ�
	*/
template <typename T>
inline constexpr auto has_y_v = saki::has_y<T>::value;
} // namespace saki
#endif //SAKI_TYPE_TRAITS_HAS_VARIABLE_HAS_Y_HPP