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

	Point getCenter();
	Point getLength();
	Point getWidth();

	void moveByX(char);
	void moveByY(char);

	void areaCompare(const Shape&)const;
	void areaCompare(const Rectangle&)const;
	void areaCompare(const Circle&)const;

	void perimeterCompare(const Shape&)const;
	void perimeterCompare(const Rectangle&)const;
	void perimeterCompare(const Circle&)const;

	int overlapType(const Shape&)const;
	int overlapType(const Rectangle&)const;
	int overlapType(const Circle&)const;

	void overlapShape(const Shape&)const;
	void overlapShape(const Rectangle&)const;
	void overlapShape(const Circle&)const;
	
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
