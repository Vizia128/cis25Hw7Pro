#include "Fraction.h"
#include "FractionUtility.h"
#include "Point.h"
#include "PointUtility.h"
#include "Circle.h"
#include "CircleUtility.h"
#include "Rectangle.h"
#include "Shape.h"
using namespace std;


Circle::Circle() : cPtr(new Point()), rPtr(new Fraction()) {
}
Circle::Circle(int f1, int f2, int r)
	: cPtr(new Point(f1, f2)), rPtr(new Fraction(r)) {
}
Circle::Circle(const Point& P, const Fraction& r) 
	: cPtr(new Point(P)), rPtr(new Fraction(r)) {
}
Circle::Circle(const Fraction& Fx, const Fraction& Fy, const Fraction& F)
	: cPtr(new Point(Fx,Fy)), rPtr(new Fraction(F)) {
}
Circle::Circle(const Circle& C)
	: cPtr(new Point(*C.cPtr)), rPtr(new Fraction(*C.rPtr)) {
}

Point Circle::getCenter() {
	return *cPtr;
}

Fraction Circle::getRadius() {
	return *rPtr;
}

void Circle::moveByX(char l) {
	int dxn, dxd;

	cout << "\n          Enter Delta-x : ";
	switch (l) {
	case 'i':	// 'i' for int
		cin >> dxn;
		*cPtr = *cPtr + Point(dxn, 0);
		break;

	case 'F':  // 'F' for Fraction
		cout << "\n    Enter numerator : ";
		cin >> dxn;
		do {
			cout << "    Enter denominator: ";
			cin >> dxd;
			if (dxd == 0)
				cout << "\n     ERROR!! Denominator canNOT equal zero";
		} while (dxd == 0);
		*cPtr = *cPtr + Point(dxn, dxd, 0, 1);
	}
}
void Circle::moveByY(char l) {
	int dyn, dyd;

	cout << "\n          Enter Delta-y : ";
	switch (l) {
	case 'i':	// 'i' for int
		cin >> dyn;
		*cPtr = *cPtr + Point(0, dyn);
		break;

	case 'F':  // 'F' for Fraction
		cout << "\n    Enter numerator : ";
		cin >> dyn;
		do {
			cout << "    Enter denominator: ";
			cin >> dyd;
			if (dyd == 0)
				cout << "\n     ERROR!! Denominator canNOT equal zero";
		} while (dyd == 0);
		*cPtr = *cPtr + Point(0, 1, dyn, dyd);
	}
}

void Circle::areaCompare(const Shape& with)const {
	with.areaCompare(*this);
}
void Circle::areaCompare(const Rectangle&)const {
	cout << "\n    Circle::areaCompare(const Rectangle&)";
}
void Circle::areaCompare(const Circle& C)const {
	Fraction area1(*rPtr * *rPtr * 157, 50);
	Fraction area2(*C.rPtr * *C.rPtr * 157, 50);

	cout << "\n        Circle 1:"
		<< "\n            Center: " << *cPtr
		<< "\n            Radius: " << *rPtr
		<< "\n            Area:   " << area1;

	if (area1 > area2)
		cout << "\n\n        Has a larger area than" << endl;
	else if (area1 == area2)
		cout << "\n\n        Has an equal area to" << endl;
	else
		cout << "\n\n        Has a smaller area than" << endl;

	cout << "\n        Circle 2:"
		<< "\n            Center: " << *C.cPtr
		<< "\n            Radius: " << *C.rPtr
		<< "\n            Area:   " << area2;
}

void Circle::perimeterCompare(const Shape& with)const {
	with.perimeterCompare(*this);
}
void Circle::perimeterCompare(const Rectangle&)const {
	cout << "\n    Circle::perimeterCompare(const Rectangle&)";
}
void Circle::perimeterCompare(const Circle& C)const {
	Fraction perim1(*rPtr * 157, 25);
	Fraction perim2(*C.rPtr * 157, 25);

	cout << "\n        Circle 1:"
		<< "\n            Center:    " << *cPtr
		<< "\n            Radius:    " << *rPtr
		<< "\n            Perimiter: " << perim1;

	if (perim1 > perim2)
		cout << "\n\n        Has a larger perimiter than" << endl;
	else if (perim1 == perim2)
		cout << "\n\n        Has an equal perimiter to" << endl;
	else
		cout << "\n\n        Has a smaller perimiter than" << endl;

	cout << "\n        Circle 2:"
		<< "\n            Center:    " << *C.cPtr
		<< "\n            Radius:    " << *C.rPtr
		<< "\n            Perimiter: " << perim2;
}

int Circle::overlapType(const Shape& with)const {
	return with.overlapType(*this);
}
int Circle::overlapType(const Rectangle& w)const {
	cout << "\nCirc::overlapType(const Rect&)const";
	return 12;
}
int Circle::overlapType(const Circle& C)const {
	double d = cPtr->distance(*C.cPtr);
	double gap = (d - *rPtr - *C.rPtr);
	if (gap > 0) {
		cout << "\n      The circles are disjointed";
		return 1;
	}
	else if (gap == 0) {
		cout << "\n      The circles are touching";
		return 2;
	}
	else if (double(*rPtr) < double(*C.rPtr) + d
		&& double(*C.rPtr) < double(*rPtr) + d) {
		cout << "\n      The circles are overlapping";
		return 3;
	}
	else if (*rPtr > *C.rPtr) {
		cout << "\n      Circle 2 is entirely within Circle 1";
		return 4;
	}
	else {
		cout << "\n      Circle 1 is entirely within Circle 2";
		return 5;
	}
}
const char* Circle::getType()const {
	return "Circle";
}


void Circle::overlapShape(const Shape& with)const {
	with.overlapShape(*this);
}
void Circle::overlapShape(const Rectangle& R)const {
	cout << "\n  Circle::overlapShape(const Rectangle& R)const";
}
void Circle::overlapShape(const Circle& c)const {
	int type = this->overlapType(c);

	switch (type) {
	case 1: case 2: case 4: case 5:
		break;
	case 3:
		cout << "\n      The circles overlap to create a lens with an area of " 
			<< this->overlapArea(c) << endl;
		break;
	}
}

double Circle::overlapArea(const Circle& C)const {
	double d = cPtr->distance(*C.cPtr);
	//	cout << "\ndistance : " << d;
	double cosTh1 = cosTheta(*rPtr, *C.rPtr, d);
	double cosTh2 = cosTheta(*C.rPtr, *rPtr, d);

	//	cout << "\nArea of sector 1 : " << theta(*rPtr, *C.rPtr, d) * *rPtr * *rPtr << "\t Theta1 : " << theta(*rPtr, *C.rPtr, d) //yay
	//		<< "\nArea of sector 2 : " << theta(*C.rPtr, *rPtr, d) * *C.rPtr * *C.rPtr << "\t Theta2 : " << theta(*C.rPtr, *rPtr, d)  //yay
	//		<< "\nArea of triangle 1 : " << cosTh1 * sqroot(1 - cosTh1*cosTh1) * *rPtr * *rPtr << "\t costheta1 : " << cosTh1
	//		<< "\nArea of triangle 2 : " << cosTh2 * sqroot(1 - cosTh2*cosTh2) * *C.rPtr * *C.rPtr << "\t costheta2 : " << cosTh2;

	return theta(*rPtr, *C.rPtr, d) * *rPtr * *rPtr 	//Area of sector 1
		+ theta(*C.rPtr, *rPtr, d) * *C.rPtr * *C.rPtr 		//Area of sector 2
		- cosTh1 * sqroot(1 - cosTh1*cosTh1) * *rPtr * *rPtr	//Area of triangle 1
		- cosTh2 * sqroot(1 - cosTh2*cosTh2) * *C.rPtr * *C.rPtr;	//Area of triangle 2
}

void Circle::printMyself(std::ostream& out)const {
	out << "(x : " << cPtr->getFrx()
		<< ", y : " << cPtr->getFry()
		<< ", r : " << *rPtr << ")";
}

std::ostream& operator<<(std::ostream &out, const Circle &C) {
	out << "(x : " << C.cPtr->getFrx()
		<< ", y : " << C.cPtr->getFry()
		<< ", r : " << *C.rPtr << ")";
	return out;
}