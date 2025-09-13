#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<vector>
#include"Function.h"


class Polynomial : public Function{
public:
    
private:
    struct term{
        double coefficient;
        double variable;
        unsigned short exponent;
    };

    std::vector<term> terms;
};

#endif