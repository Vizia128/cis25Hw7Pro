#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Shap.h"
using namespace std;

class Circ;

class Rect : public Shap {
public:
	Rect();
	Rect(int, int, int, int);

	int overlapwith(const Shap&)const;
	int overlap(const Rect&)const;
	int overlap(const Circ&)const;

private:
	int x, y, l, w;

};


#endif
