#pragma once

#include <iostream>
#include <stdint.h>
#include <vector>

struct Data
{
	std::string			str;
	int					num;
	std::vector<int>	set;
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
