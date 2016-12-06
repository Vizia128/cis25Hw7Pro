#include "Rect.h"
#include "Circ.h"
#include <iostream>
using namespace std;

Rect::Rect() : x(0), y(0), l(0), w(0) {
}
Rect::Rect(int X, int Y, int L, int W) : x(X), y(Y), l(L), w(W) {
}

int Rect::overlapwith(const Shap& with)const {
	cout << "\nRect::overlapwith(const Shap&)const";
	return with.overlap(*this);
}
int Rect::overlap(const Rect& w)const {
	cout << "\nRect::overlap(const Rect&)const";
	return 22;
}
int Rect::overlap(const Circ& w)const {
	cout << "\nRect::overlap(const Circ&)const";
	return 21;
}