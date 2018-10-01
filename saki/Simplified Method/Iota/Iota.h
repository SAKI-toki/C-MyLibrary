#pragma once
/*!
* @file Iota.h
* @brief ������iota�֐��̊ȗ����{�g��
* @author �ΎR�@�I
* @date 2018/09/30
*/
/*
�z��̒��g�S�ĂɘA�Ԃ�����ꍇ�̓C�e���[�^�[��n�����A�R���e�i�N���X�����̂܂ܓn�������ł悢
����ɍŏ��̒l�̐ݒ��A���������ɒl���i�[���邩�����߂邱�Ƃ��ł���

�L���ȕW�����C�u�����̃R���e�i�N���X
vector,list,forward_list,array

�L���Ȍ^
operator+��operator=���������
*/

namespace saki
{
	template<typename Container>
	void iota(Container& con, typename Container::value_type val = 0, typename Container::value_type separated = 1)
	{
		for (auto&& n : con)
		{
			n = val;
			val = val + separated;
		}
	}

	template<typename Container>

}