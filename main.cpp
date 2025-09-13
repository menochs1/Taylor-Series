#include <iostream>
#include "polynomial.h"
#include "rational.h"
#include "function.h"
#include <vector>

int main() {
	// Create a Polynomial object
	std::cout << "Testing Polynomial Class" << std::endl;
	Polynomial poly('x', "Poly_Func");
	poly.addTerm(3, 2); // 3 * x^2
	poly.addTerm(4, 1); // 4 * x^1
	poly.addTerm(-5, 0); // -5 * x^0
	std::cout << "Polynomial: ";
	poly.print(); // Expected output: 3 * x^2 + 4 * x^1 - 5 * x^0
	std::cout << std::endl;
	// Modify a term in the polynomial
	poly.changeTerm(1, 2, 1); // Change second term to 2 * x^1
	std::cout << "Modified Polynomial: ";
	poly.print(); // Expected output: 3 * x^2 + 2 * x^1 - 5 * x^0
	std::cout << std::endl;
	// Remove a term from the polynomial
	poly.removeTerm(2); // Remove third term
	std::cout << "After Removing Term: ";
	poly.print(); // Expected output: 3 * x^2 + 2 * x^1
	std::cout << std::endl;
	// Clear all terms from the polynomial
	poly.clear();
	std::cout << "After Clearing Terms: ";
	poly.print(); // Expected output: (no output)
	std::cout << std::endl;

	// Create a Rational object
	std::cout << "Testing Rational Class" << std::endl;
	Rational rat('y', "Rat_Func");
	rat.addTermToNumOrDenom(true, false, 1, 1); // Numerator: 1 * y^1
	rat.addTermToNumOrDenom(true, false, -1, 0); // Numerator: -1 * y^0
	rat.addTermToNumOrDenom(false, true, 1, 1); // Denominator: 1 * y^1
	rat.addTermToNumOrDenom(false, true, 1, 0); // Denominator: 1 * y^0
	std::cout << "Rational Function: ";
	rat.print(); // Expected output: (1 * y^1 - 1 * y^0) / (1 * y^1 + 1 * y^0)
	std::cout << std::endl;
	// Modify a term in the numerator
	rat.changeTerm(true, false, 0, 2, 1); // Change first term in numerator to 2 * y^1
	std::cout << "Modified Rational Function: ";
	rat.print(); // Expected output: (2 * y^1 - 1 * y^0) / (1 * y^1 + 1 * y^0)
	std::cout << std::endl;
	// Remove a term from the denominator
	rat.removeTerm(false, true, 1); // Remove second term in denominator
	std::cout << "After Removing Term from Denominator: ";
	rat.print(); // Expected output: (2 * y^1 - 1 * y^0) / (1 * y^1)
	std::cout << std::endl;
	// Clear all terms from the rational function
	rat.clear();
	std::cout << "After Clearing Terms: ";
	rat.print(); // Expected output: (no output)
	std::cout << std::endl;
	return 0;
}