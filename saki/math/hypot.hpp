/**
* @file hypot.hpp
* @brief �R���p�C����hypot
* @author �ΎR �I
* @date 2019/01/08
*/
#ifndef SAKI_MATH_HYPOT_HPP
#define SAKI_MATH_HYPOT_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/sqrt.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/isinf.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
///------2����--------
/**
* @brief �R���p�C�����ݏ�
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T hypot(T x, T y)
{
	if (saki::isinf(x) || saki::isinf(y))
		return std::numeric_limits<T>::infinity();
	if (saki::isnan(x))
		return x;
	if (saki::isnan(y))
		return y;

	if (x == 0)
	{
		if (y == 0)
		{
			//x==0&&y==0
			return 0;
		}
		else
		{
			//y==0
			return saki::abs(y);
		}
	}
	else if (y == 0)
	{
		//x==0
		return saki::abs(x);
	}
	return saki::sqrt(x * x + y * y);
}

/**
* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double hypot(T x, T y)
{
	return saki::hypot(static_cast<double>(x), static_cast<double>(y));
}

/**
* @brief �^���Ⴄ�ꍇ�͂��낦��
*/
template <typename T1, typename T2,
		  saki::enable_if_nullptr_t<
			  std::is_arithmetic_v<std::common_type_t<T1, T2>>> = nullptr>
constexpr auto hypot(T1 x, T2 y)
{
	using type = std::common_type_t<T1, T2>;
	return saki::hypot(static_cast<type>(x), static_cast<type>(y));
}

///------3����--------

/**
* @brief �R���p�C�����ݏ�
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T hypot(T x, T y, T z)
{
	if (saki::isinf(x) || saki::isinf(y) || saki::isinf(z))
		return std::numeric_limits<T>::infinity();
	if (saki::isnan(x))
		return x;
	if (saki::isnan(y))
		return y;
	if (saki::isnan(z))
		return z;

	if (x == 0)
	{
		if (y == 0)
		{
			if (z == 0)
			{
				//x==0&&y==0&&z==0
				return 0;
			}
		}
		else if (z == 0)
		{
			//x==0&&z==0
			return saki::abs(y);
		}
		else
		{
			//x==0
			return saki::sqrt(y * y + z * z);
		}
	}
	else if (y == 0)
	{
		if (z == 0)
		{
			//y==0&&z==0
			return saki::abs(x);
		}
		else
		{
			//y==0
			return saki::sqrt(x * x + z * z);
		}
	}
	else if (z == 0)
	{
		//z==0
		return saki::sqrt(x * x + y * y);
	}
	return saki::sqrt(x * x + y * y + z * z);
}
/**
* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double hypot(T x, T y, T z)
{
	return saki::hypot(static_cast<double>(x), static_cast<double>(y), static_cast<double>(z));
}
/**
* @brief �^���Ⴄ�ꍇ�͂��낦��
*/
template <typename T1, typename T2, typename T3,
		  saki::enable_if_nullptr_t<
			  std::is_arithmetic_v<std::common_type_t<T1, T2, T3>>> = nullptr>
constexpr auto hypot(T1 x, T2 y, T3 z)
{
	using type = std::common_type_t<T1, T2, T3>;
	return saki::hypot(static_cast<type>(x),
					   static_cast<type>(y),
					   static_cast<type>(z));
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_HYPOT_HPP