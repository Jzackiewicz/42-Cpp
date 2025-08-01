#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}

Serializer::~Serializer() {}


uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

void *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<void *>(raw));
}
