#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Array.hpp"

#define MAX_VAL 10

int main(int, char**)
{
	std::srand(std::time(NULL));

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	std::cout << "Filling the array\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	numbers.printArray();

	std::cout << "Check with the mirror\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
		std::cout << "Success: everything is the same\n";
	}

	std::cout << "Testing copy ctor and copy assignment operator\n";
	{
		Array<int> test(numbers);
		Array<int> tmp;
		tmp = test;
		tmp.printArray();
	}

	std::cout << "Testing out of bounds access\n";
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Filling the array with other values\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = std::rand();
	}
	numbers.printArray();
	delete [] mirror;
	return 0;
}