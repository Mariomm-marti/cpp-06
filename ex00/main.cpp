#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	float	givenValue;
	char	asChar;
	double	asDouble;
	int		asInt;

	if (argc != 2)
		return 1;
	givenValue = std::stof(*(argv + 1));
	std::cout << "float: '" << givenValue << "'" << std::endl;
	asChar = static_cast<char>(givenValue);
	if (asChar < 32)
		std::cout << "char: non printable" << std::endl;
	else
		std::cout << "char: '" << asChar << "'" << std::endl;
	asDouble = static_cast<double>(givenValue);
	std::cout << "double: '" << asDouble << "'" << std::endl;
	asInt = static_cast<int>(givenValue);
	std::cout << "int: '" << asInt << "'" << std::endl;
}
