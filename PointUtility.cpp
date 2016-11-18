#include <iostream>
#include "Menu.h"
#include "Fraction.h"
#include "FractionUtility.h"
#include "Point.h"
#include "PointUtility.h"
using namespace std;



void init(Point** pt1, Point** pt2) {
	Fraction *frxPtr = nullptr;
	Fraction *fryPtr = nullptr;

	cout << "\nEnter coordinates of Point 1"
		<< "\n  X-coordinate - ";
	init(&frxPtr);
	cout << "\n    Y-coordinate - ";
	init(&fryPtr);
	*pt1 = new Point(*frxPtr, *fryPtr);
	delete frxPtr;
	delete fryPtr;

	cout << "\nEnter coordinates of Point 2"
		<< "\n  X-coordinate -- ";
	init(&frxPtr);
	cout << "\n  Y-coordinate -- ";
	init(&fryPtr);
	*pt2 = new Point(*frxPtr, *fryPtr);
	delete frxPtr;
	delete fryPtr;
}

void init(Point** pt, int pnum) {
	Fraction *frxPtr = nullptr;
	Fraction *fryPtr = nullptr;

	cout << "\nEnter coordinates of Point " << pnum
		<< "\n  X-coordinate -- ";
	init(&frxPtr);
	cout << "\n  Y-coordinate -- ";
	init(&fryPtr);
	*pt = new Point(*frxPtr, *fryPtr);
	delete frxPtr;
	delete fryPtr;
}

void init(Point** pt) {
	Fraction *frxPtr = nullptr;
	Fraction *fryPtr = nullptr;

	cout << "\n  X-coordinate -- ";
	init(&frxPtr);
	cout << "\n  Y-coordinate -- ";
	init(&fryPtr);
	*pt = new Point(*frxPtr, *fryPtr);
	delete frxPtr;
	delete fryPtr;
}

