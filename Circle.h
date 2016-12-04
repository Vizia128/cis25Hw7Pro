#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
using namespace std;

//add virtual function for area and perimiter
//add class rectangle

class Circle : public Shape {
public:
	Circle();
	Circle(int, int, int);
	Circle(const Point&, const Fraction&);
	Circle(const Fraction&, const Fraction&, const Fraction&);
	Circle(const Circle&);

	void moveBy();
	
	Point getLocation()const;
	Fraction getRadius()const;
	int overlap(const Circle&)const;
	double overlappingArea(const Circle&)const;
	void combine(const Circle&)const;

	double area()const;
	double perimiter()const;

	Circle operator=(const Circle&);
	Circle operator+(const Point&);
	Circle operator-(const Point&);
	Circle operator*(const Fraction&);
	Circle operator/(const Fraction&);
	
//	friend std::ostream& operator<<(std::ostream &out, const Circle &C);

protected:
	virtual void printMyself(std::ostream& out) const {
		out << "(x : " << cPtr->getFrx()
			<< ", y : " << cPtr->getFry()
			<< ", r : " << *rPtr << ")";
	}

private:
	Point *cPtr;
	Fraction *rPtr;

};
#endif