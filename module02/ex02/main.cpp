#include <iostream>
#include <sstream>
#include <iomanip>
#include "Fixed.hpp"

// Compatibility-friendly version of to_string for int
std::string to_string_compat(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// Compatibility-friendly version of to_string for float
std::string to_string_compat(float value, int precision = 4) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    return oss.str();
}

void printTest(const std::string& desc, const std::string& expected, const std::string& actual) {
    std::cout << desc << " | Expected: " << expected << " | Got: " << actual << std::endl;
}

void test_basic_values() {
    std::cout << "\n== BASIC VALUE TESTS ==" << std::endl;

    Fixed a(12);
    Fixed b(12.0133f);
    Fixed c(-5.75f);

    printTest("a.toInt()", "12", to_string_compat(a.toInt()));
    printTest("a.toFloat()", "12.0000", to_string_compat(a.toFloat()));

    printTest("b.toInt()", "12", to_string_compat(b.toInt()));
    printTest("b.toFloat()", "12.0133", to_string_compat(b.toFloat(), 4));

    printTest("c.toInt()", "-5", to_string_compat(c.toInt()));
    printTest("c.toFloat()", "-5.7500", to_string_compat(c.toFloat(), 4));
}

void test_arithmetic_operations() {
    std::cout << "\n== ARITHMETIC OPERATORS TEST (INT & FLOAT) ==" << std::endl;

    Fixed a(12.0133f);
    Fixed b(2.5f);

    Fixed sum = a + b;
    Fixed diff = a - b;
    Fixed prod = a * b;
    Fixed quot = a / b;

    printTest("a + b", "14.5133", to_string_compat(sum.toFloat(), 4));
    printTest("a - b", "9.5133", to_string_compat(diff.toFloat(), 4));
    printTest("a * b", "30.0333", to_string_compat(prod.toFloat(), 4));
    printTest("a / b", "4.8053", to_string_compat(quot.toFloat(), 4));
}

void test_comparisons() {
    std::cout << "\n== COMPARISON TESTS WITH FLOATS ==" << std::endl;

    Fixed x(0.1f);
    Fixed y(0.10001f);
    Fixed z(0.1f);

    printTest("x < y", "1", x < y ? "1" : "0");
    printTest("x > y", "0", x > y ? "1" : "0");
    printTest("x == z", "1", x == z ? "1" : "0");
    printTest("x != y", "1", x != y ? "1" : "0");
}

void test_toInt_and_toFloat_rounding() {
    std::cout << "\n== ROUNDING TESTS (toInt vs toFloat) ==" << std::endl;

    Fixed a(3.99f);
    Fixed b(3.01f);
    Fixed c(3.50f);

    printTest("a.toInt()", "3", to_string_compat(a.toInt()));
    printTest("b.toInt()", "3", to_string_compat(b.toInt()));
    printTest("c.toInt()", "3", to_string_compat(c.toInt()));
    printTest("a.toFloat()", "3.9900", to_string_compat(a.toFloat(), 4));
    printTest("b.toFloat()", "3.0100", to_string_compat(b.toFloat(), 4));
    printTest("c.toFloat()", "3.5000", to_string_compat(c.toFloat(), 4));
}

void test_output_operator() {
    std::cout << "\n== OUTPUT STREAM OPERATOR TEST ==" << std::endl;
    Fixed a(12.0133f);
    std::ostringstream oss;
    oss << a;
    std::string out = oss.str();

    std::cout << "Operator << : Expected approx: 12.0133 | Got: " << out << std::endl;
}

void test_min_max() {
    std::cout << "\n== MIN/MAX STATIC FUNCTION TESTS ==" << std::endl;
    Fixed a(3.5f);
    Fixed b(7.25f);
    Fixed c(-2.0f);

    // Non-const min/max
    Fixed &min_ab = Fixed::min(a, b);
    Fixed &max_ab = Fixed::max(a, b);
    Fixed &min_bc = Fixed::min(b, c);
    Fixed &max_bc = Fixed::max(b, c);

    printTest("min(a, b)", "3.5000", to_string_compat(min_ab.toFloat(), 4));
    printTest("max(a, b)", "7.2500", to_string_compat(max_ab.toFloat(), 4));
    printTest("min(b, c)", "-2.0000", to_string_compat(min_bc.toFloat(), 4));
    printTest("max(b, c)", "7.2500", to_string_compat(max_bc.toFloat(), 4));

    // Const min/max
    const Fixed ca(1.1f);
    const Fixed cb(2.2f);
    const Fixed cc(-3.3f);

    const Fixed &cmin_ab = Fixed::min(ca, cb);
    const Fixed &cmax_ab = Fixed::max(ca, cb);
    const Fixed &cmin_bc = Fixed::min(cb, cc);
    const Fixed &cmax_bc = Fixed::max(cb, cc);

    printTest("min(ca, cb)", "1.1000", to_string_compat(cmin_ab.toFloat(), 4));
    printTest("max(ca, cb)", "2.2000", to_string_compat(cmax_ab.toFloat(), 4));
    printTest("min(cb, cc)", "-3.3000", to_string_compat(cmin_bc.toFloat(), 4));
    printTest("max(cb, cc)", "2.2000", to_string_compat(cmax_bc.toFloat(), 4));
}

void	run_tests(void)
{
	test_basic_values();
    test_arithmetic_operations();
    test_comparisons();
    test_toInt_and_toFloat_rounding();
    test_output_operator();
	test_min_max();
}

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

    // run_tests();
    return 0;
}
