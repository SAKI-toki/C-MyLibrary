/**
* @file vector_test.hpp
* @brief �R���p�C����vector�̃e�X�g
* @author �ΎR �I
* @date 2019/02/19
*/
#ifndef SAKI_VECTOR_TEST_HPP
#define SAKI_VECTOR_TEST_HPP
#include <saki/vector.hpp>

static_assert(saki::vector3<float>{1, 2, 3} + saki::vector3<float>{6, 4, 2} == saki::vector3<float>{7, 6, 5});

#endif //SAKI_VECTOR_TEST_HPP