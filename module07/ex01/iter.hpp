#pragma once

#include <cstddef>

template <typename T> void iter(T * address, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; ++i)
		func(address[i]);
}
