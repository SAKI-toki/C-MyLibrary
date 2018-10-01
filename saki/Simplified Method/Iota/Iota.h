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
#ifndef SAKI_SIMPLIFIED_METHOD_IOTA
#define SAKI_SIMPLIFIED_METHOD_IOTA
namespace saki
{
	/**
	* @param con		�R���e�i�N���X
	* @param val		�ŏ��̒l
	* @param interval	���������ɒl���i�[�����邩
	* @details	�S�Ă̗v�f�ɑ΂��čs���ꍇ�͂��������g��
	*/
	template<typename Container>
	void iota(Container& con, typename Container::value_type val = 0, typename Container::value_type interval = 1)
	{
		for (auto&& n : con)
		{
			n = val;
			val = val + interval;
		}
	}

	/**
	* @param start		�X�^�[�g�̃C�e���[�^�[
	* @param end		�I���̃C�e���[�^�[
	* @param val		�ŏ��̒l
	* @param interval	���������ɒl���i�[�����邩
	* @details	���߂�ꂽ�͈̗͂v�f�ɑ΂��čs���ꍇ�͂��������g��
	*/
	template<typename Iterator>
	void iota(Iterator start, const Iterator& end, typename Iterator::value_type val = 0, typename Iterator::value_type interval = 1)
	{
		for (; start != end; ++start)
		{
			*start = val;
			val = val + interval;
		}
	}
}
#endif //SAKI_SIMPLIFIED_METHOD_IOTA