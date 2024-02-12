#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Array.hpp"
#include "Array_test.hpp"

#define MAX_VAL 10

int	main(void)
{
	std::srand(std::time(NULL));

	ArrayTest<int>("int", MAX_VAL);
	ArrayTest<float>("float", MAX_VAL);
	ArrayTest<double>("double", MAX_VAL);

	return 0;
}