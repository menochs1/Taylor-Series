// Move the definition of struct term outside the class and before its usage

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <string>
#include "function.h"

class Polynomial : public Function {
public:
    Polynomial();
    Polynomial(char variable, std::string functionName); // Constructor with variable character
    ~Polynomial();
    void addTerm(double coefficient, unsigned short exponent);
    void removeTerm(unsigned short index);
    void changeTerm(unsigned short index, double coefficient, unsigned short exponent);
    double evaluate(double variableValue);
    void clear();
    void print();

    //accessors
    term getTerm(unsigned short index) const;
private:
    std::vector<term> terms;
};

#endif