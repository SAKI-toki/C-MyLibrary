/**
* @file has_variable.hpp
* @brief �w�肵���^������̕ϐ��������Ă��邩�ǂ������肷�郁�^�֐��̊ȈՃC���N���[�h
* @author �ΎR �I
* @date 2018/12/29
*/
#ifndef SAKI_TYPE_TRAITS_HAS_VARIABLE_HPP
#define SAKI_TYPE_TRAITS_HAS_VARIABLE_HPP

#define HAS_VARIABLE_MACRO(name)                                                                                          \
    template <typename T>                                                                                                 \
    struct has_##name                                                                                                     \
    {                                                                                                                     \
    private:                                                                                                              \
        template <typename U>                                                                                             \
        static constexpr std::true_type name##_check(saki::remove_reference_const_t<decltype(std::declval<U>().name)> *); \
        template <typename U>                                                                                             \
        static constexpr std::false_type name##_check(...);                                                               \
                                                                                                                          \
    public:                                                                                                               \
        static constexpr auto value = decltype(name##_check<T>(nullptr))::value;                                          \
    };                                                                                                                    \
    template <typename T>                                                                                                 \
    inline constexpr auto has_##name##_v = saki::has_##name<T>::value;

#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
HAS_VARIABLE_MACRO(x)
HAS_VARIABLE_MACRO(y)
HAS_VARIABLE_MACRO(z)
SAKI_NAMESPACE_END

#endif //SAKI_TYPE_TRAITS_HAS_VARIABLE_HPP