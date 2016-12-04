#include "Fraction.h"
#include "FractionUtility.h"
#include "Point.h"
#include "PointUtility.h"
#include "Shape.h"
#include "Circle.h"
#include "CircleUtility.h"
#include "Rectangle.h"
using namespace std;


Rectangle::Rectangle() : cPtr(new Point()), lPtr(new Fraction()), hPtr(new Fraction()) {
}
Rectangle::Rectangle(int f1, int f2, int l, int h)
	: cPtr(new Point(f1, f2)), lPtr(new Fraction(l)), hPtr(new Fraction(h)) {
}
Rectangle::Rectangle(const Point& P, const Fraction& l, const Fraction& h)
	: cPtr(new Point(P)), lPtr(new Fraction(l)), hPtr(new Fraction(h)) {
}
Rectangle::Rectangle(const Fraction& Fx, const Fraction& Fy, const Fraction& l, const Fraction& h)
	: cPtr(new Point(Fx, Fy)), lPtr(new Fraction(l)), hPtr(new Fraction(h)) {
}
Rectangle::Rectangle(const Rectangle& R)
	: cPtr(new Point(*R.cPtr)), lPtr(new Fraction(*R.lPtr)), hPtr(new Fraction(*R.hPtr)) {
}

void Rectangle::moveBy() {
	Fraction *delx = nullptr;
	Fraction *dely = nullptr;
	Point *pt = nullptr;

	cout << "\n      Enter delta-x";
	init(&delx);
	cout << "\n      Enter delta-y";
	init(&dely);
	pt = new Point(*delx, *dely);
	delete delx;
	delete dely;

	*cPtr = *cPtr + *pt;
	delete pt;
}

Point Rectangle::getLocation()const {
	return *cPtr;
}

Fraction Rectangle::getLength()const {
	return *lPtr;
}

Fraction Rectangle::getHeight()const {
	return *hPtr;
}


int Rectangle::overlap(const Rectangle& R)const {
	Fraction delx = (cPtr->getFrx() - R.cPtr->getFrx());
	Fraction dely = (cPtr->getFry() - R.cPtr->getFry());
	delx < Fraction() ? -delx : delx;
	delx < Fraction() ? -dely : dely;

	if (delx > *lPtr / 2 + *R.lPtr / 2 || dely > *hPtr / 2 + *R.hPtr / 2) {
		cout << "\n    They rectangles are overlapping";
		return 1;
	}
	else if (delx == *hPtr / 2 + *R.hPtr / 2 || dely == *hPtr / 2 + *R.hPtr / 2) {
		cout << "\n    There is no overlap!";
		return 2;
	}
	else if (delx + *lPtr / 2 < *R.lPtr / 2 && dely + *hPtr / 2 < *R.hPtr / 2) {
		cout << "\n    Rectangle 1 is inside rectangle 2";
		return 4;
	}
	else if (delx + *R.lPtr / 2 < *lPtr / 2 && dely + *R.hPtr / 2 < *hPtr / 2) {
		cout << "\n    Rectangle 2 is inside rectangle 1";
		return 5;
	}
	else {
		cout << "\n    The rectangles are overlapping";
		return 3;
	}
}

void Rectangle::combine(const Rectangle& R)const {
	int type = this->overlap(R);
	Fraction* del;

	switch (type) {
	case 1: case 2: case 4: case 5:
		break;
	case 3:
		del = new Fraction[4];
		*(del + 0) = cPtr->getFrx() - R.cPtr->getFrx();
		*(del + 1) = cPtr->getFry() - R.cPtr->getFry();
		*(del + 2) = *(del + 0) < Fraction() ? -*(del + 0) : *(del + 0);
		*(del + 3) = *(del + 1) < Fraction() ? -*(del + 1) : *(del + 1);

		cout << "\n    The rectangles overlap on the rectangle :"
			"\n      "
			<< Rectangle(cPtr->getFrx() - *(del + 0),
				cPtr->getFry() - *(del + 1),
				*R.lPtr + *lPtr - *(del + 2),
				*R.hPtr + *hPtr - *(del + 3));
		delete[] del;
		break;
	default:
			cout << "\n  ERROR!!";
		break;
	}
}

double Rectangle::area()const {
	return double(*lPtr * *hPtr);
}
double Rectangle::perimiter()const {
	return double(*lPtr * *hPtr * 2);
}


Rectangle Rectangle::operator=(const Rectangle& R) {
	*cPtr = *R.cPtr;
	*lPtr = *R.lPtr;
	*hPtr = *R.hPtr;
	return Rectangle(*cPtr, *lPtr, *hPtr);
}

Rectangle Rectangle::operator+(const Point& P) {
	return Rectangle(*cPtr + P, *lPtr, *hPtr);
}
Rectangle Rectangle::operator-(const Point& P) {
	return Rectangle(*cPtr - P, *lPtr, *hPtr);
}
Rectangle Rectangle::operator*(const Fraction& F) {
	return Rectangle(*cPtr, *lPtr * F, *hPtr * F);
}
Rectangle Rectangle::operator/(const Fraction& F) {
	return Rectangle(*cPtr, *lPtr / F, *hPtr / F);
}


//
//std::ostream& operator<<(std::ostream &out, const Rectangle &R) {
//	out << "Center : " << *R.cPtr
//		<< ", Length : " << *R.lPtr
//		<< ", Height : " << *R.hPtr;
//	return out;
//}
