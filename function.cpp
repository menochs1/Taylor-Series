#include"function.h"

Function::Function(){
	this->numOfTerms = 0;
	this->DEFAULT_VAR_NAME = 'x';
}

Function::~Function(){
}

void Function::addTerm(double coefficient, double variableValue, unsigned short exponent){
	// Virtual function to be overridden in derived classes
}

void Function::removeTerm(unsigned short index){
	// Virtual function to be overridden in derived classes
}

void Function::changeTerm(unsigned short index, double coefficient, double variable, unsigned short exponent){
	// Virtual function to be overridden in derived classes
}

void Function::clear(){
	// Virtual function to be overridden in derived classes
}

void Function::print(){
	// Virtual function to be overridden in derived classes
}