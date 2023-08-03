#include "Fixed.hpp"

Fixed::Fixed(void): _fixedNum( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedNum = src._fixedNum;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
		this->_fixedNum = ref.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedNum;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedNum = raw;
}
