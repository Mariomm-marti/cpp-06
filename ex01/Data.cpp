#include "Data.hpp"

Data::Data(void) : _number(0) { }

Data::Data(Data const &copy)
{
	_number = copy.getNumber();
}

Data::Data(int const num) : _number(num) { }

Data::~Data(void) { }

Data	&Data::operator=(Data const &rhs)
{
	_number = rhs.getNumber();
	return *this;
}

int	Data::getNumber(void) const
{
	return _number;
}
