/**
* @file immobile_ptr.h
* @brief �R�s�[�E���[�u�֎~�̃X�}�[�g�|�C���^
* @author �ΎR �I
* @date 2018/11/26
*/
/*
�W�����C�u������std::unique_ptr�̃��[�u���֎~�����o�[�W�����ł��B
boost��scoped_ptr�Ǝd�l�͂��������ꏏ�ł����Aswap�����폜���Ă���̂ł��B��Ȃ��̂ɂȂ��Ă܂��B
*/
#pragma once
#ifndef SAKI_IMMOBILE_PTR_2018_11_26
#define SAKI_IMMOBILE_PTR_2018_11_26
#include <assert.h>	//for assert
namespace saki
{
	/**
	* @brief �R�s�[�E���[�u�֎~�̃X�}�[�g�|�C���^
	*/
	template<typename T>
	class immobile_ptr
	{
	public:
		/**
		* @brief �R���X�g���N�^���Ƀ������m��
		* @param args T�̃R���X�g���N�^�ɕK�v�Ȉ���
		*/
		template<typename ...Args>
		explicit immobile_ptr(Args... args)
		{
			ptr = new T(args...);
		}
		/**
		* @brief �f�X�g���N�^���Ƀ��������
		*/
		~immobile_ptr()noexcept
		{
			release();
		}
		/**
		* @brief �����I�ȃ��������
		*/
		void release()noexcept
		{
			if (ptr != nullptr)
			{
				delete(ptr);
				ptr = nullptr;
			}
		}
		/**
		* @brief ���\�[�X�̎擾
		*/
		T* get()
		{
			check();
			return ptr;
		}
		/**
		* @brief ���\�[�X�̃A�h���X���擾
		*/
		T** get_address()
		{
			check();
			return &ptr;
		}
		/**
		* @brief �����I�ȃ���������ƐV���Ƀ������m�ۂ���
		* @param args T�̃R���X�g���N�^�ɕK�v�Ȉ���
		*/
		template<typename ...Args>
		void reset(Args ...args)
		{
			release();
			ptr = new T(args...);
		}
		/**
		* @brief �ϊ����Z�q
		*/
		explicit operator bool()const
		{
			return ptr != nullptr;
		}
		/**
		* @brief �A���[���Z�q
		*/
		T* operator->()const
		{
			check();
			return ptr;
		}
		/**
		* @brief �Q�Ɖ��Z�q
		*/
		T operator*()const
		{
			return *ptr;
		}
		//�R�s�[�E���[�u�֎~
		immobile_ptr(const immobile_ptr&) = delete;
		immobile_ptr(immobile_ptr&&) = delete;
		immobile_ptr& operator=(const immobile_ptr&) = delete;
		immobile_ptr& operator=(immobile_ptr&&) = delete;
	private:
		//�|�C���^
		T* ptr;
		/**
		* @brief ���\�[�X�����邩�ǂ������肷��
		*/
		void check()
		{
			assert(ptr != nullptr);
		}
	};
}
#endif //SAKI_IMMOBILE_PTR_2018_11_26