#include "Fixed.hpp"
#include "Point.hpp"
#include <cassert>

bool checkTriangle(Point const &a, Point const &b, Point const &c);
bool bsp(Point const a, Point const b, Point const c, Point const point);

void test_triangle_area_zero_for_colinear_points() {
    Point a(0.0f, 0.0f);
    Point b(1.0f, 1.0f);
    Point c(2.0f, 2.0f); // Colinear with a and b
    assert(checkTriangle(a, b, c) == false);
    std::cout << "\033[32mtest_triangle_area_zero_for_colinear_points passed\033[0m\n";
}

void test_triangle_area_nonzero_for_valid_triangle() {
    Point a(0.0f, 0.0f);
    Point b(-1.0f, 0.0f);
    Point c(0.0f, 10.0f);
    assert(checkTriangle(a, b, c) == true);
    std::cout << "\033[32mtest_triangle_area_nonzero_for_valid_triangle passed\033[0m\n";
}

void test_triangle_area_zero_for_identical_points() {
    Point a(1.0f, 1.0f);
    Point b(1.0f, 1.0f);
    Point c(1.0f, 1.0f);
    assert(checkTriangle(a, b, c) == false);
    std::cout << "\033[32mtest_triangle_area_zero_for_identical_points passed\033[0m\n";
}

void test_bsp(void)
{
	// Triangle vertices
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(0.0f, 4.0f);

	// Point inside the triangle
	Point inside(1.0f, 1.0f);
	assert(bsp(a, b, c, inside) == true);

	// Point outside the triangle
	Point outside(5.0f, 5.0f);
	assert(bsp(a, b, c, outside) == false);

	// Point on the edge of the triangle
	Point on_edge(2.0f, 0.0f);
	assert(bsp(a, b, c, on_edge) == true);

	// Point at a vertex of the triangle
	Point at_vertex(0.0f, 0.0f);
	assert(bsp(a, b, c, at_vertex) == true);

	std::cout << "\033[32mtest_bsp passed\033[0m\n";
}

void    run_tests(void)
{
    test_triangle_area_zero_for_colinear_points();
    test_triangle_area_nonzero_for_valid_triangle();
    test_triangle_area_zero_for_identical_points();
	test_bsp();
}

int main(void)
{
    Point a(-7.0f, 4.5f);
    Point b(1.0f, 0.0f);
    Point c(3.0f, 5.0f);
    Point point(-0.5f, 2.2f);

    if (!checkTriangle(a, b, c))
    {
        std::cout << "Passed points don't form a triangle!" << std::endl;
        return (1);
    }
    if (!bsp(a, b, c, point))
        std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is outside the passed triangle!" << std::endl;
    else
        std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is inside the passed triangle!" << std::endl;
	
	// run_tests();
    return (0);
}
