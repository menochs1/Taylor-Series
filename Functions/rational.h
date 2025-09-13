#ifndef RATIONAL_H
#define RATIONAL_H

#include<vector>
#include"Polynomial.h"
#include"Function.h"

class Rational : public Function, public Polynomial{
public:

private:
    struct term{
        Polynomial numerator;
        Polynomial denominator;
    };

    std::vector<term> terms;
};

#endif