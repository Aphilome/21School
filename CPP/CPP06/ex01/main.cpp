#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data *myStruct)
{
	return reinterpret_cast<uintptr_t>(myStruct);
}

Data* deserialize(uintptr_t encryptedData)
{
	return reinterpret_cast<Data *>(encryptedData);
}

int main()
{
	Data data;
	data.charValue = 'A';
	data.intValue = 21;

	std::cout << "data struct: "
			  << data.intValue
			  << ", "
			  << data.charValue
			  << std::endl;

	uintptr_t serialized = serialize(&data);

	std::cout << "serialized: "
			  << serialized
				<< std::endl;

	Data *nextData = deserialize(serialized);

	std::cout << "deserialized: "
			  << nextData->intValue
			  << ", "
			  << nextData->charValue
				<< std::endl;

	std::cout	<< &data
				<< " = "
				<< nextData << std::endl;

	return (0);
}
