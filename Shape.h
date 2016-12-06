#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Rectangle;
class Circle;

class Shape {
public:
	virtual Point getPoint() = 0;

	virtual void moveByX(char) = 0;
	virtual void moveByY(char) = 0;

	virtual int overlapType(const Shape&)const = 0;
	virtual int overlapType(const Rectangle&)const = 0;
	virtual int overlapType(const Circle&)const = 0;

	virtual void overlapArea(const Shape&)const = 0;
	virtual void overlapArea(const Rectangle&)const = 0;
	virtual void overlapArea(const Circle&)const = 0;

	virtual const char* getType()const = 0;
	friend std::ostream& operator<<(std::ostream &out, const Shape &S) {
		S.printMyself(out);
		return out;
	}
protected:
	virtual void printMyself(std::ostream& out) const = 0;
};

#endif
