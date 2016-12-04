#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Shape.h"
using namespace std;


class Rectangle : virtual public Shape {
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
	double area()const;
	double perimiter()const;

	void combine(const Rectangle&)const;

	Rectangle operator=(const Rectangle&);
	Rectangle operator+(const Point&);
	Rectangle operator-(const Point&);
	Rectangle operator*(const Fraction&);
	Rectangle operator/(const Fraction&);

	//friend std::ostream& operator<<(std::ostream &out, const Rectangle &R);

protected:
	virtual void printMyself(std::ostream& out) const {
		out << "Center : " << *cPtr
			<< ", Length : " << *lPtr
			<< ", Height : " << *hPtr;
	}
private:
	Point *cPtr;
	Fraction *lPtr;
	Fraction *hPtr;

};


#endif
