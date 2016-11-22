#include "Fraction.h"
#include "FractionUtility.h"
#include "Point.h"
#include "PointUtility.h"
#include "Circle.h"
#include "CircleUtility.h"
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

void Circle::moveBy() {
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

Point Circle::getLocation()const {
	return *cPtr;
}

Fraction Circle::getRadius()const {
	return *rPtr;
}


int Circle::overlap(const Circle& C)const {
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

double Circle::overlappingArea(const Circle& C)const {
	double d = cPtr->distance(*C.cPtr);
//	cout << "\ndistance : " << d;
	double cosTh1 = cosTheta(*rPtr, *C.rPtr, d);
	double cosTh2 = cosTheta(*C.rPtr,*rPtr , d);
	
//	cout << "\nArea of sector 1 : " << theta(*rPtr, *C.rPtr, d) * *rPtr * *rPtr << "\t Theta1 : " << theta(*rPtr, *C.rPtr, d) //yay
//		<< "\nArea of sector 2 : " << theta(*C.rPtr, *rPtr, d) * *C.rPtr * *C.rPtr << "\t Theta2 : " << theta(*C.rPtr, *rPtr, d)  //yay
//		<< "\nArea of triangle 1 : " << cosTh1 * sqroot(1 - cosTh1*cosTh1) * *rPtr * *rPtr << "\t costheta1 : " << cosTh1
//		<< "\nArea of triangle 2 : " << cosTh2 * sqroot(1 - cosTh2*cosTh2) * *C.rPtr * *C.rPtr << "\t costheta2 : " << cosTh2;

	return theta(*rPtr, *C.rPtr, d) * *rPtr * *rPtr 	//Area of sector 1
		+ theta(*C.rPtr, *rPtr, d) * *C.rPtr * *C.rPtr 		//Area of sector 2
		- cosTh1 * sqroot(1 - cosTh1*cosTh1) * *rPtr * *rPtr	//Area of triangle 1
		- cosTh2 * sqroot(1 - cosTh2*cosTh2) * *C.rPtr * *C.rPtr;	//Area of triangle 2
}

void Circle::combine(const Circle& c)const {
	double x, y, r;
	double A1 = double(*this->rPtr* *this->rPtr) * 3.141592653;
	double A2 = double(*c.rPtr* *c.rPtr) * 3.141592653;
	int ovl = this->overlap(c);
	
	//cout << "\n A1 : " << A1 << "\t A2 : " << A2  << "\t overlap# : " << ovl;

	x = (double(this->cPtr->getFrx()) * A1
		+ double(c.cPtr->getFrx()) * A2) / (A1 + A2);
	y = (double(this->cPtr->getFry()) * A1
		+ double(c.cPtr->getFry()) * A2) / (A1 + A2);

	switch (ovl) {
	case 1: case 2:
		r = sqroot((A1 + A2) / 3.141592653);
		break;
	case 3:
		r = sqroot((A1 + A2 - this->overlappingArea(c)) / 3.141592653);
		break;
	case 4:
		r = *this->rPtr;
		break;
	case 5:
		r = *c.rPtr;
		break;
	}
	cout << "\n      The combined circle is located at ("
		<< x << ", " << y << ")"
		<< "\n      and has a radius of " << r << endl;
}

Circle Circle::operator=(const Circle& C) { 
	*cPtr = *C.cPtr;
	*rPtr = *C.rPtr;
	return Circle(*cPtr, *rPtr);
}

Circle Circle::operator+(const Point& P) {
	return Circle(*cPtr + P, *rPtr);
}
Circle Circle::operator-(const Point& P) {
	return Circle(*cPtr - P, *rPtr);
}
Circle Circle::operator*(const Fraction& F) {
	return Circle(*cPtr, *rPtr * F);
}
Circle Circle::operator/(const Fraction& F) {
	return Circle(*cPtr, *rPtr / F);
}



std::ostream& operator<<(std::ostream &out, const Circle &C) {
	out << "(x : " << C.cPtr->getFrx()
		<< ", y : " << C.cPtr->getFry()
		<< ", r : " << *C.rPtr << ")";
	return out;
}