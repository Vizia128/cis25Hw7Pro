#include "Fraction.h"
#include "FractionUtility.h"
#include "Point.h"
#include "PointUtility.h"
#include "Circle.h"
#include "CircleUtility.h"
using namespace std;


void init(Circle** c1, Circle** c2) {
	Fraction *frxPtr = nullptr;
	Fraction *fryPtr = nullptr;
	Fraction *rPtr = nullptr;

	cout << "\nEnter dimensions of Cirlce 1"
		<< "\n    X-coordinate - ";
	init(&frxPtr);
	cout << "\n    Y-coordinate - ";
	init(&fryPtr);
	cout << "\n    radius - ";
	init(&rPtr);
	*c1 = new Circle(*frxPtr, *fryPtr, *rPtr);
	delete frxPtr;
	delete fryPtr;
	delete rPtr;

	cout << "\nEnter dimensions of Cirlce 2"
		<< "\n    X-coordinate - ";
	init(&frxPtr);
	cout << "\n    Y-coordinate - ";
	init(&fryPtr);
	cout << "\n    radius - ";
	init(&rPtr);
	*c2 = new Circle(*frxPtr, *fryPtr, *rPtr);
	delete frxPtr;
	delete fryPtr;
	delete rPtr;
}

void init(Circle** c) {
	Fraction *frxPtr = nullptr;
	Fraction *fryPtr = nullptr;
	Fraction *rPtr = nullptr;

	cout << "\nEnter dimensions of Cirlce"
		<< "\n    X-coordinate - ";
	init(&frxPtr);
	cout << "\n    Y-coordinate - ";
	init(&fryPtr);
	cout << "\n    radius - ";
	init(&rPtr);
	*c = new Circle(*frxPtr, *fryPtr, *rPtr);
	delete frxPtr;
	delete fryPtr;
	delete rPtr;
}



double arccos(double x) {
	const double pi = 3.141592653;
	
		return pi / 2 - (.5689111419 - .2644381021*x - .4212611542*(2 * x - 1)*(2 * x - 1)
			 + .1475622352*(2 * x - 1)*(2 * x - 1)*(2 * x - 1))
			 / (2.006022274 - 2.343685222*x + .3316406750*(2 * x - 1)*(2 * x - 1) +
				 .02607135626*(2 * x - 1)*(2 * x - 1)*(2 * x - 1));
}

double theta(double r1, double r2, double d) {
	return arccos((r1*r1+d*d-r2*r2)/(2*r1*d));
}

double cosTheta(double r1, double r2, double d) {
	return (r1*r1 + d*d - r2*r2) / (2 * r1*d);
}

//double OverlappingArea() {}