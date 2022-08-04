#include "Data.hpp"
#include <stdint.h>
#include <iostream>

uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

void	testSerialize(int const number)
{
	Data	data(number);

	uintptr_t	serialized = serialize(&data);
	Data		*deserialized = deserialize(serialized);

	std::cout << "Original number    : " << data.getNumber() << std::endl;
	std::cout << "Original data      : " << &data << std::endl;
	std::cout << "Deserialized number: " << deserialized->getNumber() << std::endl;
	std::cout << "Deserialized data  : " << deserialized << std::endl;
}

int	main(void)
{
	testSerialize(24);
	testSerialize(42);
	testSerialize(2147483647);
}
