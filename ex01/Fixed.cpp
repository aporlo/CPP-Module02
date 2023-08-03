#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointNum( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num): _fixedPointNum (num << _bitNum)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const num): _fixedPointNum (roundf(num * (1 << _bitNum)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ): _fixedPointNum(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
		this->_fixedPointNum = ref.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}



int	Fixed::getRawBits( void ) const
{
	return this->_fixedPointNum;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Default constructor called" << std::endl;
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