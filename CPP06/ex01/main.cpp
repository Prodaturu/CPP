#include "Serializer.hpp"

#include <iostream>

int main()
{
	Data original;
	original.id = 42;
	original.label = "serializer-test";
	original.score = 98.7;

	Data* ptr = &original;
	uintptr_t raw = Serializer::serialize(ptr);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original pointer:  " << ptr << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Restored pointer:  " << restored << std::endl;

	if (restored == ptr)
	{
		std::cout << "Pointers are equal" << std::endl;
		std::cout << "Data -> id: " << restored->id
			<< ", label: " << restored->label
			<< ", score: " << restored->score << std::endl;
		return 0;
	}

	std::cout << "Pointers are NOT equal" << std::endl;
	return 1;
}
