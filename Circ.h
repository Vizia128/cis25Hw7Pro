#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shap.h"
using namespace std;

class Rect;

class Circ : public Shap {
public:
	Circ();
	Circ(int, int, int);

	int overlapwith(const Shap&)const;
	int overlap(const Rect&)const;
	int overlap(const Circ&)const;

private:
	int x, y, r;

};
#endif