#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class Fraction {
public:

	Fraction();
	Fraction(int);
	Fraction(int, int);
	Fraction(const Fraction&);


	void print()const;
	~Fraction();
	int getNum()const;
	int getDenom()const;

	void update(int);
	void reduce();
	double sqroot()const;
	
	Fraction add(const Fraction&)const;
	Fraction subtract(const Fraction&)const;
	Fraction multiply(const Fraction&)const;
	Fraction divide(const Fraction&)const;

	
	friend	Fraction add(const Fraction&, const Fraction&);
	friend	Fraction subtract(const Fraction&, const Fraction&);
	friend	Fraction multiply(const Fraction&, const Fraction&);
	friend	Fraction divide(const Fraction&, const Fraction&);


	Fraction operator=(const Fraction&);
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);

	Fraction operator+=(const Fraction&);
	Fraction operator-=(const Fraction&);
	Fraction operator*=(const Fraction&);
	Fraction operator/=(const Fraction&);

	bool operator==(const Fraction&)const;
	bool operator<(const Fraction&)const;
	bool operator>(const Fraction&)const;
	bool operator<=(const Fraction&)const;
	bool operator>=(const Fraction&)const;

	Fraction operator=(const int);
	Fraction operator+(const int);
	Fraction operator-(const int);
	Fraction operator*(const int);
	Fraction operator/(const int);

	operator double();


	friend std::ostream& operator<<(std::ostream &out, const Fraction &F);
//	friend std::ostream& operator>>(std::ostream &in, const Fraction &F);
	friend void print(const Fraction&, const Fraction&, const Fraction&);

private:
	int num;
	int denom;

};




//std::ostream& operator>>(std::ostream &in, const Fraction &F) {
//	cout << "\n  Enter the numerator : ";
//	in >> F.num;
//	cout << "\n  Enter the denominator : ";
//	in >> F.denom;
//	return in;
//}

#endif

