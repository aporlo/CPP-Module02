#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>

class Fixed
{
private:
	int	_fixedNum;
	const static int _bitNum = 8;
public:
	Fixed(void);
	~Fixed(void);

	Fixed(Fixed const &src);

	Fixed & operator = ( Fixed const & ref);

	int		getRawBits();
	void	setRawBits( int const raw);
};


#endif
