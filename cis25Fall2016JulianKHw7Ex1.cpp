#include "Menu.h"
#include <iostream>
using namespace std;



int main() {
	cout << "CIS 25 - C++ Programming"
		<< "\nLaney College"
		<< "\nJulian K"
		<< "\nAssignment Information --"
		<< "\n  Assignment Number : Homework 7,"
		<< "\n                      Exercise #1"
		<< "\n  Written by :        Julian K"
		<< "\n  Due Date :            2016/12/8";

	menuHw7Ex1();
	return 0;
}


/*	Comments
I added the full rectangle shape and option 5 just for fun.
Option 5 displays the overlapping area,
however it was difficult to test how how accurate 
the circle overlapping area was and I know to 
rectangle overlapping area is often wrong.

This could be because I get a C4244 ERROR 
'argument': conversion from 'double' to 'const int'
on lines 192 and 193 in Rectangle.cpp


Hidden option: 12 will create two random circles or rectangles
I used this to quickly test different shapes and thought I 
should leave it in.
*/

//	Output
//CIS 25 - C++ Programming
//Laney College
//Julian K
//Assignment Information --
//Assignment Number : Homework 7,
//Exercise #1
//Written by : Julian K
//Due Date : 2016 / 12 / 6
//
//* ******************************
//*         MENU - Hw #7 *
//*  1. Initializing(2 Shapes)  *
//*  2. Positioning             *
//*  3. Moving                  *
//*  4. Comparing               *
//*  5. Overlapping Area        *
//*  6. Displaying              *
//*  7. Quit                    *
//*******************************
//Select an option(use integer value only) : 2
//
//Shapes not initialized
//
//*******************************
//*         MENU - Hw #7 *
//*  1. Initializing(2 Shapes)  *
//*  2. Positioning             *
//*  3. Moving                  *
//*  4. Comparing               *
//*  5. Overlapping Area        *
//*  6. Displaying              *
//*  7. Quit                    *
//*******************************
//Select an option(use integer value only) : 1
//
//
//Initialization Option--
//*************************************
//*  Sub MENU -- CircleInitialization *
//*  1. Initializing(2 Circles)       *
//*  2. Initializing(2 Rectangles)    *
//*  3. Printing                      *
//*  4. Returning                     *
//*************************************
//Select an option(use integer value only) : 1
//
//Enter dimensions of Circle 1
//X - coordinate -
//Enter numerator : 0
//Enter denominator : 1
//
//Y - coordinate -
//Enter numerator : 4
//Enter denominator : 2
//
//radius -
//Enter numerator : 1
//Enter denominator : 1
//
//Enter dimensions of Circle 2
//X - coordinate -
//Enter numerator : 3
//Enter denominator : 2
//
//Y - coordinate -
//Enter numerator : 1
//Enter denominator : -2
//
//radius -
//Enter numerator : -6
//Enter denominator : -3
//
//Circle 1 --(x : 0, y : 2, r : 1)
//Circle 2 --(x : 3 / 2, y : -1 / 2, r : 2)
//
//Initialization Option--
//*************************************
//*  Sub MENU -- CircleInitialization *
//*  1. Initializing(2 Circles)       *
//*  2. Initializing(2 Rectangles)    *
//*  3. Printing                      *
//*  4. Returning                     *
//*************************************
//Select an option(use integer value only) : 4
//
//Returning to previous menu!
//
//*******************************
//*         MENU - Hw #7 *
//*  1. Initializing(2 Shapes)  *
//*  2. Positioning             *
//*  3. Moving                  *
//*  4. Comparing               *
//*  5. Overlapping Area        *
//*  6. Displaying              *
//*  7. Quit                    *
//*******************************
//Select an option(use integer value only) : 2
//
//The circles are overlapping
//
//*******************************
//*         MENU - Hw #7 *
//*  1. Initializing(2 Shapes)  *
//*  2. Positioning             *
//*  3. Moving                  *
//*  4. Comparing               *
//*  5. Overlapping Area        *
//*  6. Displaying              *
//*  7. Quit                    *
//*******************************
//Select an option(use integer value only) : 3
//
//
//Moving Option--
//******************************************
//*  Sub MENU -- Moving                    *
//*              (With respect to Shape 1) *
//*  1. Horizontally                       *
//*  2. Vertically                         *
//*  3. Printing                           *
//*  4. Returning                          *
//******************************************
//Select an option(use integer value only) : 1
//
//
//* ****************************************
//* SubMenu - Moving Horizontally         *
//*           (With respect to Circle 1)  *
//* 1. By an int                          *
//* 2. By a Fraction                      *
//* 3. Displaying                         *
//* 4. Returning                          *
//*****************************************
//Select an option(use integer value only) : -2
//
//WRONG OPTION!
//
//
//*****************************************
//* SubMenu - Moving Horizontally         *
//*           (With respect to Circle 1)  *
//* 1. By an int                          *
//* 2. By a Fraction                      *
//* 3. Displaying                         *
//* 4. Returning                          *
//*****************************************
//Select an option(use integer value only) : 1
//
//Enter Delta - x : -2
//
//Circle 1 --(x : 0, y : 2, r : 1)
//Circle 2 --(x : -1 / 2, y : -1 / 2, r : 2)
//
//*****************************************
//* SubMenu - Moving Horizontally         *
//*           (With respect to Circle 1)  *
//* 1. By an int                          *
//* 2. By a Fraction                      *
//* 3. Displaying                         *
//* 4. Returning                          *
//*****************************************
//Select an option(use integer value only) : 4
//
//Returning to previous menu!
//
//Moving Option--
//******************************************
//*  Sub MENU -- Moving                    *
//*              (With respect to Shape 1) *
//*  1. Horizontally                       *
//*  2. Vertically                         *
//*  3. Printing                           *
//*  4. Returning                          *
//******************************************
//Select an option(use integer value only) : 2
//
//
//* ****************************************
//* SubMenu - Moving Verticaly            *
//*           (With respect to Circle 1)  *
//* 1. By an int                          *
//* 2. By a Fraction                      *
//* 3. Displaying                         *
//* 4. Returning                          *
//*****************************************
//Select an option(use integer value only) : 2
//
//Enter Delta - y :
//	Enter numerator : 1
//	Enter denominator : 2
//
//	Circle 1 --(x : 0, y : 2, r : 1)
//	Circle 2 --(x : -1 / 2, y : 0, r : 2)
//
//	*****************************************
//	* SubMenu - Moving Verticaly            *
//	*           (With respect to Circle 1)  *
//	* 1. By an int                          *
//	* 2. By a Fraction                      *
//	* 3. Displaying                         *
//	* 4. Returning                          *
//	*****************************************
//	Select an option(use integer value only) : 4
//
//	Returning to previous menu!
//
//	Moving Option--
//	******************************************
//	*  Sub MENU -- Moving                    *
//	*              (With respect to Shape 1) *
//	*  1. Horizontally                       *
//	*  2. Vertically                         *
//	*  3. Printing                           *
//	*  4. Returning                          *
//	******************************************
//	Select an option(use integer value only) : 4
//
//
//	* ******************************
//	*         MENU - Hw #7 *
//	*  1. Initializing(2 Shapes)  *
//	*  2. Positioning             *
//	*  3. Moving                  *
//	*  4. Comparing               *
//	*  5. Overlapping Area        *
//	*  6. Displaying              *
//	*  7. Quit                    *
//	*******************************
//	Select an option(use integer value only) : 4
//
//	* ****************************************
//	* SubMenu - Comparing                   *
//	*           (With respect to Circle 1)  *
//	* 1. Area                               *
//	* 2. Perimeter                          *
//	* 3. Displaying                         *
//	* 4. Returning                          *
//	*****************************************
//	Select an option(use integer value only) : 1
//
//	Circle 1 :
//	Center : (0, 2)
//	Radius : 1
//	Area : 157 / 50
//
//	Has a smaller area than
//
//	Circle 2 :
//	Center : (-1 / 2, 0)
//	Radius : 2
//	Area : 314 / 25
//	* ****************************************
//	* SubMenu - Comparing                   *
//	*           (With respect to Circle 1)  *
//	* 1. Area                               *
//	* 2. Perimeter                          *
//	* 3. Displaying                         *
//	* 4. Returning                          *
//	*****************************************
//	Select an option(use integer value only) : 2
//
//	Circle 1 :
//	Center : (0, 2)
//	Radius : 1
//	Perimiter : 157 / 25
//
//	Has a smaller perimiter than
//
//	Circle 2 :
//	Center : (-1 / 2, 0)
//	Radius : 2
//	Perimiter : 314 / 25
//	* ****************************************
//	* SubMenu - Comparing                   *
//	*           (With respect to Circle 1)  *
//	* 1. Area                               *
//	* 2. Perimeter                          *
//	* 3. Displaying                         *
//	* 4. Returning                          *
//	*****************************************
//	Select an option(use integer value only) : 4
//
//	Returning to previous menu!
//	WRONG OPTION!
//
//
//	*******************************
//	*         MENU - Hw #7 *
//	*  1. Initializing(2 Shapes)  *
//	*  2. Positioning             *
//	*  3. Moving                  *
//	*  4. Comparing               *
//	*  5. Overlapping Area        *
//	*  6. Displaying              *
//	*  7. Quit                    *
//	*******************************
//	Select an option(use integer value only) : 5
//
//	The circles are overlapping
//	The circles overlap to create a lens with an area of 1.28569
//
//
//	*******************************
//	*         MENU - Hw #7 *
//	*  1. Initializing(2 Shapes)  *
//	*  2. Positioning             *
//	*  3. Moving                  *
//	*  4. Comparing               *
//	*  5. Overlapping Area        *
//	*  6. Displaying              *
//	*  7. Quit                    *
//	*******************************
//	Select an option(use integer value only) : 7
//
//    Having fun!
