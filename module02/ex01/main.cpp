#include "Fixed.hpp"
#include <iomanip>

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	// float num = 0.1f + 0.2f;
	// Fixed e(num);
	// std::cout << "(fixed point) e is " << e << std::endl;
	// std::cout << "(floating point) e is " << std::setprecision(10) << num << std::endl;

	// float x = num * 100000000; // 300 000 000
	// Fixed f(x);
	// std::cout << "(fixed point) e is " << f << std::endl;
	// std::cout << "(floating point) e is " << x << std::endl;
	return 0;
}