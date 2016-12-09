#include "Fraction.h"
#include "FractionUtility.h"
#include "Point.h"
#include "PointUtility.h"
#include "Shape.h"
#include "Circle.h"
#include "CircleUtility.h"
#include "Rectangle.h"
using namespace std;



Rectangle::Rectangle() : cPtr(new Point()), lPtr(new Fraction()), wPtr(new Fraction()) {
}
Rectangle::Rectangle(int f1, int f2, int l, int h)
	: cPtr(new Point(f1, f2)), lPtr(new Fraction(l)), wPtr(new Fraction(h)) {
}
Rectangle::Rectangle(const Point& P, const Fraction& l, const Fraction& h)
	: cPtr(new Point(P)), lPtr(new Fraction(l)), wPtr(new Fraction(h)) {
}
Rectangle::Rectangle(const Fraction& Fx, const Fraction& Fy, const Fraction& l, const Fraction& h)
	: cPtr(new Point(Fx, Fy)), lPtr(new Fraction(l)), wPtr(new Fraction(h)) {
}
Rectangle::Rectangle(const Rectangle& R)
	: cPtr(new Point(*R.cPtr)), lPtr(new Fraction(*R.lPtr)), wPtr(new Fraction(*R.wPtr)) {
}

Point Rectangle::getCenter() {
	return *cPtr;
}
Point Rectangle::getLength() {
	return *lPtr;
}
Point Rectangle::getWidth() {
	return *wPtr;
}

void Rectangle::moveByX(char l) {
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
		*cPtr = *cPtr + Point(dxn,dxd,0,1);
	}
}
void Rectangle::moveByY(char l) {
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

void Rectangle::areaCompare(const Shape& with)const {
	with.areaCompare(*this);	//This swaps Shape 1 and 2 
}								//so call s2ptr->areaCompare(*s1ptr)

void Rectangle::areaCompare(const Rectangle& C)const {
	Fraction area1(*lPtr * *wPtr);
	Fraction area2(*C.lPtr * *C.wPtr);

	cout << "\n        Rectangle 1:"
		<< "\n            Center: " << *cPtr
		<< "\n            Length: " << *lPtr
		<< "\n            Width:  " << *wPtr
		<< "\n            Area:   " << area1;

	if (area1 > area2)
		cout << "\n\n        Has a larger area than" << endl;
	else if (area1 == area2)
		cout << "\n\n        Has an equal area to" << endl;
	else
		cout << "\n\n        Has a smaller area than" << endl;

	cout << "\n        Rectangle 1:"
		<< "\n            Center: " << *C.cPtr
		<< "\n            Length: " << *C.lPtr
		<< "\n            Width:  " << *C.wPtr
		<< "\n            Area:   " << area2;
}
void Rectangle::areaCompare(const Circle&)const {
	cout << "\n    Rectangle::areaCompare(const Circle&)";
}

void Rectangle::perimeterCompare(const Shape& with)const {
	with.perimeterCompare(*this);	//This swaps Shape 1 and 2 
}									//so call s2ptr->areaCompare(*s1ptr)

void Rectangle::perimeterCompare(const Rectangle& C)const {
	Fraction perim1((*lPtr + *wPtr)*2);
	Fraction perim2((*C.lPtr + *C.wPtr)*2);

	cout << "\n        Rectangle 1:"
		<< "\n            Center:      " << *cPtr
		<< "\n            Length:      " << *lPtr
		<< "\n            Width:       " << *wPtr
		<< "\n            Perimeter:   " << perim1;

	if (perim1 > perim2)
		cout << "\n\n        Has a larger perimeter than" << endl;
	else if (perim1 == perim2)
		cout << "\n\n        Has an equal perimeter to" << endl;
	else
		cout << "\n\n        Has a smaller perimeter than" << endl;

	cout << "\n        Rectangle 1:"
		<< "\n            Center:      " << *C.cPtr
		<< "\n            Length:      " << *C.lPtr
		<< "\n            Width:       " << *C.wPtr
		<< "\n            Perimeter:   " << perim2;
}
void Rectangle::perimeterCompare(const Circle&)const {
	cout << "\n    Rectangle::perimeterCompare(const Circle&)";
}

int Rectangle::overlapType(const Shape& with)const {
//	cout << "\nRect::overlapType(const Shap&)const";
	return with.overlapType(*this);
}
int Rectangle::overlapType(const Rectangle& R)const {
//	cout << "\nRect::overlapType(const Rect&)const";
	Fraction delx = (cPtr->getFrx() - R.cPtr->getFrx());
	Fraction dely = (cPtr->getFry() - R.cPtr->getFry());
	delx < Fraction() ? -delx : delx;
	delx < Fraction() ? -dely : dely;

	if (delx > *lPtr / 2 + *R.lPtr / 2 || dely > *wPtr / 2 + *R.wPtr / 2) {
		cout << "\n    The rectangles are not overlapping";
		return 1;
	}
	else if (delx == *wPtr / 2 + *R.wPtr / 2 || dely == *wPtr / 2 + *R.wPtr / 2) {
		cout << "\n    The rectangles are just touching";
		return 2;
	}
	else if (delx + *lPtr / 2 < *R.lPtr / 2 && dely + *wPtr / 2 < *R.wPtr / 2) {
		cout << "\n    Rectangle 1 is enclosed by rectangle 2";
		return 4;
	}
	else if (delx + *R.lPtr / 2 < *lPtr / 2 && dely + *R.wPtr / 2 < *wPtr / 2) {
		cout << "\n    Rectangle 2 is enclosed by rectangle 1";
		return 5;
	}
	else {
		cout << "\n    The rectangles are overlapping";
		return 3;
	}

}
int Rectangle::overlapType(const Circle& w)const {
	cout << "\nRect::overlapType(const Circ&)const";
	return 21;
}

void Rectangle::overlapShape(const Shape& with)const {
	with.overlapShape(*this);
}
void Rectangle::overlapShape(const Rectangle& R)const {
	// This doesn't always work
	int type = this->overlapType(R);
	Fraction del[4];
	del[0] = cPtr->getFrx() - R.cPtr->getFrx();
	del[1] = cPtr->getFry() - R.cPtr->getFry();
	del[2] = del[0] < Fraction() ? -del[0] : del[0];
	del[3] = del[1] < Fraction() ? -del[1] : del[1];
	switch (type) {
	case 1: case 2: case 4: case 5:
		break;
	case 3:
		cout << "\n    The rectangle caused by the overlap :"
			<< "\n    Has Area : "
			<< ((*R.lPtr + *lPtr)/2 - del[2] *
			((*R.wPtr + *wPtr) - del[3]));
		break;
	default:
		cout << "\n  ERROR!!";
		break;
	}
}
void Rectangle::overlapShape(const Circle& C)const {
	cout << "\nERROR Rectangle::overlapShape(const Circle&)";
}

const char* Rectangle::getType()const {
	return "Rectangle";
}

void Rectangle::printMyself(std::ostream& out)const {
	out << "Center : (x : " << cPtr->getFrx()
		<< ", y : " << cPtr->getFry()
		<< ") , Size : (l : " << *lPtr
		<< ", w : " << *wPtr << ")";
}

std::ostream& operator<<(std::ostream &out, const Rectangle &C) {
	out << "Center : (x : " << C.cPtr->getFrx()
		<< ", y : " << C.cPtr->getFry()
		<< ") , Size : (l : " << *C.lPtr
		<< ", w : " << *C.wPtr << ")";
	return out;
}