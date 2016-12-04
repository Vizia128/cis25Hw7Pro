#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;


class Shape {
public:
	virtual void moveBy() {};

	virtual Point getLocation()const { return 1; };
	virtual Fraction getRadius()const { return 1; };
	virtual int overlap(const Shape&)const { return 1; };
	virtual double overlappingArea(const Shape&)const { return 1; };
	virtual void combine(const Shape&)const {};

	virtual double area()const { return 1; };
	virtual double perimiter()const { return 1; };

	//Shape virtual operator=(const Shape&) = 0;
	//Shape virtual operator+(const Shape&) = 0;
	//Shape virtual operator-(const Shape&) = 0;
	//Shape virtual operator*(const Shape&) = 0;
	//Shape virtual operator/(const Shape&) = 0;

	friend std::ostream& operator<<(std::ostream &out, const Shape &S) {
		S.printMyself(out);
		return out;
	}
protected:
	virtual void printMyself(std::ostream& out) const {};
};




#endif
