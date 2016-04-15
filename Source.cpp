// Skeletal RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream> 
#include <stdexcept>
#include "Header.h"
using namespace std;

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n, int d)
{
	numerator = n;

	// validate denominator
	if (d > 0)
		denominator = d;
	else
		invalid_argument("Denominator cannot be 0");

	reduce();     // reduces the fraction
} // end RationalNumber constructor

  // overloaded + operator
RationalNumber RationalNumber::operator+(const RationalNumber &a)
{
	return RationalNumber(
		numerator * a.denominator + denominator * a.numerator,
		denominator * a.denominator);
} // end function operator+

RationalNumber RationalNumber::operator-(const RationalNumber &a)
{
	return RationalNumber(
		numerator * a.denominator - denominator * a.numerator,
		denominator * a.denominator);
} // end function operator-

RationalNumber RationalNumber::operator*(const RationalNumber &a)
{
	return RationalNumber(
		numerator * a.numerator,
		denominator * a.denominator);
} // end function operator*

RationalNumber RationalNumber::operator/(const RationalNumber &a)
{
	return RationalNumber(
		numerator * a.denominator,
		denominator * a.numerator);
} // end function operator/
///////////////////////////END ARITHMETIC////////////////

  // overloaded < operator
bool RationalNumber::operator<(const RationalNumber &lr) const
{
	double thisVal = static_cast< double >(numerator) / denominator;
	double lrVal = static_cast< double >(lr.numerator) / lr.denominator;
	return thisVal < lrVal;
} // end function operator<

  // overloaded > operator
bool RationalNumber::operator>(const RationalNumber &gr) const
{
	return gr < *this;
} // end function operator>

bool RationalNumber::operator<=(const RationalNumber &lr) const
{
	double thisVal = static_cast< double >(numerator) / denominator;
	double lrVal = static_cast< double >(lr.numerator) / lr.denominator;
	return thisVal <= lrVal;
} // end function operator<=

bool RationalNumber::operator>=(const RationalNumber &gr) const
{
	return gr <= *this;
} // end function operator>=

bool RationalNumber::operator==(const RationalNumber &lr) const
{
	double thisVal = static_cast< double >(numerator) / denominator;
	double lrVal = static_cast< double >(lr.numerator) / lr.denominator;
	return thisVal == lrVal;
} // end function operator<=

bool RationalNumber::operator!=(const RationalNumber &eq) const
{
	return !(*this == eq);
} // end function operator!=

  // function printRational definition
void RationalNumber::printRational() const
{
	if (numerator == 0) // print fraction as zero
		cout << numerator;
	else if (denominator == 1) // print fraction as integer
		cout << numerator;
	else
		cout << numerator << '/' << denominator;
} // end function printRational


void RationalNumber::reduce()
{
	int smallest = (numerator < denominator) ? numerator : denominator;

	for (int factor = 2; factor <= smallest; ++factor)
		while (numerator % factor == 0 && denominator % factor == 0)
		{
			numerator /= factor;
			denominator /= factor;
			smallest /= factor;			// Note, we are changing the loop condition here.
		}
} // end function reduce

