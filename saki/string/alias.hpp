/**
* @file alias.hpp
* @brief string_base���g�p���₷���A�G�C���A�X�錾���Ă���
* @author �ΎR �I
* @date 2019/01/22
*/
#ifndef SAKI_STRING_ALIAS_2019_01_22
#define SAKI_STRING_ALIAS_2019_01_22
#include <saki/string/base/string_base.hpp>

namespace saki
{
template <size_t N>
using string = saki::string_base<char, N>;
}
#endif //SAKI_STRING_ALIAS_2019_01_22
