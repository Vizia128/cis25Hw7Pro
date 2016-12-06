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

Point Rectangle::getPoint() {
	return *cPtr;
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

void Rectangle::overlapArea(const Shape& with)const {
	with.overlapArea(*this);
}
void Rectangle::overlapArea(const Rectangle& R)const {
	int type = this->overlapType(R);
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

		cout << "\n    The rectangle caused by the overlap :"
			"\n      "
			<< Rectangle(cPtr->getFrx() - *(del + 0),
				cPtr->getFry() - *(del + 1),
				*R.lPtr + *lPtr - *(del + 2),
				*R.wPtr + *wPtr - *(del + 3))
			<< "\n    Has Area : "
			<< (*R.lPtr + *lPtr - *(del + 2) *
			*R.wPtr + *wPtr - *(del + 3));
		break;
	default:
		cout << "\n  ERROR!!";
		break;
	}
}
void Rectangle::overlapArea(const Circle& C)const {
	cout << "\/ERROR Rectangle::overlapArea(const Circle&)";
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