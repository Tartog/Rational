#ifndef Rational_H
#define Rational_H

class Rational
{
private:
	int numerator = 0;
	int denominator = 1;
	int sign = 1;
public:
	Rational(int numerator, int denominator, int sign);
	Rational(const Rational &h);
	Rational();
	~Rational();
	void print();
	void input();
	void reduction();
	int GetNumerator() const;
	int GetDenominator()const;
	int GetSign()const;
	void SetNumerator(int value_numerator);
	void SetDenominator(int value_denominator);
	void SetSign(int value_sign);
	Rational operator +(const Rational &temp)const;
	Rational operator +=(const Rational &temp);
	Rational operator -(const Rational &temp)const;
	Rational operator -=(const Rational &temp);
	Rational operator *(const Rational &temp)const;
	Rational operator *=(const Rational &other);
	Rational operator /(const Rational &temp)const;
	Rational operator /=(const Rational &temp);
	Rational &operator =(const Rational &h);
	bool operator >(const Rational &temp)const;
	bool operator ==(const Rational &temp)const;
	bool operator <(const Rational &temp)const;
	bool operator !=(const Rational &temp)const;
	bool operator >=(const Rational &temp)const;
	bool operator <=(const Rational &temp)const;
};

#endif