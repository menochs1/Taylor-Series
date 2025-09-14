#include"polynomial.h"
#include<iostream>

Polynomial::Polynomial():Function(){
	setNumOfTerms(0);
}

Polynomial::Polynomial(char variable, std::string functionName):Function(){
	setNumOfTerms(0);
	setDefaultVarName(variable);
	setFunctionName(functionName);
}

Polynomial::~Polynomial(){
	this->terms.clear();
}

void Polynomial::addTerm(double coefficient, unsigned short exponent){
	if (coefficient == 0) return;
	if (exponent < 0) {
		std::cout << "Exponent must be non-negative." << std::endl;
		return;
	}
	
	term newTerm;
	newTerm.coefficient = coefficient;
	newTerm.variable = getDefaultVarName();
	newTerm.exponent = exponent;
	this->terms.push_back(newTerm);
	setNumOfTerms(getNumOfTerms() + 1);
}

void Polynomial::removeTerm(unsigned short index){
	if(index < getNumOfTerms()){
		this->terms.erase(this->terms.begin() + index);
		setNumOfTerms(getNumOfTerms() - 1);
	}
}

void Polynomial::changeTerm(unsigned short index, double coefficient, unsigned short exponent){
	if(coefficient == 0){
		this->removeTerm(index);
		return;
	}

	if(index < getNumOfTerms()){
		this->terms[index].coefficient = coefficient;
		this->terms[index].exponent = exponent;
	}
}

double Polynomial::evaluate(double variableValue){
	double result = 0.0;
	for(unsigned short i = 0; i < getNumOfTerms(); i++){
		result += this->terms[i].coefficient * power(variableValue, this->terms[i].exponent);
	}
	return result;
}

void Polynomial::clear(){
	this->terms.clear();
	setNumOfTerms(0);
}

void Polynomial::print(){
	if(getNumOfTerms() == 0){
		std::cout << "The polynomial has no terms." << std::endl;
		return;
	}
	std::cout << getFunctionName() << "(" << getDefaultVarName() << ") = ";
	for(unsigned short i = 0; i < getNumOfTerms(); i++){
		std::cout << this->terms[i].coefficient << "*("  << this->terms[i].variable << ")" << "^(" << this->terms[i].exponent << ")";
		if(i < getNumOfTerms() - 1) {
			if (this->terms[i].coefficient < 0)
			{
				std::cout << " - ";
			}
			else {
				std::cout << " + ";
			}
		}
	}
	std::cout << std::endl;
}

Polynomial::term Polynomial::getTerm(unsigned short index) const {
	if(index < getNumOfTerms()){
		return this->terms[index];
	}
	std::cerr << "Index out of bounds. Returning default term." << std::endl;
	return term(); // Return a default term if index is out of bounds.
}