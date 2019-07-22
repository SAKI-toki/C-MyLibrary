#include <iostream>
#include <iomanip>
#include <saki/type_traits/can_ostream.hpp>
#include <saki/type_traits/enable_if_nullptr.hpp>
//output method
template <typename... Args,
		  saki::enable_if_nullptr_t<
			  std::conjunction_v<saki::can_ostream<Args>...>> = nullptr>
void Comment(const Args &... args)
{
	(std::cout << ... << args) << std::endl;
}
#include <saki/saki.hpp>
#include "../compile_time_test/compile_time_fizzbuzz.hpp"
#include "../compile_time_test/math_test.hpp"
#include "../compile_time_test/type_traits_test.hpp"
#include "../compile_time_test/vector_test.hpp"

int main()
{
	Comment(saki::is_size_64_v<int>);
	return 0;
}
