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

	bool operator>(const Fixed &ref) const;
	bool operator<(const Fixed &ref) const;
	bool operator>=(const Fixed &ref) const;
	bool operator<=(const Fixed &ref) const;
	bool operator==(const Fixed &ref) const;
	bool operator!=(const Fixed &ref) const;

	Fixed & operator = ( Fixed const & ref);
	Fixed operator+(const Fixed &ref) const;
	Fixed operator-(const Fixed &ref) const;
	Fixed operator*(const Fixed &ref) const;
	Fixed operator/(const Fixed &ref) const;

	Fixed	&operator++( void );
	Fixed	operator++( int );
	Fixed	&operator--( void );
	Fixed	operator--( int );

	int		getRawBits( void ) const;
	int		toInt( void ) const;
	float	toFloat( void ) const;
	void	setRawBits( int const raw);
	static Fixed &min(Fixed &ref1, Fixed &ref2);
	static Fixed &max(Fixed &ref1, Fixed &ref2);
	static const Fixed &min(const Fixed &ref1, const Fixed &ref2);
	static const Fixed &max(const Fixed &ref1, const Fixed &ref2);

};

std::ostream & operator<<( std::ostream & output, Fixed const & input );

#endif
