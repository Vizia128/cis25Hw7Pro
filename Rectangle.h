#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Shape.h"
using namespace std;

class Circle;

class Rectangle : public Shape {
public:
	Rectangle();
	Rectangle(int, int, int, int);
	Rectangle(const Point&, const Fraction&, const Fraction&);
	Rectangle(const Fraction&, const Fraction&, const Fraction&, const Fraction&);
	Rectangle(const Rectangle&);

	Point getPoint();

	void moveByX(char);
	void moveByY(char);

	int overlapType(const Shape&)const;
	int overlapType(const Rectangle&)const;
	int overlapType(const Circle&)const;

	void overlapArea(const Shape&)const;
	void overlapArea(const Rectangle&)const;
	void overlapArea(const Circle&)const;
	
	const char* getType()const;
	friend std::ostream& operator<<(std::ostream &out, const Rectangle &C);
protected:
	void printMyself(std::ostream& out)const;
private:
	Point *cPtr;
	Fraction *lPtr;
	Fraction *wPtr;

};


#endif
