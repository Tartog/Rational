#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational(int n, int d, int s){
	sign = s;
	numerator = n;
	denominator = d;
	if (denominator == 0){
		cout << endl << "denominator cannont be 0 !Therefore, it is 1 (default)" << endl;
		denominator = 1;
	}
	reduction();
};
Rational::Rational(){
	numerator = 0;
	denominator = 1;
	sign = 1;
}
Rational::Rational(const Rational &h){
	sign = h.sign;
	numerator = h.numerator;
	denominator = h.denominator;
}
bool Rational::operator >(const Rational &other)const{
	if (this->denominator == other.denominator){
		if (this->sign == other.sign){
			if (this->numerator*this->sign > other.numerator*other.sign){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			if (this->sign == -1){
				return false;
			}
			else{
				return true;
			}
		}
	}
	else{
		if (this->sign == other.sign){
			if (this->numerator * other.denominator * this->sign > other.numerator * this->denominator * other.sign){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			if (this->sign == -1){
				return false;
			}
			else{
				return true;
			}
		}
	}
	return false;
}
bool Rational::operator <(const Rational &other)const{
	if (*this > other){
		return false;
	}
	else{
		if (this->denominator == other.denominator){
			if (this->sign == other.sign){
				if (this->numerator == other.numerator){
					return false;
				}
				else{
					return true;
				}
			}
			else{
				if (this->sign == -1){
					return true;
				}
				else{
					return false;
				}
			}
		}
		else{
			if (this->sign == other.sign){
				if (this->numerator * other.denominator == other.numerator * this->denominator){
					return false;
				}
				else{
					return true;
				}
			}
			else{
				if (this->sign == -1){
					return true;
				}
				else{
					return false;
				}
			}
		}
	}
	return true;
}
bool Rational::operator ==(const Rational &other)const{
	if (*this < other || *this > other){
		return false;
	}
	return true;
}
bool Rational::operator !=(const Rational &other)const{
	return !(*this == other);
}
bool Rational::operator >=(const Rational &other)const{
	return (*this > other || *this == other);
}
bool Rational::operator <=(const Rational &other)const{
	return (*this < other || *this == other);
}
Rational Rational::operator -(const Rational &other)const{
	Rational s(other);
	if (s.sign == -1){
		s.SetSign(1);
	}
	else{
		s.SetSign(-1);
	}
	return *this + s;
}
Rational& Rational::operator =(const Rational &other){
	this->sign = other.sign;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	return *this;
}
void  Rational::print(){
	cout << "numerator = " << numerator << endl;
	cout << "denominator = " << denominator << endl;
	cout << "sign = " << sign << endl;
}
int Rational::GetNumerator() const{
	return numerator;
}
int Rational::GetDenominator() const{
	return denominator;
}
int Rational::GetSign() const{
	return sign;
}
void Rational::SetNumerator(int value_numerator){
	numerator = value_numerator;
}
void Rational::SetDenominator(int value_denominator){
	denominator = value_denominator;
}
void Rational::SetSign(int value_sign){
	sign = value_sign;
}
void Rational::input(){
	cout << "numerator = ";
	cin >> numerator;
	cout << "denomintor = ";
	cin >> denominator;
	if (denominator == 0)
	{
		printf_s("\ndenominator cannont be 0 !Therefore, it is 1 (default)\n");
		denominator = 1;
	}
	if (numerator >= 0 && denominator > 0)
	{
		sign = 1;
	}
	else
	{
		if (numerator < 0 && denominator < 0)
		{
			sign = 1;
			numerator *= -1;
			denominator *= -1;
		}
		else
		{
			if (numerator < 0)
			{
				numerator *= -1;
			}
			else
			{
				denominator *= -1;
			}
			sign = -1;
			if (numerator == 0)
			{
				sign = 1;
			}
		}
	}
	reduction();
}
Rational::~Rational()
{};
Rational Rational::operator +=(const Rational &other)
{
	*this = *this + other;
	return *this;
}
Rational Rational::operator -=(const Rational &other)
{
	*this = *this - other;
	return *this;
}
Rational Rational::operator +(const Rational &other)const
{
	Rational temp;
	if (this->denominator == other.denominator)
	{
		temp.numerator = this->numerator*this->sign + other.numerator*other.sign;
		temp.denominator = this->denominator;
		if (this->numerator > other.numerator)
		{
			temp.sign = this->sign;
		}
		else
		{
			temp.sign = other.sign;
		}
	}
	else
	{
		temp.numerator = this->numerator*this->sign*other.denominator + other.numerator*other.sign*this->denominator;
		temp.denominator = this->denominator * other.denominator;
		if (this->numerator*other.denominator > other.numerator*this->denominator)
		{
			temp.sign = this->sign;
		}
		else
		{
			temp.sign = other.sign;
		}
	}
	if (temp.numerator < 0)
	{
		temp.numerator *= -1;
	}
	temp.reduction();
	if (temp.numerator == 0)
	{
		temp.sign = 1;
	}
	return temp;
}
Rational Rational::operator *(const Rational &other)const
{
	Rational temp;
	temp.numerator = this->numerator * other.numerator;
	temp.denominator = this->denominator * other.denominator;
	temp.reduction();
	if ((this->sign == other.sign) || (temp.numerator == 0))
	{
		temp.sign = 1;
	}
	else
	{
		temp.sign = -1;
	}
	return temp;
}
Rational Rational::operator /(const Rational &other)const
{
	Rational temp;
	temp.numerator = this->numerator * other.denominator;
	temp.denominator = this->denominator * other.numerator;
	temp.reduction();
	if ((this->sign == other.sign) || (temp.numerator == 0))
	{
		temp.sign = 1;
	}
	else
	{
		temp.sign = -1;
	}
	return temp;
}
Rational Rational::operator *=(const Rational &other)
{
	*this = *this * other;
	return *this;
}
Rational Rational::operator /=(const Rational &other)
{
	*this = *this / other;
	return *this;
}
void Rational::reduction()
{
	if (this->denominator != this->numerator && this->numerator != 0)
	{
		int a = this->numerator, b = this->denominator;
		while (a != b)
		{
			if (a > b)
			{
				a = a - b;
			}
			else
			{
				b = b - a;
			}
		}
		this->numerator = this->numerator / a;
		this->denominator = this->denominator / a;
	}
	else
	{
		if (this->numerator != 0)
		{
			this->denominator = this->numerator = 1;
		}
	}
}