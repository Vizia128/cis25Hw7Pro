#include <iostream>
#include "Menu.h"
#include "Fraction.h"
#include "FractionUtility.h"
#include "Point.h"
#include "PointUtility.h"
#include "Circle.h"
#include "CircleUtility.h"
#include "Rectangle.h"
#include "ShapeUtility.h"
using namespace std;

void menuHw7Ex1() {
	Shape* s1ptr = nullptr;
	Shape* s2ptr = nullptr;
	Point* movePtr = nullptr;
	int overlapType = -1;
	int option = -1;

	do {
		cout << "\n\n*******************************"
			<< "\n*         MENU - Hw #7        *"
			<< "\n*  1. Initializing(2 Shapes)  *"
			<< "\n*  2. Positioning             *"
			<< "\n*  3. Moving                  *"
			<< "\n*  4. Comparing               *"
			<< "\n*  5. Overlapping Area        *"
			<< "\n*  6. Displaying              *"
			<< "\n*  7. Quit                    *"
			<< "\n*******************************"
			<< "\nSelect an option(use integer value only) : ";
		cin >> option;

		switch (option) {
		case 1:
			do {
				cout << "\n\n  Initialization Option--"
					<< "\n    *************************************"
					<< "\n    *  Sub MENU -- CircleInitialization *"
					<< "\n    *  1. Initializing(2 Circles)       *"
					<< "\n    *  2. Initializing(2 Rectangles)    *"
					<< "\n    *  3. Printing                      *"
					<< "\n    *  4. Returning                     *"
					<< "\n    *************************************"
					<< "\n    Select an option (use integer value only) : ";
				cin >> option;

				switch (option) {
				case 1:
					delete s1ptr;
					init(&s1ptr, &s2ptr, "Circle");
					cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
						<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
					break;
				case 2:
					init(&s1ptr, &s2ptr, "Rectangle");
					cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
						<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
					break;
				case 3:
					cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
						<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
					break;
				case 4:
					cout << "\n        Returning to previous menu!";
					break;
				default:
					cout << "\n    WRONG OPTION!\n";
					break;
				}
			} while (option != 4);
			break;
		case 2:
			if (s1ptr == nullptr || s2ptr == nullptr) {
				cout << "\n    Shapes not initialized  ";
			}

			else {
				//cout << "\n    " << s1ptr->getType() << " 1 is centered in Quadrant : "
				//	<< s1ptr->getCenter().getQuadrant()
				//	<< "\n    " << s2ptr->getType() << " 2 is centered in Quadrant : "
				//	<< s2ptr->getCenter().getQuadrant();
				s1ptr->overlapType(*s2ptr);
			}
			break;
		case 3:
			if (s1ptr == nullptr || s2ptr == nullptr) {
				cout << "\n    Shapes not initialized  ";
			}

			else do {
				cout << "\n\n Moving Option--"
					<< "\n    ******************************************"
					<< "\n    *  Sub MENU -- Moving                    *"
					<< "\n    *              (With respect to Shape 1) *"
					<< "\n    *  1. Horizontally                       *"
					<< "\n    *  2. Vertically                         *"
					<< "\n    *  3. Printing                           *"
					<< "\n    *  4. Returning                          *"
					<< "\n    ******************************************"
					<< "\n    Select an option (use integer value only) : ";
				cin >> option;

				switch (option) {
				case 1:
					do {
						cout << "\n\n        *****************************************"
							<< "\n        * SubMenu - Moving Horizontally         *"
							<< "\n        *           (With respect to Circle 1)  *"
							<< "\n        * 1. By an int                          *"
							<< "\n        * 2. By a Fraction                      *"
							<< "\n        * 3. Displaying                         *"
							<< "\n        * 4. Returning                          *"
							<< "\n        *****************************************"
							<< "\n        Select an option(use integer value only) : ";
						cin >> option;
						switch (option) {
						case 1:
							s2ptr->moveByX('i');
							cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
								<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
							break;
						case 2:
							s2ptr->moveByX('F');
							cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
								<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
							break;
						case 3:
							cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
								<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
							break;
						case 4:
							cout << "\n        Returning to previous menu!";
							break;
						default:
							cout << "\n    WRONG OPTION!\n";
							break;
						}
						
					} while (option != 4);
					option = 0;
					break;
				case 2:
					do {
						cout << "\n\n        *****************************************"
							<< "\n        * SubMenu - Moving Verticaly            *"
							<< "\n        *           (With respect to Circle 1)  *"
							<< "\n        * 1. By an int                          *"
							<< "\n        * 2. By a Fraction                      *"
							<< "\n        * 3. Displaying                         *"
							<< "\n        * 4. Returning                          *"
							<< "\n        *****************************************"
							<< "\n        Select an option(use integer value only) : ";
						cin >> option;
						switch (option) {
						case 1:
							s2ptr->moveByY('i');
							cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
								<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
							break;
						case 2:
							s2ptr->moveByY('F');
							cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
								<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
							break;
						case 3:
							cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
								<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
							break;
						case 4:
							cout << "\n        Returning to previous menu!";
							break;
						default:
							cout << "\n    WRONG OPTION!\n";
							break;
						}
					} while (option != 4);
					option = 0;
					break;
				case 3:
					cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
						<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
					break;
				case 4:
					break;
					cout << "\n        Returning to previous menu!";
				default:
					cout << "\n    WRONG OPTION!\n";
					break;
				}
			} while (option != 4);
			break;
		case 4:
			if (s1ptr == nullptr && s2ptr == nullptr)
				cout << "\n    Shapes not initialized  ";
			else do {
				cout << "\n    *****************************************"
					<< "\n    * SubMenu - Comparing                   *"
					<< "\n    *           (With respect to Circle 1)  *"
					<< "\n    * 1. Area                               *"
					<< "\n    * 2. Perimeter                          *"
					<< "\n    * 3. Displaying                         *"
					<< "\n    * 4. Returning                          *"
					<< "\n    *****************************************"
					<< "\n    Select an option(use integer value only) : ";
				cin >> option;
				switch (option) {
				case 1:
					s2ptr->areaCompare(*s1ptr);
					break;
				case 2:
					s2ptr->perimeterCompare(*s1ptr);
					break;
				case 3:
					cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
						<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
					break;
				case 4:
					cout << "\n        Returning to previous menu!";
				default:
					cout << "\n    WRONG OPTION!\n";
					break;
				}
			} while (option != 4);
			break;
		case 5:
			if (s1ptr == nullptr && s2ptr == nullptr)
				cout << "\n    Shapes not initialized  ";
			else {
				s1ptr->overlapShape(*s2ptr);
			}
			break;
		case 6:
			if (s1ptr == nullptr && s2ptr == nullptr)
				cout << "\n    Shapes not initialized  ";
			else
				cout << "\n      " << s1ptr->getType() << " 1 -- " << *s1ptr
				<< "\n      " << s2ptr->getType() << " 2 -- " << *s2ptr;
			break;
		case 7:
			cout << "\n    Having fun!";
			break;
		case 12:
			cout << "\n    Testing Option -- "
				<< "\n    *******************"
				<< "\n    * 1. Circles      *"
				<< "\n    * 2. Rectangles   *"
				<< "\n    *******************"
				<< "\n    Enter option : ";
			cin >> option;
			if (option == 1) {
				delete s1ptr;
				delete s2ptr;
				s1ptr = new Circle(rand()%10, rand() % 10, rand() % 10);
				s2ptr = new Circle(rand() % 10, rand() % 10, rand() % 10);
			}
			else if (option == 2) {
				delete s1ptr;
				delete s2ptr;
				s1ptr = new Rectangle(rand() % 10, rand() % 10,
					rand() % 10, rand() % 10);
				s2ptr = new Rectangle(rand() % 10, rand() % 10,
					rand() % 10, rand() % 10);
			}
			else 
				cout << "/n    peanutbutter";
			cout << "\n*s1ptr : " << *s1ptr
				<< "\n*s2ptr : " << *s2ptr;
			break;
		default:
			cout << "\n  WRONG ANSWER ...";
			break;
		}

	} while (option != 7);
}