#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
using namespace std;


class Shape {
public:
	virtual double area()const = 0;
	virtual double perimiter()const {
	}

};


#endif
