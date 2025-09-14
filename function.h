#ifndef FUNCTION_H
#define FUNCTION_H

#include<string> 

class Function{
public:
    Function();
    ~Function();
    virtual void addTerm(double coefficient, double variableValue, unsigned short exponent);
    virtual void removeTerm(unsigned short index);
    virtual void changeTerm(unsigned short index, double coefficient, double variable, unsigned short exponent);
    double power(double base, unsigned short exponent);
    virtual void clear();
    virtual void print();

    struct term {
        double coefficient = 0.0;
        double variableValue = 0.0;
        char variable = 'x'; 
        unsigned short exponent = 0;
    };

    //accessors
	std::string getFunctionName() const { return this->functionName; }
	unsigned short getNumOfTerms() const { return this->numOfTerms; }
	char getDefaultVarName() const { return this->DEFAULT_VAR_NAME; }

    //mutators
    void setFunctionName(const std::string name) { this->functionName = name; }
    void setDefaultVarName(char varName) { this->DEFAULT_VAR_NAME = varName; }
    void setNumOfTerms(unsigned short num) { this->numOfTerms = num; }
    
private:
    char DEFAULT_VAR_NAME;
    std::string functionName;
    unsigned short numOfTerms;
};

#endif