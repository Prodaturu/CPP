#include "Serializer.hpp"

// Private canonical members are defined even though the class is not meant
// to be instantiated, keeping the interface complete and link-safe.
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}
Serializer::~Serializer() {}

// reinterpret_cast preserves the bit pattern of the pointer value.
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// Inverse operation: rebuild the exact pointer from the integer representation.
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
