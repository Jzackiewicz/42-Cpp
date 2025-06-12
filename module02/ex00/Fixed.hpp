#pragma once

#include <iostream>
#include <string>

class Fixed
{
	private:
		int	_value;
		int _binaryPointPosition;

	public:
		Fixed(void);
		Fixed(const Fixed& obj);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
