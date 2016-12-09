#ifndef SHAPEUTILITY_H
#define SHAPEUTILITY_H
#include <iostream>
#include "Fraction.h"
#include "FractionUtility.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
using namespace std;

void init(Shape** c1, Shape** c2, string type) {
	Fraction *frxPtr = nullptr;
	Fraction *fryPtr = nullptr;
	Fraction *rPtr = nullptr;
	Fraction *hPtr = nullptr;

	if (type == "Circle") {
		cout << "\nEnter dimensions of Circle 1"
			<< "\n    X-coordinate - ";
		init(&frxPtr);
		cout << "\n    Y-coordinate - ";
		init(&fryPtr);
		cout << "\n    radius - ";
		init(&rPtr);
		*rPtr *= *rPtr < Fraction() ? -1 : 1;
		*c1 = new Circle(*frxPtr, *fryPtr, *rPtr);
		delete frxPtr;
		delete fryPtr;
		delete rPtr;

		cout << "\nEnter dimensions of Circle 2"
			<< "\n    X-coordinate - ";
		init(&frxPtr);
		cout << "\n    Y-coordinate - ";
		init(&fryPtr);
		cout << "\n    radius - ";
		init(&rPtr);
		*rPtr *= *rPtr < Fraction() ? -1 : 1;
		*c2 = new Circle(*frxPtr, *fryPtr, *rPtr);
		delete frxPtr;
		delete fryPtr;
		delete rPtr;
	}

	else if (type == "Rectangle") {
		cout << "\nEnter dimensions of Rectangle 1"
			<< "\n    X-coordinate of center - ";
		init(&frxPtr);
		cout << "\n    Y-coordinate of center - ";
		init(&fryPtr);
		cout << "\n    Length - ";
		init(&rPtr);
		cout << "\n    Width - ";
		init(&hPtr);
		*rPtr *= *rPtr < Fraction() ? -1 : 1;
		*hPtr *= *hPtr < Fraction() ? -1 : 1;
		*c1 = new Rectangle(*frxPtr, *fryPtr, *rPtr, *hPtr);
		delete frxPtr;
		delete fryPtr;
		delete rPtr;
		delete hPtr;

		cout << "\nEnter dimensions of Rectangle 2"
			<< "\n    X-coordinate of center - ";
		init(&frxPtr);
		cout << "\n    Y-coordinate of center - ";
		init(&fryPtr);
		cout << "\n    Length - ";
		init(&rPtr);
		cout << "\n    Width - ";
		init(&hPtr);
		*rPtr *= *rPtr < Fraction() ? -1 : 1;
		*hPtr *= *hPtr < Fraction() ? -1 : 1;
		*c2 = new Rectangle(*frxPtr, *fryPtr, *rPtr, *hPtr);
		delete frxPtr;
		delete fryPtr;
		delete rPtr;
		delete hPtr;
	}


}


#endif