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
	friend std::ostream& operator<<(std::ostream &out, const Circle &C);
protected:
	void printMyself(std::ostream& out)const;
private:
	Point *cPtr;
	Fraction *rPtr;
};


#endif