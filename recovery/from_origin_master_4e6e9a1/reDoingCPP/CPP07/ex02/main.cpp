#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = static_cast<int>(i * 10);

	std::cout << "numbers:" << std::endl;
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	Array<int> copy(numbers);
	copy[0] = 999;

	std::cout << "original after copy change: " << numbers[0] << std::endl;
	std::cout << "copy[0]: " << copy[0] << std::endl;

	Array<std::string> words(3);
	words[0] = "CPP";
	words[1] = "Module";
	words[2] = "07";

	std::cout << "words:" << std::endl;
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << std::endl;

	try
	{
		std::cout << words[3] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}