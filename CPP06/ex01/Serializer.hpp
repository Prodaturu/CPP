#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstddef>
#include <stdint.h>
#include "Data.hpp"

// Utility class for raw pointer <-> integer conversions.
// It is intentionally non-instantiable and only exposes static methods.
class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
