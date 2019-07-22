/**
* @file size.hpp
* @brief サイズを判定する
* @author 石山 悠
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
* @brief サイズが指定した値かどうかチェックする
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
* @brief 簡単に設定できるようにするためのマクロ
*/
#define IS_SIZE_MACRO(NUM)                                                     \
    template <typename T>                                                      \
    struct is_size_##NUM : public decltype(impl::is_size::check<T, NUM / 8>()) \
    {                                                                          \
    };                                                                         \
                                                                               \
    template <typename T>                                                      \
    inline constexpr bool is_size_##NUM##_v = is_size_##NUM<T>::value;

//主に利用する1,2,4,8,(16)byteを定義
IS_SIZE_MACRO(8)
IS_SIZE_MACRO(16)
IS_SIZE_MACRO(32)
IS_SIZE_MACRO(64)
IS_SIZE_MACRO(128)
//これ以上マクロを設定しないためundef
#undef IS_SIZE_MACRO

SAKI_NAMESPACE_END
#endif //SAKI_SIZE_SIZE_HPP