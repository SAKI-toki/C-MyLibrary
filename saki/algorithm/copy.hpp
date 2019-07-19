/**
* @file copy.hpp
* @brief ������copy�֐��̊ȗ���
* @author �ΎR �I
* @date 2019/01/24
*/
#ifndef SAKI_ALGORITHM_COPY_HPP
#define SAKI_ALGORITHM_COPY_HPP
#include <iterator>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/type_traits/can_range_based_for.hpp>

namespace saki
{
/**
	* @brief �R���e�i�ƃR���e�i��n��copy
	* @param con1 �R�s�[����R���e�i�N���X
	* @param con2 �y�[�X�g����R���e�i�N���X
	* @details �Е���end�ɂȂ�����R�s�[�I��
	*/
template <typename Container1, typename Container2,
		  saki::enable_if_nullptr_t<
			  saki::can_range_based_for_v<Container1> && //�R���e�i1��begin,end�L����
			  saki::can_range_based_for_v<Container2>	//�R���e�i2��begin,end�L����
			  > = nullptr>
constexpr auto copy(const Container1 &con1, Container2 &con2)
	-> decltype(*std::begin(con2) = *std::begin(con1), std::begin(con2))
{
	auto con1itr = std::begin(con1);
	auto con1end = std::end(con1);
	auto con2itr = std::begin(con2);
	auto con2end = std::end(con2);
	while (con1itr != con1end && con2itr != con2end)
	{
		*con2itr = *con1itr;
		++con1itr;
		++con2itr;
	}
	return con2itr;
}
} // namespace saki
#endif //SAKI_ALGORITHM_COPY_HPP