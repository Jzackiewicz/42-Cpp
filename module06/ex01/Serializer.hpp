#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
	char	c;
	int		i;
	float	f;
	double	d;
};

class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);

		static uintptr_t serialize(Data *ptr);
		static void *deserialize(uintptr_t raw);
};
