#include "Serializer.hpp"
#include <fstream>

int main(void)
{
	Data data;
	data.c = 'A';
	data.i = 42;
	data.f = 3.14f;
	data.d = 2.718281828459045;

	uintptr_t raw = Serializer::serialize(&data);
	Data *deserializedData = static_cast<Data *>(Serializer::deserialize(raw));

	std::cout << "Original Data:" << std::endl;
	std::cout << "Char: " << data.c << std::endl;
	std::cout << "Int: " << data.i << std::endl;
	std::cout << "Float: " << data.f << std::endl;
	std::cout << "Double: " << data.d << std::endl;

	std::ofstream file("savefile", std::ios::binary);
	file.write(static_cast<std::string>(raw), sizeof(raw));
	std::cout << "Serialized: " << raw << std::endl;
	std::cout << "\nDeserialized Data:" << std::endl;
	std::cout << "Char: " << deserializedData->c << std::endl;
	std::cout << "Int: " << deserializedData->i << std::endl;
	std::cout << "Float: " << deserializedData->f << std::endl;
	std::cout << "Double: " << deserializedData->d << std::endl;

	return 0;
}