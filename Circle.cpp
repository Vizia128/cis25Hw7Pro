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
Circle::Circle(const Point& P, const Fraction& F) 
	: cPtr(new Point(P)), rPtr(new Fraction(F)) {
}
Circle::Circle(const Fraction& Fx, const Fraction& Fy, const Fraction& F)
	: cPtr(new Point(Fx,Fy)), rPtr(new Fraction(F)) {
}
Circle::Circle(const Circle& C)
	: cPtr(new Point(*C.cPtr)), rPtr(new Fraction(*C.rPtr)) {
}

Point Circle::getPoint() {
	return *cPtr;
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

int Circle::overlapType(const Shape& with)const {
	cout << "\nCirc::overlapType(const Shap&)const";
	return with.overlapType(*this);
}
int Circle::overlapType(const Rectangle& w)const {
	cout << "\nCirc::overlapType(const Rect&)const";
	return 12;
}
int Circle::overlapType(const Circle& w)const {
	cout << "\nCirc::overlapType(const Circ&)const";
	return 11;
}
const char* Circle::getType()const {
	return "Circle";
}


void Circle::overlapArea(const Shape& with)const {
	with.overlapArea(*this);
}
void Circle::overlapArea(const Rectangle& R)const {

}
void Circle::overlapArea(const Circle& C)const {

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