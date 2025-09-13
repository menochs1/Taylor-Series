#include"rational.h"

#include<iostream>

Rational::Rational():Polynomial(){
	Function::setNumOfTerms(0);
}
Rational::Rational(char variable, std::string functionName):Polynomial(){
	Function::setNumOfTerms(1);
	Function::setDefaultVarName(variable);
	Function::setFunctionName(functionName);
	Polynomial numerator;
	Polynomial denominator;
}

Rational::~Rational(){
	numerator.clear();
	denominator.clear();
}

void Rational::addTermToNumOrDenom(bool targetingNum, bool targetingDenom, double coefficient, unsigned short exponent){
	if(!targetingNum && !targetingDenom){
		std::cout << "Error: Specify either numerator or denominator." << std::endl;
		return;
	}
	if(coefficient == 0) return;
	if(exponent < 0) {
		std::cout << "Exponent must be non-negative." << std::endl;
		return;
	}

	if(targetingNum){
		numerator.addTerm(coefficient, exponent);
	}
	if(targetingDenom){
		denominator.addTerm(coefficient, exponent);
	}
}

void Rational::removeTerm(bool targetingNum, bool targetingDenom, unsigned short index){
	if(!targetingNum && !targetingDenom){
		std::cout << "Error: Specify either numerator or denominator." << std::endl;
		return;
	}
	
	if(targetingNum){
		numerator.removeTerm(index);
	}
	if(targetingDenom){
		denominator.removeTerm(index);
	}
}

void Rational::changeTerm(bool targetingNum, bool targetingDenom, unsigned short index, double coefficient, unsigned short exponent){
	if(!targetingNum && !targetingDenom){
		std::cout << "Error: Specify either numerator or denominator." << std::endl;
		return;
	}
	if(coefficient == 0){
		if(targetingNum){
			numerator.removeTerm(index);
		}
		if(targetingDenom){
			denominator.removeTerm(index);
		}
		return;
	}
	if(targetingNum){
		numerator.changeTerm(index, coefficient, exponent);
	}
	if(targetingDenom){
		denominator.changeTerm(index, coefficient, exponent);
	}
}

double Rational::evaluate(double variableValue){
	double denomValue = denominator.evaluate(variableValue);
	if(denomValue == 0){
		std::cout << "Error: Division by zero in rational function evaluation." << std::endl;
		return NULL; // or handle error as appropriate
	}
	return numerator.evaluate(variableValue) / denomValue;
}

void Rational::clear(){
	numerator.clear();
	denominator.clear();
}

void Rational::print(){
	if (numerator.getNumOfTerms() == 0 && denominator.getNumOfTerms() == 0) {
		std::cout << "The rational has no terms" << std::endl;
		return;
	}

	std::cout << getFunctionName() << "( " << getDefaultVarName() << " ) = ";
	if (numerator.getNumOfTerms() > 0) {
		std::cout << "[";
		for (unsigned short i = 0; i < numerator.getNumOfTerms(); i++)
		{
			std::cout << numerator.getTerm(i).coefficient << "*" << getDefaultVarName() << "^("
				<< numerator.getTerm(i).exponent << ")";
			if (i < numerator.getNumOfTerms() - 1) std::cout << " + ";
		}
		std::cout << "]";
	}
	if (denominator.getNumOfTerms() > 0) {
		std::cout << " / [";
		for (unsigned short i = 0; i < denominator.getNumOfTerms(); i++)
		{
			std::cout << denominator.getTerm(i).coefficient << "*(" << getDefaultVarName() << ")^("
				<< denominator.getTerm(i).exponent << ")";
			if (i < denominator.getNumOfTerms() - 1) std::cout << " + ";
		}
		std::cout << "]" << std::endl;
	}
}