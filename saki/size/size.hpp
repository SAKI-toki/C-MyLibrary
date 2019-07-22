/**
* @file size.hpp
* @brief �T�C�Y�𔻒肷��
* @author �ΎR �I
* @date 2019/07/21
*/
#ifndef SAKI_SIZE_SIZE_HPP
#define SAKI_SIZE_SIZE_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
namespace impl
{
/**
* @brief �T�C�Y���w�肵���l���ǂ����`�F�b�N����
*/
struct is_size
{
    template <typename T, decltype(sizeof(void *)) N,
              saki::enable_if_nullptr_t<sizeof(T) == N> = nullptr>
    static std::true_type check();
    template <typename T, decltype(sizeof(void *)) N,
              saki::enable_if_nullptr_t<sizeof(T) != N> = nullptr>
    static std::false_type check();
};
} // namespace impl

/**
* @brief �ȒP�ɐݒ�ł���悤�ɂ��邽�߂̃}�N��
*/
#define IS_SIZE_MACRO(NUM)                                                     \
    template <typename T>                                                      \
    struct is_size_##NUM : public decltype(impl::is_size::check<T, NUM / 8>()) \
    {                                                                          \
    };                                                                         \
                                                                               \
    template <typename T>                                                      \
    inline constexpr bool is_size_##NUM##_v = is_size_##NUM<T>::value;

//��ɗ��p����1,2,4,8,(16)byte���`
IS_SIZE_MACRO(8)
IS_SIZE_MACRO(16)
IS_SIZE_MACRO(32)
IS_SIZE_MACRO(64)
IS_SIZE_MACRO(128)
//����ȏ�}�N����ݒ肵�Ȃ�����undef
#undef IS_SIZE_MACRO

SAKI_NAMESPACE_END
#endif //SAKI_SIZE_SIZE_HPP