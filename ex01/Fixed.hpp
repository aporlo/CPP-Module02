#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_fixedPointNum;
	const static int _bitNum = 8;

public:
	Fixed(void);
	~Fixed(void);

	Fixed( const int num);
	Fixed( const float num);
	Fixed(Fixed const &src);

	Fixed & operator = ( Fixed const & ref);

	int		getRawBits( void ) const;
	int		toInt( void ) const;
	float	toFloat( void ) const;
	void	setRawBits( int const raw);

};

std::ostream & operator<<( std::ostream & output, Fixed const & input );

#endif
