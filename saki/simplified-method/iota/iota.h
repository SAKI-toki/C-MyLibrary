/**
* @file iota.h
* @brief ������iota�֐��̊ȗ����{�g��
* @author �ΎR �I
* @date 2018/09/30
*/
/*
�z��̒��g�S�ĂɘA�Ԃ�����ꍇ�̓C�e���[�^�[��n�����A�R���e�i�N���X�����̂܂ܓn�������ł悢
����ɍŏ��̒l�̐ݒ��A���������ɒl���i�[���邩�����߂邱�Ƃ��ł���
*/
#ifndef SAKI_IOTA_2018_09_30
#define SAKI_IOTA_2018_09_30
namespace saki
{
	/**
	* @brief			�S�Ă̒l�ɘA�Ԃ�����
	* @param con		�R���e�i�N���X
	* @param init		�ŏ��̒l
	* @param interval	���������ɒl���i�[�����邩
	*/
	template<typename Container>
	void iota(Container& con, typename Container::value_type init = 0, typename Container::value_type interval = 1)
	{
		for (auto&& n : con)
		{
			n = init;
			init = init + interval;
		}
	}

	/**
	* @brief			���܂����͈͂ɘA�Ԃ�����
	* @param start		�X�^�[�g�̃C�e���[�^�[
	* @param end		�I���̃C�e���[�^�[
	* @param init		�ŏ��̒l
	* @param interval	���������ɒl���i�[�����邩
	*/
	template<typename Iterator>
	void iota(Iterator start, const Iterator& end, typename Iterator::value_type init = 0, typename Iterator::value_type interval = 1)
	{
		for (; start != end; ++start)
		{
			*start = init;
			init = init + interval;
		}
	}
}
#endif //SAKI_IOTA_2018_09_30