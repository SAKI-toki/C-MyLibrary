/**
* @file array.h
* @brief �R���p�C�����Œ蒷�z��N���X
* @author �ΎR �I
* @date 2018/12/24
*/
#pragma once
#ifndef SAKI_ARRAY_2018_12_24
#define SAKI_ARRAY_2018_12_24
#include <saki/macro/type_macro.h>
#include <saki/array/details/array_operator.h>

namespace saki
{
	/**
	* @brief �R���p�C�����Œ蒷�z��N���X
	*/
	template<typename T, size_t Size>
	class Array
	{
	public:
		SAKI_TYPE_MACRO(T)
	private:
		value_type arr[Size];
	public:
		/**
		* @brief �����Ȃ��R���X�g���N�^
		* @details �S��0�ŏ�����
		*/
		constexpr Array() :
			arr{}
		{}
		/**
		* @brief ��������R���X�g���N�^
		* @param u �z��̏������l
		*/
		template<typename ...U>
		constexpr Array(const U& ...u) :
			arr{ u... }
		{}
		//�f�t�H���g���g�p
		//�f�t�H���g�ł̓����o�ϐ��̃R�s�[�A���[�u���s��
		Array(const Array<T, Size>&) = default;
		Array<T, Size>& operator=(const Array<T, Size>&) = default;
		Array(Array<T, Size>&&)noexcept = default;
		Array<T, Size>& operator=(Array<T, Size>&&)noexcept = default;
		/**
		* @brief []���Z�q
		*/
		reference operator[](unsigned int index)
		{
			return arr[index];
		}
		/**
		* @brief []���Z�q(constexpr)
		*/
		constexpr const_reference operator[](unsigned int index)const
		{
			return arr[index];
		}
		/**
		* @brief �z��̑傫�����擾
		* @return �z��̑傫��
		*/
		constexpr size_type size()const
		{
			return Size;
		}
	};
}
#endif //SAKI_ARRAY_2018_12_24