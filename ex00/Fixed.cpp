#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointNum( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ): _fixedPointNum(0)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointNum = src.getRawBits();
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNum;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointNum = raw;
}
