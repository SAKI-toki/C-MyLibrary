/**
* @file vector_2d.h
* @brief 2�����ł̃x�N�g��
* @author �ΎR �I
* @date 2018/11/13
*/
#ifndef SAKI_VECTOR_2D_2018_11_13
#define SAKI_VECTOR_2D_2018_11_13
#include <type_traits>
#include "../operator/compound_assignment_operator_define.h"
namespace saki
{
	/**
	* @brief 2�����ł̃x�N�g��
	*/
	template<typename T>
	class Vector2
	{
	public:
		T x, y;
		/**
		* @brief �����Ȃ��R���X�g���N�^
		*/
		Vector2() {}
		/**
		* @brief ��������R���X�g���N�^
		* @param _x x�̏����l
		* @param _y y�̏����l
		*/
		Vector2(const T _x, const T _y) :
			x(_x), y(_y) {}
		/**
		* @brief �R�s�[�R���X�g���N�^
		*/
		Vector2(const Vector2<T>& other)
		{
			this->x = other.x;
			this->y = other.y;
		}
		/**
		* @brief �R�s�[������Z�q
		*/
		Vector2& operator=(const Vector2<T>& other)
		{
			if (this != &other)
			{
				this->x = other.x;
				this->y = other.y;
			}
			return *this;
		}
		/**
		* @brief ���[�u�R���X�g���N�^
		*/
		Vector2(Vector2<T>&& other)noexcept
		{
			this->x = std::move(other.x);
			this->y = std::move(other.y);
		}
		/**
		* @brief ���[�u������Z�q
		*/
		Vector2& operator=(Vector2<T>&& other)noexcept
		{
			if (this != &other)
			{
				this->x = std::move(other.x);
				this->y = std::move(other.y);
			}
			return *this;
		}
		/**
		* @brief +���Z�q
		*/
		Vector2 operator+(const Vector2<T>& other)
		{
			auto temp = Vector2{ this->x + other.x,this->y + other.y };
			return temp;
		}
		/**
		* @brief -���Z�q
		*/
		Vector2 operator-(const Vector2<T>& other)
		{
			auto temp = Vector2{ this->x - other.x,this->y - other.y };
			return temp;
		}
		/**
		* @brief *���Z�q
		*/
		Vector2 operator*(const T scalar)
		{
			auto temp = Vector2{ this->x * scalar,this->y * scalar };
			return temp;
		}
		/**
		* @brief /���Z�q
		*/
		Vector2 operator/(const T scalar)
		{
			auto temp = Vector2{ this->x / scalar,this->y / scalar };
			return temp;
		}

		SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE(Vector2&,Vector2<T>, T)

		/**
		* @brief ==���Z�q
		*/
		bool operator==(const Vector2<T>& other)
		{
			return this->x == other.x && this->y == other.y;
		}
		/**
		* @brief !=���Z�q
		*/
		bool operator!=(const Vector2<T>& other)
		{
			return !(this == other);
		}
	};
}
#endif //SAKI_VECTOR_2D_2018_11_13