#include "Circ.h"
#include "Rect.h"
#include <iostream>
using namespace std;

Circ::Circ() : x(0), y(0), r(0) {
}
Circ::Circ(int X, int Y, int R) : x(X), y(Y), r(R) {
}

int Circ::overlapwith(const Shap& with)const {
	cout << "\nCirc::overlapwith(const Shap&)const";
	return with.overlap(*this);
}
int Circ::overlap(const Rect& w)const {
	cout << "\nCirc::overlap(const Rect&)const";
	return 12;
}
int Circ::overlap(const Circ& w)const {
	cout << "\nCirc::overlap(const Circ&)const";
	return 11;
}