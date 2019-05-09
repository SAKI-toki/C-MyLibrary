/**
* @file can_not_equal.hpp
* @brief �w�肵���^��(!=)���Z�q���g�p�ł��邩�ǂ������肷�郁�^�֐�
* @author �ΎR �I
* @date 2019/01/22
*/
#ifndef SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_NOT_EQUAL_HPP
#define SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_NOT_EQUAL_HPP
#include <type_traits>
#include <utility>
#include <saki/type_traits/remove_reference_const.hpp>

namespace saki
{
/**
	* @brief �m�b�g�C�R�[����r�ł��邩�ǂ����𔻒肷��\����(!=)
	*/
template <typename T>
struct can_not_equal
{
private:
	template <typename U>
	static constexpr std::true_type not_equal_check(
			saki::remove_reference_const_t<decltype(std::declval<U>() != std::declval<U>())> *);
	template <typename U>
	static constexpr std::false_type not_equal_check(...);

public:
	static constexpr auto value = decltype(not_equal_check<T>(nullptr))::value;
};
/**
	* @brief can_not_equal���ȒP�ɌĂяo����ϐ�
	*/
template <typename T>
static constexpr auto can_not_equal_v = saki::can_not_equal<T>::value;
} // namespace saki
#endif //SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_NOT_EQUAL_HPP