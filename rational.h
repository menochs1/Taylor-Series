#ifndef RATIONAL_H
#define RATIONAL_H

#include<vector>
#include"polynomial.h"
#include"function.h"

class Rational : public Polynomial{
public:
	Rational();
	Rational(char variable, std::string functionName);
    ~Rational();
	void addTermToNumOrDenom(bool targetingNum, bool targetingDenom, double coefficient, unsigned short exponent);
	void removeTerm(bool targetingNum, bool targetingDenom, unsigned short index);
	void changeTerm(bool targetingNum, bool targetingDenom, unsigned short index, double coefficient, unsigned short exponent);
	double evaluate(double variableValue);
	void clear();
	void print();
private:
	Polynomial numerator;
	Polynomial denominator;
};

#endif