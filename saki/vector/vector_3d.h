/**
* @file vector_3d.h
* @brief 3次元でのベクトル
* @author 石山 悠
* @date 2018/12/06
*/
#pragma once
#ifndef SAKI_VECTOR_3D_2018_12_06
#define SAKI_VECTOR_3D_2018_12_06
#include <limits> //for numeric_limits
#include <saki/math/sqrt.h> //for constexpr_sqrt
#include <saki/vector/details/3d/vector_3d_operator.h>
#include <saki/macro/type_macro.h>
#include <cmath>

namespace saki
{
	/**
	* @brief 3次元でのベクトル
	*/
	template<typename T>
	class Vector3
	{
	public:
		SAKI_TYPE_MACRO(T)
	public:
		value_type 
			x = static_cast<value_type>(0),
			y = static_cast<value_type>(0), 
			z = static_cast<value_type>(0);
		/**
		* @brief 引数なしコンストラクタ
		* @details 全て0で初期化
		*/
		constexpr Vector3()
		{}
		/**
		* @brief 引数ありコンストラクタ
		* @param _x xの初期値
		* @param _y yの初期値
		* @param _z zの初期値
		*/
		constexpr Vector3(const_reference _x, const_reference _y, const_reference _z) :
			x(_x), y(_y), z(_z)
		{}
		/**
		* @brief 生配列からの初期化
		* @param pointer 配列のポインタ
		*/
		explicit constexpr Vector3(const_pointer const pointer) :
			x(*pointer), y(*(pointer + 1)), z(*(pointer + 2))
		{}
		//デフォルトを使用
		//デフォルトではメンバ変数のコピー、ムーブを行う
		Vector3(const Vector3<value_type>&) = default;
		Vector3<value_type>& operator=(const Vector3<value_type>&) = default;
		Vector3(Vector3<value_type>&&)noexcept = default;
		Vector3<value_type>& operator=(Vector3<value_type>&&)noexcept = default;
		/**
		* @brief +=演算子
		*/
		template<typename U = value_type>
		constexpr auto operator+=(const saki::Vector3<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -=演算子
		*/
		template<typename U = value_type>
		constexpr auto operator-=(const saki::Vector3<U>& other)
		{
			*this = *this - other;
			return *this;
		}
		/**
		* @brief *=演算子(スカラ)
		*/
		template<typename U = value_type>
		constexpr auto operator*=(const U& scalar)
		{
			*this = *this * scalar;
			return *this;
		}
		/**
		* @brief *=演算子(ベクトル)
		*/
		template<typename U = value_type>
		constexpr auto operator*=(const saki::Vector3<U>& other)
		{
			*this = *this * other;
			return *this;
		}
		/**
		* @brief /=演算子(スカラ)
		*/
		template<typename U = value_type>
		constexpr auto operator/=(const U& scalar)
		{
			*this = *this / scalar;
			return *this;
		}
		/**
		* @brief /=演算子(ベクトル)
		*/
		template<typename U = value_type>
		constexpr auto operator/=(const saki::Vector3<U>& other)
		{
			*this = *this / other;
			return *this;
		}
		/**
		* @brief 単項+演算子
		*/
		constexpr saki::Vector3<value_type> operator+()const
		{
			return *this;
		}
		/**
		* @brief 単項-演算子
		*/
		constexpr saki::Vector3<value_type> operator-()const
		{
			return saki::Vector3<value_type>(this->x * (-1), this->y * (-1), this->z * (-1));
		}
		/**
		* @brief []演算子
		*/
		constexpr reference operator[](const size_type index)
		{
			return (index == 0) ? this->x : (index == 1) ? this->y : this->z;
		}
		/**
		* @brief []演算子(constexpr)
		*/
		constexpr const_reference operator[](const size_type index)const
		{
			return (index == 0) ? this->x : (index == 1) ? this->y : this->z;
		}
		/**
		* @brief ++演算子(前置)
		*/
		constexpr saki::Vector3<value_type>& operator++()
		{
			this->x += 1; this->y += 1; this->z += 1;
			return *this;
		}
		/**
		* @brief ++演算子(後置)
		*/
		constexpr saki::Vector3<value_type> operator++(int)
		{
			saki::Vector3<value_type> temp = *this;
			this->x += 1; this->y += 1; this->z += 1;
			return temp;
		}
		/**
		* @brief --演算子(前置)
		*/
		constexpr saki::Vector3<value_type>& operator--()
		{
			this->x -= 1; this->y -= 1; this->z -= 1;
			return *this;
		}
		/**
		* @brief --演算子(後置)
		*/
		constexpr saki::Vector3<value_type> operator--(int)
		{
			saki::Vector3<value_type> temp = *this;
			this->x -= 1; this->y -= 1; this->z -= 1;
			return temp;
		}
		/**
		* @brief 正規化
		* @details int型の場合、すべての要素が0で返ります
		*/
		constexpr void normalize()
		{
			//分母
			auto den = std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
			if (den == 0)
			{
				this->x = 0;
				this->y = 0;
				this->z = 0;
			}
			else
			{
				this->x /= den;
				this->y /= den;
				this->z /= den;
			}
		}

	};

	/**
	* @brief Vector3のオールゼロ
	*/
	template<typename T>
	static constexpr saki::Vector3<T> vector3_zero{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(0) };
	/**
	* @brief Vector3のオールワン
	*/
	template<typename T>
	static constexpr saki::Vector3<T> vector3_one{ static_cast<T>(1), static_cast<T>(1), static_cast<T>(1) };
	/**
	* @brief Vector3の最小値
	*/
	template<typename T>
	static constexpr saki::Vector3<T> vector3_min{ std::numeric_limits<T>::min(), std::numeric_limits<T>::min(), std::numeric_limits<T>::min() };
	/**
	* @brief Vector3の最大値
	*/
	template<typename T>
	static constexpr saki::Vector3<T> vector3_max{ std::numeric_limits<T>::max(), std::numeric_limits<T>::max(), std::numeric_limits<T>::max() };
	/**
	* @brief 正規化
	* @return 正規化したもの
	*/
	template<typename U = double, typename T>
	constexpr saki::Vector3<U> normalize(const saki::Vector3<T>& v)
	{
		//分母
		auto den = saki::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		if (den == 0)
		{
			return saki::Vector3<U>
				(static_cast<U>(0),//x
					static_cast<U>(0),//y
					static_cast<U>(0));//z
		}
		else
		{
			return saki::Vector3<U>
				(static_cast<U>(v.x / den),//x
					static_cast<U>(v.y / den),//y
					static_cast<U>(v.z / den));//z
		}
	}
	/**
	* @brief 内積
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U dot(const saki::Vector3<T1>& v1, const saki::Vector3<T2>& v2)
	{
		return static_cast<U>(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	}
	/**
	* @brief 外積
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr saki::Vector3<U> cross(const saki::Vector3<T1>& v1, const saki::Vector3<T2>& v2)
	{
		return saki::Vector3<U>(
			v1.y * v2.z - v1.z * v1.y, //x
			v1.z * v2.x - v1.x * v1.z, //y
			v1.x * v2.y - v1.y * v1.x);//z
	}
	/**
	* @brief 線形補間
	* @details Quaternionは使用していません
	*/
	template<typename U = double, typename T1, typename T2, typename T = double>
	constexpr saki::Vector3<U> lerp(const saki::Vector3<T1>& v1, const saki::Vector3<T2>& v2, const T& t, const T& base = 1)
	{
		auto ratio = t / base;
		return saki::Vector3<U>(
			v1.x + (v2.x - v1.x) * ratio,
			v1.y + (v2.y - v1.y) * ratio,
			v1.z + (v2.z - v1.z) * ratio);
	}
}

#endif //SAKI_VECTOR_3D_2018_12_06