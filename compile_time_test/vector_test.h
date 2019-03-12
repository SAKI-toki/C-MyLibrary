/**
* @file vector_test.h
* @brief �R���p�C����vector�̃e�X�g
* @author �ΎR �I
* @date 2019/02/19
*/
#pragma once
#ifndef SAKI_VECTOR_TEST_2019_02_19
#define SAKI_VECTOR_TEST_2019_02_19
#include <saki/vector.h>

static_assert(saki::vector3<float>{1, 2, 3} + saki::vector3<float>{6, 4, 2} == saki::vector3<float>{7, 6, 5});

#endif //SAKI_VECTOR_TEST_2019_02_19