/**
* @file type_macro.hpp
* @brief value_type,pointer,referenceìôÇé©ìÆíËã`
* @author êŒéR óI
* @date 2018/12/13
*/
#ifndef SAKI_MACRO_TYPE_MACRO_HPP
#define SAKI_MACRO_TYPE_MACRO_HPP
#include <cstddef>

#ifndef SAKI_TYPE_MACRO
#define SAKI_TYPE_MACRO(T)             \
    using value_type = T;              \
    using size_type = size_t;          \
    using difference_type = ptrdiff_t; \
    using pointer = T *;               \
    using const_pointer = const T *;   \
    using reference = T &;             \
    using const_reference = const T &;

#endif //SAKI_TYPE_MACRO

#endif //SAKI_MACRO_TYPE_MACRO_HPP