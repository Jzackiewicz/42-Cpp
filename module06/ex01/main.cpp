#include "Serializer.hpp"
#include <fstream>

Data	create_data(void)
{
	Data	data;

	data.str = "Example text";
	data.num = 42;
	data.set.push_back(3);
	data.set.push_back(-4);
	data.set.push_back(123125);
	data.set.push_back(303);

	return (data);
}

void	print_data(Data data)
{
	std::cout << "Str: " << data.str << std::endl;
	std::cout << "Int: " << data.num << std::endl;
	std::cout << "Set: " << data.set[0];
	for (unsigned int i = 1; i < data.set.size(); i++)
		std::cout << " | " << data.set[i]; 
	std::cout << std::endl;
}

int main(void)
{
	Data		data;
	uintptr_t	raw;

	data = create_data();
	std::cout << "Original Data:" << std::endl;
	print_data(data);

	raw = Serializer::serialize(&data);
	Data *deserializedData = static_cast<Data *>(Serializer::deserialize(raw));
	std::cout << "\nSerialized: " << raw << std::endl;
	
	std::cout << "\nDeserialized Data:" << std::endl;
	print_data(*deserializedData);

	return 0;
}
