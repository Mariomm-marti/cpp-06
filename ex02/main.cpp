#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <fstream>

uint8_t	rrandom(uint8_t const min, uint8_t const max)
{
	std::ifstream	file("/dev/urandom");
	char			number[1];

	file.read(number, 1);
	if (number[0] < 0)
		number[0] *= -1;
	return (number[0] % (max - min)) + min;
}

Base	*generate(void)
{
	Base	*ptr;

	std::cout << "[GENERATE] Returned ";
	switch (rrandom(0, 3)) {
		case 0:
			ptr = static_cast<Base *>(new A());
			std::cout << "a" << std::endl;
			break ;
		case 1:
			ptr = static_cast<Base *>(new B());
			std::cout << "b" << std::endl;
			break ;
		default:
			ptr = static_cast<Base *>(new C());
			std::cout << "c" << std::endl;
	}
	return ptr;
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A *>(p);
	B	*b = dynamic_cast<B *>(p);
	C	*c = dynamic_cast<C *>(p);

	std::cout << "[IDENTIFY*] Found type ";
	if (a != NULL)
		std::cout << "a" << std::endl;
	if (b != NULL)
		std::cout << "b" << std::endl;
	if (c != NULL)
		std::cout << "c" << std::endl;
}

void	identify(Base &p)
{
	try {
		A	&a = dynamic_cast<A &>(p);
		std::cout << "[IDENTIFY&] Found type a: " << &a << std::endl;
	} catch (std::bad_cast const &e) {
		std::cout << "[IDENTIFY&] Discarded type a" << std::endl;
	}
	try {
		B	&b = dynamic_cast<B &>(p);
		std::cout << "[IDENTIFY&] Found type b: " << &b << std::endl;
	} catch (std::bad_cast const &e) {
		std::cout << "[IDENTIFY&] Discarded type b" << std::endl;
	}
	try {
		C	&c = dynamic_cast<C &>(p);
		std::cout << "[IDENTIFY&] Found type c: " << &c << std::endl;
	} catch (std::bad_cast const &e) {
		std::cout << "[IDENTIFY&] Discarded type c" << std::endl;
	}
}

int		main(void)
{
	Base	*generatedPtr = generate();

	identify(generatedPtr);
	identify(*generatedPtr);

	delete generatedPtr;
	system("leaks convert");
}
