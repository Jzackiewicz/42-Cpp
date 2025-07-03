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

