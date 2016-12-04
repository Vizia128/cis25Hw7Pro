#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Shape.h"
using namespace std;


class Rectangle : Shape {
public:
	Rectangle();
	Rectangle(int, int, int, int);
	Rectangle(const Point&, const Fraction&, const Fraction&);
	Rectangle(const Fraction&, const Fraction&, const Fraction&, const Fraction&);
	Rectangle(const Rectangle&);

	void moveBy();

	Point getLocation()const;
	Fraction getLength()const;
	Fraction getHeight()const;
	int overlap(const Rectangle&)const;
//	double overlappingArea(const Rectangle&)const;
	Fraction area()const;
	Fraction perimiter()const;

	void combine(const Rectangle&)const;

	Rectangle operator=(const Rectangle&);
	Rectangle operator+(const Point&);
	Rectangle operator-(const Point&);
	Rectangle operator*(const Fraction&);
	Rectangle operator/(const Fraction&);


	friend std::ostream& operator<<(std::ostream &out, const Fraction &C);

private:
	Point *cPtr;
	Fraction *lPtr;
	Fraction *hPtr;

};


#endif
