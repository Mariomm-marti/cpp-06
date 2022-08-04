#pragma once
#ifndef CPP06_EX01_DATA_H_
# define CPP06_EX01_DATA_H_

class Data
{
private:
	int		_number;

	Data(void);

public:
	Data(Data const &copy);
	Data(int const num);
	~Data(void);

	Data	&operator=(Data const &rhs);
	int		getNumber(void) const;
};

#endif
