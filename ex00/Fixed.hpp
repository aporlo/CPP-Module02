#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
private:
	int	_fixedPointNum;
	const static int _bitNum = 8;
public:
	Fixed(void);
	~Fixed(void);

	Fixed(Fixed const &src);

	Fixed & operator = ( Fixed const & ref);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
};


#endif
