#include <iostream>
#include "Rational.h"

using namespace std;

int main(){
	Rational a;
	a.input();
	//a.print();
	Rational b;
	b.input();
	//b.print();
	Rational c;
	cout << "res '*'" << endl;
	c = a * b;
	c.print();
	cout << "res '/'" << endl;
	c = a / b;
	c.print();
	cout << "res '+'" << endl;
	c = a + b;
	c.print();
	cout << "res '-'" << endl;
	c = a - b;
	c.print();
	cout << "res '>' - " << (a > b) << endl;
	cout << "res '<' - " << (a < b) << endl;
	cout << "res '==' - " << (a == b) << endl;
	cout << "res '!=' - " << (a != b) << endl;
	cout << "res '>=' - " << (a >= b) << endl;
	cout << "res '<=' - " << (a <= b) << endl;
	Rational d, k, j;
	j *= b;
	cout << "res '*='" << endl;
	j.print();
	k /= a;
	cout << "res '/='" << endl;
	k.print();
	d += a;
	cout << "res '+='" << endl;
	d.print();
	d -= a;
	cout << "res '-='" << endl;
	d.print();
	return 0;
}