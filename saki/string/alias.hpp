/**
* @file alias.hpp
* @brief string_base���g�p���₷���A�G�C���A�X�錾���Ă���
* @author �ΎR �I
* @date 2019/01/22
*/
#ifndef SAKI_STRING_ALIAS_HPP
#define SAKI_STRING_ALIAS_HPP
#include <saki/string/base/string_base.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
template <size_t N>
using string = saki::string_base<char, N>;
SAKI_NAMESPACE_END
#endif //SAKI_STRING_ALIAS_HPP