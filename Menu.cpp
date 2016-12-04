#include <iostream>
#include "Menu.h"
#include "Fraction.h"
#include "FractionUtility.h"
#include "Point.h"
#include "PointUtility.h"
#include "Circle.h"
#include "CircleUtility.h"
#include "Rectangle.h"
using namespace std;

void menuHw7Ex1() {
	Circle* c1ptr = nullptr;
	Circle* c2ptr = nullptr;
	Shape* s1ptr = nullptr;
	Shape* s2ptr = nullptr;
	Point* movePtr = nullptr;
	int overlap = -1;
	int option = -1;

	do {
		cout << "\n\n*******************************"
			<< "\n*         MENU - Hw #7        *"
			<< "\n*  1. Initializing(2 Points)  *"
			<< "\n*  2. Positioning             *"
			<< "\n*  3. Moving                  *"
			<< "\n*  4. Comparing               *"
			<< "\n*  5. Combining               *"
			<< "\n*  6. Displaying              *"
			<< "\n*  7. Quit                    *"
			<< "\n*******************************"
			<< "\nSelect an option(use integer value only) : ";
		cin >> option;

		switch (option) {
		case 1:
			if (c1ptr == nullptr && c2ptr == nullptr) {
				init(&c1ptr, &c2ptr);
				cout << "\n    Circle 1 -- " << *c1ptr
					<< "\n    Circle 2 -- " << *c2ptr;
			}

			else do {
				cout << "\n  Initialization Option--"
					<< "\n    *************************************"
					<< "\n    *  Sub MENU -- CircleInitialization *"
					<< "\n    *  1. Initializing(2 Circles)       *"
					<< "\n    *  2. Initializing(Circle 1)        *"
					<< "\n    *  3. Initializing(Circle 2)        *"
					<< "\n    *  4. Printing                      *"
					<< "\n    *  5. Returning                     *"
					<< "\n    *************************************"
					<< "\n    Select an option (use integer value only) : ";
				cin >> option;

				switch (option) {
				case 1:
					init(&c1ptr, &c2ptr);
					cout << "\n      Circle 1 -- " << *c1ptr
						<< "\n      Circle 2 -- " << *c2ptr;
					break;
				case 2:
					init(&c1ptr);
					cout << "\n      Circle 1 -- " << *c1ptr;
					break;
				case 3:
					init(&c2ptr);
					cout << "\n      Circle 2 -- " << *c2ptr;
					break;
				case 4:
					cout << "\n      Circle 1 -- " << *c1ptr
						<< "\n      Circle 2 -- " << *c2ptr;
					break;
				case 5:
					break;
				default:
					cout << "\n    WRONG OPTION!\n";
					break;
				}
			} while (option != 5);
			break;
		case 2:
			//TODO
			break;
		case 3:
			if (c1ptr == nullptr && c2ptr == nullptr) {
				cout << "\n    Circles not initialized  ";
			}

			else do {
				cout << "\n  Initialization Option--"
					<< "\n    *************************************"
					<< "\n    *  Sub MENU -- CircleInitialization *"
					<< "\n    *  1. Moving Both 2 Circles         *"
					<< "\n    *  2. Moving Circle 1               *"
					<< "\n    *  3. Moving Circle 2               *"
					<< "\n    *  4. Printing                      *"
					<< "\n    *  5. Returning                     *"
					<< "\n    *************************************"
					<< "\n    Select an option (use integer value only) : ";
				cin >> option;

				switch (option) {
				case 1:
					c1ptr->moveBy();
					c2ptr->moveBy();
					cout << "\n    Circle 1 -- " << *c1ptr
						<< "\n    Circle 2 -- " << *c2ptr;
					break;
				case 2:
					c1ptr->moveBy();
					cout << "\n    Circle 1 -- " << *c1ptr;
					break;
				case 3:
					c2ptr->moveBy();
					cout << "\n    Circle 2 -- " << *c2ptr;
					break;
				case 4:
					cout << "\n    Circle 1 -- " << *c1ptr
						<< "\n    Circle 2 -- " << *c2ptr;
					break;
				case 5:
					break;
				default:
					cout << "\n    WRONG OPTION!\n";
					break;
				}
			} while (option != 5);
			break;
		case 4:
			if (c1ptr == nullptr && c2ptr == nullptr)
				cout << "\n    Circles not initialized  ";
			else
				c1ptr->overlap(*c2ptr);
			break;
		case 5:
			if (c1ptr == nullptr && c2ptr == nullptr)
				cout << "\n    Circles not initialized  ";
			else {
				cout << "\n\n    Combining Circles ...";
				c1ptr->combine(*c2ptr);
			}
			break;
		case 6:
			if (c1ptr == nullptr && c2ptr == nullptr)
				cout << "\n    Circles not initialized  ";
			else
				cout << "\n    Circle 1 -- " << *c1ptr
					<< "\n    Circle 2 -- " << *c2ptr;
			break;
		case 7:
			cout << "\n    Having fun!";
			break;
		case 12:

			
			s1ptr = new Circle(0, 0, 2);
			s2ptr = new Rectangle(1, 0, 2, 4);
			cout << "\n*s1ptr : " << *s1ptr
				<< "\n*s2ptr : " << *s2ptr;
			break;
		default:
			cout << "\n  WRONG ANSWER ...";
			break;
		}

	} while (option != 7);
}