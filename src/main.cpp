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

#include <algorithm>

int main()
{
	std::vector<int> vec(10);
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		vec[i] = i * i;
	}
	for (const auto &n : vec)
	{
		Comment(n);
	}
	std::cout << std::endl;
	vec.erase(std::remove_if(
				  vec.begin(),
				  vec.end(),
				  [](int x) { return x % 2 == 0; }),
			  vec.end());
	for (const auto &n : vec)
	{
		Comment(n);
	}
	return 0;
}
