// Exercise 10.10 RationalNumber.h
// RationalNumber skeletal class definition.
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
public:
	explicit RationalNumber(int = 0, int = 1); // default constructor
	RationalNumber operator+(const RationalNumber &); // addition
	RationalNumber operator-(const RationalNumber &); // Subtraction
	RationalNumber operator*(const RationalNumber &); // Multiplication
	RationalNumber operator/(const RationalNumber &); //Division
													  // relational operators
	bool operator<(const RationalNumber &) const;
	bool operator>(const RationalNumber &) const;
	bool operator<=(const RationalNumber &) const;
	bool operator>=(const RationalNumber &) const;
	// equality operators
	bool operator==(const RationalNumber &) const;
	bool operator!=(const RationalNumber &) const;


	void printRational() const; // display rational number
private:
	int numerator; 	// private variable numerator
	int denominator; // private variable denominator
	void reduce(); 	// function for fraction reduction
}; // end class RationalNumber

#endif#pragma once
