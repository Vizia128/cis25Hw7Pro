#include <iostream>
#include <ostream>
#include "Fraction.h"
#include "FractionUtility.h"
using namespace std;


Fraction::Fraction() : num(0), denom(1) {}
Fraction::Fraction(int n) : num(n), denom(1) {}
Fraction::Fraction(int n, int d) : num(d < 0? -n : n), denom(d < 0? -d : d) {}
Fraction::Fraction(const Fraction& ref) : num(ref.num), denom(ref.denom) {}


void Fraction::print()const {
	if (denom != 1)
		cout << num << "/" << denom;
	else
		cout << num;
}

int Fraction::getNum()const {
	return num;
}

int Fraction::getDenom()const {
	return denom;
}

void Fraction::update(int del) {
	num += denom * del;
	reduce();
}


void Fraction::reduce() {
//	cout << "\nA call to reduce(Fraction) was made to reduce the Fraction!\n";
	int GCD = -1;
	int tempNum = num < 0 ? -num : num;
	GCD = GreatestCommonDivisor(tempNum, denom);
	num /= GCD;
	denom /= GCD;
}



Fraction Fraction::add(const Fraction& f1)const {
	cout << "\nA call to add(Fraction) was made to add the Fractions!\n";
	return Fraction(num * f1.denom + denom * f1.num,
		denom * f1.denom);
}

Fraction Fraction::subtract(const Fraction& f1)const {
	cout << "\nA call to subtract(Fraction) was made to subtract the Fractions!\n";
	return Fraction(num * f1.denom - denom * f1.num,
		denom * f1.denom);
}

Fraction Fraction::multiply(const Fraction& f1)const {
	cout << "\nA call to multiply(Fraction) was made to multiply the Fractions!\n";
	return Fraction(f1.num * num, f1.denom * denom);
}

Fraction Fraction::divide(const Fraction& f1)const {
	cout << "\nA call to divide(Fraction) was made to divide the Fractions!\n";
	return Fraction(num * f1.denom, denom * f1.num);
}



Fraction add(const Fraction& f1, const Fraction& f2) {
	cout << "\nA call to add(Fraction, Fraction) was made to add the Fractions!\n";
	return Fraction(f2.num * f1.denom + f2.denom * f1.num,
		f2.denom * f1.denom);
}

Fraction subtract(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.num * f2.denom - f1.denom * f2.num,
		f2.denom * f1.denom);
}

Fraction multiply(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.num * f2.num, f1.denom * f2.denom);
}

Fraction divide(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.num * f2.denom, f1.denom * f2.num);
}




Fraction::~Fraction() {
//	cout << "\n Calling ~Fraction()";
}




Fraction Fraction::operator=(const Fraction& f) {
	num = f.num;
	denom = f.denom;
	return Fraction(num, denom);
}

Fraction Fraction::operator+(const Fraction& f) {
//	cout << "\nA call to add(Fraction) was made to add the Fractions!\n";
	return Fraction(num * f.denom + denom * f.num,
		denom * f.denom);
}

Fraction Fraction::operator-(const Fraction& f) {
//	cout << "\nA call to subtract(Fraction) was made to subtract the Fractions!\n";
	return Fraction(num * f.denom - denom * f.num,
		denom * f.denom);
}

Fraction Fraction::operator*(const Fraction& f) {
//	cout << "\nA call to multiply(Fraction) was made to multiply the Fractions!\n";
	return Fraction(num * f.num, denom * f.denom);
}

Fraction Fraction::operator/(const Fraction& f) {
//	cout << "\nA call to divide(Fraction) was made to divide the Fractions!\n";
	return Fraction(num * f.denom, denom * f.num);
}





Fraction Fraction::operator+=(const Fraction& f) {
	num = num * f.denom + denom * f.num;
	denom = denom * f.denom;
	return Fraction(num, denom);
}

Fraction Fraction::operator-=(const Fraction& f) {
	num = num * f.denom - denom * f.num;
	denom = denom * f.denom;
	return Fraction(num, denom);
}

Fraction Fraction::operator*=(const Fraction& f) {
	num *= f.num;
	denom *= f.denom;
	return Fraction(num, denom);
}

Fraction Fraction::operator/=(const Fraction& f) {
	num *= f.denom;
	denom *= f.num;
	return Fraction(num, denom);
}



Fraction Fraction::operator=(const int f) {
	num = f;
	denom = 1;
	return Fraction(num, denom);
}

Fraction Fraction::operator+(const int f) {
	return Fraction(num + denom * f,
		denom);
}

Fraction Fraction::operator-(const int f) {
	return Fraction(num  - denom * f,
		denom);
}

Fraction Fraction::operator*(const int f) {
	return Fraction(num * f, denom);
}

Fraction Fraction::operator/(const int f) {
	return Fraction(num, denom * f);
}



std::ostream& operator<<(std::ostream &out, const Fraction &F) {
	if (F.denom != 1)
		out << F.num << "/" << F.denom;
	else
		out << F.num;
	return out;
}

void print(const Fraction& lf, const Fraction& rf, const Fraction& result) {
	cout << "\n      (" << lf.num << "/" << lf.denom << ", "
		<< rf.num << "/" << rf.denom << ", "
		<< result.num << "/" << result.denom << ")";
}






