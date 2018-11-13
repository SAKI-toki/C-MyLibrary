/**
* @file vector_2d.h
* @brief 2次元でのベクトル
* @author 石山 悠
* @date 2018/11/13
*/
#ifndef SAKI_VECTOR_2D_2018_11_13
#define SAKI_VECTOR_2D_2018_11_13
#include <type_traits>
#include "../operator/compound_assignment_operator_define.h"
namespace saki
{
	/**
	* @brief 2次元でのベクトル
	*/
	template<typename T>
	class Vector2
	{
	public:
		T x, y;
		/**
		* @brief 引数なしコンストラクタ
		*/
		Vector2() {}
		/**
		* @brief 引数ありコンストラクタ
		* @param _x xの初期値
		* @param _y yの初期値
		*/
		Vector2(const T _x, const T _y) :
			x(_x), y(_y) {}
		/**
		* @brief コピーコンストラクタ
		*/
		Vector2(const Vector2<T>& other)
		{
			this->x = other.x;
			this->y = other.y;
		}
		/**
		* @brief コピー代入演算子
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
		* @brief ムーブコンストラクタ
		*/
		Vector2(Vector2<T>&& other)noexcept
		{
			this->x = std::move(other.x);
			this->y = std::move(other.y);
		}
		/**
		* @brief ムーブ代入演算子
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
		* @brief +演算子
		*/
		Vector2 operator+(const Vector2<T>& other)
		{
			auto temp = Vector2{ this->x + other.x,this->y + other.y };
			return temp;
		}
		/**
		* @brief -演算子
		*/
		Vector2 operator-(const Vector2<T>& other)
		{
			auto temp = Vector2{ this->x - other.x,this->y - other.y };
			return temp;
		}
		/**
		* @brief *演算子
		*/
		Vector2 operator*(const T scalar)
		{
			auto temp = Vector2{ this->x * scalar,this->y * scalar };
			return temp;
		}
		/**
		* @brief /演算子
		*/
		Vector2 operator/(const T scalar)
		{
			auto temp = Vector2{ this->x / scalar,this->y / scalar };
			return temp;
		}

		SAKI_COMPOUND_ASSIGNMENT_OPERATOR_DEFINE(Vector2&,Vector2<T>, T)

		/**
		* @brief ==演算子
		*/
		bool operator==(const Vector2<T>& other)
		{
			return this->x == other.x && this->y == other.y;
		}
		/**
		* @brief !=演算子
		*/
		bool operator!=(const Vector2<T>& other)
		{
			return !(this == other);
		}
	};
}
#endif //SAKI_VECTOR_2D_2018_11_13