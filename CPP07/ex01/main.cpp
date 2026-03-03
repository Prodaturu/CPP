#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printValue(T const &value)
{
	std::cout << value << std::endl;
}

void addTen(int &value)
{
	value += 10;
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};
	std::size_t count = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "Before addTen:" << std::endl;
	::iter(numbers, count, printValue<int>);

	::iter(numbers, count, addTen);

	std::cout << "After addTen:" << std::endl;
	::iter(numbers, count, printValue<int>);

	std::string words[] = {"hello", "42", "heilbronn"};
	std::size_t wordsCount = sizeof(words) / sizeof(words[0]);

	std::cout << "String array:" << std::endl;
	::iter(words, wordsCount, printValue<std::string>);

	return 0;
}