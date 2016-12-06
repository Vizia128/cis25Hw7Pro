#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
using namespace std;

//add virtual function for area and perimiter
//add class rectangle

class Rectangle;

class Circle : public Shape {
public:
	Circle();
	Circle(int, int, int);
	Circle(const Point&, const Fraction&);
	Circle(const Fraction&, const Fraction&, const Fraction&);
	Circle(const Circle&);

	Point getCenter();
	Fraction getRadius();

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
	double overlapArea(const Circle&)const;

	const char* getType()const;
	friend std::ostream& operator<<(std::ostream &out, const Circle &C);
protected:
	void printMyself(std::ostream& out)const;
private:
	Point *cPtr;
	Fraction *rPtr;
};


#endif