#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointNum( 0 ){}

Fixed::Fixed(int const num): _fixedPointNum (num << _bitNum){}

Fixed::Fixed(float const num): _fixedPointNum (roundf(num * (1 << _bitNum))){}

Fixed::Fixed( Fixed const & src ): _fixedPointNum(0)
{
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & ref)
{
	if (this != &ref)
		this->_fixedPointNum = ref.getRawBits();
	return *this;
}

Fixed::~Fixed(){}

int	Fixed::getRawBits( void ) const
{
	return this->_fixedPointNum;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointNum = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_fixedPointNum / (float)(1 << _bitNum)));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointNum >> _bitNum);
}

std::ostream &operator<<(std::ostream &output, Fixed const &input)
{
	output << input.toFloat();
	return (output);
}

bool	Fixed::operator>(const Fixed &ref) const
{
	return(this->getRawBits() > ref.getRawBits());
}

bool	Fixed::operator<(const Fixed &ref) const
{
	return(this->getRawBits() < ref.getRawBits());
}

bool	Fixed::operator>=(const Fixed &ref) const
{
	return(this->getRawBits() >= ref.getRawBits());
}

bool	Fixed::operator<=(const Fixed &ref) const
{
	return(this->getRawBits() <= ref.getRawBits());
}

bool	Fixed::operator==(const Fixed &ref) const
{
	return(this->getRawBits() == ref.getRawBits());
}

bool	Fixed::operator!=(const Fixed &ref) const
{
	return(this->getRawBits() != ref.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &ref) const
{
	return Fixed(this->getRawBits() + ref.getRawBits());
}

Fixed	Fixed::operator-(const Fixed &ref) const
{
	return Fixed(this->getRawBits() - ref.getRawBits());
}

Fixed	Fixed::operator*(const Fixed &ref) const
{
	return Fixed (this->toFloat() * ref.toFloat());
}

Fixed	Fixed::operator/(const Fixed &ref) const
{
	return Fixed (this->toFloat() / ref.toFloat());
}

Fixed	&Fixed::operator++( void )
{
	this->_fixedPointNum += 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	res( *this );
	res._fixedPointNum = this->_fixedPointNum;
	this->_fixedPointNum += 1;
	return (res);
}

Fixed	&Fixed::operator--( void )
{
	this->_fixedPointNum -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	res( *this );
	res._fixedPointNum = this->_fixedPointNum;
	this->_fixedPointNum -= 1;
	return (res);
}

Fixed	&Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1.getRawBits() < ref2.getRawBits())
		return ref1;
	else
		return ref2;
}

const Fixed	&Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.getRawBits() < ref2.getRawBits())
		return ref1;
	else
		return ref2;
}

Fixed	&Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1.getRawBits() > ref2.getRawBits())
		return ref1;
	else
		return ref2;
}

const Fixed	&Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.getRawBits() > ref2.getRawBits())
		return ref1;
	else
		return ref2;
}

