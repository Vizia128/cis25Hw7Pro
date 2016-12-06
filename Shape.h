#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Rectangle;
class Circle;

class Shape {
public:
	virtual Point getCenter() = 0;

	virtual void moveByX(char) = 0;
	virtual void moveByY(char) = 0;

	virtual void areaCompare(const Shape&)const = 0;
	virtual void areaCompare(const Rectangle&)const = 0;
	virtual void areaCompare(const Circle&)const = 0;

	virtual void perimeterCompare(const Shape&)const = 0;
	virtual void perimeterCompare(const Rectangle&)const = 0;
	virtual void perimeterCompare(const Circle&)const = 0;

	virtual int overlapType(const Shape&)const = 0;
	virtual int overlapType(const Rectangle&)const = 0;
	virtual int overlapType(const Circle&)const = 0;

	virtual void overlapShape(const Shape&)const = 0;
	virtual void overlapShape(const Rectangle&)const = 0;
	virtual void overlapShape(const Circle&)const = 0;

	virtual const char* getType()const = 0;
	friend std::ostream& operator<<(std::ostream &out, const Shape &S) {
		S.printMyself(out);
		return out;
	}
protected:
	virtual void printMyself(std::ostream& out) const = 0;
};

#endif
